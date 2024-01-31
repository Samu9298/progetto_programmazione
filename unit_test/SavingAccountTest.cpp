#include <gtest/gtest.h>
#include <memory>
#include "../Header files/BankAccount.h"
#include "../Header files/AccountFactory.h"
#include "../Header files/OperationFactory.h"

TEST(SavingAccountTest, insertOperations) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Saving, "Test saving account", "1500.00", "5000.00");
    SavingAccount* account = dynamic_cast<SavingAccount*>(newAccount.get());

    for (const auto& iterator : OPERATION_LABELS) {
        std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation(iterator.first, "10.00",
                                                                                                       wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                       wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

        newAccount->addOperation(std::move(newOperation), false);
    }

    ASSERT_EQ(newAccount->getAmount(), 1460.00);
    for (const auto& iterator : account->getLabelsTotal()) {
        ASSERT_EQ(iterator.second, 10.00);
    }
    ASSERT_EQ(account->getBudgetToReach(), 5000.00);
}

TEST(SavingAccountTest, removeIncomeOperations) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Saving, "Test saving account", "1500.00", "5000.00");

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank deposit", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->removeOperation(std::move(newOperation));

    ASSERT_EQ(newAccount->getAmount(), 1500.00);
}

TEST(SavingAccountTest, removeNotIncomeOperations) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Saving, "Test saving account", "1500.00", "5000.00");
    SavingAccount* account = dynamic_cast<SavingAccount*>(newAccount.get());


    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank withdraw", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->removeOperation(std::move(newOperation));

    ASSERT_EQ(newAccount->getAmount(), 1500.00);
    ASSERT_EQ(account->getLabelsTotal().at("Bank withdraw"), 0.00);
}

TEST(SavingAccountTest, modifyAmountIncomeOperation) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Saving, "Test saving account", "1500.00", "5000.00");

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank deposit", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->addOperation(std::move(newOperation), false);
    newAccount->modifyOperation(0, "5.00", wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    ASSERT_EQ(newAccount->getOperationList()[0]->getAmount(), 5.00);
    ASSERT_EQ(newAccount->getAmount(), 1505.00);
    ASSERT_EQ(newAccount->getOperationList()[0]->getDate(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newAccount->getOperationList()[0]->getTime(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
}

TEST(SavingAccountTest, modifyAmountNotIncomeOperation) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Saving, "Test saving account", "1500.00", "5000.00");
    SavingAccount* account = dynamic_cast<SavingAccount*>(newAccount.get());

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank withdraw", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->addOperation(std::move(newOperation), false);
    newAccount->modifyOperation(0, "5.00", wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    ASSERT_EQ(newAccount->getOperationList()[0]->getAmount(), 5.00);
    ASSERT_EQ(newAccount->getAmount(), 1495.00);
    ASSERT_EQ(account->getLabelsTotal().at("Bank withdraw"), 5.00);
    ASSERT_EQ(newAccount->getOperationList()[0]->getDate(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newAccount->getOperationList()[0]->getTime(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
}

TEST(SavingAccountTest, modifyDateOperation) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Saving, "Test saving account", "1500.00", "5000.00");
    SavingAccount* account = dynamic_cast<SavingAccount*>(newAccount.get());

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank withdraw", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->addOperation(std::move(newOperation), false);
    newAccount->modifyOperation(0, "15.00", wxDateTime(10, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    ASSERT_EQ(newAccount->getOperationList()[0]->getAmount(), 15.00);
    ASSERT_EQ(newAccount->getAmount(), 1485.00);
    ASSERT_EQ(account->getLabelsTotal().at("Bank withdraw"), 15.00);
    ASSERT_EQ(newAccount->getOperationList()[0]->getDate(), wxDateTime(10, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newAccount->getOperationList()[0]->getTime(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
}

TEST(SavingAccountTest, modifyTimeOperation) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Saving, "Test saving account", "1500.00", "5000.00");
    SavingAccount* account = dynamic_cast<SavingAccount*>(newAccount.get());

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank withdraw", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->addOperation(std::move(newOperation), false);
    newAccount->modifyOperation(0, "15.00", wxDateTime(10, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                wxDateTime(5, wxDateTime::Jan, 2024, 12, 10, 0, 0));

    ASSERT_EQ(newAccount->getOperationList()[0]->getAmount(), 15.00);
    ASSERT_EQ(newAccount->getAmount(), 1485.00);
    ASSERT_EQ(account->getLabelsTotal().at("Bank withdraw"), 15.00);
    ASSERT_EQ(newAccount->getOperationList()[0]->getDate(), wxDateTime(10, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newAccount->getOperationList()[0]->getTime(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 10, 0, 0));
}



