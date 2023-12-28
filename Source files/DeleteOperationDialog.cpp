#include "../Header files/DeleteOperationDialog.h"

DeleteOperationDialog::DeleteOperationDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                             const wxSize &size, const wxString& accountTarget) :
                                             wxDialog(parent, id, title, pos, size) {
    this->accountTarget = accountTarget;
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *labelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, OPERATION_DIALOG_LABEL);
    labelSizer->Add(labelText, 0, wxRIGHT, DIALOG_BORDER);

    wxArrayString choices;
    for(auto iterator: AccountCollection::getInstance()->getAccountList().at(accountTarget)->getOperationList()){
        wxString operation = iterator->getLabel() + SEPARATOR + iterator->getAmount() + SEPARATOR + iterator->getDate();
        choices.push_back(operation);
    }
    labelChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);
    labelSizer->Add(labelChoice, 1);

    mainSizer->Add(labelSizer, 0, wxALL | wxEXPAND, DIALOG_BORDER);

    wxButton *okButton = new wxButton(this, wxID_ANY, ACCOUNT_DIALOG_OK);
    Bind(wxEVT_BUTTON, &DeleteOperationDialog::onOkButtonClicked, this, okButton->GetId());

    mainSizer->Add(okButton, 0, wxALIGN_RIGHT | wxRIGHT, DIALOG_BORDER);

    SetSizer(mainSizer);
}

DeleteOperationDialog::~DeleteOperationDialog() {

}

void DeleteOperationDialog::onOkButtonClicked(wxCommandEvent &event) {
    int selection = labelChoice->GetSelection();
    wxString selectedOperationLabel = labelChoice->GetString(selection);

    wxStringTokenizer *tokenizer = new wxStringTokenizer(selectedOperationLabel, ",");
    wxString splittedLabel = tokenizer->GetNextToken();

    Controller::getInstance()->deleteOperation(accountTarget, splittedLabel);
    labelChoice->Delete(selection);
}
