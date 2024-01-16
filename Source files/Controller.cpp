#include "../Header files/Controller.h"

std::shared_ptr<Controller> Controller::instance = nullptr;

std::shared_ptr<Controller> Controller::getInstance() {
    if (instance == nullptr)
        instance = std::shared_ptr<Controller>(new Controller);
    return instance;
}

bool Controller::createAccount(AccountType type, const wxString &label, const wxString &amount, const wxString& budget) {
    bool created = false;
    bool found = false;
    for (const auto& iterator: AccountCollection::getInstance()->getAccountList()) {
        if (label == iterator.first) {
            found = true;
        }
    }

    if (!found) {
        std::unique_ptr<Account> newAccount = AccountFactory::getInstance()->createAccount(type, label, amount, budget);
        AccountCollection::getInstance()->addAccount(std::move(newAccount));
        created = true;
    }

    return created;
}

void Controller::deleteAccount(const wxString &label) {
    AccountCollection::getInstance()->removeAccount(label);
}

Controller::~Controller() {

}

void Controller::createOperation(const wxString &accountTarget, const wxString &label, const wxString &amount,
                                 const wxDateTime &date, const wxDateTime &time) {
    std::unique_ptr<BankOperation> newOperation = std::move(OperationFactory::getInstance()->createOperation(label, amount, date, time));
    AccountCollection::getInstance()->createOperation(accountTarget, std::move(newOperation));
}

void Controller::deleteOperation(const wxString &accountTarget, std::unique_ptr<BankOperation> operation) {
    AccountCollection::getInstance()->deleteOperation(accountTarget, std::move(operation));
}

void Controller::modifyOperation(const wxString &accountTarget, const long &operationIndex, const wxString &amount,
                                 const wxDateTime &date, const wxDateTime &time) {
    AccountCollection::getInstance()->modifyOperation(accountTarget, operationIndex, amount, date, time);
}


