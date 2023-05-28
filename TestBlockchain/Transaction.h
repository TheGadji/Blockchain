#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

struct Transaction {
    std::string sender;
    std::string recipient;
    double amount;

    Transaction(const std::string& s, const std::string& r, double a)
        : sender(s), recipient(r), amount(a) {}
};

#endif 
