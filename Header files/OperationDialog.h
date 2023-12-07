#ifndef PROGETTO_PROGRAMMAZIONE_OPERATIONDIALOG_H
#define PROGETTO_PROGRAMMAZIONE_OPERATIONDIALOG_H

#include <wx/wx.h>
#include "Constants.h"
#include "Controller.h"

class OperationDialog: public wxDialog {
public:
    OperationDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                  const wxSize &size, const wxString& accountTarget);

    virtual ~OperationDialog() {};

    const wxString getLabel() const;

    float getAmount() const;

    const wxString getDate() const;

    const wxString getHour() const;

private:
    wxString label = "Empty";
    float amount = 0.00;
    wxString date = "Empty";
    wxString hour = "Empty";
    wxString accountTarget;
    wxArrayString choices;
    wxChoice *labelChoice = nullptr;
    wxTextCtrl *amountBox = nullptr;
    wxTextCtrl *dateBox = nullptr;
    wxTextCtrl *hourBox = nullptr;

    void onOkButtonClicked(wxCommandEvent &event);
};


#endif //PROGETTO_PROGRAMMAZIONE_OPERATIONDIALOG_H
