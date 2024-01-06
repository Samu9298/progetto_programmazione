#include "../Header files/OperationDialog.h"

OperationDialog::OperationDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                 const wxSize &size, const wxString& accountTarget) :
                                 wxDialog(parent, id, title, pos, size) {
    this->accountTarget = accountTarget;
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    //label
    for(const auto& iterator: OPERATION_LABELS) {
        choices.push_back(iterator.first);
    }
    wxBoxSizer *labelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, OPERATION_DIALOG_LABEL);
    labelSizer->Add(labelText, 0, wxRIGHT, DIALOG_BORDER);
    labelChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);
    labelSizer->Add(labelChoice, 1);

    mainSizer->Add(labelSizer, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, DIALOG_BORDER);

    //amount
    //TODO: aggiungi validator per far inserire solo numeri e punto
    wxBoxSizer *amountSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *amountText = new wxStaticText(this, wxID_ANY, OPERATION_DIALOG_AMOUNT);
    amountText->SetMinSize(wxSize(amountText->GetMinSize().x, amountText->GetMinSize().y));
    amountSizer->Add(amountText, 0, wxRIGHT, DIALOG_BORDER);

    amountBox = new wxTextCtrl(this, wxID_ANY);
    amountSizer->Add(amountBox, 1);

    mainSizer->Add(amountSizer, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, DIALOG_BORDER);

    //date
    wxBoxSizer *dateSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *dateText = new wxStaticText(this, wxID_ANY, OPERATION_DIALOG_DATE);
    dateText->SetMinSize(wxSize(dateText->GetMinSize().x, dateText->GetMinSize().y));
    dateSizer->Add(dateText, 0, wxRIGHT, DIALOG_BORDER);

    datePicker = new wxDatePickerCtrl(this, wxID_ANY);
    dateSizer->Add(datePicker, 1);

    mainSizer->Add(dateSizer, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, DIALOG_BORDER);

    //hour
    wxBoxSizer *timeSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *timeText = new wxStaticText(this, wxID_ANY, OPERATION_DIALOG_HOUR);
    timeText->SetMinSize(wxSize(timeText->GetMinSize().x, timeText->GetMinSize().y));
    timeSizer->Add(timeText, 0, wxRIGHT, DIALOG_BORDER);

    timePicker = new wxTimePickerCtrl(this, wxID_ANY);
    timeSizer->Add(timePicker, 1);

    mainSizer->Add(timeSizer, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, DIALOG_BORDER);

    wxButton *okButton = new wxButton(this, wxID_ANY, OPERATION_DIALOG_OK);
    mainSizer->Add(okButton, 0, wxALIGN_RIGHT | wxTOP | wxBOTTOM | wxRIGHT, DIALOG_BORDER);
    Bind(wxEVT_BUTTON, &OperationDialog::onOkButtonClicked, this, okButton->GetId());

    SetSizer(mainSizer);
    SetSize(OPERATION_DIALOG_SIZE);
}

void OperationDialog::onOkButtonClicked(wxCommandEvent &event) {
    if(!amountBox->GetValue().empty()) {
        int selection = labelChoice->GetSelection();
        wxString selectedLabel = labelChoice->GetString(selection);
        if(!selectedLabel.empty()) {
            Controller::getInstance()->createOperation(this->accountTarget, selectedLabel,
                                                       amountBox->GetValue(), datePicker->GetValue(),
                                                       timePicker->GetValue());
        }
    } else {
        wxMessageBox(OPERATION_ERROR);
    }
    amountBox->Clear();
}