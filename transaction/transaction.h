#pragma once
#include <string>
#include <vector>

using namespace std;

class Transaction {
private:
    string transactionId;
    string type;            // "Tarik Tunai", "Setor Tunai", "Transfer Keluar", "Transfer Masuk"
    double amount;
    string timestamp;
    string description;
    double balanceAfter;

public:
    // Constructor
    Transaction(string id, string t, double amt, string time, string desc, double balAfter)
        : transactionId(id), type(t), amount(amt), timestamp(time), description(desc), balanceAfter(balAfter) {}

    // Getters
    string getTransactionId() const { return transactionId; }
    string getType() const { return type; }
    double getAmount() const { return amount; }
    string getTimestamp() const { return timestamp; }
    string getDescription() const { return description; }
    double getBalanceAfter() const { return balanceAfter; }
};

// Objek Pengelola Transaksi (PengelolaTransaksi)
class TransactionManager {
private:
    int transactionCounter;

public:
    TransactionManager() : transactionCounter(1) {}

    Transaction createTransaction(const string& type, double amount, const string& timestamp, const string& description, double balanceAfter) {
        string id = "TRX" + to_string(transactionCounter++);
        return Transaction(id, type, amount, timestamp, description, balanceAfter);
    }
};
