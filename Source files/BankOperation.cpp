#include "../Header files/BankOperation.h"

BankOperation::BankOperation(const wxString& label, const wxString& amount, const wxString& date, const wxString& hour) {
    this->label = label;
    this->amount = amount;
    this->date = date;
    this->hour = hour;

}

BankOperation::~BankOperation() {

}

const wxString &BankOperation::getLabel() const {
    return label;
}

const wxString &BankOperation::getAmount() const {
    return amount;
}

const wxString &BankOperation::getDate() const {
    return date;
}

const wxString &BankOperation::getHour() const {
    return hour;
}

bool BankOperation::operator==(const BankOperation &rhs) const {
    return label == rhs.label &&
           amount == rhs.amount &&
           date == rhs.date &&
           hour == rhs.hour;
}


