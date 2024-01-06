#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H

#include "BankAccount.h"
#include "Constants.h"
#include "SavingAccount.h"

class AccountFactory {
public:
    AccountFactory(AccountFactory& obj) = delete;
    static std::shared_ptr<AccountFactory> getInstance();

    virtual ~AccountFactory();

    std::unique_ptr<Account> createAccount(AccountType type, const wxString &label, const wxString &amount);

private:
    static std::shared_ptr<AccountFactory> instance;

    AccountFactory() {};
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H
