/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_AD_TRANSFER_AD_TRANSFER_OBSERVER_H_  // NOLINT
#define BAT_ADS_INTERNAL_AD_TRANSFER_AD_TRANSFER_OBSERVER_H_  // NOLINT

#include "base/observer_list.h"

namespace ads {

struct AdInfo;

class AdTransferObserver : public base::CheckedObserver {
 public:
  // Invoked when an ad is transferred
  virtual void OnAdTransfer(const AdInfo& ad) {}

  // Invoked when an ad fails to transfer
  virtual void OnAdTransferFailed(const AdInfo& ad) {}

 protected:
  ~AdTransferObserver() override = default;
};

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_AD_TRANSFER_AD_TRANSFER_OBSERVER_H_  NOLINT
