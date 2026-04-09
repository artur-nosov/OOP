#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <string>

struct Money {
    int grn;
    short int kop;
};

void normalize(Money& m);
int add(const Money& a, const Money& b, Money& result);
int multiply(Money& price, int quantity);
int roundMoney(const Money& m, Money& result);
void printMoney(const Money& m, const std::string& label = "");
int processFile(const std::string& filename);

#endif
