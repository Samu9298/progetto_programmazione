#include <gtest/gtest.h>
#include <memory>
#include "../Header files/BankAccount.h"
#include "../Header files/AccountFactory.h"
#include "../Header files/OperationFactory.h"

TEST(BankAccountTest, insertOperations) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Bank, "Test bank account", "1500.00");

    for (const auto& iterator : OPERATION_LABELS) {
        std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation(iterator.first, "10.00",
                                                                                                       wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                       wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

        newAccount->addOperation(std::move(newOperation));
    }

    ASSERT_EQ(newAccount->getAmount(), 1450.00);
}

TEST(BankAccountTest, removeOperations) {
    std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(Bank, "Test bank account", "1500.00");

    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank deposit", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));

    newAccount->removeOperation(std::move(newOperation));

    ASSERT_EQ(newAccount->getAmount(), 1500.00);
}

