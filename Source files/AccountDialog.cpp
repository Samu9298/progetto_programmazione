#include "../Header files/AccountDialog.h"

AccountDialog::AccountDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                             const wxSize &size) :
                             wxDialog(parent, id, title, pos, size) {
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *labelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, ACCOUNT_DIALOG_LABEL);
    labelSizer->Add(labelText, 0, wxRIGHT, DIALOG_BORDER);

    labelBox = new wxTextCtrl(this, wxID_ANY);
    labelSizer->Add(labelBox, 1);

    mainSizer->Add(labelSizer, 0, wxALL | wxEXPAND, DIALOG_BORDER);

    wxBoxSizer *amountSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *amountText = new wxStaticText(this, wxID_ANY, ACCOUNT_DIALOG_AMOUNT);
    amountSizer->Add(amountText, 0, wxRIGHT, DIALOG_BORDER);

    amountBox = new wxTextCtrl(this, wxID_ANY);
    amountSizer->Add(amountBox, 1);

    mainSizer->Add(amountSizer, 0, wxLEFT| wxRIGHT | wxBOTTOM | wxEXPAND, DIALOG_BORDER);

    //wxSizer *buttonSizer = CreateButtonSizer(wxOK | wxCANCEL);
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
        Controller::getInstance()->createAccount(labelBox->GetValue(), amountBox->GetValue());
    } else {
        wxMessageBox(ACCOUNT_ERROR);
    }
    this->Destroy();
}

/*
bool AccountDialog::TransferDataFromWindow() {
    label = labelBox->GetValue();
    amount = amountBox->GetValue();
    return true;
}
*/

