#include "../Header files/SavingAccount.h"

SavingAccount::SavingAccount(const wxString &label, const float &amount, const float& budgetToReach, AccountType type) : Account(label, amount, type) {
    this->budgetToReach = budgetToReach;
    this->percToBudget = evaluatePercToBudget();

    for (const auto& iterator: OPERATION_LABELS) {
        if (iterator.first != "Bank deposit" && iterator.first != "Salary" && iterator.first != "Saved") {
            this->labelsTotal.insert({iterator.first, 0.00});
        }
    }
}

void SavingAccount::addOperation(std::unique_ptr<BankOperation> operation, bool fromFile) {
    if (!fromFile) {
        if (operation->getIsIncome()) {
            this->amount += operation->getAmount();
        } else {
            this->amount -= operation->getAmount();
            labelsTotal.at(operation->getLabel()) += operation->getAmount();
        }
    }

    this->operationList.push_back(std::move(operation));

    percToBudget = evaluatePercToBudget();
}

void SavingAccount::removeOperation(std::unique_ptr<BankOperation> operation) {
    auto iterator = operationList.begin();
    while (iterator != operationList.end()) {
        if (iterator->get()->operator==(*(operation))) {
            iterator = operationList.erase(iterator);
            if (operation->getIsIncome()) {
                this->amount -= operation->getAmount();
            }
            else {
                this->amount += operation->getAmount();
                labelsTotal.at(operation->getLabel()) -= operation->getAmount();
            }
        } else {
            ++iterator;
        }
    }

    percToBudget = evaluatePercToBudget();
}

int SavingAccount::evaluatePercToBudget() {
    int newPerc;
    if (amount <= budgetToReach) {
        if (amount > 0) {
            newPerc = static_cast<int>((amount / budgetToReach) * 100);
        } else {
            newPerc = 0;
        }

    } else {
        newPerc = 100;
    }
    return newPerc;
}

float SavingAccount::getBudgetToReach() const {
    return budgetToReach;
}

void SavingAccount::modifyOperation(const long &operationIndex, const wxString &operationAmount, const wxDateTime date,
                                    const wxDateTime time) {
    double amountNumber;
    operationAmount.ToDouble(&amountNumber);
    if (operationAmount != wxEmptyString && (float)amountNumber != operationList[operationIndex]->getAmount()) {
        if (!operationList[operationIndex]->getIsIncome()) {
            amount = amount + operationList[operationIndex]->getAmount() - (float)amountNumber;
            labelsTotal.at(operationList[operationIndex]->getLabel()) = labelsTotal.at(operationList[operationIndex]->getLabel()) - operationList[operationIndex]->getAmount() + (float)amountNumber;
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

int SavingAccount::getPercToBudget() const {
    return percToBudget;
}

const std::map<wxString, double> &SavingAccount::getLabelsTotal() const {
    return labelsTotal;
}

void SavingAccount::updateDataFromFileLoading() {
    for (const auto& iterator: this->operationList) {
        if (!iterator->getIsIncome()) {
            this->labelsTotal.at(iterator->getLabel()) += iterator->getAmount();
        }
    }
}


