#ifndef PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNT_H
#define PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNT_H

#include "Account.h"
#include "Constants.h"

class SavingAccount : public Account {
public:
    explicit SavingAccount(const wxString &label, const float &amount, const float& budgetToReach, AccountType type = Saving);

    void addOperation(std::unique_ptr<BankOperation> operation) override;
    void removeOperation(std::unique_ptr<BankOperation> operation) override;
    virtual void modifyOperation(const long &operationIndex, const wxString& amount, const wxDateTime& date, const wxDateTime& time) override;

    float getBudgetToReach() const;

private:
    float budgetToReach;
    int percToBudget;

    int evaluatePercToBudget();
};


#endif //PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNT_H
