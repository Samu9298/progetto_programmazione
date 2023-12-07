#include "../Header files/Account.h"

Account::Account(const wxString &label, const wxString &amount) {
    this->label = label;
    this->amount = amount;
    this->operationList = std::list<BankOperation*>();
}

void Account::addOperation(BankOperation *operation) {
    this->operationList.push_back(operation);
}

void Account::removeOperation(BankOperation *operation) {
    this->operationList.remove(operation);
}

const wxString &Account::getLabel() const {
    return label;
}

const std::list<BankOperation *> &Account::getOperationList() const {
    return operationList;
}
