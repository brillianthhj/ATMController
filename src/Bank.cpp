#include "Bank.h"

Bank::Bank() {
    initializeBankSystem();
}

void Bank::initializeBankSystem() {
    Account customer1("123-456-7890", "1111", 10000);
    addAccount(customer1);

    Account customer2("645-234-8473", "2222", 20000);
    addAccount(customer2);

    Account customer3("333-333-3333", "3333", 30000);
    addAccount(customer3);
}

void Bank::addAccount(const Account& account) {
    accounts.push_back(account);
}

Account* Bank::getAccount(const std::string& accountNum) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNum) {
            return &acc;
        }
    }

    return nullptr;
}

long long Bank::getBalance() {
    return currentAccount->getBalance();
}

bool Bank::withdraw(long long amount) {
    return currentAccount->withdraw(amount);
}

void Bank::deposit(long long amount) {
    return currentAccount->deposit(amount);
}

bool Bank::verifyAccountAndPinNum(const std::string& accountNum, const std::string& pinNum) {
    currentAccount = getAccount(accountNum);
    // if not searched, create account
    if (currentAccount == nullptr) {
        Account newAccount(accountNum, pinNum, 0);
        addAccount(newAccount);
        currentAccount = &accounts.back();
    }

    // check whether accountNum and pinNum matches or not
    if (currentAccount->getPinNumber() != pinNum) {
        return false;
    }

    return true;
}