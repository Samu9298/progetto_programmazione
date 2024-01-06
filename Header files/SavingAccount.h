#ifndef PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNT_H
#define PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNT_H

#include "Account.h"
#include "Constants.h"

class SavingAccount : public Account {
public:
    explicit SavingAccount(const wxString &label, const float &amount, AccountType type = Bank);

    void addOperation(std::unique_ptr<BankOperation> operation) override;
    void removeOperation(std::unique_ptr<BankOperation> operation) override;
};


#endif //PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNT_H
