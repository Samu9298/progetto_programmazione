#ifndef PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNT_H
#define PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNT_H

#include <map>
#include "Account.h"

class SavingAccount : public Account {
public:
    explicit SavingAccount(const wxString &label, const float &amount, const float& budgetToReach, AccountType type = Saving);

    void addOperation(std::unique_ptr<BankOperation> operation, bool fromFile) override;
    void removeOperation(std::unique_ptr<BankOperation> operation) override;
    void modifyOperation(const long &operationIndex, const wxString& amount,
                         const wxDateTime date, const wxDateTime time) override;
    void updateDataFromFileLoading();

    float getBudgetToReach() const;
    int getPercToBudget() const;
    const std::map<wxString, double> &getLabelsTotal() const;

private:
    std::map<wxString, double> labelsTotal;
    float budgetToReach;
    int percToBudget;

    int evaluatePercToBudget();
};


#endif //PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNT_H
