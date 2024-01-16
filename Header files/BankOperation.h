#ifndef PROGETTO_PROGRAMMAZIONE_BANKOPERATION_H
#define PROGETTO_PROGRAMMAZIONE_BANKOPERATION_H

#include <wx/wx.h>

class BankOperation {
public:
    BankOperation(const wxString& label, const bool& isIncome, const float& amount, const wxDateTime& date, const wxDateTime& hour);
    virtual ~BankOperation();

    const wxString &getLabel() const;
    float getAmount() const;
    bool getIsIncome() const;
    const wxDateTime &getDate() const;
    const wxDateTime &getTime() const;

    void setLabel(const wxString &newLabel);
    void setAmount(float newAmount);
    void setDate(const wxDateTime &newDate);
    void setHour(const wxDateTime &newHour);

    void setIsIncome(bool newIsIncome);

    bool operator==(const BankOperation &rhs) const;

private:
    wxString label;
    bool isIncome;
    float amount;
    wxDateTime date;
    wxDateTime hour;
};


#endif //PROGETTO_PROGRAMMAZIONE_BANKOPERATION_H
