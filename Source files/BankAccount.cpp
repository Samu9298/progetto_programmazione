#include "../Header files/BankAccount.h"

BankAccount::BankAccount(const wxString &label, const float &amount, AccountType type) : Account(label, amount, type) {

}

void BankAccount::addOperation(std::unique_ptr<BankOperation> operation, bool fromFile) {
    if (!fromFile) {
        if (operation->getIsIncome()) {
            this->amount += operation->getAmount();
        } else {
            this->amount -= operation->getAmount();
        }
    }

    this->operationList.insert(operationList.begin(), std::move(operation));
}

void BankAccount::removeOperation(std::unique_ptr<BankOperation> operation) {
    auto iterator = operationList.begin();
    while (iterator != operationList.end()) {
        if (iterator->get()->operator==(*operation)) {
            iterator = operationList.erase(iterator);
            if (operation->getIsIncome()) {
                this->amount -= operation->getAmount();
            }
            else {
                this->amount += operation->getAmount();
            }
        } else {
            ++iterator;
        }
    }
}

void BankAccount::modifyOperation(const long &operationIndex, const wxString &operationAmount,
                              const wxDateTime date, const wxDateTime time) {

    double amountNumber;
    operationAmount.ToDouble(&amountNumber);
    if (operationAmount != wxEmptyString && (float)amountNumber != operationList[operationIndex]->getAmount()) {
        if (!operationList[operationIndex]->getIsIncome()) {
            amount = amount + operationList[operationIndex]->getAmount() - (float)amountNumber;
        } else {
            amount = amount - operationList[operationIndex]->getAmount() + (float)amountNumber;
        }
        operationList[operationIndex]->setAmount((float)amountNumber);
    }

    if (date.IsValid() && date != operationList[operationIndex]->getDate()) {
        operationList[operationIndex]->setDate(date);
    }

    if (date.IsValid() && date != operationList[operationIndex]->getTime()) {
        operationList[operationIndex]->setHour(time);
    }
}
