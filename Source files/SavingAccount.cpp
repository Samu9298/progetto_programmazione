#include "../Header files/SavingAccount.h"

SavingAccount::SavingAccount(const wxString &label, const float &amount, AccountType type) : Account(label, amount, type) {

}

void SavingAccount::addOperation(std::unique_ptr<BankOperation> operation) {
    if(operation->getIsIncome()) {
        this->amount += operation->getAmount();
    } else {
        this->amount -= operation->getAmount();
    }

    this->operationList.push_back(std::move(operation));
}

void SavingAccount::removeOperation(std::unique_ptr<BankOperation> operation) {
    auto iterator = operationList.begin();
    while (iterator != operationList.end()) {
        if ((*iterator)->getAmount() == operation->getAmount()) {
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
