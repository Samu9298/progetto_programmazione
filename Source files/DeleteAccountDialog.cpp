#include "../Header files/DeleteAccountDialog.h"

DeleteAccountDialog::DeleteAccountDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                         const wxSize &size): wxDialog(parent, id, title, pos, size) {
    wxBoxSizer *mainSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, ACCOUNT_DIALOG_LABEL);
    mainSizer->Add(labelText, 0, wxALL, DIALOG_BORDER);

    wxArrayString choices;
    for(auto iterator: AccountCollection::getInstance()->getAccountList()) {
        choices.push_back(iterator.first);
    }
    wxChoice *labelChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);
    mainSizer->Add(labelChoice, 1, wxALL, DIALOG_BORDER);

    SetSizer(mainSizer);
}

DeleteAccountDialog::~DeleteAccountDialog() {

}
