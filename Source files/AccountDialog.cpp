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

    wxSizer *buttonSizer = CreateButtonSizer(wxOK | wxCANCEL);
    mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT | wxBOTTOM, DIALOG_BORDER);

    SetSizer(mainSizer);
}
