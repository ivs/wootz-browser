// Copyright 2023 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.autofill.save_card;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.verifyNoInteractions;
import static org.mockito.Mockito.when;

import androidx.test.filters.SmallTest;

import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.junit.MockitoJUnit;
import org.mockito.junit.MockitoRule;

import org.chromium.base.test.BaseRobolectricTestRunner;
import org.chromium.base.test.util.Features.DisableFeatures;
import org.chromium.base.test.util.Features.EnableFeatures;
import org.chromium.chrome.browser.flags.ChromeFeatureList;
import org.chromium.components.browser_ui.bottomsheet.BottomSheetController;
import org.chromium.components.browser_ui.bottomsheet.BottomSheetController.StateChangeReason;
import org.chromium.ui.modelutil.PropertyModel;

/** Unit test for {@link AutofillSaveCardBottomSheetMediator}. */
@SmallTest
@RunWith(BaseRobolectricTestRunner.class)
public final class AutofillSaveCardBottomSheetMediatorTest {
    @Rule public MockitoRule mMockitoRule = MockitoJUnit.rule();
    @Mock private AutofillSaveCardBottomSheetContent mBottomSheetContent;
    @Mock private AutofillSaveCardBottomSheetLifecycle mLifeCycle;
    @Mock private BottomSheetController mBottomSheetController;
    @Mock private PropertyModel mModel;
    @Mock private AutofillSaveCardBottomSheetBridge mDelegate;
    private AutofillSaveCardBottomSheetMediator mMediator;

    @Before
    public void setUp() {
        mMediator =
                new AutofillSaveCardBottomSheetMediator(
                        mBottomSheetContent,
                        mLifeCycle,
                        mBottomSheetController,
                        mModel,
                        mDelegate,
                        /* isServerCard= */ true);
    }

    @Test
    public void testRequestShowContent() {
        when(mBottomSheetController.requestShowContent(
                        any(AutofillSaveCardBottomSheetContent.class), eq(true)))
                .thenReturn(true);
        mMediator.requestShowContent();

        verify(mBottomSheetController)
                .requestShowContent(
                        any(AutofillSaveCardBottomSheetContent.class), /* animate= */ eq(true));
        verify(mLifeCycle).begin(mMediator);
        verify(mDelegate).onUiShown();
    }

    @Test
    public void testRequestShowContent_whenBottomSheetReturnsFalse() {
        when(mBottomSheetController.requestShowContent(
                        any(AutofillSaveCardBottomSheetContent.class), eq(true)))
                .thenReturn(false);
        mMediator.requestShowContent();

        verifyNoInteractions(mLifeCycle);
        verify(mDelegate).onUiIgnored();
    }

    @Test
    @EnableFeatures({ChromeFeatureList.AUTOFILL_ENABLE_SAVE_CARD_LOADING_AND_CONFIRMATION})
    public void testOnAccepted_withLoadingConfirmation() {
        mMediator.onAccepted();

        verifyNoInteractions(mLifeCycle);
        verifyNoInteractions(mBottomSheetController);
        verify(mModel).set(AutofillSaveCardBottomSheetProperties.SHOW_LOADING_STATE, true);
        verify(mDelegate).onUiAccepted();
    }

    @Test
    @EnableFeatures({ChromeFeatureList.AUTOFILL_ENABLE_SAVE_CARD_LOADING_AND_CONFIRMATION})
    public void testOnAccepted_forLocalCard_withLoadingConfirmation() {
        // Create a mediator for local card. `isServerCard` is false for local cards.
        AutofillSaveCardBottomSheetMediator mediator =
                new AutofillSaveCardBottomSheetMediator(
                        mBottomSheetContent,
                        mLifeCycle,
                        mBottomSheetController,
                        mModel,
                        mDelegate,
                        /* isServerCard= */ false);
        mediator.onAccepted();

        verify(mLifeCycle).end();
        verify(mBottomSheetController)
                .hideContent(
                        any(AutofillSaveCardBottomSheetContent.class),
                        /* animate= */ eq(true),
                        eq(StateChangeReason.INTERACTION_COMPLETE));
        verify(mDelegate).onUiAccepted();
    }

    @Test
    @DisableFeatures({ChromeFeatureList.AUTOFILL_ENABLE_SAVE_CARD_LOADING_AND_CONFIRMATION})
    public void testOnAccepted_withoutLoadingConfirmation() {
        mMediator.onAccepted();

        verify(mLifeCycle).end();
        verify(mBottomSheetController)
                .hideContent(
                        any(AutofillSaveCardBottomSheetContent.class),
                        /* animate= */ eq(true),
                        eq(StateChangeReason.INTERACTION_COMPLETE));
        verify(mDelegate).onUiAccepted();
    }

    @Test
    public void testOnCanceled() {
        mMediator.onCanceled();

        verify(mLifeCycle).end();
        verify(mBottomSheetController)
                .hideContent(
                        any(AutofillSaveCardBottomSheetContent.class),
                        /* animate= */ eq(true),
                        eq(StateChangeReason.INTERACTION_COMPLETE));
        verify(mDelegate).onUiCanceled();
    }

    @Test
    public void testOnIgnored() {
        mMediator.onIgnored();

        verify(mLifeCycle).end();
        verify(mBottomSheetController)
                .hideContent(
                        any(AutofillSaveCardBottomSheetContent.class),
                        /* animate= */ eq(true),
                        eq(StateChangeReason.INTERACTION_COMPLETE));
        verify(mDelegate).onUiIgnored();
    }

    @Test
    public void testHide() {
        mMediator.hide(StateChangeReason.INTERACTION_COMPLETE);

        verify(mLifeCycle).end();
        verify(mBottomSheetController)
                .hideContent(
                        any(AutofillSaveCardBottomSheetContent.class),
                        /* animate= */ eq(true),
                        eq(StateChangeReason.INTERACTION_COMPLETE));
    }
}
