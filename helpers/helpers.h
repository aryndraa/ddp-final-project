#pragma once
#include <string>

using namespace std;

void waitEnter();
string formatRupiah(long long amount);
void displayHeader(const string& title, int width = 50);
string inputPassword();
string getCurrentTimestamp();