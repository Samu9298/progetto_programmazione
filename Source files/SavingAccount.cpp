#include "../Header files/SavingAccount.h"

SavingAccount::SavingAccount(const wxString &label, const float &amount, const float& budgetToReach, AccountType type) : Account(label, amount, type) {
    this->budgetToReach = budgetToReach;
    this->percToBudget = evaluatePercToBudget();
}

void SavingAccount::addOperation(std::unique_ptr<BankOperation> operation) {
    if(operation->getIsIncome()) {
        this->amount += operation->getAmount();
    } else {
        this->amount -= operation->getAmount();
    }

    this->operationList.push_back(std::move(operation));

    percToBudget = evaluatePercToBudget();
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

    percToBudget = evaluatePercToBudget();
}

int SavingAccount::evaluatePercToBudget() {
    int newPerc = static_cast<int>((amount / budgetToReach) * 100);
    return newPerc;
}

float SavingAccount::getBudgetToReach() const {
    return budgetToReach;
}

void SavingAccount::modifyOperation(const long &operationIndex, const wxString &amount, const wxDateTime &date,
                                    const wxDateTime &time) {

}


