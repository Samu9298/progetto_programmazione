#include <gtest/gtest.h>
#include <memory>
#include <wx/wx.h>
#include "../Header files/OperationFactory.h"

TEST(OperationFactoryTest, incomeOperationCreation) {
    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank deposit", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newOperation->getLabel(), "Bank deposit");
    ASSERT_EQ(newOperation->getIsIncome(), true);
    ASSERT_EQ(newOperation->getAmount(), 15.00);
    ASSERT_EQ(newOperation->getDate(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newOperation->getTime(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
}

TEST(OperationFactoryTest, notIncomeOperationCreation) {
    std::unique_ptr<BankOperation> newOperation = OperationFactory::getInstance()->createOperation("Bank withdraw", "15.00",
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0),
                                                                                                   wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newOperation->getLabel(), "Bank withdraw");
    ASSERT_EQ(newOperation->getIsIncome(), false);
    ASSERT_EQ(newOperation->getAmount(), 15.00);
    ASSERT_EQ(newOperation->getDate(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
    ASSERT_EQ(newOperation->getTime(), wxDateTime(5, wxDateTime::Jan, 2024, 12, 0, 0, 0));
}

