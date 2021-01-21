/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_shields/browser/domain_blocked_navigation_throttle.h"

#include <memory>
#include <utility>

#include "base/bind.h"
#include "base/threading/thread_task_runner_handle.h"
#include "brave/components/brave_shields/browser/domain_blocked_interstitial_controller_client.h"
#include "brave/components/brave_shields/browser/domain_blocked_page.h"
#include "components/prefs/pref_service.h"
#include "components/security_interstitials/content/security_interstitial_tab_helper.h"
#include "components/user_prefs/user_prefs.h"
#include "content/public/browser/browser_context.h"
#include "content/public/browser/navigation_handle.h"
#include "content/public/browser/web_contents.h"
#include "content/public/browser/web_contents_user_data.h"
#include "net/base/net_errors.h"

namespace brave_shields {

// static
std::unique_ptr<DomainBlockedNavigationThrottle>
DomainBlockedNavigationThrottle::MaybeCreateThrottleFor(
    content::NavigationHandle* navigation_handle,
    const std::string& locale) {
  return std::make_unique<DomainBlockedNavigationThrottle>(navigation_handle,
                                                           locale);
}

DomainBlockedNavigationThrottle::DomainBlockedNavigationThrottle(
    content::NavigationHandle* navigation_handle,
    const std::string& locale)
    : content::NavigationThrottle(navigation_handle),
      locale_(locale) {
  content::BrowserContext* context =
      navigation_handle->GetWebContents()->GetBrowserContext();
  pref_service_ = user_prefs::UserPrefs::Get(context);
}

DomainBlockedNavigationThrottle::~DomainBlockedNavigationThrottle() = default;

content::NavigationThrottle::ThrottleCheckResult DomainBlockedNavigationThrottle::WillStartRequest() {
  GURL url = navigation_handle()->GetURL();
  // TODO
  if (url.host() == "www.example.com") {
    ShowInterstitial();
    return content::NavigationThrottle::BLOCK_REQUEST;
  }
  return content::NavigationThrottle::PROCEED;
}

void DomainBlockedNavigationThrottle::ShowInterstitial() {
  content::NavigationHandle* handle = navigation_handle();
  content::WebContents* web_contents = handle->GetWebContents();
  const GURL& request_url = handle->GetURL();

  auto controller_client =
      std::make_unique<DomainBlockedInterstitialControllerClient>(
          web_contents, request_url, pref_service_, locale_);
  auto blocked_page = std::make_unique<DomainBlockedPage>(
      web_contents, handle->GetURL(), std::move(controller_client));

  // Get the page content before giving up ownership of |blocked_page|.
  std::string blocked_page_content = blocked_page->GetHTMLContents();

  security_interstitials::SecurityInterstitialTabHelper::AssociateBlockingPage(
      web_contents, handle->GetNavigationId(), std::move(blocked_page));

  CancelDeferredNavigation(content::NavigationThrottle::ThrottleCheckResult(
      content::NavigationThrottle::CANCEL, net::ERR_BLOCKED_BY_CLIENT,
      blocked_page_content));
}

const char* DomainBlockedNavigationThrottle::GetNameForLogging() {
  return "DomainBlockedNavigationThrottle";
}

}  // namespace brave_shields
