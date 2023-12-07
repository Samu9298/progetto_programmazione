#ifndef PROGETTO_PROGRAMMAZIONE_BANKOPERATION_H
#define PROGETTO_PROGRAMMAZIONE_BANKOPERATION_H

#include "wx/wx.h"

class BankOperation {
public:
    BankOperation(const wxString& label, const wxString& amount, const wxString& date, const wxString& hour);
    virtual ~BankOperation();

    const wxString &getLabel() const;

    const wxString &getAmount() const;

    const wxString &getDate() const;

    const wxString &getHour() const;

    bool operator==(const BankOperation &rhs) const;

private:
    wxString label;
    wxString amount;
    wxString date;
    wxString hour;
};


#endif //PROGETTO_PROGRAMMAZIONE_BANKOPERATION_H
