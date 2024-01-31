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
                                 const wxDateTime &date, const wxDateTime &time, bool fromFile) {
    std::unique_ptr<BankOperation> newOperation = std::move(OperationFactory::getInstance()->createOperation(label, amount, date, time));
    AccountCollection::getInstance()->createOperation(accountTarget, std::move(newOperation), fromFile);
}

void Controller::deleteOperation(const wxString &accountTarget, std::unique_ptr<BankOperation> operation) {
    AccountCollection::getInstance()->deleteOperation(accountTarget, std::move(operation));
}

void Controller::modifyOperation(const wxString &accountTarget, const long &operationIndex, const wxString &amount,
                                 const wxDateTime &date, const wxDateTime &time) {
    AccountCollection::getInstance()->modifyOperation(accountTarget, operationIndex, amount, date, time);
}

void Controller::writeToFile(const wxString &memorizedFileName) {
    wxString relativePath = wxFileName::GetCwd() + wxFileName::GetPathSeparator() + ".." + wxFileName::GetPathSeparator() + "Utilities" + wxFileName::GetPathSeparator();
    wxString filename = wxFileName(relativePath, memorizedFileName).GetFullPath();

    wxTextFile textFile;
    if (textFile.Open(filename)) {
        textFile.Clear();

        wxString accountTypeString;
        wxString accountBudget;
        for (const auto& accountIterator : AccountCollection::getInstance()->getAccountList()) {
            const auto& account = accountIterator.second;
            if (account->getType() == Bank) {
                accountTypeString = "Bank account";
                accountBudget = "0.00";
            } else if (account->getType() == Saving) {
                accountTypeString = "Saving account";
                accountBudget = wxString::Format("%.2f", dynamic_cast<SavingAccount*>(account.get())->getBudgetToReach());
            }
            textFile.AddLine("Account:" + account->getLabel() + ",Type:" + accountTypeString + ",Amount:"
                             + wxString::Format("%.2f", account->getAmount()) + ",Budget:" + accountBudget);

            for (const auto& operationIterator : account->getOperationList()) {
                textFile.AddLine("Operation target:" + accountIterator.first + ",Label:" + operationIterator->getLabel() +
                                 ",Amount:" + wxString::Format("%.2f", operationIterator->getAmount()) +
                                 ",Date:" + operationIterator->getDate().FormatDate() + ",Time:" + operationIterator->getTime().FormatTime());
            }
        }

        textFile.Write();
        textFile.Close();
    } else {
        wxMessageBox(OPENING_FILE_ERROR);
    }
}

void Controller::loadFromFile(const wxString &memorizedFileName) {
    wxString relativePath = wxFileName::GetCwd() + wxFileName::GetPathSeparator() + ".." + wxFileName::GetPathSeparator() + "Utilities" + wxFileName::GetPathSeparator();
    wxString filename = wxFileName(relativePath, memorizedFileName).GetFullPath();

    wxTextFile textFile;
    if (textFile.Open(filename)) {
        wxString currentAccount;
        wxString currentAmount;
        wxString currentAccountType;
        wxString currentBudget;
        wxString currentOperationTarget;
        wxString currentOperationLabel;
        wxString currentOperationAmount;
        wxString currentOperationDateString;
        wxString currentOperationTimeString;

        wxString line;
        for (line = textFile.GetFirstLine(); !textFile.Eof(); line = textFile.GetNextLine()) {
            if (line.StartsWith("Account:")) {
                wxStringTokenizer* accountTokenizer = new wxStringTokenizer(line, ",");
                currentAccount = accountTokenizer->GetNextToken().AfterFirst(':');
                currentAccountType = accountTokenizer->GetNextToken().AfterFirst(':');
                currentAmount = accountTokenizer->GetNextToken().AfterFirst(':');
                currentBudget = accountTokenizer->GetNextToken().AfterFirst(':');

                bool created = this->createAccount(ACCOUNT_TYPE.at(currentAccountType), currentAccount, currentAmount, currentBudget);

                if (!created) {
                    wxMessageBox(LOADING_ACCOUNT_ERROR);
                }
            } else if (line.StartsWith("Operation target:")) {
                wxStringTokenizer* operationTokenizer = new wxStringTokenizer(line, ",");
                currentOperationTarget = operationTokenizer->GetNextToken().AfterFirst(':');
                currentOperationLabel = operationTokenizer->GetNextToken().AfterFirst(':');
                currentOperationAmount = operationTokenizer->GetNextToken().AfterFirst(':');
                currentOperationDateString = operationTokenizer->GetNextToken().AfterFirst(':');
                currentOperationTimeString = operationTokenizer->GetNextToken().AfterFirst(':');

                wxDateTime currentOperationDate;
                currentOperationDate.ParseFormat(currentOperationDateString, "%m/%d/%Y");
                wxDateTime currentOperationTime;
                currentOperationTime.ParseFormat(currentOperationTimeString, "%H:%M:%S");

                this->createOperation(currentOperationTarget, currentOperationLabel, currentOperationAmount,
                                      currentOperationDate, currentOperationTime, true);
            }
        }

        textFile.Close();

        for (const auto& iterator : AccountCollection::getInstance()->getAccountList()) {
            const std::type_info& typeInfo = typeid(*(iterator.second));
            if (typeInfo == typeid(SavingAccount)) {
                dynamic_cast<SavingAccount*>(iterator.second.get())->updateDataFromFileLoading();
            }
        }
    } else {
        wxMessageBox(OPENING_FILE_ERROR);
    }
}