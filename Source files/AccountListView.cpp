#include "../Header files/AccountListView.h"

AccountListView::AccountListView(wxFrame *parent, const wxString& title, const wxString& accountTarget, const wxPoint& pos,
                                 const wxSize& size): View(parent, title, pos, size) {
    this->accountTarget = accountTarget;
    AccountCollection::getInstance()->registerModelObserver(this);

    auto *mainPanel = new wxPanel(this);
    operationListView = new wxListView(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    createListView(accountTarget);
    Bind(wxEVT_LIST_ITEM_SELECTED, &AccountListView::onItemListCLicked, this, operationListView->GetId());

    wxBoxSizer *filtersSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelFilter = new wxStaticText(mainPanel, wxID_ANY, ACCOUNT_VIEW_FILTER_LABEL);
    wxArrayString choices;
    for (const auto &iterator: OPERATION_LABELS) {
        choices.push_back(iterator.first);
    }
    labelFilterCtrl = new wxChoice(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);

    wxStaticText *amountFilter = new wxStaticText(mainPanel, wxID_ANY, ACCOUNT_VIEW_FILTER_AMOUNT);
    amountFilterCtrl = new wxTextCtrl(mainPanel, wxID_ANY);

    incomeFilter = new wxCheckBox(mainPanel, wxID_ANY, ACCOUNT_VIEW_FILTER_INCOME);

    filtersSizer->Add(labelFilter,0, wxLEFT | wxTOP | wxALIGN_LEFT | wxALIGN_TOP, ACCOUNT_VIEW_BORDER);
    filtersSizer->Add(labelFilterCtrl,0, wxLEFT | wxTOP | wxALIGN_LEFT | wxALIGN_TOP, ACCOUNT_VIEW_BORDER);
    filtersSizer->Add(amountFilter,0, wxLEFT | wxTOP | wxALIGN_LEFT | wxALIGN_TOP, ACCOUNT_VIEW_BORDER);
    filtersSizer->Add(amountFilterCtrl,0, wxLEFT | wxTOP | wxALIGN_LEFT | wxALIGN_TOP, ACCOUNT_VIEW_BORDER);
    filtersSizer->Add(incomeFilter,0, wxLEFT | wxTOP | wxALIGN_LEFT | wxALIGN_TOP, ACCOUNT_VIEW_BORDER);

    wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton *searchButton = new wxButton(mainPanel, wxID_ANY, ACCOUNT_VIEW_SEARCH);
    Bind(wxEVT_BUTTON, &AccountListView::onSearchClicked, this, searchButton->GetId());

    wxButton *removeFilterButton = new wxButton(mainPanel, wxID_ANY, ACCOUNT_VIEW_REMOVE_FILTERS);
    Bind(wxEVT_BUTTON, &AccountListView::onRemoveFiltersClicked, this, removeFilterButton->GetId());

    buttonSizer->Add(searchButton,1, wxLEFT | wxTOP, ACCOUNT_VIEW_BORDER);
    buttonSizer->Add(removeFilterButton,1, wxLEFT | wxTOP, ACCOUNT_VIEW_BORDER);

    auto *mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(filtersSizer, 0,  wxALIGN_LEFT | wxALIGN_TOP);
    mainSizer->Add(buttonSizer, 0, wxALIGN_LEFT | wxALIGN_TOP);
    mainSizer->Add(operationListView, 1, wxLEFT | wxTOP | wxEXPAND, ACCOUNT_VIEW_BORDER);

    mainPanel->SetSizer(mainSizer);
}

AccountListView::~AccountListView() {
    AccountCollection::getInstance()->removeModelObserver(this);
}

void AccountListView::update() {
    createListView(accountTarget);
}

void AccountListView::onSearchClicked(wxCommandEvent &event) {
    int selection = labelFilterCtrl->GetSelection();
    wxString labelToFind = labelFilterCtrl->GetString(selection);
    wxString amountToFind = amountFilterCtrl->GetValue();
    bool isIncomeToFind = incomeFilter->GetValue();

    for (int i = 0; i < operationListView->GetItemCount(); i++) {
        wxString viewLabel = operationListView->GetItemText(i, 0);
        wxString viewAmount = operationListView->GetItemText( i, 1);

        double viewAmountNumber;
        viewAmount.ToDouble(&viewAmountNumber);
        bool viewIsIncome = true;
        if ((float)viewAmountNumber > 0) {
            viewIsIncome = false;
        }

        if (!labelToFind.empty() && !(viewLabel == labelToFind) || !amountToFind.empty() && !(viewAmount.Contains(amountToFind))
            || isIncomeToFind == viewIsIncome) {
            operationListView->DeleteItem(i);
            i--;
        }
    }
}

void AccountListView::onRemoveFiltersClicked(wxCommandEvent &event) {
    amountFilterCtrl->Clear();

    createListView(accountTarget);
}

void AccountListView::onItemListCLicked(wxListEvent &event) {
    long index = event.GetIndex();

    OperationDialog* operationDialog = new OperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME, wxDefaultPosition, OPERATION_DIALOG_SIZE, accountTarget,
                                                           index, true);

    operationDialog->ShowModal();
    operationDialog->Destroy();
}

void AccountListView::createListView(const wxString& account) {
    operationListView->ClearAll();
    int numberOfColumns = std::end(VIEW_COLUMN) - std::begin(VIEW_COLUMN);
    int columnWidth = MAIN_SIZE.x / numberOfColumns;
    for(int length = 0; length < numberOfColumns; length++) {
        operationListView->AppendColumn(VIEW_COLUMN[length], wxLIST_FORMAT_CENTER, columnWidth);
    }

    populateListView(account);
}

void AccountListView::populateListView(const wxString& account) {
    int index = 0;
    for (auto iterator = AccountCollection::getInstance()->getAccountList().at(account)->getOperationList().rbegin();
         iterator != AccountCollection::getInstance()->getAccountList().at(account)->getOperationList().rend(); ++iterator) {
        int column = 1;
        operationListView->InsertItem(index, (*iterator)->getLabel());
        if ((*iterator)->getIsIncome()) {
            operationListView->SetItem(index, column, wxT("+") + wxString::Format(wxT("%.2f"), (*iterator)->getAmount()));
        } else {
            operationListView->SetItem(index, column, wxT("-") + wxString::Format(wxT("%.2f"), (*iterator)->getAmount()));
        }
        operationListView->SetItem(index, ++column, (*iterator)->getDate().FormatDate());
        operationListView->SetItem(index, ++column, (*iterator)->getTime().FormatTime());
    }
}