#include "../Header files/BankAccount.h"

BankAccount::BankAccount(const wxString &label, const float &amount, AccountType type) : Account(label, amount, type) {

}

void BankAccount::addOperation(std::unique_ptr<BankOperation> operation) {
    if(operation->getIsIncome()) {
        this->amount += operation->getAmount();
    } else {
        this->amount -= operation->getAmount();
    }

    this->operationList.push_back(std::move(operation));
}

void BankAccount::removeOperation(std::unique_ptr<BankOperation> operation) {
    auto iterator = operationList.begin();
    while (iterator != operationList.end()) {
        if ((*iterator)->getLabel() == operation->getLabel() && (*iterator)->getAmount() == operation->getAmount() &&
                (*iterator)->getIsIncome() == operation->getIsIncome() && (*iterator)->getDate().FormatDate() == operation->getDate().FormatDate()
                && (*iterator)->getTime().FormatTime() == operation->getTime().FormatTime()) {
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
