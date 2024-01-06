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
    for(auto &iterator: AccountCollection::getInstance()->getAccountList().at(accountTarget)->getOperationList()){
        wxString amountString = wxString::Format(wxT("%.2f"), iterator->getAmount());
        wxString dateString = iterator->getDate().FormatDate();
        wxString timeString = iterator->getTime().FormatTime();
        wxString operation = iterator->getLabel() + SEPARATOR + amountString + SEPARATOR + dateString + SEPARATOR + timeString;
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
    wxString splittedAmount = tokenizer->GetNextToken();
    wxString splittedDate = tokenizer->GetNextToken();
    wxString splittedTime = tokenizer->GetNextToken();
    wxDateTime date;
    date.ParseFormat(splittedDate, "%m/%d/%Y");
    wxDateTime time;
    time.ParseFormat(splittedTime, "%H:%M:%S");

    std::unique_ptr<BankOperation> operationToDelete = std::move(OperationFactory::getInstance()->createOperation(splittedLabel, splittedAmount, date, time));

    Controller::getInstance()->deleteOperation(accountTarget, std::move(operationToDelete));
    labelChoice->Delete(selection);
}
