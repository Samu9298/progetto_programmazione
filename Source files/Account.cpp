#include "../Header files/Account.h"

void Account::addOperation(BankOperation *operation) {
    this->operationList.push_back(operation);
}

void Account::removeOperation(BankOperation *operation) {
    this->operationList.remove(operation);
}

Account::Account(const wxString &label) {
    this->label = label;
    this->operationList = std::list<BankOperation*>();
}

const wxString &Account::getLabel() const {
    return label;
}
