#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTDIALOG_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTDIALOG_H

#include "wx/wx.h"
#include "Constants.h"

class AccountDialog: public wxDialog {
public:
    AccountDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                  const wxSize &size);

    virtual ~AccountDialog() {};
private:
    wxString label = "Empty";
    wxTextCtrl *labelBox = nullptr;
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTDIALOG_H
