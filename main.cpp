#include "config/common.h"
#include "helpers/helpers.h"
#include "admin/admin.h"
#include "account/account.h"
#include "transaction/transaction.h"
#include "user/user.h"

using namespace std;

int main() {
    // anjaya
    AccountManager accountManager;
    TransactionManager transactionManager;

    Account acc1("1234567890", "Budi Santoso", "123456", 5000000.0, true);
    acc1.addTransaction(Transaction("TRX001", "Setor Tunai", 5000000.0, "2026-11-01 09:30:00", "Setoran Awal", 5000000.0));
    accountManager.addAccount(acc1);

    Account acc2("0987654321", "Siti Aminah", "654321", 2500000.0, true);
    acc2.addTransaction(Transaction("TRX002", "Setor Tunai", 2500000.0, "2026-11-02 14:15:00", "Setoran Awal", 2500000.0));
    accountManager.addAccount(acc2);

    Account acc3("1122334455", "Joko Widodo", "111222", 1000000.0, false);
    accountManager.addAccount(acc3);

    bool adminSession = false;
    int adminLoginAttempts = 0;
    int option;

    while (true) {
        system("cls");

        displayHeader("Welcome to the Bank Nyahu");
        cout << "Please select option:" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. User Login" << endl;
        cout << "3. Exit" << endl;
        cout << "==================================================" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cout << "==================================================" << endl;

        if (option == 1) {
            adminSession = loginAdmin(adminLoginAttempts);
            if (adminSession) {
                adminDashboard(accountManager);
            }
        } else if (option == 2) {
            Account* loggedInAccount = nullptr;
            if (loginUser(accountManager, loggedInAccount)) {
                userDashboard(loggedInAccount, accountManager, transactionManager);
            }
        } else if (option == 3) {
            cout << "\nTerima kasih telah menggunakan Bank Nyahu." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silahkan masukkan nomor yang tersedia." << endl;
            waitEnter();
        }
    }

    return 0;
}
