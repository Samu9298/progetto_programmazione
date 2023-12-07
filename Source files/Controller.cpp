#include "../Header files/Controller.h"

Controller* Controller::instance = nullptr;

Controller *Controller::getInstance() {
    if (instance == nullptr)
        instance = new Controller();
    return instance;
}

void Controller::createAccount(const wxString &label, const wxString &amount) {
    Account *newAccount = AccountFactory::getInstance()->createAccount(label, amount);
    AccountCollection::getInstance()->addAccount(newAccount);
}

void Controller::deleteAccount(const wxString &label) {
    AccountCollection::getInstance()->removeAccount(label);
}

Controller::~Controller() {

}

void Controller::createOperation(const wxString &accountTarget, const wxString &label, const wxString &amount,
                                 const wxString &date, const wxString &hour) {
    BankOperation *newOperation = new BankOperation(label, amount, date, hour);
    AccountCollection::getInstance()->createOperation(accountTarget, newOperation);
}

void Controller::deleteOperation(const wxString &accountTarget, const wxString &label) {
    BankOperation* elementToDelete;
    for(auto iterator : AccountCollection::getInstance()->getAccountList().at(accountTarget)->getOperationList()) {
        if(iterator->getLabel() == label){
            elementToDelete = &(*iterator);
        }
    }
    AccountCollection::getInstance()->deleteOperation(accountTarget, elementToDelete);
}


