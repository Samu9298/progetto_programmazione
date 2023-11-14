#ifndef PROGETTO_PROGRAMMAZIONE_BANKOPERATION_H
#define PROGETTO_PROGRAMMAZIONE_BANKOPERATION_H

#include "wx/wx.h"

class BankOperation {
public:
    BankOperation(wxString label, float amount, wxString date, wxString hour);
    virtual ~BankOperation();

private:
    static wxString label;
    static float amount;
    static wxString date;
    static wxString hour;
};


#endif //PROGETTO_PROGRAMMAZIONE_BANKOPERATION_H
