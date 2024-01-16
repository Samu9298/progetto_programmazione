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
    Bind(wxEVT_CHOICE, &AccountDialog::onListClicked, this, typeChoice->GetId());

    mainSizer->Add(typeSizer, 0, wxALL | wxEXPAND, DIALOG_BORDER);

    wxBoxSizer *labelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, ACCOUNT_DIALOG_LABEL);
    labelSizer->Add(labelText, 0, wxRIGHT, DIALOG_BORDER);

    labelBox = new wxTextCtrl(this, wxID_ANY);
    labelSizer->Add(labelBox, 1);

    mainSizer->Add(labelSizer, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, DIALOG_BORDER);

    wxBoxSizer *amountSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *amountText = new wxStaticText(this, wxID_ANY, ACCOUNT_DIALOG_AMOUNT);
    amountSizer->Add(amountText, 0, wxRIGHT, DIALOG_BORDER);

    amountBox = new wxTextCtrl(this, wxID_ANY);
    wxTextValidator amountValidator(wxFILTER_NUMERIC, &amount);
    amountValidator.SetCharIncludes(".");
    amountBox->SetValidator(amountValidator);
    amountSizer->Add(amountBox, 1);

    mainSizer->Add(amountSizer, 0, wxLEFT| wxRIGHT | wxBOTTOM | wxEXPAND, DIALOG_BORDER);

    wxBoxSizer *budgetSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *budgetText = new wxStaticText(this, wxID_ANY, ACCOUNT_DIALOG_BUDGET);
    budgetSizer->Add(budgetText, 0, wxRIGHT, DIALOG_BORDER);

    budgetBox = new wxTextCtrl(this, wxID_ANY);
    wxTextValidator savingValidator(wxFILTER_NUMERIC, &budget);
    amountValidator.SetCharIncludes(".");
    budgetBox->SetValidator(savingValidator);
    budgetSizer->Add(budgetBox, 1);
    budgetBox->Disable();

    mainSizer->Add(budgetSizer, 0, wxLEFT| wxRIGHT | wxBOTTOM | wxEXPAND, DIALOG_BORDER);

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
        if (budgetBox->IsEnabled()) {
            if (!budgetBox->GetValue().empty()) {
                bool created = Controller::getInstance()->createAccount(type, labelBox->GetValue(), amountBox->GetValue(),
                                                                        budgetBox->GetValue());

                if(!created) {
                    wxMessageBox(ACCOUNT_FOUND_ERROR);
                }
            }  else {
                wxMessageBox(ACCOUNT_ERROR);
            }
        } else {
            bool created = Controller::getInstance()->createAccount(type, labelBox->GetValue(), amountBox->GetValue(),
                                                                    budgetBox->GetValue());

            if(!created) {
                wxMessageBox(ACCOUNT_FOUND_ERROR);
            }
        }
    } else {
        wxMessageBox(ACCOUNT_ERROR);
    }

    this->Destroy();
}

void AccountDialog::onListClicked(wxCommandEvent &event) {
    int selection = typeChoice->GetSelection();
    wxString typeSelected = typeChoice->GetString(selection);

    if (typeSelected == SAVING_ACCOUNT) {
        budgetBox->Enable();
    }
}

