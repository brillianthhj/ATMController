#include "Account.h"
#include <iostream>

std::string Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getPinNumber() const {
    return pinNumber;
}

long long Account::getBalance() const {
    return balance;
}

void Account::deposit(long long amount) {
    if (amount < 0) {
        std::cout << "Wrong amount of money: " << amount << std::endl;
        return;
    }

    balance += amount;
}

bool Account::withdraw(long long amount) {
    if (amount < 0) {
        std::cout << "Wrong amount of money: " << amount << std::endl;
        return false;
    }

    if (balance - amount < 0) {
        return false;
    }

    balance -= amount;

    return true;
}