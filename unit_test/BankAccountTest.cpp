#include <gtest/gtest.h>
#include <memory>
#include "../Header files/BankAccount.h"
#include "../Header files/AccountFactory.h"
#include "../Header files/OperationFactory.h"

TEST(BankAccountTest, insertOperations) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Bank, "Test bank account", "1500.00", "100.00");

    for (const auto& iterator : OPERATION_LABELS) {
        std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation(iterator.first, "10.00",
                                                                                                       wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                       wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

        newAccount->addOperation(std::move(newOperation));
    }

    ASSERT_EQ(newAccount->getAmount(), 1460.00);
}

TEST(BankAccountTest, removeIncomeOperations) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Bank, "Test bank account", "1500.00", "100.00");

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank deposit", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->removeOperation(std::move(newOperation));

    ASSERT_EQ(newAccount->getAmount(), 1500.00);
}

TEST(BankAccountTest, removeNotIncomeOperations) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Bank, "Test bank account", "1500.00", "100.00");

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank withdraw", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->removeOperation(std::move(newOperation));

    ASSERT_EQ(newAccount->getAmount(), 1500.00);
}

TEST(BankAccountTest, modifyAmountIncomeOperation) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Bank, "Test bank account", "1500.00", "100.00");

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank deposit", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->addOperation(std::move(newOperation));
    newAccount->modifyOperation(0, "5.00", wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    ASSERT_EQ(newAccount->getOperationList()[0]->getAmount(), 5.00);
    ASSERT_EQ(newAccount->getAmount(), 1505.00);
}

TEST(BankAccountTest, modifyAmountNotIncomeOperation) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Bank, "Test bank account", "1500.00", "100.00");

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank withdraw", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->addOperation(std::move(newOperation));
    newAccount->modifyOperation(0, "5.00", wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    ASSERT_EQ(newAccount->getOperationList()[0]->getAmount(), 5.00);
    ASSERT_EQ(newAccount->getAmount(), 1495.00);
    ASSERT_EQ(newAccount->getOperationList()[0]->getDate(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newAccount->getOperationList()[0]->getTime(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
}

TEST(BankAccountTest, modifyDateOperation) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Bank, "Test bank account", "1500.00", "100.00");

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank withdraw", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->addOperation(std::move(newOperation));
    newAccount->modifyOperation(0, "15.00", wxDateTime(10, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    ASSERT_EQ(newAccount->getOperationList()[0]->getAmount(), 15.00);
    ASSERT_EQ(newAccount->getAmount(), 1485.00);
    ASSERT_EQ(newAccount->getOperationList()[0]->getDate(), wxDateTime(10, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newAccount->getOperationList()[0]->getTime(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
}

TEST(BankAccountTest, modifyTimeOperation) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Bank, "Test bank account", "1500.00", "100.00");

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank withdraw", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->addOperation(std::move(newOperation));
    newAccount->modifyOperation(0, "15.00", wxDateTime(10, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                wxDateTime(5, wxDateTime::Jan, 2024, 12, 10, 0, 0));

    ASSERT_EQ(newAccount->getOperationList()[0]->getAmount(), 15.00);
    ASSERT_EQ(newAccount->getAmount(), 1485.00);
    ASSERT_EQ(newAccount->getOperationList()[0]->getDate(), wxDateTime(10, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newAccount->getOperationList()[0]->getTime(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 10, 0, 0));
}