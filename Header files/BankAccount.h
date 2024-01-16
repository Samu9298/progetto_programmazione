#ifndef PROGETTO_PROGRAMMAZIONE_BANKACCOUNT_H
#define PROGETTO_PROGRAMMAZIONE_BANKACCOUNT_H

#include "Account.h"

class BankAccount : public Account {
public:
    explicit BankAccount(const wxString &label, const float &amount, AccountType type = Bank);

    void addOperation(std::unique_ptr<BankOperation> operation) override;
    void removeOperation(std::unique_ptr<BankOperation> operation) override;
    void modifyOperation(const long &operationIndex, const wxString& amount = wxEmptyString,
                         const wxDateTime& date = wxDateTime(), const wxDateTime& time = wxDateTime()) override;
};


#endif //PROGETTO_PROGRAMMAZIONE_BANKACCOUNT_H
