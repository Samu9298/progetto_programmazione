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

    auto *mainPanel = new wxPanel(this);
    operationListView = new wxListView(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    createListView(accountTarget);

    wxBoxSizer *filtersSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelFilter = new wxStaticText(mainPanel, wxID_ANY, ACCOUNT_VIEW_FILTER_LABEL);
    wxArrayString choices;
    for (const auto &iterator: OPERATION_LABEL) {
        choices.push_back(iterator);
    }
    labelFilterCtrl = new wxChoice(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);

    wxStaticText *amountFilter = new wxStaticText(mainPanel, wxID_ANY, ACCOUNT_VIEW_FILTER_AMOUNT);
    amountFilterCtrl = new wxTextCtrl(mainPanel, wxID_ANY);

    filtersSizer->Add(labelFilter,0, wxLEFT | wxTOP | wxALIGN_LEFT | wxALIGN_TOP, ACCOUNT_VIEW_BORDER);
    filtersSizer->Add(labelFilterCtrl,0, wxLEFT | wxTOP | wxALIGN_LEFT | wxALIGN_TOP, ACCOUNT_VIEW_BORDER);
    filtersSizer->Add(amountFilter,0, wxLEFT | wxTOP | wxALIGN_LEFT | wxALIGN_TOP, ACCOUNT_VIEW_BORDER);
    filtersSizer->Add(amountFilterCtrl,0, wxLEFT | wxTOP | wxALIGN_LEFT | wxALIGN_TOP, ACCOUNT_VIEW_BORDER);

    wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton *searchButton = new wxButton(mainPanel, wxID_ANY, ACCOUNT_VIEW_SEARCH);
    Bind(wxEVT_BUTTON, &AccountView::onSearchClicked, this, searchButton->GetId());

    wxButton *removeFilterButton = new wxButton(mainPanel, wxID_ANY, ACCOUNT_VIEW_REMOVE_FILTERS);
    Bind(wxEVT_BUTTON, &AccountView::onRemoveFiltersClicked, this, removeFilterButton->GetId());

    buttonSizer->Add(searchButton,1, wxLEFT | wxTOP, ACCOUNT_VIEW_BORDER);
    buttonSizer->Add(removeFilterButton,1, wxLEFT | wxTOP, ACCOUNT_VIEW_BORDER);

    auto *mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(filtersSizer, 0,  wxALIGN_LEFT | wxALIGN_TOP);
    mainSizer->Add(buttonSizer, 0, wxALIGN_LEFT | wxALIGN_TOP);
    mainSizer->Add(operationListView, 1, wxLEFT | wxTOP | wxEXPAND, ACCOUNT_VIEW_BORDER);

    mainPanel->SetSizer(mainSizer);
    SetMenuBar(menuBar);

    statusBar = CreateStatusBar(ACCOUNT_VIEW_STATUS_BAR_SIZE);
    statusBar->SetStatusText(ACCOUNT_VIEW_AMOUNT);
    statusBar->SetStatusText(AccountCollection::getInstance()->getAccountList().at(accountTarget)->getAmount(), 1);

 }

AccountView::~AccountView() {
    AccountCollection::getInstance()->removeModelObserver(this);
}

void AccountView::update() {
    createListView(accountTarget);
    statusBar->SetStatusText(AccountCollection::getInstance()->getAccountList().at(accountTarget)->getAmount(), 1);
}

void AccountView::onNewClicked(wxCommandEvent &event) {
    OperationDialog *operationDialog = new OperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                           wxDefaultPosition, OPERATION_DIALOG_SIZE, accountTarget);
    operationDialog->ShowModal();
    operationDialog->Destroy();
}

void AccountView::onDeleteClicked(wxCommandEvent &event) {
    DeleteOperationDialog *deleteOperationDialog = new DeleteOperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                                             wxDefaultPosition, OPERATION_DIALOG_SIZE,
                                                                             accountTarget);
    deleteOperationDialog->ShowModal();
    deleteOperationDialog->Destroy();
}

void AccountView::onSearchClicked(wxCommandEvent &event) {
    int selection = labelFilterCtrl->GetSelection();
    wxString labelToFind = labelFilterCtrl->GetString(selection);
    wxString amountToFind = amountFilterCtrl->GetValue();

    for (int i = 0; i < operationListView->GetItemCount(); i++) {
        wxString viewLabel = operationListView->GetItemText(i, 0);
        wxString viewAmount = operationListView->GetItemText( i, 1);

        if (!labelToFind.empty() && !(viewLabel == labelToFind) || !amountToFind.empty() && !(viewAmount == amountToFind)) {
                operationListView->DeleteItem(i);
                i--;
        }
    }
}

void AccountView::onRemoveFiltersClicked(wxCommandEvent &event) {
    amountFilterCtrl->Clear();

    createListView(accountTarget);
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
