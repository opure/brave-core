/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_IDENTITY_MANAGER_H_
#define BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_IDENTITY_MANAGER_H_


#include "components/signin/public/identity_manager/identity_manager.h"

// Purpose of this class is to redirect to empty implementation
// syncer::ProfileSyncService::identity_manager_
// These must be overridden and empty:
//    GetAccountsInCookieJar
//    AddObserver
//    RemoveObserver
//    GetPrimaryAccountMutator

//google_apis/gaia/google_service_auth_error.h
class GoogleServiceAuthError;

class BraveAccountFetcherService;

namespace signin {

struct AccountsInCookieJarInfo;
class PrimaryAccountMutator;

class BraveDiagnosticsProvider;


class BraveIdentityManager : public IdentityManager {
 public:
   // class Observer {
   //  public:
   //   Observer() = default;
   //   virtual ~Observer() = default;
   //
   //   Observer(const Observer&) = delete;
   //   Observer& operator=(const Observer&) = delete;
   //
   //   virtual void OnAccountsInCookieUpdated(
   //       const signin::AccountsInCookieJarInfo& accounts_in_cookie_jar_info,
   //       const GoogleServiceAuthError& error) {}
   //   virtual void OnAccountsCookieDeletedByUserAction() {}
   // };

   explicit BraveIdentityManager(/*IdentityManager::InitParameters&& parameters*/);
   ~BraveIdentityManager() override;
   // DISALLOW_COPY_AND_ASSIGN
   BraveIdentityManager(const BraveIdentityManager&) = delete;
   BraveIdentityManager& operator=(const BraveIdentityManager&) = delete;

  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  AccountsInCookieJarInfo GetAccountsInCookieJar() const;
  PrimaryAccountMutator* GetPrimaryAccountMutator();

 private:
  IdentityManager::InitParameters MakeInitParameters();
  // std::unique_ptr<BraveDiagnosticsProvider> brave_diagnostics_provider;
  // std::unique_ptr<BraveAccountFetcherService> brave_account_fetcher_service;
};

}  // namespace signin

#endif  // BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_IDENTITY_MANAGER_H_