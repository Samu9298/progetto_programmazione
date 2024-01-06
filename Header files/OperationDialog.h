#ifndef PROGETTO_PROGRAMMAZIONE_OPERATIONDIALOG_H
#define PROGETTO_PROGRAMMAZIONE_OPERATIONDIALOG_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/timectrl.h>
#include "Constants.h"
#include "Controller.h"

class OperationDialog: public wxDialog {
public:
    OperationDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                  const wxSize &size, const wxString& accountTarget);

    virtual ~OperationDialog() {};

private:
    wxString accountTarget;
    wxArrayString choices;
    wxChoice *labelChoice = nullptr;
    wxTextCtrl *amountBox = nullptr;
    wxDatePickerCtrl *datePicker = nullptr;
    wxTimePickerCtrl *timePicker = nullptr;

    void onOkButtonClicked(wxCommandEvent &event);
};


#endif //PROGETTO_PROGRAMMAZIONE_OPERATIONDIALOG_H
