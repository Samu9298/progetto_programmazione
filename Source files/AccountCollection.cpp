#include "../Header files/AccountCollection.h"

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
    this->accountList.emplace(account->getLabel(), account);
}

void AccountCollection::removeAccount(const wxString &label) {
    this->accountList.erase(label);
}

void AccountCollection::createOperation(const wxString &accountTarget, BankOperation *operation) {
    accountList.at(accountTarget)->addOperation(operation);
    notify();
}

void AccountCollection::deleteOperation(const wxString &accountTarget, BankOperation *operation) {
    accountList.at(accountTarget)->removeOperation(operation);
    notify();
}


