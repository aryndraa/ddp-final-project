#pragma once
#include "account/account.h"
#include "transaction/transaction.h"

bool loginUser(AccountManager& accountManager, Account*& loggedInAccount);
void userDashboard(Account* loggedInAccount, AccountManager& accountManager, TransactionManager& transactionManager);

void checkBalance(Account* loggedInAccount);
void viewUserTransactionHistory(Account* loggedInAccount);

void withdrawCash(Account* loggedInAccount, TransactionManager& transactionManager);
void depositCash(Account* loggedInAccount, TransactionManager& transactionManager);

void transferFunds(Account* loggedInAccount, AccountManager& accountManager, TransactionManager& transactionManager);
