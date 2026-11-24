#include "helpers.h"
#include "config/common.h"


using namespace std;

// Function to pause the program until the user presses Enter
void waitEnter() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();
}

// Function to display a header with a title and a line of equal signs
void displayHeader(const string& title, int width) {
    string line(width, '=');
    int leftSpacing = (width - static_cast<int>(title.length())) / 2;

    if (leftSpacing < 0) {
        leftSpacing = 0;
    }

    cout << line << endl;
    cout << string(leftSpacing, ' ') << title << endl;
    cout << line << endl;
}

// Function to input a password with masked characters
string inputPassword() {
    string password = "";
    char ch;

    while (true) {
        ch = _getch(); 

        if (ch == '\r' || ch == '\n') { 
            cout << endl;
            break;
        } else if (ch == '\b' || ch == 127) { 
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password.push_back(ch);
            cout << '*'; 
        }
    }

    return password;
}

string getCurrentTimestamp() {
    time_t now = time(nullptr);       
    tm* localTime = localtime(&now);

    stringstream ss;
    ss << put_time(localTime, "%Y-%m-%d %H:%M:%S"); 
    return ss.str();
}
// Function to format a long long integer as Indonesian Rupiah currency
string formatRupiah(long long amount) {
    bool isNegative = amount < 0;
    string numStr = to_string(isNegative ? -amount : amount);
    string result;

    int count = 0;
    for (int i = static_cast<int>(numStr.length()) - 1; i >= 0; --i) {
        result.push_back(numStr[i]);
        count++;
        if (count == 3 && i > 0) {
            result.push_back('.');
            count = 0;
        }
    }

    if (isNegative) {
        result.push_back('-');
    }

    // Reverse the result string
    for (size_t i = 0, j = result.size() - 1; i < j; ++i, --j) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }

    return "Rp" + result;
}
