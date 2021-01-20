/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_FEATURES_TEXT_CLASSIFICATION_TEXT_CLASSIFICATION_FEATURES_H_  // NOLINT
#define BAT_ADS_INTERNAL_FEATURES_TEXT_CLASSIFICATION_TEXT_CLASSIFICATION_FEATURES_H_  // NOLINT

#include "base/feature_list.h"

namespace ads {
namespace features {

extern const base::Feature kTextClassification;

bool IsTextClassificationEnabled();

int GetTextClassificationProbabilitiesHistorySize();

}  // namespace features
}  // namespace ads

#endif  // BAT_ADS_INTERNAL_FEATURES_TEXT_CLASSIFICATION_TEXT_CLASSIFICATION_FEATURES_H_  NOLINT
