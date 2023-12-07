#include "../Header files/AccountView.h"

AccountView::AccountView(wxFrame *parent, const wxString& title, const wxString& accountTarget, const wxPoint& pos,
                         const wxSize& size): wxFrame(parent, wxID_ANY, title, pos, size) {
    this->accountTarget = accountTarget;
    AccountCollection::getInstance()->registerModelObserver(this);

    auto *menuBar = new wxMenuBar();
    auto *operationMenu = new wxMenu();
    auto *addItem = new wxMenuItem(operationMenu, wxID_NEW);
    auto *removeItem = new wxMenuItem(operationMenu, wxID_DELETE);
    operationMenu->Append(addItem);
    operationMenu->Append(removeItem);
    Bind(wxEVT_MENU, &AccountView::onNewClicked, this, addItem->GetId());
    Bind(wxEVT_MENU, &AccountView::onDeleteClicked, this, removeItem->GetId());

    menuBar->Append(operationMenu, OPERATION_MENU);

    auto *operationListPanel = new wxPanel(this);
    operationListView = new wxListView(operationListPanel);
    createListView(accountTarget);

    auto *operationListSizer = new wxBoxSizer(wxVERTICAL);
    operationListSizer->Add(operationListView, 1,wxALL | wxEXPAND, DIALOG_BORDER);

    operationListPanel->SetSizer(operationListSizer);
    SetMenuBar(menuBar);
}

AccountView::~AccountView() {
    AccountCollection::getInstance()->removeModelObserver(this);
}

void AccountView::update() {
    createListView(accountTarget);
}

void AccountView::onNewClicked(wxCommandEvent &event) {
    OperationDialog *operationDialog = new OperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                           wxDefaultPosition, OPERATION_DIALOG_SIZE, accountTarget);
    operationDialog->ShowModal();
    operationDialog->Destroy();
}

void AccountView::onDeleteClicked(wxCommandEvent &event) {
    DeleteOperationDialog *deleteOperationDialog = new DeleteOperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                                             wxDefaultPosition, DELETE_OPERATION_DIALOG_SIZE,
                                                                             accountTarget);
    deleteOperationDialog->ShowModal();
    deleteOperationDialog->Destroy();
}

void AccountView::createListView(const wxString& account) {
    operationListView->ClearAll();
    int numberOfColumns = std::end(VIEW_COLUMN) - std::begin(VIEW_COLUMN);
    int columnWidth = MAIN_SIZE.x / numberOfColumns;
    for(int length = 0; length < numberOfColumns; length++) {
        operationListView->AppendColumn(VIEW_COLUMN[length], wxLIST_FORMAT_CENTER, columnWidth);
    }

    populateListView(account);
}

void AccountView::populateListView(const wxString& account) {
    int index = 0;
    for (auto iterator : AccountCollection::getInstance()->getAccountList().at(account)->getOperationList()) {
        int column = 1;
        operationListView->InsertItem(index, iterator->getLabel());
        operationListView->SetItem(index, column, iterator->getAmount());
        operationListView->SetItem(index, ++column, iterator->getDate());
        operationListView->SetItem(index, ++column, iterator->getHour());
    }
}
