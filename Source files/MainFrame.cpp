#include "../Header files/MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size):
    wxFrame(nullptr, wxID_ANY, title, pos, size) {

    //TODO: how to call accountCollection: it's a singleton!
    this->accountCollection = new AccountCollection();
    this->controller = new Controller();

    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    wxPNGHandler *pngHandler = new wxPNGHandler;
    wxImage::AddHandler(pngHandler);
    wxStaticBitmap *image = new wxStaticBitmap(this, wxID_ANY, wxBitmap(LOGO_PATH, wxBITMAP_TYPE_PNG), wxDefaultPosition, LOGO_SIZE);
    mainSizer->Add(image, 0, wxALIGN_CENTER);

    /*
    wxButton *listButton = new wxButton(this, wxID_ANY, SELECT_ACCOUNT, wxDefaultPosition,MAIN_BUTTON_SIZE);
    mainSizer->Add(listButton, 0, wxALIGN_CENTER);
    Bind(wxEVT_BUTTON, &MainFrame::onListButtonClicked, this, listButton->GetId());
    */
    wxArrayString choices;
    for (const auto &iterator: accountCollection->getAccountList()) {
        choices.push_back(iterator.first);
    }

    wxBoxSizer *labelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, "Account");
    labelSizer->Add(labelText, 1);
    labelChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);
    labelSizer->Add(labelChoice, 1);

    mainSizer->Add(labelSizer, 0, wxALIGN_CENTER);
    Bind(wxEVT_CHOICE, &MainFrame::onListButtonClicked, this, labelChoice->GetId());

    wxButton *createAccountButton = new wxButton(this, wxID_ANY, NEW_ACCOUNT, wxDefaultPosition, MAIN_BUTTON_SIZE);
    mainSizer->Add(createAccountButton, 0, wxALIGN_CENTER);

    wxButton *deleteAccountButton = new wxButton(this, wxID_ANY, DELETE_ACCOUNT, wxDefaultPosition, MAIN_BUTTON_SIZE);
    mainSizer->Add(deleteAccountButton, 0, wxALIGN_CENTER);

    SetSizer(mainSizer);
}

void MainFrame::onListButtonClicked(wxCommandEvent &event) {
    int selection = labelChoice->GetSelection();
    wxString selectedAccount = labelChoice->GetString(selection);
    auto accountList = accountCollection->getAccountList();
    if (typeid(accountList.at(selectedAccount)) == typeid(Account*)) {
        this->accountView = new AccountView(accountCollection, controller, this, ACCOUNT_VIEW);
        accountView->update();
    }
}