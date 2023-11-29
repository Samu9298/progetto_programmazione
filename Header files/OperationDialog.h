#ifndef PROGETTO_PROGRAMMAZIONE_OPERATIONDIALOG_H
#define PROGETTO_PROGRAMMAZIONE_OPERATIONDIALOG_H

#include <wx/wx.h>
#include "Constants.h"

class OperationDialog: public wxDialog {
public:
    OperationDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos = wxDefaultPosition,
                  const wxSize &size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE,
                  const wxString &name = wxDialogNameStr);

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

    wxArrayString choices;
    wxChoice *labelChoice = nullptr;
    wxTextCtrl *amountBox = nullptr;
    wxTextCtrl *dateBox = nullptr;
    wxTextCtrl *hourBox = nullptr;
};


#endif //PROGETTO_PROGRAMMAZIONE_OPERATIONDIALOG_H
