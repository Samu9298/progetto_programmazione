#include "../Header files/BankOperation.h"

BankOperation::BankOperation(const wxString& label, const bool& isIncome, const float& amount, const wxDateTime& date, const wxDateTime& hour) {
    this->label = label;
    this->isIncome = isIncome;
    this->amount = amount;
    this->date = date;
    this->hour = hour;
}

BankOperation::~BankOperation() {
}

const wxString &BankOperation::getLabel() const {
    return label;
}

float BankOperation::getAmount() const {
    return amount;
}

const wxDateTime &BankOperation::getDate() const {
    return date;
}

const wxDateTime &BankOperation::getTime() const {
    return hour;
}

bool BankOperation::getIsIncome() const {
    return isIncome;
}

void BankOperation::setLabel(const wxString &newLabel) {
    BankOperation::label = newLabel;
}

void BankOperation::setAmount(float newAmount) {
    BankOperation::amount = newAmount;
}

void BankOperation::setDate(const wxDateTime &newDate) {
    BankOperation::date = newDate;
}

void BankOperation::setHour(const wxDateTime &newHour) {
    BankOperation::hour = newHour;
}

void BankOperation::setIsIncome(bool newIsIncome) {
    BankOperation::isIncome = newIsIncome;
}

bool BankOperation::operator==(const BankOperation &rhs) const {
    bool isEqual = false;
    if (this->label == rhs.getLabel() && this->amount == rhs.getAmount() && this->date.FormatDate() == rhs.getDate().FormatDate()
        && this->hour.FormatTime() == rhs.getTime().FormatTime()) {
        isEqual = true;
    }

    return isEqual;
}


