#ifndef PROGETTO_PROGRAMMAZIONE_DELETEACCOUNTDIALOG_H
#define PROGETTO_PROGRAMMAZIONE_DELETEACCOUNTDIALOG_H

#include "wx/wx.h"
#include "AccountCollection.h"
#include "Constants.h"
#include "Controller.h"

class DeleteAccountDialog: public wxDialog {
public:
    DeleteAccountDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
    const wxSize &size);

    ~DeleteAccountDialog() override;

private:
    wxChoice *labelChoice;

    void onOkButtonClicked(wxCommandEvent &event);
};


#endif //PROGETTO_PROGRAMMAZIONE_DELETEACCOUNTDIALOG_H
