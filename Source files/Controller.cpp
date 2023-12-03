#include "../Header files/Controller.h"

Controller* Controller::instance = nullptr;

Controller *Controller::getInstance() {
    if (instance == nullptr)
        instance = new Controller();
    return instance;
}

void Controller::createAccount(const wxString &label) {
    Account *newAccount = AccountFactory::getInstance()->createAccount(label);
    AccountCollection::getInstance()->addAccount(newAccount);
}

void Controller::deleteAccount(const wxString &label) {
    AccountCollection::getInstance()->removeAccount(label);
}

Controller::~Controller() {

}

