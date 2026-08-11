#include "Account.h"
#include <string>
#include <vector>

class Bank {
public:
    Bank();

    void initializeBankSystem();

    void addAccount(const Account& account);
    Account* getAccount(const std::string& accountNum);

    long long getBalance() const;
    bool withdraw(long long amount);
    bool deposit(long long amount);

    bool verifyAccountAndPinNum(const std::string& accountNum, const std::string& pinNum);
    bool isCurrentAccountNullPtr();

private:
    std::vector<Account> accounts;
    Account* currentAccount = nullptr;
};


