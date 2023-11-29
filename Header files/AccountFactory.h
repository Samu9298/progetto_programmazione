#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H

class AccountFactory {
public:
    AccountFactory(AccountFactory& obj) = delete;
    static AccountFactory *getInstance();

private:
    static AccountFactory *instance;

    AccountFactory() {};
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H
