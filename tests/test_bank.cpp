#include <gtest/gtest.h>
#include "Bank.h"

class BankTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
    }

    Bank bank;
    std::string accNum = "0000-0000-0000";
    std::string pinNum = "23456";

    std::string accNum2 = "123-456-7890";
    std::string pinNum2 = "1111";
    std::string pinNum2_1 = "1112";
};

TEST_F(BankTestFixture, IsAccountPtrNullPtr) {
    ASSERT_EQ(bank.isCurrentAccountNullPtr(), true);
    ASSERT_EQ(bank.getBalance(), -1);
    ASSERT_EQ(bank.withdraw(100), false);
    ASSERT_EQ(bank.deposit(100), false);

    bank.verifyAccountAndPinNum(accNum, pinNum);
    ASSERT_EQ(bank.isCurrentAccountNullPtr(), false);
    ASSERT_NE(bank.getBalance(), -1);
    ASSERT_EQ(bank.withdraw(100), false);
    ASSERT_EQ(bank.deposit(100), true);

    bank.verifyAccountAndPinNum(accNum2, pinNum2);
    ASSERT_EQ(bank.isCurrentAccountNullPtr(), false);
    ASSERT_NE(bank.getBalance(), -1);
    ASSERT_EQ(bank.withdraw(100), true);
    ASSERT_EQ(bank.deposit(100), true);
}

TEST_F(BankTestFixture, getAccountCheck) {
    ASSERT_EQ(bank.getAccount(accNum), nullptr);

    ASSERT_NE(bank.getAccount(accNum2), nullptr);
}

TEST_F(BankTestFixture, verifyAccountAndPinNumCheck) {
    EXPECT_EQ(bank.verifyAccountAndPinNum(accNum, pinNum), true);
    EXPECT_EQ(bank.verifyAccountAndPinNum(accNum2, pinNum2), true);
    EXPECT_EQ(bank.verifyAccountAndPinNum(accNum2, pinNum2_1), false);
}