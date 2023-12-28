#include "../Header files/Account.h"

Account::Account(const wxString &label, const wxString &amount) {
    this->label = label;
    this->amount = amount;
    this->operationList = std::list<BankOperation*>();
}

void Account::addOperation(BankOperation *operation) {
    this->operationList.push_back(operation);

    double amountNumber;
    double operationAmountNumber;
    if(amount.ToDouble(&amountNumber)) {
        if(operation->getAmount().ToDouble(&operationAmountNumber)) {
            float newAmount = (float)(amountNumber - operationAmountNumber);
            amount.Clear();
            amount = wxString::Format(wxT("%.2f"), newAmount);
        }
    }
}

void Account::removeOperation(BankOperation *operation) {
    this->operationList.remove(operation);

    double amountNumber;
    double operationAmountNumber;
    if(amount.ToDouble(&amountNumber)) {
        if(operation->getAmount().ToDouble(&operationAmountNumber)) {
            float newAmount = (float)(amountNumber + operationAmountNumber);
            amount.Clear();
            amount = wxString::Format(wxT("%.2f"), newAmount);
        }
    }
}

const wxString &Account::getLabel() const {
    return label;
}

const std::list<BankOperation *> &Account::getOperationList() const {
    return operationList;
}

const wxString &Account::getAmount() const {
    return amount;
}
