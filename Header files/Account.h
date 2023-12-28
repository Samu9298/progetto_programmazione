#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNT_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNT_H

#include <list>
#include "BankOperation.h"

class Account {
public:
    explicit Account(const wxString &label, const wxString &amount);

    void addOperation(BankOperation *operation);
    void removeOperation(BankOperation *operation);

    const std::list<BankOperation *> &getOperationList() const;
    const wxString &getLabel() const;

    const wxString &getAmount() const;

private:
    wxString label;
    wxString amount;
    std::list<BankOperation *> operationList;
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNT_H
