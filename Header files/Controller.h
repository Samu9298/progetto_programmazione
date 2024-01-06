#ifndef PROGETTO_PROGRAMMAZIONE_CONTROLLER_H
#define PROGETTO_PROGRAMMAZIONE_CONTROLLER_H

#include <wx/wx.h>
#include <memory>
#include "AccountFactory.h"
#include "AccountCollection.h"
#include "OperationFactory.h"

class Controller {
public:
    Controller(Controller& obj) = delete;
    static std::shared_ptr<Controller> getInstance();

    virtual ~Controller();

    void createAccount(AccountType type, const wxString &label, const wxString &amount);
    void deleteAccount(const wxString &label);

    void createOperation(const wxString& accountTarget, const wxString& label, const wxString& amount, const wxDateTime& date,
                         const wxDateTime& time);
    void deleteOperation(const wxString &accountTarget, std::unique_ptr<BankOperation> operation);

private:
    static std::shared_ptr<Controller> instance;

    Controller() {};
};


#endif //PROGETTO_PROGRAMMAZIONE_CONTROLLER_H
