// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/chrome/browser/price_insights/model/price_insights_model.h"

#import "base/test/ios/wait_util.h"
#import "base/test/task_environment.h"
#import "components/commerce/core/mock_shopping_service.h"
#import "ios/chrome/browser/commerce/model/shopping_service_factory.h"
#import "ios/chrome/browser/contextual_panel/model/contextual_panel_item_configuration.h"
#import "ios/chrome/browser/shared/model/browser_state/test_chrome_browser_state.h"
#import "ios/web/public/test/fakes/fake_navigation_manager.h"
#import "ios/web/public/test/fakes/fake_web_state.h"
#import "ios/web/public/web_state.h"
#import "testing/platform_test.h"

using testing::_;

namespace {

const char kTestUrl[] = "https://www.merchant.com/price_drop_product";
const char kTestSecondUrl[] =
    "https://www.merchant.com/second_price_drop_product";
std::string kTestTitle = "Product";

}  // namespace

// Unittests related to the PriceInsightsModel.
class PriceInsightsModelTest : public PlatformTest {
 public:
  PriceInsightsModelTest() {}
  ~PriceInsightsModelTest() override {}

  void SetUp() override {
    TestChromeBrowserState::Builder builder;
    builder.AddTestingFactory(
        commerce::ShoppingServiceFactory::GetInstance(),
        base::BindRepeating(
            [](web::BrowserState*) -> std::unique_ptr<KeyedService> {
              return commerce::MockShoppingService::Build();
            }));
    test_chrome_browser_state_ = builder.Build();
    std::unique_ptr<web::FakeNavigationManager> navigation_manager =
        std::make_unique<web::FakeNavigationManager>();
    navigation_manager->AddItem(GURL(kTestUrl), ui::PAGE_TRANSITION_LINK);
    navigation_manager->SetLastCommittedItem(
        navigation_manager->GetItemAtIndex(0));
    web_state_ = std::make_unique<web::FakeWebState>();
    web_state_->SetNavigationManager(std::move(navigation_manager));
    web_state_->SetBrowserState(test_chrome_browser_state_.get());
    web_state_->SetNavigationItemCount(1);
    web_state_->SetCurrentURL(GURL(kTestUrl));
    web_state_->SetBrowserState(test_chrome_browser_state_.get());
    price_insights_model_ = std::make_unique<PriceInsightsModel>();
    shopping_service_ = static_cast<commerce::MockShoppingService*>(
        commerce::ShoppingServiceFactory::GetForBrowserState(
            test_chrome_browser_state_.get()));
    shopping_service_->SetResponseForGetProductInfoForUrl(std::nullopt);
    shopping_service_->SetResponseForGetPriceInsightsInfoForUrl(std::nullopt);
    shopping_service_->SetIsSubscribedCallbackValue(false);
    fetch_configuration_callback_count = 0;
  }

  void FetchConfigurationCallback(
      std::unique_ptr<ContextualPanelItemConfiguration> configuration) {
    returned_configuration_ = std::move(configuration);
    fetch_configuration_callback_count++;
  }

  int GetPriceInsightsCallbacksCount() {
    return price_insights_model_->callbacks_.size();
  }

  int GetPriceInsightsCallbacksValueCountForUrl(const GURL& product_url) {
    auto callbacks_it = price_insights_model_->callbacks_.find(product_url);
    return callbacks_it->second.size();
  }

  int GetPriceInsightsExecutionsCount() {
    return price_insights_model_->price_insights_executions_.size();
  }

 protected:
  base::test::TaskEnvironment task_environment_;
  std::unique_ptr<PriceInsightsModel> price_insights_model_;
  raw_ptr<commerce::MockShoppingService> shopping_service_;
  std::unique_ptr<ContextualPanelItemConfiguration> returned_configuration_;
  int fetch_configuration_callback_count;
  std::unique_ptr<web::FakeWebState> web_state_;
  std::unique_ptr<TestChromeBrowserState> test_chrome_browser_state_;
};

// Tests that fetching the configuration for the price insights model returns no
// data when there's any product info.
TEST_F(PriceInsightsModelTest, TestFetchConfigurationNoProductInfo) {
  base::RunLoop run_loop;

  EXPECT_CALL(*shopping_service_, GetProductInfoForUrl(_, _)).Times(1);
  EXPECT_CALL(*shopping_service_, GetPriceInsightsInfoForUrl(_, _)).Times(0);

  price_insights_model_->FetchConfigurationForWebState(
      web_state_.get(),
      base::BindOnce(&PriceInsightsModelTest::FetchConfigurationCallback,
                     base::Unretained(this))
          .Then(run_loop.QuitClosure()));

  run_loop.Run();

  PriceInsightsItemConfiguration* config =
      static_cast<PriceInsightsItemConfiguration*>(
          returned_configuration_.get());

  EXPECT_EQ(nullptr, config);
}

// Test that GetProductInfoForUrl return data when the configuration is fetched.
TEST_F(PriceInsightsModelTest, TestFetchProductInfo) {
  base::RunLoop run_loop;

  std::optional<commerce::ProductInfo> info;
  info.emplace();
  info->title = kTestTitle;
  shopping_service_->SetResponseForGetProductInfoForUrl(std::move(info));

  EXPECT_CALL(*shopping_service_, GetProductInfoForUrl(_, _)).Times(1);
  EXPECT_CALL(*shopping_service_, IsSubscribed(_, _)).Times(0);

  price_insights_model_->FetchConfigurationForWebState(
      web_state_.get(),
      base::BindOnce(&PriceInsightsModelTest::FetchConfigurationCallback,
                     base::Unretained(this))
          .Then(run_loop.QuitClosure()));

  EXPECT_EQ(1, GetPriceInsightsCallbacksCount());
  EXPECT_EQ(1, GetPriceInsightsExecutionsCount());

  run_loop.Run();

  PriceInsightsItemConfiguration* config =
      static_cast<PriceInsightsItemConfiguration*>(
          returned_configuration_.get());

  EXPECT_EQ(false, config->price_insights_info.has_value());
  EXPECT_EQ(true, config->product_info.has_value());
  commerce::ProductInfo info2 = config->product_info.value();
  EXPECT_EQ(kTestTitle, info2.title);

  EXPECT_EQ(0, GetPriceInsightsCallbacksCount());
  EXPECT_EQ(0, GetPriceInsightsExecutionsCount());
}

// Test that GetPriceInsightsInfoForUrl return data when the configuration is
// fetched.
TEST_F(PriceInsightsModelTest, TestFetchPriceInsightsInfo) {
  base::RunLoop run_loop;

  std::optional<commerce::ProductInfo> info;
  info.emplace();
  info->title = kTestTitle;
  shopping_service_->SetResponseForGetProductInfoForUrl(std::move(info));

  std::optional<commerce::PriceInsightsInfo> price_info;
  price_info.emplace();
  price_info->product_cluster_id = 123u;
  price_info->catalog_history_prices.emplace_back("2021-01-01", 3330000);
  price_info->catalog_history_prices.emplace_back("2021-01-02", 4440000);
  shopping_service_->SetResponseForGetPriceInsightsInfoForUrl(
      std::move(price_info));

  EXPECT_CALL(*shopping_service_, GetProductInfoForUrl(_, _)).Times(1);
  EXPECT_CALL(*shopping_service_, GetPriceInsightsInfoForUrl(_, _)).Times(1);
  EXPECT_CALL(*shopping_service_, IsSubscribed(_, _)).Times(0);

  price_insights_model_->FetchConfigurationForWebState(
      web_state_.get(),
      base::BindOnce(&PriceInsightsModelTest::FetchConfigurationCallback,
                     base::Unretained(this))
          .Then(run_loop.QuitClosure()));

  EXPECT_EQ(1, GetPriceInsightsCallbacksCount());
  EXPECT_EQ(1, GetPriceInsightsExecutionsCount());

  run_loop.Run();

  PriceInsightsItemConfiguration* config =
      static_cast<PriceInsightsItemConfiguration*>(
          returned_configuration_.get());

  EXPECT_EQ(true, config->product_info.has_value());
  EXPECT_EQ(true, config->price_insights_info.has_value());
  commerce::PriceInsightsInfo info2 = config->price_insights_info.value();
  EXPECT_EQ(123u, info2.product_cluster_id);

  EXPECT_EQ(0, GetPriceInsightsCallbacksCount());
  EXPECT_EQ(0, GetPriceInsightsExecutionsCount());
}

// Tests that GetProductInfoForUrl is only called once when multiple requests
// in-flight have the same URL.
TEST_F(PriceInsightsModelTest, TestMultipleRequestForTheSameURL) {
  base::RunLoop run_loop;

  std::optional<commerce::ProductInfo> product_info;
  product_info.emplace();
  product_info->title = kTestTitle;
  shopping_service_->SetResponseForGetProductInfoForUrl(
      std::move(product_info));

  std::optional<commerce::PriceInsightsInfo> price_insights_info;
  price_insights_info.emplace();
  price_insights_info->catalog_history_prices.emplace_back("2021-01-01",
                                                           3330000);
  shopping_service_->SetResponseForGetPriceInsightsInfoForUrl(
      std::move(price_insights_info));

  EXPECT_CALL(*shopping_service_, GetProductInfoForUrl(_, _)).Times(1);
  EXPECT_CALL(*shopping_service_, GetPriceInsightsInfoForUrl(_, _)).Times(1);
  EXPECT_CALL(*shopping_service_, IsSubscribed(_, _)).Times(0);

  price_insights_model_->FetchConfigurationForWebState(
      web_state_.get(),
      base::BindOnce(&PriceInsightsModelTest::FetchConfigurationCallback,
                     base::Unretained(this))
          .Then(run_loop.QuitClosure()));

  price_insights_model_->FetchConfigurationForWebState(
      web_state_.get(),
      base::BindOnce(&PriceInsightsModelTest::FetchConfigurationCallback,
                     base::Unretained(this))
          .Then(run_loop.QuitClosure()));

  EXPECT_EQ(1, GetPriceInsightsCallbacksCount());
  EXPECT_EQ(2, GetPriceInsightsCallbacksValueCountForUrl(GURL(kTestUrl)));
  EXPECT_EQ(1, GetPriceInsightsExecutionsCount());

  run_loop.Run();

  ASSERT_TRUE(base::test::ios::WaitUntilConditionOrTimeout(
      base::test::ios::kWaitForActionTimeout, ^bool {
        base::RunLoop().RunUntilIdle();
        return fetch_configuration_callback_count == 2;
      }));

  PriceInsightsItemConfiguration* config =
      static_cast<PriceInsightsItemConfiguration*>(
          returned_configuration_.get());

  EXPECT_EQ(true, config->product_info.has_value());
  EXPECT_EQ(true, config->price_insights_info.has_value());

  EXPECT_EQ(0, GetPriceInsightsCallbacksCount());
  EXPECT_EQ(0, GetPriceInsightsExecutionsCount());
}

// Tests that GetProductInfoForUrl is called for each request in-flight that has
// a different URL.
TEST_F(PriceInsightsModelTest, TestMultipleRequestForDifferentURL) {
  base::RunLoop run_loop;

  std::optional<commerce::ProductInfo> product_info;
  product_info.emplace();
  product_info->title = kTestTitle;
  shopping_service_->SetResponseForGetProductInfoForUrl(
      std::move(product_info));

  std::optional<commerce::PriceInsightsInfo> price_insights_info;
  price_insights_info.emplace();
  price_insights_info->catalog_history_prices.emplace_back("2021-01-01",
                                                           3330000);
  shopping_service_->SetResponseForGetPriceInsightsInfoForUrl(
      std::move(price_insights_info));

  EXPECT_CALL(*shopping_service_, GetProductInfoForUrl(_, _)).Times(2);
  EXPECT_CALL(*shopping_service_, GetPriceInsightsInfoForUrl(_, _)).Times(2);
  EXPECT_CALL(*shopping_service_, IsSubscribed(_, _)).Times(0);

  price_insights_model_->FetchConfigurationForWebState(
      web_state_.get(),
      base::BindOnce(&PriceInsightsModelTest::FetchConfigurationCallback,
                     base::Unretained(this))
          .Then(run_loop.QuitClosure()));

  web_state_->SetCurrentURL(GURL(kTestSecondUrl));

  price_insights_model_->FetchConfigurationForWebState(
      web_state_.get(),
      base::BindOnce(&PriceInsightsModelTest::FetchConfigurationCallback,
                     base::Unretained(this))
          .Then(run_loop.QuitClosure()));

  EXPECT_EQ(2, GetPriceInsightsCallbacksCount());
  EXPECT_EQ(2, GetPriceInsightsExecutionsCount());

  run_loop.Run();

  ASSERT_TRUE(base::test::ios::WaitUntilConditionOrTimeout(
      base::test::ios::kWaitForActionTimeout, ^bool {
        base::RunLoop().RunUntilIdle();
        return fetch_configuration_callback_count == 2;
      }));

  PriceInsightsItemConfiguration* config =
      static_cast<PriceInsightsItemConfiguration*>(
          returned_configuration_.get());

  EXPECT_EQ(true, config->product_info.has_value());
  EXPECT_EQ(true, config->price_insights_info.has_value());

  EXPECT_EQ(0, GetPriceInsightsCallbacksCount());
  EXPECT_EQ(0, GetPriceInsightsExecutionsCount());
}

// Test that GetProductInfoForUrl return data when the configuration is fetched.
TEST_F(PriceInsightsModelTest, TestFetchIsSubscribed) {
  base::RunLoop run_loop;

  std::optional<commerce::ProductInfo> info;
  info.emplace();
  info->title = kTestTitle;
  info->product_cluster_id = 12345L;
  shopping_service_->SetResponseForGetProductInfoForUrl(std::move(info));
  shopping_service_->SetIsSubscribedCallbackValue(true);

  EXPECT_CALL(*shopping_service_, GetProductInfoForUrl(_, _)).Times(1);
  EXPECT_CALL(*shopping_service_, IsSubscribed(_, _)).Times(1);

  price_insights_model_->FetchConfigurationForWebState(
      web_state_.get(),
      base::BindOnce(&PriceInsightsModelTest::FetchConfigurationCallback,
                     base::Unretained(this))
          .Then(run_loop.QuitClosure()));

  run_loop.Run();

  PriceInsightsItemConfiguration* config =
      static_cast<PriceInsightsItemConfiguration*>(
          returned_configuration_.get());

  EXPECT_EQ(true, config->is_subscribed);
}

// Test that GetProductInfoForUrl return data when the configuration is fetched.
TEST_F(PriceInsightsModelTest, TestFetchProductInfoWithPriceTrackAvailable) {
  base::RunLoop run_loop;

  std::optional<commerce::ProductInfo> info;
  info.emplace();
  info->title = kTestTitle;
  info->product_cluster_id = 12345L;
  shopping_service_->SetResponseForGetProductInfoForUrl(std::move(info));
  shopping_service_->SetIsSubscribedCallbackValue(false);

  EXPECT_CALL(*shopping_service_, GetProductInfoForUrl(_, _)).Times(1);
  EXPECT_CALL(*shopping_service_, IsSubscribed(_, _)).Times(1);

  price_insights_model_->FetchConfigurationForWebState(
      web_state_.get(),
      base::BindOnce(&PriceInsightsModelTest::FetchConfigurationCallback,
                     base::Unretained(this))
          .Then(run_loop.QuitClosure()));

  run_loop.Run();

  PriceInsightsItemConfiguration* config =
      static_cast<PriceInsightsItemConfiguration*>(
          returned_configuration_.get());

  EXPECT_EQ(true, config->can_price_track);
}

// Test that GetProductInfo, GetProductInfoForUrl, and IsSubscribed all return
// data for the config.
TEST_F(PriceInsightsModelTest, TestFetchCompleteConfig) {
  base::RunLoop run_loop;

  shopping_service_->SetIsSubscribedCallbackValue(true);

  std::optional<commerce::ProductInfo> info;
  info.emplace();
  info->title = kTestTitle;
  info->product_cluster_id = 12345L;
  shopping_service_->SetResponseForGetProductInfoForUrl(std::move(info));

  std::optional<commerce::PriceInsightsInfo> price_info;
  price_info.emplace();
  price_info->product_cluster_id = 123u;
  price_info->catalog_history_prices.emplace_back("2021-01-01", 3330000);
  price_info->catalog_history_prices.emplace_back("2021-01-02", 4440000);
  shopping_service_->SetResponseForGetPriceInsightsInfoForUrl(
      std::move(price_info));

  EXPECT_CALL(*shopping_service_, GetProductInfoForUrl(_, _)).Times(1);
  EXPECT_CALL(*shopping_service_, GetPriceInsightsInfoForUrl(_, _)).Times(1);
  EXPECT_CALL(*shopping_service_, IsSubscribed(_, _)).Times(1);

  price_insights_model_->FetchConfigurationForWebState(
      web_state_.get(),
      base::BindOnce(&PriceInsightsModelTest::FetchConfigurationCallback,
                     base::Unretained(this))
          .Then(run_loop.QuitClosure()));

  run_loop.Run();

  PriceInsightsItemConfiguration* config =
      static_cast<PriceInsightsItemConfiguration*>(
          returned_configuration_.get());

  EXPECT_EQ(true, config->is_subscribed);
}
