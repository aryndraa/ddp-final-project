#include "config/common.h"
#include "helpers/helpers.h"
#include "admin.h"
#include <iostream>

using namespace std;

bool loginAdmin(int& adminLoginAttempts) {
    string inputUser, inputPass;

    while (adminLoginAttempts < MAX_LOGIN_ATTEMPTS) {
        system("cls");
        displayHeader("ADMIN LOGIN");

        cout << "Username: ";
        cin >> inputUser;

        cout << "Password: ";
        inputPass = inputPassword();

        if (inputUser == ADMIN_ID && inputPass == ADMIN_PIN) {
            cout << "\nAdmin login successful!" << endl;
            adminLoginAttempts = 0;
            waitEnter();
            return true;
        }

        adminLoginAttempts++;
        system("cls"); 

        displayHeader("ADMIN LOGIN");
        cout << "\nInvalid credentials. Please try again." << endl;

        if (adminLoginAttempts < MAX_LOGIN_ATTEMPTS) {
            waitEnter();
        }
    }

    system("cls");
    displayHeader("ADMIN LOGIN");
    cout << "\nMaximum login attempts reached. Access denied." << endl;
    waitEnter();

    return false;
}

bool logoutAdmin() {
    char choice;
    cout << "Are you sure you want to logout? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        cout << "Logging out..." << endl;
        waitEnter();
        return true;
    } else {
        cout << "Logout canceled." << endl;
        waitEnter();
        return false;
    }
}

void viewAllAccounts(AccountManager& accountManager) {
    // TODO [Deva]: Implementasi melihat daftar rekening
}

void createAccount(AccountManager& accountManager) {
    // TODO [Deva]: Implementasi create rekening
}

void updateAccount(AccountManager& accountManager) {
    // TODO [Deva]: Implementasi update rekening (ganti PIN dan status)
}

void viewAccountTransactions(AccountManager& accountManager) {
    // TODO [Rayxel]: Implementasi melihat riwayat transaksi melalui admin
}

void adminDashboard(AccountManager& accountManager) {
    int option;

    while (true) {
        system("cls");
        displayHeader("ADMIN DASHBOARD");
        cout << "Waktu Akses: " << getCurrentTimestamp() << endl;
        displayHeader("Menu");
        cout << "1. View All Accounts" << endl;
        cout << "2. Add New Account" << endl;
        cout << "3. Update Account (PIN or Status)" << endl;
        cout << "4. View Account Transaction History" << endl;
        cout << "5. Logout" << endl;
        cout << "==================================================" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cout << "==================================================" << endl;

        switch (option) {
            case 1:
                viewAllAccounts(accountManager);
                break;
            case 2:
                createAccount(accountManager);
                break;
            case 3:
                updateAccount(accountManager);
                break;
            case 4:
                viewAccountTransactions(accountManager);
                break;
            case 5:
                if (logoutAdmin()) {
                    return;
                }
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                waitEnter();
                break;
        }
    }
}
