#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H

#include "Account.h"

class AccountFactory {
public:
    AccountFactory(AccountFactory& obj) = delete;
    static AccountFactory *getInstance();

    virtual ~AccountFactory();

    Account* createAccount(const wxString &label);

private:
    static AccountFactory *instance;

    AccountFactory() {};
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H
