#ifndef PROGETTO_PROGRAMMAZIONE_DELETEOPERATIONDIALOG_H
#define PROGETTO_PROGRAMMAZIONE_DELETEOPERATIONDIALOG_H

#include "wx/wx.h"
#include "wx/tokenzr.h"
#include "Constants.h"
#include "AccountCollection.h"
#include "Controller.h"

class DeleteOperationDialog : public wxDialog{
public:
    DeleteOperationDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                          const wxSize &size, const wxString& accountTarget);

    ~DeleteOperationDialog() override;

private:
    wxChoice *labelChoice;
    wxString accountTarget;

    void onOkButtonClicked(wxCommandEvent &event);
};


#endif //PROGETTO_PROGRAMMAZIONE_DELETEOPERATIONDIALOG_H
