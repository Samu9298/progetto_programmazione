#include "../Header files/SavingAccountView.h"

SavingAccountView::SavingAccountView(wxFrame *parent, const wxString &title, const wxString &accountTarget, const wxPoint &pos,
                                     const wxSize &size) : View(parent, title, pos, size) {
    this->accountTarget = accountTarget;
    AccountCollection::getInstance()->registerModelObserver(this);

    auto *menuBar = new wxMenuBar();
    auto *operationMenu = new wxMenu();
    auto *addItem = new wxMenuItem(operationMenu, wxID_NEW);
    auto *removeItem = new wxMenuItem(operationMenu, wxID_DELETE);
    operationMenu->Append(addItem);
    operationMenu->Append(removeItem);
    Bind(wxEVT_MENU, &SavingAccountView::onNewClicked, this, addItem->GetId());
    Bind(wxEVT_MENU, &SavingAccountView::onDeleteClicked, this, removeItem->GetId());

    menuBar->Append(operationMenu, OPERATION_MENU);

    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *progressionTextSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *progressiontext = new wxStaticText(this, wxID_ANY, SAVING_VIEW_PROGRESSION_TITLE);
    progressionTextSizer->Add(progressiontext, 1);

    mainSizer->Add(progressionTextSizer, 0, wxALL | wxEXPAND, DIALOG_BORDER);

    wxBoxSizer *barSizer = new wxBoxSizer(wxHORIZONTAL);
    progressionBar = new wxGauge(this, wxID_ANY, 100);
    progressionPercText = new wxStaticText(this, wxID_ANY,
                                           wxString::Format(wxT("%i"), dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getPercToBudget()) + "%");
    barSizer->Add(progressionBar, 1);
    barSizer->Add(progressionPercText, 0, wxLEFT | wxALIGN_RIGHT, DIALOG_BORDER);
    updateProgressionBar();

    mainSizer->Add(barSizer, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, DIALOG_BORDER);

    SetSizer(mainSizer);
    SetMenuBar(menuBar);

    statusBar = CreateStatusBar(SAVING_ACCOUNT_VIEW_STATUS_BAR_SIZE);
    statusBar->SetStatusText(ACCOUNT_VIEW_AMOUNT);
    statusBar->SetStatusText(wxString::Format(wxT("%.2f"),dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getAmount()), 1);
    statusBar->SetStatusText(SAVING_ACCOUNT_VIEW_BUDGET, 2);
    statusBar->SetStatusText(wxString::Format(wxT("%.2f"),dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getBudgetToReach()), 3);
}

SavingAccountView::~SavingAccountView() {
    AccountCollection::getInstance()->removeModelObserver(this);
}

void SavingAccountView::onNewClicked(wxCommandEvent &event) {
    OperationDialog *operationDialog = new OperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                           wxDefaultPosition, OPERATION_DIALOG_SIZE, accountTarget);

    operationDialog->ShowModal();
    operationDialog->Destroy();
}

void SavingAccountView::onDeleteClicked(wxCommandEvent &event) {
    DeleteOperationDialog *deleteOperationDialog = new DeleteOperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                                             wxDefaultPosition, DELETE_OPERATION_DIALOG_SIZE,
                                                                             accountTarget);
    deleteOperationDialog->ShowModal();
    deleteOperationDialog->Destroy();
}

void SavingAccountView::update() {
    updateProgressionBar();
    wxYield();

    progressionPercText->SetLabel(wxString::Format(wxT("%i"), dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getPercToBudget()) + "%");

    statusBar->SetStatusText(wxString::Format(wxT("%.2f"),dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getAmount()), 1);
    statusBar->SetStatusText(wxString::Format(wxT("%.2f"),dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getBudgetToReach()), 3);
}

void SavingAccountView::updateProgressionBar() {
    auto *account = dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get());
    progressionBar->SetValue(account->getPercToBudget());
}