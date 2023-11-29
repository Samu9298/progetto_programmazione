#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H

#include <list>
#include <map>
#include "Model.h"
#include "BankOperation.h"
#include "Account.h"

class AccountCollection : public Model {
public:
    AccountCollection();

    void notify() override;

    void registerModelObserver(View *view) override;
    void removeModelObserver(View *view) override;
    //void addAccount(Account *account);
    //void removeAccount(Account *account);
    const std::map<wxString, Account *> &getAccountList() const;

private:
    std::list<View *> observerList;
    std::map<wxString, Account*> accountList;
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H
