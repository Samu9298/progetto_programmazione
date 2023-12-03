#include "../Header files/AccountFactory.h"

AccountFactory* AccountFactory::instance = nullptr;

AccountFactory *AccountFactory::getInstance() {
    if (instance == nullptr)
        instance = new AccountFactory();
    return instance;
}

Account *AccountFactory::createAccount(const wxString &label) {
    Account *newAccount = new Account(label);
    return newAccount;
}

AccountFactory::~AccountFactory() {

}
