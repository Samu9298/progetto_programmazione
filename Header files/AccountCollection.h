#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H

#include <wx/textfile.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/tokenzr.h>
#include <map>
#include <memory>
#include "Model.h"
#include "BankOperation.h"
#include "BankAccount.h"
#include "SavingAccount.h"
#include "Constants.h"

class AccountCollection : public Model {
public:
    AccountCollection(AccountCollection *obj) = delete;
    static std::shared_ptr<AccountCollection> getInstance();

    void notify() override;

    void registerModelObserver(View* view) override;
    void removeModelObserver(View* view) override;
    void addAccount(std::unique_ptr<Account> account);
    void removeAccount(const wxString& label);
    void createOperation(const wxString &accountTarget, std::unique_ptr<BankOperation> operation, bool fromFile);
    void deleteOperation(const wxString &accountTarget, std::unique_ptr<BankOperation> operation);
    void modifyOperation(const wxString &accountTarget, const long &operationIndex, const wxString& amount = wxEmptyString,
                         const wxDateTime& date = wxDateTime(), const wxDateTime& time = wxDateTime());

    const std::map<wxString, std::unique_ptr<Account>> &getAccountList() const;

private:
    static std::shared_ptr<AccountCollection> instance;
    std::list<View*> observerList;
    std::map<wxString, std::unique_ptr<Account>> accountList;

    AccountCollection() {};
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H
