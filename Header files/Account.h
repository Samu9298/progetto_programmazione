#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNT_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNT_H

#include <list>
#include "BankOperation.h"

class Account {
public:
    explicit Account(const wxString &label);

    void addOperation(BankOperation *operation);
    void removeOperation(BankOperation *operation);
private:
    wxString label;
    std::list<BankOperation *> operationList;
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNT_H
