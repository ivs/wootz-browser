// Copyright 2023 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_COMMON_COMPANION_VISUAL_QUERY_FEATURES_H_
#define CHROME_COMMON_COMPANION_VISUAL_QUERY_FEATURES_H_

#include "base/feature_list.h"
#include "base/time/time.h"

namespace companion::visual_query::features {

// Enables visual query capabilities for the companion.
BASE_DECLARE_FEATURE(kVisualQuerySuggestions);

// Enables triggering visual query capabilities from renderer agent.
// This flag is mainly used to test the model download mechanism and guard
// against breakages from pushing new models to production.
BASE_DECLARE_FEATURE(kVisualQuerySuggestionsAgent);

// Determines if visual suggestions is enabled.
bool IsVisualQuerySuggestionsEnabled();

// Determines if visual suggestions by agent is enabled.
bool IsVisualQuerySuggestionsAgentEnabled();

// The number of ms that we need to wait before we retry to traverse the
// DOM again and perform visual classification.
base::TimeDelta StartClassificationRetryDuration();

// Only sending back 1 result to match our current UI behavior.
int MaxVisualSuggestions();

}  // namespace companion::visual_query::features
#endif  // CHROME_COMMON_COMPANION_VISUAL_QUERY_FEATURES_H_
