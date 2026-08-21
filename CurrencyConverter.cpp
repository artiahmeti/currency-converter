#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std;

namespace {

using Rates = map<string, double>;

const Rates kUsdRates{
    {"USD", 1.0000}, {"EUR", 0.9200}, {"GBP", 0.7900}, {"JPY", 150.2500},
    {"CHF", 0.8800}, {"CAD", 1.3600}, {"AUD", 1.5200}, {"CNY", 7.1800},
};

string normalizeCode(string code) {
    code.erase(remove_if(code.begin(), code.end(), [](unsigned char ch) {
        return isspace(ch);
    }), code.end());
    transform(code.begin(), code.end(), code.begin(), [](unsigned char ch) {
        return static_cast<char>(toupper(ch));
    });
    return code;
}

void printCurrencies() {
    cout << "\nSupported currencies (rates are illustrative, per USD):\n";
    for (const auto& [code, rate] : kUsdRates) {
        cout << "  " << left << setw(4) << code
             << right << fixed << setprecision(4) << rate << '\n';
    }
}

double readAmount() {
    double amount{};
    while (true) {
        cout << "Amount: ";
        if (cin >> amount && amount > 0.0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amount;
        }
        cout << "Please enter a positive numeric amount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string readCurrency(const string& prompt) {
    string code;
    while (true) {
        cout << prompt;
        getline(cin, code);
        code = normalizeCode(code);
        if (kUsdRates.find(code) != kUsdRates.end()) {
            return code;
        }
        cout << "Unsupported currency code. Enter one from the supported list.\n";
    }
}

void convert() {
    printCurrencies();
    const double amount = readAmount();
    const string from = readCurrency("From currency (e.g., USD): ");
    const string to = readCurrency("To currency (e.g., EUR): ");

    const double exchangeRate = kUsdRates.at(to) / kUsdRates.at(from);
    const double converted = amount * exchangeRate;

    cout << "\nConversion summary\n"
         << "------------------\n"
         << fixed << setprecision(2) << amount << ' ' << from
         << " = " << converted << ' ' << to << '\n'
         << setprecision(6) << "Exchange rate: 1 " << from << " = "
         << exchangeRate << ' ' << to << "\n\n";
}

}  

int main() {
    cout << "========================================\n"
         << "      PROFESSIONAL CURRENCY CONVERTER\n"
         << "========================================\n"
         << "Offline calculator — update kUsdRates with live data when needed.\n";

    while (true) {
        cout << "\n1. Convert currency\n2. View supported currencies\n3. Exit\nChoose an option: ";
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            convert();
        } else if (choice == "2") {
            printCurrencies();
        } else if (choice == "3") {
            cout << "Thank you for using Currency Converter.\n";
            return 0;
        } else {
            cout << "Invalid option. Please choose 1, 2, or 3.\n";
        }
    }
}
