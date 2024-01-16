#include "../Header files/MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size):
    wxFrame(nullptr, wxID_ANY, title, pos, size) {

    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    wxPNGHandler *pngHandler = new wxPNGHandler;
    wxImage::AddHandler(pngHandler);
    wxStaticBitmap *image = new wxStaticBitmap(this, wxID_ANY, wxBitmap(LOGO_PATH,wxBITMAP_TYPE_PNG),
                                               wxDefaultPosition,LOGO_SIZE);
    mainSizer->Add(image, 0, wxALIGN_CENTER);

    wxBoxSizer *labelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, CHOOSE_ACCOUNT, wxDefaultPosition,
                                               MAIN_LABEL_TEXT_SIZE);
    labelSizer->Add(labelText, 0, wxTOP, LABEL_CHOICE_BORDER);
    labelChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, labelText->GetSize(), choices);
    labelSizer->Add(labelChoice, 1, wxEXPAND);
    mainSizer->Add(labelSizer, 0, wxALIGN_CENTER);
    Bind(wxEVT_CHOICE, &MainFrame::onListButtonClicked, this, labelChoice->GetId());

    wxButton *createAccountButton = new wxButton(this, wxID_ANY, NEW_ACCOUNT, wxDefaultPosition,
                                                 MAIN_BUTTON_SIZE);
    mainSizer->Add(createAccountButton, 0, wxALIGN_CENTER);
    Bind(wxEVT_BUTTON, &MainFrame::onNewAccountClicked, this, createAccountButton->GetId());

    wxButton *deleteAccountButton = new wxButton(this, wxID_ANY, DELETE_ACCOUNT, wxDefaultPosition,
                                                 MAIN_BUTTON_SIZE);
    mainSizer->Add(deleteAccountButton, 0, wxALIGN_CENTER);
    Bind(wxEVT_BUTTON, &MainFrame::onDeleteAccountClicked, this, deleteAccountButton->GetId());

    SetSizer(mainSizer);
}

void MainFrame::onListButtonClicked(wxCommandEvent &event) {
    int selection = labelChoice->GetSelection();
    wxString selectedAccount = labelChoice->GetString(selection);
    auto& accountList = AccountCollection::getInstance()->getAccountList();
    const std::type_info& typeInfo = typeid(*accountList.at(selectedAccount));
    if (typeInfo == typeid(BankAccount)) {
        accountView = new BankAccountView(this, selectedAccount + SEPARATOR + ACCOUNT_VIEW, selectedAccount);
    }
    if (typeInfo == typeid(SavingAccount)) {
        accountView = new SavingAccountView(this, selectedAccount + SEPARATOR + ACCOUNT_VIEW, selectedAccount);
    }

    accountView->Show(true);
}

void MainFrame::onNewAccountClicked(wxCommandEvent &event) {
    AccountDialog *accountDialog = new AccountDialog(this, wxID_ANY, ACCOUNT, wxDefaultPosition,
                                                     ACCOUNT_DIALOG_SIZE);
    accountDialog->ShowModal();
    accountDialog->Destroy();

    updateChoice();
}

void MainFrame::onDeleteAccountClicked(wxCommandEvent &event) {
    DeleteAccountDialog *accountDialog = new DeleteAccountDialog(this, wxID_ANY, ACCOUNT,
                                                                 wxDefaultPosition, DELETE_ACCOUNT_DIALOG_SIZE);
    accountDialog->ShowModal();
    accountDialog->Destroy();

    updateChoice();
}

void MainFrame::updateChoice() {
    labelChoice->Clear();
    int pos = 0;
    for (const auto &iterator: AccountCollection::getInstance()->getAccountList()) {
        labelChoice->Append(iterator.first);
    }
}
