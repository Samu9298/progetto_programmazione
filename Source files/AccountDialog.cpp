#include "../Header files/AccountDialog.h"

AccountDialog::AccountDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                             const wxSize &size) :
                             wxDialog(parent, id, title, pos, size) {
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *typeSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *typeText = new wxStaticText(this, wxID_ANY, ACCOUNT_TYPE_STRING);
    typeSizer->Add(typeText, 0, wxRIGHT, DIALOG_BORDER);

    wxArrayString choices;
    for (const auto& iterator : ACCOUNT_TYPE) {
        choices.push_back(iterator.first);
    }
    typeChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);
    typeSizer->Add(typeChoice, 1);

    mainSizer->Add(typeSizer, 0, wxALL | wxEXPAND, DIALOG_BORDER);

    wxBoxSizer *labelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, ACCOUNT_DIALOG_LABEL);
    labelSizer->Add(labelText, 0, wxRIGHT, DIALOG_BORDER);

    labelBox = new wxTextCtrl(this, wxID_ANY);
    labelSizer->Add(labelBox, 1);

    mainSizer->Add(labelSizer, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, DIALOG_BORDER);

    //TODO: aggiungi validator per far inserire solo numeri e punto
    wxBoxSizer *amountSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *amountText = new wxStaticText(this, wxID_ANY, ACCOUNT_DIALOG_AMOUNT);
    amountSizer->Add(amountText, 0, wxRIGHT, DIALOG_BORDER);

    amountBox = new wxTextCtrl(this, wxID_ANY);
    amountSizer->Add(amountBox, 1);

    mainSizer->Add(amountSizer, 0, wxLEFT| wxRIGHT | wxBOTTOM | wxEXPAND, DIALOG_BORDER);

    wxButton *okButton = new wxButton(this, wxID_ANY, ACCOUNT_DIALOG_OK);
    mainSizer->Add(okButton, 0, wxALIGN_RIGHT | wxRIGHT, DIALOG_BORDER);
    Bind(wxEVT_BUTTON, &AccountDialog::onOkButtonClicked, this, okButton->GetId());

    //Bind(wxEVT_UPDATE_UI, &AccountDialog::onUpdateOkButton, this, wxID_OK);

    SetSizer(mainSizer);
}

/*
void AccountDialog::onUpdateOkButton(wxUpdateUIEvent &event) {
    event.Enable(false);

    if(!labelBox->GetValue().empty()) {
        if(!amountBox->GetValue().empty()) {
            event.Enable(true);
            Controller::getInstance()->createAccount(labelBox->GetValue(), amountBox->GetValue());
        }
    }
}
*/

void AccountDialog::onOkButtonClicked(wxCommandEvent &event) {
    if(!labelBox->GetValue().empty() && !amountBox->GetValue().empty()) {
        int selection = typeChoice->GetSelection();
        wxString accountType = typeChoice->GetString(selection);

        AccountType type;
        for (const auto& iterator : ACCOUNT_TYPE) {
            if (iterator.first == accountType) {
                type = iterator.second;
            }
        }

        Controller::getInstance()->createAccount(type, labelBox->GetValue(), amountBox->GetValue());
    } else {
        wxMessageBox(ACCOUNT_ERROR);
    }
    this->Destroy();
}

