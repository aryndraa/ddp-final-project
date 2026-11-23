#pragma once
#include <string>
#include "account/account.h"

using namespace std;

bool loginAdmin(int& adminLoginAttempts);
bool logoutAdmin(); 
void adminDashboard(AccountManager& accountManager);

void viewAllAccounts(AccountManager& accountManager);
void createAccount(AccountManager& accountManager);
void updateAccount(AccountManager& accountManager);

void viewAccountTransactions(AccountManager& accountManager);
