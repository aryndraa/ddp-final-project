#include "config/common.h"
#include "helpers/helpers.h"
#include "account/account.h"
#include "transaction/transaction.h"
#include "user.h"
#include <iostream>

using namespace std;

bool loginUser(AccountManager& accountManager, Account*& loggedInAccount) {
    string inputAccNum;
    Account* acc = nullptr;

    while (true) {
        system("cls");
        displayHeader("LOGIN USER");

        cout << "Masukkan Nomor Rekening (10 digit): ";
        cin >> inputAccNum;

        acc = accountManager.findAccount(inputAccNum);

        if (acc == nullptr) {
            cout << "\nNomor rekening tidak terdaftar." << endl;
            waitEnter();
        } else {
            break;
        }
    }

    if (!acc->getIsActive()) {
        cout << "\nRekening Anda sedang dinonaktifkan, silahkan hubungi Admin." << endl;
        waitEnter();
        return false;
    }

    int userLoginAttempts = 0;

    while (userLoginAttempts < MAX_LOGIN_ATTEMPTS) {
        system("cls");
        displayHeader("LOGIN USER");
        cout << "Nomor Rekening: " << acc->getAccountNumber() << endl;
        cout << "Pemilik       : " << acc->getOwnerName() << endl;

        cout << "Masukkan PIN (6 digit): ";
        string inputPin = inputPassword();

        if (inputPin == acc->getPin()) {
            userLoginAttempts = 0;
            loggedInAccount = acc;

            cout << "\nLogin berhasil! Selamat datang, " << acc->getOwnerName() << "." << endl;
            waitEnter();
            return true;
        } else {
            cout << "\nPIN salah, silahkan coba lagi." << endl;
            userLoginAttempts++;
            waitEnter();
        }
    }

    system("cls");
    displayHeader("LOGIN USER");
    cout << "\nRekening Anda telah diblokir karena melebihi batas percobaan login." << endl;
    acc->setIsActive(false);
    waitEnter();

    return false;
}

void checkBalance(Account* loggedInAccount) {
    // TODO [Rayxel]: Implementasi cek saldo
}

void viewUserTransactionHistory(Account* loggedInAccount) {
    // TODO [Rayxel]: Implementasi melihat riwayat transaksi user
}

void withdrawCash(Account* loggedInAccount, TransactionManager& transactionManager) {
    // TODO [Nanda]: Implementasi tarik tunai
}

void depositCash(Account* loggedInAccount, TransactionManager& transactionManager) {
    // TODO [Nanda]: Implementasi setor tunai
}

void transferFunds(Account* loggedInAccount, AccountManager& accountManager, TransactionManager& transactionManager) {
    // TODO [Andika]: Implementasi transfer antar rekening
}

void userDashboard(Account* loggedInAccount, AccountManager& accountManager, TransactionManager& transactionManager) {
    if (loggedInAccount == nullptr) return;

    int option;

    while (true) {
        system("cls");
        displayHeader("MENU UTAMA USER");
        cout << "Pemilik Rekening : " << loggedInAccount->getOwnerName() << endl;
        cout << "Nomor Rekening   : " << loggedInAccount->getAccountNumber() << endl;
        cout << "Waktu            : " << getCurrentTimestamp() << endl;
        displayHeader("PILIHAN TRANSAKSI");
        cout << "1. Tarik Tunai" << endl;
        cout << "2. Setor Tunai" << endl;
        cout << "3. Cek Saldo" << endl;
        cout << "4. Transfer Rekening Lain" << endl;
        cout << "5. Riwayat Transaksi" << endl;
        cout << "6. Logout" << endl;
        cout << "==================================================" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cout << "==================================================" << endl;

        switch (option) {
            case 1:
                withdrawCash(loggedInAccount, transactionManager);
                break;
            case 2:
                depositCash(loggedInAccount, transactionManager);
                break;
            case 3:
                checkBalance(loggedInAccount);
                break;
            case 4:
                transferFunds(loggedInAccount, accountManager, transactionManager);
                break;
            case 5:
                viewUserTransactionHistory(loggedInAccount);
                break;
            case 6:
                cout << "\nLogout berhasil. Terima kasih telah menggunakan ATM Bank Nyahu." << endl;
                waitEnter();
                return;
            default:
                cout << "\nOpsi tidak valid. Silahkan coba lagi." << endl;
                waitEnter();
                break;
        }
    }
}
