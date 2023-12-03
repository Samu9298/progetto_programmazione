#include "../Header files/AccountCollection.h"

/*
AccountCollection::AccountCollection() {
    wxString stringTest1 = "Prova1";
    Account *test1 = new Account(stringTest1);
    wxString stringTest2 = "Prova2";
    Account *test2 = new Account(stringTest2);

    accountList.insert({stringTest1, test1});
    accountList.insert({stringTest2, test2});
}
*/

AccountCollection* AccountCollection::instance = nullptr;

AccountCollection *AccountCollection::getInstance() {
    if (instance == nullptr)
        instance = new AccountCollection();
    return instance;
}

void AccountCollection::notify() {
    for (auto observerIterator : observerList)
        observerIterator->update();
}

void AccountCollection::registerModelObserver(View *view) {
    this->observerList.push_back(view);
}

void AccountCollection::removeModelObserver(View *view) {
    this->observerList.remove(view);
}

const std::map<wxString, Account *> &AccountCollection::getAccountList() const {
    return accountList;
}

void AccountCollection::addAccount(Account *account) {
    this->accountList.insert({account->getLabel(), account});
}

void AccountCollection::removeAccount(const wxString &label) {
    this->accountList.erase(label);
}


