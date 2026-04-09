#include "Money.h"
#include <fstream>

using namespace std;

void normalize(Money& m) {
    if (m.kop >= 100) {
        m.grn += m.kop / 100;
        m.kop = m.kop % 100;
    }
    if (m.kop < 0) {
        m.grn -= 1;
        m.kop += 100;
    }
}

int add(const Money& a, const Money& b, Money& result) {
    result.grn = a.grn + b.grn;
    result.kop = a.kop + b.kop;
    normalize(result);
    return 0;
}

int multiply(Money& price, int quantity) {
    price.grn *= quantity;
    price.kop *= quantity;
    normalize(price);
    return 0;
}

int roundMoney(const Money& m, Money& result) {
    int lastDigit = m.kop % 10;

    if (lastDigit < 5)
        result.kop = m.kop - lastDigit;
    else
        result.kop = m.kop - lastDigit + 10;

    result.grn = m.grn;
    normalize(result);
    return 0;
}

void printMoney(const Money& m, const string& label) {
    if (!label.empty())
        cout << label;
    cout << m.grn << " UAH ";
    if (m.kop < 10)
        cout << "0";
    cout << m.kop << " kop" << endl;
}

int processFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        return 1;
    }

    Money total = {0, 0};
    int lineNumber = 0;
    int grn, quantity;
    short int kop;

    cout << "--- Items ---" << endl;

    while (inputFile >> grn >> kop >> quantity) {
        lineNumber++;
        Money price = {grn, kop};
        Money subtotal = {grn, kop};
        multiply(subtotal, quantity);

        cout << "Item " << lineNumber << ": ";
        printMoney(price, "price = ");
        cout << "  quantity: " << quantity << endl;
        printMoney(subtotal, "  cost:     ");
        cout << endl;

        Money newTotal;
        add(total, subtotal, newTotal);
        total = newTotal;
    }

    inputFile.close();

    if (lineNumber == 0) {
        cerr << "File is empty or has invalid format!" << endl;
        return 1;
    }

    cout << "--- Result ---" << endl;
    printMoney(total, "Total: ");

    Money rounded;
    roundMoney(total, rounded);
    printMoney(rounded, "To pay (after rounding): ");

    return 0;
}
