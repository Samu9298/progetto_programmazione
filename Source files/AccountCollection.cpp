#include "../Header files/AccountCollection.h"

std::shared_ptr<AccountCollection> AccountCollection::instance = nullptr;

std::shared_ptr<AccountCollection> AccountCollection::getInstance() {
    if (instance == nullptr)
        instance = std::move(std::shared_ptr<AccountCollection>(new AccountCollection()));
    return instance;
}

void AccountCollection::notify() {
    for (auto &observerIterator : observerList)
        observerIterator->update();
}

void AccountCollection::registerModelObserver(View *view) {
    this->observerList.push_back(view);
}

void AccountCollection::removeModelObserver(View *view) {
    this->observerList.remove(view);
}

const std::map<wxString, std::unique_ptr<Account>> &AccountCollection::getAccountList() const {
    return accountList;
}

void AccountCollection::addAccount(std::unique_ptr<Account> account) {
    this->accountList.emplace(account->getLabel(), std::move(account));
}

void AccountCollection::removeAccount(const wxString& label) {
    auto iterator = accountList.begin();
    while (iterator != accountList.end()) {
        if ((*iterator).first == label) {
            accountList.erase(iterator);
        } else {
            ++iterator;
        }
    }
}

void AccountCollection::createOperation(const wxString &accountTarget, std::unique_ptr<BankOperation> operation) {
    accountList.at(accountTarget)->addOperation(std::move(operation));
    notify();
}

void AccountCollection::deleteOperation(const wxString &accountTarget, std::unique_ptr<BankOperation> operation) {
    accountList.at(accountTarget)->removeOperation(std::move(operation));
    notify();
}

void AccountCollection::modifyOperation(const wxString &accountTarget, const long &operationIndex, const wxString &amount, const wxDateTime &date, const wxDateTime &time) {
    accountList.at(accountTarget)->modifyOperation(operationIndex, amount, date, time);
    notify();
}


