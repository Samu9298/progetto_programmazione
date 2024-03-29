#include "../Header files/Account.h"

Account::Account(const wxString &label, const float &amount, AccountType type) : operationList() {
    this->label = label;
    this->amount = amount;
    this->type = type;
}

const wxString &Account::getLabel() const {
    return label;
}

const std::vector<std::unique_ptr<BankOperation>> &Account::getOperationList() const {
    return operationList;
}

const float &Account::getAmount() const {
    return amount;
}

AccountType Account::getType() const {
    return type;
}

Account::~Account() {

}

