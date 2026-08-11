#include <string>

class Account {
public:
    Account() {}
    Account(const std::string& accountNum, const std::string& pinNum, long long balance)
        : accountNumber(accountNum), pinNumber(pinNum), balance(balance) {}

    std::string getAccountNumber() const;
    std::string getPinNumber() const;
    long long getBalance() const;

    void deposit(long long amount);
    bool withdraw(long long amount);

private:
    std::string pinNumber;
    std::string accountNumber;
    long long balance;
};