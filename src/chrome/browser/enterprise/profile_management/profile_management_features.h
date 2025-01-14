// Copyright 2023 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_ENTERPRISE_PROFILE_MANAGEMENT_PROFILE_MANAGEMENT_FEATURES_H_
#define CHROME_BROWSER_ENTERPRISE_PROFILE_MANAGEMENT_PROFILE_MANAGEMENT_FEATURES_H_

#include "base/feature_list.h"
#include "base/metrics/field_trial_params.h"
#include "build/build_config.h"

namespace profile_management::features {

// Controls whether third-party profile management is enabled.
BASE_DECLARE_FEATURE(kThirdPartyProfileManagement);

// Controls whether token-based profile management is enabled.
BASE_DECLARE_FEATURE(kEnableProfileTokenManagement);

// Controls whether OIDC-response profile management is enabled.
BASE_DECLARE_FEATURE(kOidcAuthProfileManagement);

// Oidc authentication related feature params.
extern const base::FeatureParam<std::string> kOidcAuthStubDmToken;
extern const base::FeatureParam<std::string> kOidcAuthStubProfileId;
extern const base::FeatureParam<std::string> kOidcAuthStubClientId;
extern const base::FeatureParam<std::string> kOidcAuthStubUserName;
extern const base::FeatureParam<std::string> kOidcAuthStubUserEmail;
extern const base::FeatureParam<bool> kOidcAuthIsDasherBased;

}  // namespace profile_management::features

#endif  // CHROME_BROWSER_ENTERPRISE_PROFILE_MANAGEMENT_PROFILE_MANAGEMENT_FEATURES_H_
