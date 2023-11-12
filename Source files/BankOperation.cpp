#include "../Header files/BankOperation.h"

BankOperation::BankOperation(wxString label, float amount, wxString date, wxString hour) {
    this->label = label;
    this->amount = amount;
    this->date = date;
    this->hour = hour;

}

BankOperation::~BankOperation() {

}


