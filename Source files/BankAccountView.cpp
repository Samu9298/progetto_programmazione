#include "../Header files/BankAccountView.h"

BankAccountView::BankAccountView(wxFrame *parent, const wxString& title, const wxString& accountTarget, const wxPoint& pos,
                                 const wxSize& size): AccountListView(parent, title, accountTarget, pos, size) {
    auto *menuBar = new wxMenuBar();
    auto *operationMenu = new wxMenu();
    auto *addItem = new wxMenuItem(operationMenu, wxID_NEW);
    auto *removeItem = new wxMenuItem(operationMenu, wxID_DELETE);
    operationMenu->Append(addItem);
    operationMenu->Append(removeItem);
    Bind(wxEVT_MENU, &BankAccountView::onNewClicked, this, addItem->GetId());
    Bind(wxEVT_MENU, &BankAccountView::onDeleteClicked, this, removeItem->GetId());

    menuBar->Append(operationMenu, OPERATION_MENU);

    SetMenuBar(menuBar);

    statusBar = CreateStatusBar(BANK_ACCOUNT_VIEW_STATUS_BAR_SIZE);
    statusBar->SetStatusText(ACCOUNT_VIEW_AMOUNT);
    statusBar->SetStatusText(wxString::Format(wxT("%.2f"),AccountCollection::getInstance()->getAccountList().at(accountTarget)->getAmount()), 1);
 }

BankAccountView::~BankAccountView() {
    AccountCollection::getInstance()->removeModelObserver(this);
}

void BankAccountView::update() {
    createListView(accountTarget);
    statusBar->SetStatusText(wxString::Format(wxT("%.2f"),AccountCollection::getInstance()->getAccountList().at(accountTarget)->getAmount()), 1);
}

void BankAccountView::onNewClicked(wxCommandEvent &event) {
    OperationDialog *operationDialog = new OperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                           wxDefaultPosition, OPERATION_DIALOG_SIZE, accountTarget);
    operationDialog->ShowModal();
    operationDialog->Destroy();
}

void BankAccountView::onDeleteClicked(wxCommandEvent &event) {
    DeleteOperationDialog *deleteOperationDialog = new DeleteOperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                                             wxDefaultPosition, DELETE_OPERATION_DIALOG_SIZE,
                                                                             accountTarget);
    deleteOperationDialog->ShowModal();
    deleteOperationDialog->Destroy();
}
