#include "../Header files/OperationDialog.h"

OperationDialog::OperationDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                 const wxSize &size) :
                                 wxDialog(parent, id, title, pos, size) {
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    //label
    for (const auto &iterator: OPERATION_LABEL) {
        choices.push_back(iterator);
    }
    wxBoxSizer *labelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, "Label");
    labelSizer->Add(labelText, 0, wxRIGHT, DIALOG_BORDER);
    labelChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);
    labelSizer->Add(labelChoice, 1);

    mainSizer->Add(labelSizer, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, DIALOG_BORDER);

    //amount
    wxBoxSizer *amountSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *amountText = new wxStaticText(this, wxID_ANY, "Amount");
    amountText->SetMinSize(wxSize(amountText->GetMinSize().x, amountText->GetMinSize().y));
    amountSizer->Add(amountText, 0, wxRIGHT, DIALOG_BORDER);

    amountBox = new wxTextCtrl(this, wxID_ANY);
    amountSizer->Add(amountBox, 1);

    mainSizer->Add(amountSizer, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, DIALOG_BORDER);

    //date
    wxBoxSizer *dateSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *dateText = new wxStaticText(this, wxID_ANY, "Date");
    dateText->SetMinSize(wxSize(dateText->GetMinSize().x, dateText->GetMinSize().y));
    dateSizer->Add(dateText, 0, wxRIGHT, DIALOG_BORDER);

    dateBox = new wxTextCtrl(this, wxID_ANY);
    dateSizer->Add(dateBox, 1);

    mainSizer->Add(dateSizer, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, DIALOG_BORDER);

    //hour
    wxBoxSizer *hourSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *hourText = new wxStaticText(this, wxID_ANY, "Hour");
    hourText->SetMinSize(wxSize(hourText->GetMinSize().x, hourText->GetMinSize().y));
    hourSizer->Add(hourText, 0, wxRIGHT, DIALOG_BORDER);

    hourBox = new wxTextCtrl(this, wxID_ANY);
    hourSizer->Add(hourBox, 1);

    mainSizer->Add(hourSizer, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, DIALOG_BORDER);

    wxSizer *buttonSizer = CreateButtonSizer(wxOK | wxCANCEL);
    mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT | wxTOP | wxBOTTOM, DIALOG_BORDER);

    SetSizer(mainSizer);
    SetSize(OPERATION_DIALOG_SIZE);
}

const wxString OperationDialog::getLabel() const {
    return label;
}

float OperationDialog::getAmount() const {
    return amount;
}

const wxString OperationDialog::getDate() const {
    return date;
}

const wxString OperationDialog::getHour() const {
    return hour;
}
