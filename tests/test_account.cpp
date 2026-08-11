#include <gtest/gtest.h>
#include "Account.h"

class AccountTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        acc1 = Account();
        acc2 = Account("", "", 100);
        acc3 = Account("", "", -100);
        acc4 = Account("", "", 30'000'000'000);
        acc5 = Account("", "", 1.2345);
    }

    Account acc1, acc2, acc3, acc4, acc5;
};

TEST_F(AccountTestFixture, depositCheck) {
    acc1.deposit(100);
    EXPECT_EQ(acc1.getBalance(), 100);
    acc1.deposit(-100);
    EXPECT_EQ(acc1.getBalance(), 100);

    acc2.deposit(100);
    EXPECT_EQ(acc2.getBalance(), 200);
    acc2.deposit(-100);
    EXPECT_EQ(acc2.getBalance(), 200);

    acc3.deposit(100);
    EXPECT_EQ(acc3.getBalance(), 0);
    acc3.deposit(-100);
    EXPECT_EQ(acc3.getBalance(), 0);

    acc4.deposit(100);
    EXPECT_EQ(acc4.getBalance(), 30'000'000'100);
    acc4.deposit(-100);
    EXPECT_EQ(acc4.getBalance(), 30'000'000'100);

    acc5.deposit(100);
    EXPECT_EQ(acc5.getBalance(), 101);
    acc5.deposit(-100);
    EXPECT_EQ(acc5.getBalance(), 101);
}

TEST_F(AccountTestFixture, withdrawCheck) {
    acc1.withdraw(100);
    EXPECT_EQ(acc1.getBalance(), 0);
    acc1.withdraw(-100);
    EXPECT_EQ(acc1.getBalance(), 0);

    acc2.withdraw(100);
    EXPECT_EQ(acc2.getBalance(), 0);
    acc2.withdraw(-100);
    EXPECT_EQ(acc2.getBalance(), 0);

    acc3.withdraw(100);
    EXPECT_EQ(acc3.getBalance(), -100);
    acc3.withdraw(-100);
    EXPECT_EQ(acc3.getBalance(), -100);

    acc4.withdraw(100);
    EXPECT_EQ(acc4.getBalance(), 29'999'999'900);
    acc4.withdraw(-100);
    EXPECT_EQ(acc4.getBalance(), 29'999'999'900);

    acc5.withdraw(100);
    EXPECT_EQ(acc5.getBalance(), 1);
    acc5.withdraw(-100);
    EXPECT_EQ(acc5.getBalance(), 1);

}