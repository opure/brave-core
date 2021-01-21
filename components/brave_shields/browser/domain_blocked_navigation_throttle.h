/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_SHIELDS_BROWSER_DOMAIN_BLOCKED_NAVIGATION_THROTTLE_H_
#define BRAVE_COMPONENTS_BRAVE_SHIELDS_BROWSER_DOMAIN_BLOCKED_NAVIGATION_THROTTLE_H_

#include <memory>
#include <string>
#include <vector>

#include "base/gtest_prod_util.h"
#include "base/memory/weak_ptr.h"
#include "content/public/browser/navigation_throttle.h"

namespace content {
class NavigationHandle;
class WebContents;
}  // namespace content

class PrefService;

namespace brave_shields {

class DomainBlockedNavigationThrottle : public content::NavigationThrottle {
 public:
  explicit DomainBlockedNavigationThrottle(
      content::NavigationHandle* navigation_handle,
      const std::string& locale);
  ~DomainBlockedNavigationThrottle() override;

  DomainBlockedNavigationThrottle(const DomainBlockedNavigationThrottle&) =
      delete;
  DomainBlockedNavigationThrottle& operator=(
      const DomainBlockedNavigationThrottle&) = delete;

  static std::unique_ptr<DomainBlockedNavigationThrottle>
  MaybeCreateThrottleFor(content::NavigationHandle* navigation_handle,
                         const std::string& locale);

  // content::NavigationThrottle implementation:
  content::NavigationThrottle::ThrottleCheckResult WillStartRequest() override;
  const char* GetNameForLogging() override;

 private:
  void ShowInterstitial();

  PrefService* pref_service_ = nullptr;
  std::string locale_;
  base::WeakPtrFactory<DomainBlockedNavigationThrottle> weak_ptr_factory_{this};
};

}  // namespace brave_shields

#endif  // BRAVE_COMPONENTS_BRAVE_SHIELDS_BROWSER_DOMAIN_BLOCKED_NAVIGATION_THROTTLE_H_
