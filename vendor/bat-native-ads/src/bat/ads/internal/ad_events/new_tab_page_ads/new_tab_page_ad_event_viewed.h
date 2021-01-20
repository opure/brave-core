/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_AD_EVENTS_NEW_TAB_PAGE_ADS_NEW_TAB_PAGE_AD_EVENT_VIEWED_H_  // NOLINT
#define BAT_ADS_INTERNAL_AD_EVENTS_NEW_TAB_PAGE_ADS_NEW_TAB_PAGE_AD_EVENT_VIEWED_H_  // NOLINT

#include "bat/ads/internal/ad_events/ad_event.h"

namespace ads {

struct NewTabPageAdInfo;

namespace new_tab_page_ads {

class AdEventViewed : public AdEvent<NewTabPageAdInfo> {
 public:
  AdEventViewed();

  ~AdEventViewed() override;

  void FireEvent(const NewTabPageAdInfo& ad) override;
};

}  // namespace new_tab_page_ads
}  // namespace ads

#endif  // BAT_ADS_INTERNAL_AD_EVENTS_NEW_TAB_PAGE_ADS_NEW_TAB_PAGE_AD_EVENT_VIEWED_H_  NOLINT
