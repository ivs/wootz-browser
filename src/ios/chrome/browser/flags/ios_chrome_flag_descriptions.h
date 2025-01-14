// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IOS_CHROME_BROWSER_FLAGS_IOS_CHROME_FLAG_DESCRIPTIONS_H_
#define IOS_CHROME_BROWSER_FLAGS_IOS_CHROME_FLAG_DESCRIPTIONS_H_

#include "Availability.h"

#include "base/debug/debugging_buildflags.h"

// Please add names and descriptions in alphabetical order.

namespace flag_descriptions {

// Title and description for the flag to control upstreaming credit cards.
extern const char kAutofillCreditCardUploadName[];
extern const char kAutofillCreditCardUploadDescription[];

// Title and description for the flag that disables autofill profile updates for
// testing purposes.
extern const char kAutofillDisableProfileUpdatesName[];
extern const char kAutofillDisableProfileUpdatesDescription[];

// Title and description for the flag that disables silent autofill profile
// updates for testing purposes.
extern const char kAutofillDisableSilentProfileUpdatesName[];
extern const char kAutofillDisableSilentProfileUpdatesDescription[];

// Title and description for the flag to enable custom card art images for
// autofill Payments UI, instead of built-in network images.
extern const char kAutofillEnableCardArtImageName[];
extern const char kAutofillEnableCardArtImageDescription[];

// Title and description for the flag to enable American Express card benefits
// for autofill Payments UI.
extern const char kAutofillEnableCardBenefitsForAmericanExpressName[];
extern const char kAutofillEnableCardBenefitsForAmericanExpressDescription[];

// Title and description for the flag to enable Capital One card benefits for
// autofill Payments UI.
extern const char kAutofillEnableCardBenefitsForCapitalOneName[];
extern const char kAutofillEnableCardBenefitsForCapitalOneDescription[];

// Title and description for the flag to enable syncing card benefits from
// the Payments server for Payments Autofill.
extern const char kAutofillEnableCardBenefitsSyncName[];
extern const char kAutofillEnableCardBenefitsSyncDescription[];

// Title and description for the flag to enable dynamically loading the fields
// for address input based on the country value.
extern const char kAutofillEnableDynamicallyLoadingFieldsForAddressInputName[];
extern const char
    kAutofillEnableDynamicallyLoadingFieldsForAddressInputDescription[];

// Title and description for the flag to send merchant_domain as a top-level
// parameter in card unmask requests.
extern const char kAutofillEnableMerchantDomainInUnmaskCardRequestName[];
extern const char kAutofillEnableMerchantDomainInUnmaskCardRequestDescription[];

// Title and description for the flag to control the latency optimization where
// the risk data pre-fetched during retrieval.
extern const char kAutofillEnablePrefetchingRiskDataForRetrievalName[];
extern const char kAutofillEnablePrefetchingRiskDataForRetrievalDescription[];

// Title and description for the flag to control the new autofill suggestion
// ranking formula for address profiles.
extern const char kAutofillEnableRankingFormulaAddressProfilesName[];
extern const char kAutofillEnableRankingFormulaAddressProfilesDescription[];

// Title and description for the flag to control the new autofill suggestion
// ranking formula for credit cards.
extern const char kAutofillEnableRankingFormulaCreditCardsName[];
extern const char kAutofillEnableRankingFormulaCreditCardsDescription[];

// Title and description for the flag that controls whether the remade Autofill
// Downstream metrics are enabled.
extern const char kAutofillEnableRemadeDownstreamMetricsName[];
extern const char kAutofillEnableRemadeDownstreamMetricsDescription[];

// Title and description for the flag to enable loading and confirmation
// for save card.
extern const char kAutofillEnableSaveCardLoadingAndConfirmationName[];
extern const char kAutofillEnableSaveCardLoadingAndConfirmationDescription[];

// Title and description for the flag to enable fallback for save card failure
// to upload and saves the card locally instead.
extern const char kAutofillEnableSaveCardLocalSaveFallbackName[];
extern const char kAutofillEnableSaveCardLocalSaveFallbackDescription[];

// Title and description for the flag that controls whether Autofill handles
// administrative area level 2 fields.
extern const char kAutofillEnableSupportForAdminLevel2Name[];
extern const char kAutofillEnableSupportForAdminLevel2Description[];

// Title and description for the flag that controls whether Autofill handles
// between streets fields.
extern const char kAutofillEnableSupportForBetweenStreetsName[];
extern const char kAutofillEnableSupportForBetweenStreetsDescription[];

// Title and description for the flag that controls whether Autofill handles
// landmark fields.
extern const char kAutofillEnableSupportForLandmarkName[];
extern const char kAutofillEnableSupportForLandmarkDescription[];

// Title and description for flag to enable showing card product name (instead
// of issuer network) in Payments UI.
extern const char kAutofillEnableCardProductNameName[];
extern const char kAutofillEnableCardProductNameDescription[];

// Title and description for the flag to enable loading and confirmation
// for virtual card enrollment.
extern const char kAutofillEnableVcnEnrollLoadingAndConfirmationName[];
extern const char kAutofillEnableVcnEnrollLoadingAndConfirmationDescription[];

// Title and description for flag to enable Verve card support for autofill.
extern const char kAutofillEnableVerveCardSupportName[];
extern const char kAutofillEnableVerveCardSupportDescription[];

// Title and description for flag to enable virtual card enrollment and
// retrieval.
extern const char kAutofillEnableVirtualCardsName[];
extern const char kAutofillEnableVirtualCardsDescription[];

// Title and description for flag to enable XHR submission detection on iOS.
extern const char kAutofillEnableXHRSubmissionDetectionIOSName[];
extern const char kAutofillEnableXHRSubmissionDetectionIOSDescription[];

// Title and description for the flag to parse standalone CVC fields for VCN
// card on file in Autofill.
extern const char kAutofillParseVcnCardOnFileStandaloneCvcFieldsName[];
extern const char kAutofillParseVcnCardOnFileStandaloneCvcFieldsDescription[];

// Title and description for the flag that controls whether the maximum number
// of Autofill suggestions shown is pruned.
extern const char kAutofillPruneSuggestionsName[];
extern const char kAutofillPruneSuggestionsDescription[];

// Title and description for the flag that makes the autofill infobars sticky.
extern const char kAutofillStickyInfobarName[];
extern const char kAutofillStickyInfobarDescription[];

// Title and description for the flag to update GPay-related links in chrome
// settings to GPay web instead of the legacy Payments Center.
extern const char kAutofillUpdateChromeSettingsLinkToGPayWebName[];
extern const char kAutofillUpdateChromeSettingsLinkToGPayWebDescription[];

// Title and description for the flag that controls whether Autofill's
// logic is using numeric unique renderer IDs instead of string IDs for
// form and field elements.
extern const char kAutofillUseRendererIDsName[];
extern const char kAutofillUseRendererIDsDescription[];

// Title and description for the flag that controls whether Autofill uses
// two or four '•' characters when displaying the last four digits of a credit
// card.
extern const char kAutofillUseTwoDotsForLastFourDigitsName[];
extern const char kAutofillUseTwoDotsForLastFourDigitsDescription[];

// Title and description for the flag that changes the default setting for the
// omnibox position.
extern const char kBottomOmniboxDefaultSettingName[];
extern const char kBottomOmniboxDefaultSettingDescription[];

// Title and description for the flag that enables the app-launch promo of
// bottom omnibox.
extern const char kBottomOmniboxPromoAppLaunchName[];
extern const char kBottomOmniboxPromoAppLaunchDescription[];

// Title and description for the flag that changes the default omnibox position
// in the promos.
extern const char kBottomOmniboxPromoDefaultPositionName[];
extern const char kBottomOmniboxPromoDefaultPositionDescription[];

// Title and description for the flag that enables the FRE promo of bottom
// omnibox.
extern const char kBottomOmniboxPromoFREName[];
extern const char kBottomOmniboxPromoFREDescription[];

// Title and description for the flag that enables region filter for the omnibox
// position promos.
extern const char kBottomOmniboxPromoRegionFilterName[];
extern const char kBottomOmniboxPromoRegionFilterDescription[];

// Title and description for the flag that enables donation of new intents.
extern const char kSpotlightDonateNewIntentsName[];
extern const char kSpotlightDonateNewIntentsDescription[];

// Title and description for the flag to control if initial uploading of crash
// reports is delayed.
extern const char kBreakpadNoDelayInitialUploadName[];
extern const char kBreakpadNoDelayInitialUploadDescription[];

// Title and description for the flag to enable the content notification
// experiments. This is a kill switcher that guarded the
// ContentPushNotifications feature.
extern const char kContentNotificationExperimentName[];
extern const char kContentNotificationExperimentDescription[];

// Title and description for the flag to enable the content notifications
// feature.
extern const char kContentPushNotificationsName[];
extern const char kContentPushNotificationsDescription[];

// Title and description for the flag to enable force showing the Contextual
// Panel entrypoint, mainly for testing purposes.
extern const char kContextualPanelForceShowEntrypointName[];
extern const char kContextualPanelForceShowEntrypointDescription[];

// Title and description for the flag to enable the contextual panel.
extern const char kContextualPanelName[];
extern const char kContextualPanelDescription[];

// Title and description for the flag to enable the Credential Provider
// Improvements.
extern const char kCredentialProviderPerformanceImprovementsName[];
extern const char kCredentialProviderPerformanceImprovementsDescription[];

// Title and description for the flag to enable experience kit apple calendar
// events.
extern const char kAppleCalendarExperienceKitName[];
extern const char kAppleCalendarExperienceKitDescription[];

// Title and description for the flag to enable phone numbers detection and
// processing.
extern const char kPhoneNumberName[];
extern const char kPhoneNumberDescription[];

// Title and description for the flag to enable measurements detection and
// conversion.
extern const char kMeasurementsName[];
extern const char kMeasurementsDescription[];

// Title and description for the flag to enable viewport intent detection.
extern const char kEnableViewportIntentsName[];
extern const char kEnableViewportIntentsDescription[];

// Title and description for the flag to enable text classifier date detection
// in experience kit.
extern const char kEnableExpKitTextClassifierDateName[];
extern const char kEnableExpKitTextClassifierDateDescription[];

// Title and description for the flag to enable text classifier address
// detection in experience kit.
extern const char kEnableExpKitTextClassifierAddressName[];
extern const char kEnableExpKitTextClassifierAddressDescription[];

// Title and description for the flag to enable text classifier phone number
// detection in experience kit.
extern const char kEnableExpKitTextClassifierPhoneNumberName[];
extern const char kEnableExpKitTextClassifierPhoneNumberDescription[];

// Title and description for the flag to enable text classifier email
// detection in experience kit.
extern const char kEnableExpKitTextClassifierEmailName[];
extern const char kEnableExpKitTextClassifierEmailDescription[];

// Title and description for the flag to enable parental controls from Family
// Link on iOS.
extern const char kEnableFamilyLinkControlsName[];
extern const char kEnableFamilyLinkControlsDescription[];

// Title and description for popout omnibox on iPad feature.
extern const char kEnablePopoutOmniboxIpadName[];
extern const char kEnablePopoutOmniboxIpadDescription[];

// Title and description for the flag to enable the Credential
// Provider Extension promo.
extern const char kCredentialProviderExtensionPromoName[];
extern const char kCredentialProviderExtensionPromoDescription[];

// Title and description for default browser video in settings experiment.
extern const char kDefaultBrowserVideoInSettingsName[];
extern const char kDefaultBrowserVideoInSettingsDescription[];

// Title and description for the flag to show the default browser tutorial from
// an external app.
extern const char kDefaultBrowserIntentsShowSettingsName[];
extern const char kDefaultBrowserIntentsShowSettingsDescription[];

// Title and description for default browser promo trigger criteria experiment.
extern const char kDefaultBrowserTriggerCriteriaExperimentName[];
extern const char kDefaultBrowserTriggerCriteriaExperimentDescription[];

// Title and description for the flag to control if a crash report is generated
// on main thread freeze.
extern const char kDetectMainThreadFreezeName[];
extern const char kDetectMainThreadFreezeDescription[];

// Title and description for the flag to disable the fullscreen scrolling logic.
extern const char kDisableFullscreenScrollingName[];
extern const char kDisableFullscreenScrollingDescription[];

// Title and description for the flag that adds the sport card to the Discover
// feed.
extern const char kDiscoverFeedSportCardName[];
extern const char kDiscoverFeedSportCardDescription[];

// Title and description for the flag to enable the color Lens and voice icons
// in the home screen widget.
extern const char kEnableColorLensAndVoiceIconsInHomeScreenWidgetName[];
extern const char kEnableColorLensAndVoiceIconsInHomeScreenWidgetDescription[];

// Title and description for the flag to enable the muting of compromised
// passwords in the Password Manager.
extern const char kEnableCompromisedPasswordsMutingName[];
extern const char kEnableCompromisedPasswordsMutingDescription[];

// Title and description for the flag to enable the sync promotion on top of the
// discover feed.
extern const char kEnableDiscoverFeedTopSyncPromoName[];
extern const char kEnableDiscoverFeedTopSyncPromoDescription[];

// Title and description for the flag to modify the feed header settings.
extern const char kEnableFeedHeaderSettingsName[];
extern const char kEnableFeedHeaderSettingsDescription[];

// Title and description for the flag to enable the sign-in promotion triggered
// by the discover feed card menu.
extern const char kEnableFeedCardMenuSignInPromoName[];
extern const char kEnableFeedCardMenuSignInPromoDescription[];

// Title and description for the flag to enable follow IPH experiment
// parameters.
extern const char kEnableFollowIPHExpParamsName[];
extern const char kEnableFollowIPHExpParamsDescription[];

// Title and description for the flag to enable the Follow UI Updates.
extern const char kEnableFollowUIUpdateName[];
extern const char kEnableFollowUIUpdateDescription[];

// Title and description for the flag to enable Friendlier Enhanced Safe
// Browsing feature on iOS.
extern const char kEnableFriendlierSafeBrowsingSettingsEnhancedProtectionName[];
extern const char
    kEnableFriendlierSafeBrowsingSettingsEnhancedProtectionDescription[];

// Title and description for the flag to enable Friendlier Standard Safe
// Browsing feature on iOS.
extern const char kEnableFriendlierSafeBrowsingSettingsStandardProtectionName[];
extern const char
    kEnableFriendlierSafeBrowsingSettingsStandardProtectionDescription[];

// Title and description for the flag to disable the Lens input selection
// and camera experience.
extern const char kDisableLensCameraName[];
extern const char kDisableLensCameraDescription[];

// Title and description for the flag to enable red interstitial facelift UI
// changes.
extern const char kEnableRedInterstitialFaceliftName[];
extern const char kEnableRedInterstitialFaceliftDescription[];

// Title and description for the flag to enable kEditPasswordsInSettings flag on
// iOS.
extern const char kEditPasswordsInSettingsName[];
extern const char kEditPasswordsInSettingsDescription[];

// Title and description for the flag to enable autofill address save prompts.
extern const char kEnableAutofillAddressSavePromptName[];
extern const char kEnableAutofillAddressSavePromptDescription[];

// Title and description for the flag to enable the discover feed discofeed
// endpoint.
extern const char kEnableDiscoverFeedDiscoFeedEndpointName[];
extern const char kEnableDiscoverFeedDiscoFeedEndpointDescription[];

// Title and description for the flag to remove the Feed from the NTP.
extern const char kEnableFeedAblationName[];
extern const char kEnableFeedAblationDescription[];

// Title and description for the flag to enable feed containment.
extern const char kEnableFeedContainmentName[];
extern const char kEnableFeedContainmentDescription[];

// Title and description for the flag to enable ghost cards on the iPad feed.
extern const char kEnableiPadFeedGhostCardsName[];
extern const char kEnableiPadFeedGhostCardsDescription[];

// Title and description for the flag to enable the preferences account storage.
extern const char kEnablePreferencesAccountStorageName[];
extern const char kEnablePreferencesAccountStorageDescription[];

// Title and description for the flag to enable the account storage.
extern const char kEnableReadingListAccountStorageName[];
extern const char kEnableReadingListAccountStorageDescription[];

// Title and description for the flag to enable the sign-in promo in the reading
// list screen.
extern const char kEnableReadingListSignInPromoName[];
extern const char kEnableReadingListSignInPromoDescription[];

// Title and description for the flag to enable omnibox suggestions scrolling on
// iPad.
extern const char kEnableSuggestionsScrollingOnIPadName[];
extern const char kEnableSuggestionsScrollingOnIPadDescription[];

// Title and description for the flag to enable startup latency improvements.
extern const char kEnableStartupImprovementsName[];
extern const char kEnableStartupImprovementsDescription[];

// Title and description for the flag to enable signed out user view demotion.
extern const char kEnableSignedOutViewDemotionName[];
extern const char kEnableSignedOutViewDemotionDescription[];

// Title and description for the flag to enable filtering experiments by Google
// group membership.
extern const char kEnableVariationsGoogleGroupFilteringName[];
extern const char kEnableVariationsGoogleGroupFilteringDescription[];

// Title and description for the flag to introduce following web channels on
// Chrome iOS.
extern const char kEnableWebChannelsName[];
extern const char kEnableWebChannelsDescription[];

// Title and description for the flag to display promos promoting the Enhanced
// Safe Browsing feature.
extern const char kEnhancedSafeBrowsingPromoName[];
extern const char kEnhancedSafeBrowsingPromoDescription[];

// Title and description for the flag to enable feed background refresh.
extern const char kFeedBackgroundRefreshName[];
extern const char kFeedBackgroundRefreshDescription[];

// Title and description for the flag to trigger the startup sign-in promo.
extern const char kForceStartupSigninPromoName[];
extern const char kForceStartupSigninPromoDescription[];

// Title and description for the flag to trigger improvement for fullscreen
// feature.
extern const char kFullscreenImprovementName[];
extern const char kFullscreenImprovementDescription[];

// Title and description for the flag to enable skipping the internal impression
// limits of the Fullscreen Promos Manager.
extern const char kFullscreenPromosManagerSkipInternalLimitsName[];
extern const char kFullscreenPromosManagerSkipInternalLimitsDescription[];

// Title and description for the command line switch used to determine the
// active fullscreen viewport adjustment mode.
extern const char kFullscreenSmoothScrollingName[];
extern const char kFullscreenSmoothScrollingDescription[];

// Title and description for the flag to enable HTTPS upgrades for
// eligible.
extern const char kHttpsUpgradesName[];
extern const char kHttpsUpgradesDescription[];

// Title and description for the flag to enable account-switching UI when
// tapping the identity disc on the New Tab page.
extern const char kIdentityDiscAccountSwitchName[];
extern const char kIdentityDiscAccountSwitchDescription[];

// Title and description for the flag to indicate the identity error in
// the overflow menu.
extern const char kIndicateIdentityErrorInOverflowMenuName[];
extern const char kIndicateIdentityErrorInOverflowMenuDescription[];

// Title and description for the flag to enable feature_engagement::Tracker
// demo mode.
extern const char kInProductHelpDemoModeName[];
extern const char kInProductHelpDemoModeDescription[];

// Title and description for the flag to enable metrics collection for edit
// menu.
extern const char kIOSBrowserEditMenuMetricsName[];
extern const char kIOSBrowserEditMenuMetricsDescription[];

// Title and description for the flag to enable detecting the username in the
// username first flows for saving.
extern const char kIOSDetectUsernameInUffName[];
extern const char kIOSDetectUsernameInUffDescription[];

// Title and description for the flag to enable the Docking Promo.
extern const char kIOSDockingPromoName[];
extern const char kIOSDockingPromoDescription[];

// Title and description for the flag to enable partial translate.
extern const char kIOSEditMenuPartialTranslateName[];
extern const char kIOSEditMenuPartialTranslateDescription[];

// Title and description for the flag to enable Search With edit menu entry.
extern const char kIOSEditMenuSearchWithName[];
extern const char kIOSEditMenuSearchWithDescription[];

// Title and description for the flag to hide Search Web edit menu entry.
extern const char kIOSEditMenuHideSearchWebName[];
extern const char kIOSEditMenuHideSearchWebDescription[];

// Title and description for the flag to enable the keyboard accessory upgrade.
extern const char kIOSKeyboardAccessoryUpgradeName[];
extern const char kIOSKeyboardAccessoryUpgradeDescription[];

// Title and description for the flag to use a UICollectionView for the Magic
// Stack.
extern const char kIOSMagicStackCollectionViewName[];
extern const char kIOSMagicStackCollectionViewDescription[];

// Title and description for the flag to require Local Authentication before
// accessing the any of the Password Manager surfaces.
extern const char kIOSPasswordAuthOnEntryV2Name[];
extern const char kIOSPasswordAuthOnEntryV2Description[];

// Title and description for the flag to enable password bottom sheet on IOS.
extern const char kIOSPasswordBottomSheetName[];
extern const char kIOSPasswordBottomSheetDescription[];

// Title and description for the flag to enable password bottom sheet triggering
// on autofocus on IOS.
extern const char kIOSPasswordBottomSheetAutofocusName[];
extern const char kIOSPasswordBottomSheetAutofocusDescription[];

// Title and description for the flag to allow syncing, managing, and displaying
// Google Password Manager WebAuthn credential ('passkey') metadata.
extern const char kSyncWebauthnCredentialsName[];
extern const char kSyncWebauthnCredentialsDescription[];

// Title and description for the flag to enable filling the username of single
// username forms in sign-in UFF.
extern const char kIOSPasswordSignInUffName[];
extern const char kIOSPasswordSignInUffDescription[];

// Title and description for the flag to enable iOS Quick Delete feature.
extern const char kIOSQuickDeleteName[];
extern const char kIOSQuickDeleteDescription[];

// Title and description for the flag to enable the Save to Drive feature.
extern const char kIOSSaveToDriveName[];
extern const char kIOSSaveToDriveDescription[];

// Title and description for the flag to enable the Save to Photos feature.
extern const char kIOSSaveToPhotosName[];
extern const char kIOSSaveToPhotosDescription[];

// Title and description of the flag to enable client side new tab page
// experiments aimed at improving user retention.
extern const char kNewTabPageFieldTrialName[];
extern const char kNewTabPageFieldTrialDescription[];

// Title and description for the flag to enable Shared Highlighting color
// change in iOS.
extern const char kIOSSharedHighlightingColorChangeName[];
extern const char kIOSSharedHighlightingColorChangeDescription[];

// Title and description for the flag to enable Shared Highlighting on AMP pages
// in iOS.
extern const char kIOSSharedHighlightingAmpName[];
extern const char kIOSSharedHighlightingAmpDescription[];

// Title and description for the flag to enable browser-layer improvements to
// the text fragments UI.
extern const char kIOSSharedHighlightingV2Name[];
extern const char kIOSSharedHighlightingV2Description[];

// Title and description for the flag to enable Tips Notifications.
extern const char kIOSTipsNotificationsName[];
extern const char kIOSTipsNotificationsDescription[];

// Title and description for the flag to enable IPH for safari switcher.
extern const char kIPHForSafariSwitcherName[];
extern const char kIPHForSafariSwitcherDescription[];

// Title and description for the flag to enable the pull-to-refreh IPH.
extern const char kIPHiOSPullToRefreshFeatureName[];
extern const char kIPHiOSPullToRefreshFeatureDescription[];

// Title and description for the flag to enable the tab swipe back/forward IPH.
extern const char kIPHiOSSwipeBackForwardFeatureName[];
extern const char kIPHiOSSwipeBackForwardFeatureDescription[];

// Title and description for the flag to enable the swipe toolbar to switch tab
// IPH.
extern const char kIPHiOSSwipeToolbarToChangeTabFeatureName[];
extern const char kIPHiOSSwipeToolbarToChangeTabFeatureDescription[];

// Title and description for the flag to enable the swipe-to-incognito IPH on
// the tab grid.
extern const char kIPHiOSTabGridSwipeRightForIncognitoName[];
extern const char kIPHiOSTabGridSwipeRightForIncognitoDescription[];

// Title and description for the flag to enable Lens circle to search feature.
extern const char kLensCircleToSearchEnabledName[];
extern const char kLensCircleToSearchEnabledDescription[];

// Title and description for the flag to add Linked Services Setting to the Sync
// Settings page.
extern const char kLinkedServicesSettingIosName[];
extern const char kLinkedServicesSettingIosDescription[];

// Title and description for the flag to lock the bottom toolbar into place.
extern const char kLockBottomToolbarName[];
extern const char kLockBottomToolbarDescription[];

// Title and Description for the flag that controls displaying the Magic Stack
// in the Home Surface,
extern const char kMagicStackName[];
extern const char kMagicStackDescription[];

// Title and Description for the flag that controls the view mode for (history)
// sync screen.
extern const char kMinorModeRestrictionsForHistorySyncOptInName[];
extern const char kMinorModeRestrictionsForHistorySyncOptInDescription[];

// Title and description for the flag that controls sending metrickit non-crash
// reports.
extern const char kMetrickitNonCrashReportName[];
extern const char kMetrickitNonCrashReportDescription[];

// Title and description for the flag to migrate syncing users to the signed-in
// non-syncing state.
extern const char kMigrateSyncingUserToSignedInName[];
extern const char kMigrateSyncingUserToSignedInDescription[];

// TODO(crbug.com/40148908): Remove this flag after the refactoring work is
// finished.
// Title and description for the flag used to test the newly
// implemented tabstrip.
extern const char kModernTabStripName[];
extern const char kModernTabStripDescription[];

// Title and description for the flag to make MVTiles a horizontal render group.
extern const char kMostVisitedTilesHorizontalRenderGroupName[];
extern const char kMostVisitedTilesHorizontalRenderGroupDescription[];

// Title and description of the flag to enable the native Find in Page API
// for iOS 16 and later.
extern const char kNativeFindInPageName[];
extern const char kNativeFindInPageDescription[];

// Title and description for the flag to enable the new NTP omnibox layout.
extern const char kNewNTPOmniboxLayoutName[];
extern const char kNewNTPOmniboxLayoutDescription[];

// Title and description for the flag to enable overflow menu customization
extern const char kOverflowMenuCustomizationName[];
extern const char kOverflowMenuCustomizationDescription[];

// Title and description for temporary bug fix to broken NTP view hierarhy.
// TODO(crbug.com/40799579): Remove this when fixed.
extern const char kNTPViewHierarchyRepairName[];
extern const char kNTPViewHierarchyRepairDescription[];

// Title and description for the flag to enable actions in suggest.
extern const char kOmniboxActionsInSuggestName[];
extern const char kOmniboxActionsInSuggestDescription[];

// Title and description for the flag to possibly remove company entity images.
extern const char kOmniboxCompanyEntityIconAdjustmentName[];
extern const char kOmniboxCompanyEntityIconAdjustmentDescription[];

// Title and description for the flag to enable Omnibox HTTPS upgrades for
// schemeless navigations.
extern const char kOmniboxHttpsUpgradesName[];
extern const char kOmniboxHttpsUpgradesDescription[];

// Title and description for the Inspire Me for Signed Out Users omnibox flag.
extern const char kOmniboxInspireMeSignedOutName[];
extern const char kOmniboxInspireMeSignedOutDescription[];

// Title and description for the flag to enable Omnibox Grouping implementation
// for ZPS.
extern const char kOmniboxGroupingFrameworkForZPSName[];
extern const char kOmniboxGroupingFrameworkForZPSDescription[];

// Title and description for the flag to enable Omnibox Grouping implementation
// for Typed Suggestions.
extern const char kOmniboxGroupingFrameworkForTypedSuggestionsName[];
extern const char kOmniboxGroupingFrameworkForTypedSuggestionsDescription[];

// Title and description for the flag to enable paste button in the omnibox's
// keyboard accessory.
extern const char kOmniboxKeyboardPasteButtonName[];
extern const char kOmniboxKeyboardPasteButtonDescription[];

// Title and description for local history zero-prefix suggestions beyond NTP.
extern const char kOmniboxLocalHistoryZeroSuggestBeyondNTPName[];
extern const char kOmniboxLocalHistoryZeroSuggestBeyondNTPDescription[];

// Title and description for the maximum number of URL matches.
extern const char kOmniboxMaxURLMatchesName[];
extern const char kOmniboxMaxURLMatchesDescription[];

// Title and description for the flag to change the max number of ZPS
// matches in the omnibox popup.
extern const char kOmniboxMaxZPSMatchesName[];
extern const char kOmniboxMaxZPSMatchesDescription[];

// Title and description for the flag to swap Omnibox Textfield implementation
// to a new experimental one.
extern const char kOmniboxNewImplementationName[];
extern const char kOmniboxNewImplementationDescription[];

// Title and description for the flag to enable Omnibox On Device Head
// suggestions (incognito).
extern const char kOmniboxOnDeviceHeadSuggestionsIncognitoName[];
extern const char kOmniboxOnDeviceHeadSuggestionsIncognitoDescription[];

// Title and description for the flag to enable Omnibox On Device Head
// suggestions (non incognito).
extern const char kOmniboxOnDeviceHeadSuggestionsNonIncognitoName[];
extern const char kOmniboxOnDeviceHeadSuggestionsNonIncognitoDescription[];

// Title and description for omnibox on device tail suggest.
extern const char kOmniboxOnDeviceTailSuggestionsName[];
extern const char kOmniboxOnDeviceTailSuggestionsDescription[];

// Title and description for storing query/match in the shortcuts database.
extern const char kOmniboxPopulateShortcutsDatabaseName[];
extern const char kOmniboxPopulateShortcutsDatabaseDescription[];

// Title and description for using content configuration in omnibox popup row.
extern const char kOmniboxPopupRowContentConfigurationName[];
extern const char kOmniboxPopupRowContentConfigurationDescription[];

// Title and description for omnibox rich inline autocompletion.
extern const char kOmniboxRichAutocompletionName[];
extern const char kOmniboxRichAutocompletionDescription[];

// Title and description for improved RTL layout of suggestions.
extern const char kOmniboxSuggestionsRTLImprovementsName[];
extern const char kOmniboxSuggestionsRTLImprovementsDescription[];

// Title and description for the flag to change the max number of autocomplete
// matches in the omnibox popup.
extern const char kOmniboxUIMaxAutocompleteMatchesName[];
extern const char kOmniboxUIMaxAutocompleteMatchesDescription[];

// Title and description for the use of in-memory zero-suggest caching.
extern const char kOmniboxZeroSuggestInMemoryCachingName[];
extern const char kOmniboxZeroSuggestInMemoryCachingDescription[];

// Title and description for the zero-suggest prefetching on the New Tab Page.
extern const char kOmniboxZeroSuggestPrefetchingName[];
extern const char kOmniboxZeroSuggestPrefetchingDescription[];

// Title and description for the zero-suggest prefetching on the Search Results
// Page.
extern const char kOmniboxZeroSuggestPrefetchingOnSRPName[];
extern const char kOmniboxZeroSuggestPrefetchingOnSRPDescription[];

// Title and description for the zero-suggest prefetching on any Web Page.
extern const char kOmniboxZeroSuggestPrefetchingOnWebName[];
extern const char kOmniboxZeroSuggestPrefetchingOnWebDescription[];

// Title and description for the flag to enable the color icons in the
// omnibox.
extern const char kOmniboxColorIconsName[];
extern const char kOmniboxColorIconsDescription[];

// Title and description for the flag to force clipboard access to be
// asynchronous.
extern const char kOnlyAccessClipboardAsyncName[];
extern const char kOnlyAccessClipboardAsyncDescription[];

// Title and description for the flag to enable Optimization Guide debug logs.
extern const char kOptimizationGuideDebugLogsName[];
extern const char kOptimizationGuideDebugLogsDescription[];

// Title and description for the flag enable download service to download in
// foreground.
extern const char kDownloadServiceForegroundSessionName[];
extern const char kDownloadServiceForegroundSessionDescription[];

// Title and description for the flag to enable optimization guide's push
// notifications
extern const char kOptimizationGuidePushNotificationClientName[];
extern const char kOptimizationGuidePushNotificationClientDescription[];

// Title and description for the flag to enable one tap experience for maps
// experience kit.
extern const char kOneTapForMapsName[];
extern const char kOneTapForMapsDescription[];

// Title and description for the flag to enable page content annotations.
extern const char kPageContentAnnotationsName[];
extern const char kPageContentAnnotationsDescription[];

// Title and description for the flag to enable persisting salient images
// metadata.
extern const char kPageContentAnnotationsPersistSalientImageMetadataName[];
extern const char
    kPageContentAnnotationsPersistSalientImageMetadataDescription[];

// Title and description for the flag to enable persisting remote page metadata.
extern const char kPageContentAnnotationsRemotePageMetadataName[];
extern const char kPageContentAnnotationsRemotePageMetadataDescription[];

// Title and description for the flag to enable page visibility.
extern const char kPageVisibilityPageContentAnnotationsName[];
extern const char kPageVisibilityPageContentAnnotationsDescription[];

// Title and description for the flag to enable PhishGuard password reuse
// detection.
extern const char kPasswordReuseDetectionName[];
extern const char kPasswordReuseDetectionDescription[];

// Title and description for the flag to enable password sharing between the
// members of the same family.
extern const char kPasswordSharingName[];
extern const char kPasswordSharingDescription[];

// Title and description for the flag to enable chrome://policy/test.
extern const char kEnablePolicyTestPageName[];
extern const char kEnablePolicyTestPageDescription[];

// Title and description for the flag to enable the Privacy Guide.
extern const char kPrivacyGuideIosName[];
extern const char kPrivacyGuideIosDescription[];

// Title and description for the flag to enable PriceNotifications IPH to be
// alwayws be displayed.
extern const char kIPHPriceNotificationsWhileBrowsingName[];
extern const char kIPHPriceNotificationsWhileBrowsingDescription[];

// Title and description for the flag to enable the notification menu item in
// the settings menu.
extern const char kNotificationSettingsMenuItemName[];
extern const char kNotificationSettingsMenuItemDescription[];

// Title and description for the flag to remove excess NTP tabs that don't have
// navigation history.
extern const char kRemoveExcessNTPsExperimentName[];
extern const char kRemoveExcessNTPsExperimentDescription[];

// Title and description for the flag to remove unsafe restore.
extern const char kRemoveOldWebStateRestoreName[];
extern const char kRemoveOldWebStateRestoreDescription[];

// Title and description for the flag to revamp Page Info in iOS.
extern const char kRevampPageInfoIosName[];
extern const char kRevampPageInfoIosDescription[];

// Title and description for the flag that makes Safe Browsing available.
extern const char kSafeBrowsingAvailableName[];
extern const char kSafeBrowsingAvailableDescription[];

// Title and description for the flag to enable real-time Safe Browsing lookups.
extern const char kSafeBrowsingRealTimeLookupName[];
extern const char kSafeBrowsingRealTimeLookupDescription[];

// Title and description for the flag to enable the Safety Check module in the
// Magic Stack.
extern const char kSafetyCheckMagicStackName[];
extern const char kSafetyCheckMagicStackDescription[];

// Title and description for the flag to enable integration with the ScreenTime
// system.
extern const char kScreenTimeIntegrationName[];
extern const char kScreenTimeIntegrationDescription[];

// Title and description for the flag to enable caching Segmentation ranking for
// the Home Magic Stack on Start.
extern const char kSegmentationPlatformIosModuleRankerCachingName[];
extern const char kSegmentationPlatformIosModuleRankerCachingDescription[];

// Title and description for the flag to enable Segmentation ranking for the
// Home Magic Stack.
extern const char kSegmentationPlatformIosModuleRankerName[];
extern const char kSegmentationPlatformIosModuleRankerDescription[];

// Title and description for the flag to enable Segmentation ranking for the
// Home Magic Stack split between Start and NTP.
extern const char kSegmentationPlatformIosModuleRankerSplitBySurfaceName[];
extern const char
    kSegmentationPlatformIosModuleRankerSplitBySurfaceDescription[];

// Title and description for the flag to send UMA data over any network.
extern const char kSendUmaOverAnyNetwork[];
extern const char kSendUmaOverAnyNetworkDescription[];

// Title and description for the flag to enable Shared Highlighting (Link to
// Text Edit Menu option).
extern const char kSharedHighlightingIOSName[];
extern const char kSharedHighlightingIOSDescription[];

// Title and description for the flag to enable the Share button
// in the web context menu in iOS.
extern const char kShareInWebContextMenuIOSName[];
extern const char kShareInWebContextMenuIOSDescription[];

// Title and description for the flag to enable annotating web forms with
// Autofill field type predictions as placeholder.
extern const char kShowAutofillTypePredictionsName[];
extern const char kShowAutofillTypePredictionsDescription[];

// Title and description for the flag to index open tabs items in Spotlight.
extern const char kSpotlightOpenTabsSourceName[];
extern const char kSpotlightOpenTabsSourceDescription[];

// Title and description for th eflag to index Reading List items in Spotlight.
extern const char kSpotlightReadingListSourceName[];
extern const char kSpotlightReadingListSourceDescription[];

// Title and description for the flag to enable the Start Surface.
extern const char kStartSurfaceName[];
extern const char kStartSurfaceDescription[];

// Title and description for the flag to control if Chrome Sync should use the
// sandbox servers.
extern const char kSyncSandboxName[];
extern const char kSyncSandboxDescription[];

// Title and description for the flag that enables session syncing when the
// visibility of a tab changes.
extern const char kSyncSessionOnVisibilityChangedName[];
extern const char kSyncSessionOnVisibilityChangedDescription[];

// Title and description for the flag to control if history's segments should
// include foreign visits from syncing devices.
extern const char kSyncSegmentsDataName[];
extern const char kSyncSegmentsDataDescription[];

// Title and description for the flag to control if tab groups are synced with
// other syncing devices.
extern const char kTabGroupSync[];
extern const char kTabGroupSyncDescription[];

// Title and description for the flag to enable TFLite for language detection.
extern const char kTFLiteLanguageDetectionName[];
extern const char kTFLiteLanguageDetectionDescription[];

// Title and description for the flag to compute both TFLite and CLD3 detection
// and ignore TFLite one.
extern const char kTFLiteLanguageDetectionIgnoreName[];
extern const char kTFLiteLanguageDetectionIgnoreDescription[];

// Title and description for the flag to use the page's theme color in the
// top toolbar.
extern const char kThemeColorInTopToolbarName[];
extern const char kThemeColorInTopToolbarDescription[];

// Title and description for the flag to enable the iOS Large Fakebox feature
extern const char kIOSLargeFakeboxName[];
extern const char kIOSLargeFakeboxDescription[];

// Title and description for the flag to enable using Lens to search using
// copied images in the omnibox.
extern const char kEnableLensInOmniboxCopiedImageName[];
extern const char kEnableLensInOmniboxCopiedImageDescription[];

// Title and description for the flag to enable session serialization
// optimizations (go/bling-session-restoration).
extern const char kEnableSessionSerializationOptimizationsName[];
extern const char kEnableSessionSerializationOptimizationsDescription[];

// Title and description for the flag to let the Tab Grid always bounce (even
// when the content fits the screen already).
extern const char kTabGridAlwaysBounceName[];
extern const char kTabGridAlwaysBounceDescription[];

// Title and description for the tab grid new compositional layout.
extern const char kTabGridCompositionalLayoutName[];
extern const char kTabGridCompositionalLayoutDescription[];

// Title and description for the tab grid refactoring flag.
extern const char kTabGridRefactoringName[];
extern const char kTabGridRefactoringDescription[];

// Title and description for the flag to enable the new transitions in the
// TabGrid.
extern const char kTabGridNewTransitionsName[];
extern const char kTabGridNewTransitionsDescription[];

// Title and description for the tab groups in grid feature.
extern const char kTabGroupsInGridName[];
extern const char kTabGroupsInGridDescription[];

// Title and description for the tab groups on iPad feature.
extern const char kTabGroupsIPadName[];
extern const char kTabGroupsIPadDescription[];

// Title and description for the flag to determine tab inactivity in the
// TabGrid.
extern const char kTabInactivityThresholdName[];
extern const char kTabInactivityThresholdDescription[];

// Title and description for the flag that adds delay between tab pickup
// banners.
extern const char kTabPickupMinimumDelayName[];
extern const char kTabPickupMinimumDelayDescription[];

// Title and description for the flag to enable tab pickup.
extern const char kTabPickupThresholdName[];
extern const char kTabPickupThresholdDescription[];

// Title and description for the flag to enable tab resumption.
extern const char kTabResumptionName[];
extern const char kTabResumptionDescription[];

// Title and description for the flag to undo the migration of syncing users to
// the signed-in non-syncing state.
extern const char kUndoMigrationOfSyncingUserToSignedInName[];
extern const char kUndoMigrationOfSyncingUserToSignedInDescription[];

// Title and description for the flag to enable the use of a single
// BookmarkModel instance per BrowserState (instead of having two).
extern const char kUnifiedBookmarkModelName[];
extern const char kUnifiedBookmarkModelDescription[];

// Title and description for the flag to control the maximum wait time (in
// seconds) for a response from the Account Capabilities API.
extern const char kWaitThresholdMillisecondsForCapabilitiesApiName[];
extern const char kWaitThresholdMillisecondsForCapabilitiesApiDescription[];

// Title and description for the flag to control if Google Payments API calls
// should use the sandbox servers.
extern const char kWalletServiceUseSandboxName[];
extern const char kWalletServiceUseSandboxDescription[];

// Title and description for the flag to control whether to send discover
// feedback to a new product destination
extern const char kWebFeedFeedbackRerouteName[];
extern const char kWebFeedFeedbackRerouteDescription[];

// Title and description for the flag to tie the default text zoom level to
// the dynamic type setting.
extern const char kWebPageDefaultZoomFromDynamicTypeName[];
extern const char kWebPageDefaultZoomFromDynamicTypeDescription[];

// Title and description for the flag to enable a different method of zooming
// web pages.
extern const char kWebPageAlternativeTextZoomName[];
extern const char kWebPageAlternativeTextZoomDescription[];

// Title and description for the flag to (re)-enable text zoom on iPad.
extern const char kWebPageTextZoomIPadName[];
extern const char kWebPageTextZoomIPadDescription[];

// Please add names and descriptions above in alphabetical order.

}  // namespace flag_descriptions

#endif  // IOS_CHROME_BROWSER_FLAGS_IOS_CHROME_FLAG_DESCRIPTIONS_H_
