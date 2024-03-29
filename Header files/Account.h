#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNT_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNT_H

#include <wx/wx.h>
#include <list>
#include <memory>
#include <algorithm>
#include <vector>
#include "BankOperation.h"
#include "Account.h"
#include "Constants.h"

class Account {

public:
    explicit Account(const wxString &label, const float &amount, AccountType type);

    virtual ~Account();

    virtual void addOperation(std::unique_ptr<BankOperation> operation, bool fromFile) = 0;
    virtual void removeOperation(std::unique_ptr<BankOperation> operation) = 0;
    virtual void modifyOperation(const long &operationIndex, const wxString& amount, const wxDateTime date, const wxDateTime time) = 0;

    const std::vector<std::unique_ptr<BankOperation>> &getOperationList() const;
    const wxString &getLabel() const;
    const float &getAmount() const;

    AccountType getType() const;

protected:
    AccountType type;
    wxString label;
    float amount;
    std::vector<std::unique_ptr<BankOperation>> operationList;
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNT_H
