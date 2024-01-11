#ifndef PROGETTO_PROGRAMMAZIONE_BANKACCOUNT_H
#define PROGETTO_PROGRAMMAZIONE_BANKACCOUNT_H

#include "Account.h"

class BankAccount : public Account {
public:
    explicit BankAccount(const wxString &label, const float &amount, AccountType type = Bank);
    BankAccount(BankAccount& obg) = delete;

    void addOperation(std::unique_ptr<BankOperation> operation) override;
    void removeOperation(std::unique_ptr<BankOperation> operation) override;
};


#endif //PROGETTO_PROGRAMMAZIONE_BANKACCOUNT_H
