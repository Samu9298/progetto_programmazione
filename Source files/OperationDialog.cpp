#include "../Header files/OperationDialog.h"

OperationDialog::OperationDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                 const wxSize &size, long style, const wxString &name) :
                                 wxDialog(parent, id, title, pos, size, style, name) {
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    //label
    for (const auto &iterator: OPERATION_LABEL) {
        choices.push_back(iterator);
    }
    wxBoxSizer *labelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *labelText = new wxStaticText(this, wxID_ANY, "Label");
    labelSizer->Add(labelText);
    labelChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);
    labelSizer->Add(labelChoice, 1);

    mainSizer->Add(labelSizer, 0, wxEXPAND | wxALL, 5);

    //amount
    wxBoxSizer *amountSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *amountText = new wxStaticText(this, wxID_ANY, "Amount");
    amountText->SetMinSize(wxSize(amountText->GetMinSize().x, amountText->GetMinSize().y));
    amountSizer->Add(amountText);

    amountBox = new wxTextCtrl(this, wxID_ANY);
    amountSizer->Add(amountBox, 1);

    mainSizer->Add(amountSizer, 0, wxEXPAND | wxALL, 5);

    //date
    wxBoxSizer *dateSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *dateText = new wxStaticText(this, wxID_ANY, "Date");
    dateText->SetMinSize(wxSize(dateText->GetMinSize().x, dateText->GetMinSize().y));
    dateSizer->Add(dateText);

    dateBox = new wxTextCtrl(this, wxID_ANY);
    dateSizer->Add(dateBox, 1);

    mainSizer->Add(dateSizer, 0, wxEXPAND | wxALL, 5);

    //hour
    wxBoxSizer *hourSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *hourText = new wxStaticText(this, wxID_ANY, "Hour");
    hourText->SetMinSize(wxSize(hourText->GetMinSize().x, hourText->GetMinSize().y));
    hourSizer->Add(hourText);

    hourBox = new wxTextCtrl(this, wxID_ANY);
    hourSizer->Add(hourBox, 1);

    mainSizer->Add(hourSizer, 0, wxEXPAND | wxALL, 5);

    wxSizer *buttonSizer = CreateButtonSizer(wxOK | wxCANCEL);
    mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT | wxBOTTOM, 5);

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
