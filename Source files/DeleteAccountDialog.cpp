#include "../Header files/DeleteAccountDialog.h"

DeleteAccountDialog::DeleteAccountDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                         const wxSize &size): wxDialog(parent, id, title, pos, size) {
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *labelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, ACCOUNT_DIALOG_LABEL);
    labelSizer->Add(labelText, 0, wxRIGHT, DIALOG_BORDER);

    wxArrayString choices;
    for(auto iterator: AccountCollection::getInstance()->getAccountList()) {
        choices.push_back(iterator.first);
    }
    labelChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);
    labelSizer->Add(labelChoice, 1);

    mainSizer->Add(labelSizer, 0, wxALL | wxEXPAND, DIALOG_BORDER);

    wxButton *okButton = new wxButton(this, wxID_ANY, ACCOUNT_DIALOG_OK);
    Bind(wxEVT_BUTTON, &DeleteAccountDialog::onOkButtonClicked, this, okButton->GetId());

    mainSizer->Add(okButton, 0, wxALIGN_RIGHT | wxRIGHT, DIALOG_BORDER);

    SetSizer(mainSizer);
}


DeleteAccountDialog::~DeleteAccountDialog() {

}

void DeleteAccountDialog::onOkButtonClicked(wxCommandEvent &event) {
    int selection = labelChoice->GetSelection();
    wxString selectedAccount = labelChoice->GetString(selection);

    Controller::getInstance()->deleteAccount(selectedAccount);

    this->Destroy();
}
