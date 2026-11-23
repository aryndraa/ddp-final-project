#pragma once
#include <string>
#include <vector>
#include "transaction/transaction.h"

using namespace std;

class Account {
private:
    string accountNumber; // 10 digit
    string ownerName;
    string pin;           // 6 digit
    double balance;
    bool isActive;
    vector<Transaction> transactions;

public:
    // Constructor
    Account(string accNum, string name, string p, double initBalance = 0.0, bool active = true)
        : accountNumber(accNum), ownerName(name), pin(p), balance(initBalance), isActive(active) {}

    // Getters
    string getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }
    string getPin() const { return pin; }
    double getBalance() const { return balance; }
    bool getIsActive() const { return isActive; }
    const vector<Transaction>& getTransactions() const { return transactions; }

    // Setters / Modifiers
    void setPin(const string& newPin) { pin = newPin; }
    void setIsActive(bool active) { isActive = active; }
    void setBalance(double newBalance) { balance = newBalance; }

    void addTransaction(const Transaction& tx) {
        transactions.push_back(tx);
    }
};

class AccountManager {
private:
    vector<Account> accounts;

public:
    void addAccount(const Account& acc) {
        accounts.push_back(acc);
    }

    Account* findAccount(const string& accNum) {
        for (auto& acc : accounts) {
            if (acc.getAccountNumber() == accNum) {
                return &acc;
            }
        }
        return nullptr;
    }

    vector<Account>& getAllAccounts() {
        return accounts;
    }
};
