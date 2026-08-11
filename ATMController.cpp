#include <iostream>
#include <limits>
#include <string>
#include "Bank.h"


int main() {
    // Initialize Bank class
    Bank bank;

    std::cout << "Hello, Welcome to the Bear Bank ATM :)" << std::endl;
    std::cout << "Please insert your card.\n" << std::endl;

    while (true) {
        std::string accountNum;
        std::cout << "Please enter your account number: ";
        std::cin >> accountNum;

        std::string pinNum;
        std::cout << "Please enter your PIN: ";
        std::cin >> pinNum;

        if (bank.verifyAccountAndPinNum(accountNum, pinNum)) {
            break;
        } else {
            std::cout << "\nWrong pin number! Please try again!\n" << std::endl;
        }
    }

    while (true) {
        std::cout << "\nPlease select an option:\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "==> Your current balance is: $" << bank.getBalance() << std::endl;

        } else if (choice == 2) {
            long long amount;
            std::cout << "Enter the amount to deposit: ";
            if (std::cin >> amount) {
                bank.deposit(amount);
                std::cout << "==> Your current balance is: $" << bank.getBalance() << std::endl;
            } else {
                std::cout << "Inavalid amount. Please try again!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

        } else if (choice == 3) {
            long long amount;
            std::cout << "Enter the amount to withdraw: ";
            if (std::cin >> amount) {
                if (!bank.withdraw(amount)) {
                    std::cout << "Insufficient funds." << std::endl;
                }
                std::cout << "==> Your current balance is: $" << bank.getBalance() << std::endl;
            } else {
                std::cout << "Inavalid amount. Please try again!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

        } else if (choice == 4) {
            std::cout << "Thank you for using Bear Bank ATM. Goodbye!" << std::endl;
            std::cout << "\n";
            break;

        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
            std::cout << "\n";
        }
    }

    return 0;
}