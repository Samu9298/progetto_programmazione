#include <gtest/gtest.h>
#include <memory>
#include "../Header files/AccountFactory.h"

TEST(AccountFactoryTest, bankAccountCreation) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Bank, "Test bank account", "100.00", "100.00");

    ASSERT_EQ(typeid(*newAccount), typeid(BankAccount));
    ASSERT_EQ(newAccount->getType(), Bank);
    ASSERT_EQ(newAccount->getLabel(), "Test bank account");
    ASSERT_EQ(newAccount->getAmount(), 100.00);
}

/*
TEST(AccountFactoryTest, savingAccountCreation) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Saving, "Test saving account", "100.00");

    ASSERT_EQ(typeid(*newAccount), typeid(SavingAccount));
    ASSERT_EQ(newAccount->getType(), Saving);
    ASSERT_EQ(newAccount->getLabel(), "Test saving account");
    ASSERT_EQ(newAccount->getAmount(), 100.00);
}
 */