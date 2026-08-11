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

Account* Bank::getAccount(const std::string& accountNum) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNum) {
            return &acc;
        }
    }

    return nullptr;
}

bool Bank::isCurrentAccountNullPtr() {
    return currentAccount == nullptr;
}

long long Bank::getBalance() const {
    if (currentAccount == nullptr)
        return -1;

    return currentAccount->getBalance();
}

bool Bank::withdraw(long long amount) {
    if (currentAccount == nullptr)
        return false;

    return currentAccount->withdraw(amount);
}

bool Bank::deposit(long long amount) {
    if (currentAccount == nullptr)
        return false;

    return currentAccount->deposit(amount);
}
