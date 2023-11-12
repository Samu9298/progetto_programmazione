#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H


class AccountFactory {
public:
    AccountFactory() {};
    AccountFactory(AccountFactory& obj) = delete;
    static AccountFactory *getInstance();

private:
    static AccountFactory *instance;
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTFACTORY_H
