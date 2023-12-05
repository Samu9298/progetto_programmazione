#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H

#include <list>
#include <map>
#include "Model.h"
#include "BankOperation.h"
#include "Account.h"
#include "Constants.h"

class AccountCollection : public Model {
public:
    AccountCollection(AccountCollection &obj) = delete;
    static AccountCollection *getInstance();

    void notify() override;

    void registerModelObserver(View *view) override;
    void removeModelObserver(View *view) override;
    void addAccount(Account *account);
    void removeAccount(const wxString &label);

    const std::map<wxString, Account *> &getAccountList() const;

private:
    static AccountCollection *instance;
    std::list<View *> observerList;
    std::map<wxString, Account*> accountList;

    AccountCollection() {};
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H
