#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTDIALOG_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTDIALOG_H

#include <wx/wx.h>
#include <wx/valtext.h>
#include "Constants.h"
#include "AccountCollection.h"
#include "AccountFactory.h"
#include "Controller.h"

class AccountDialog: public wxDialog {
public:
    AccountDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                  const wxSize &size);

    virtual ~AccountDialog() {};
private:
    wxTextCtrl *labelBox;
    wxTextCtrl *amountBox;
    wxTextCtrl *budgetBox;
    wxChoice *typeChoice;
    wxString amount;
    wxString budget;

    //void onUpdateOkButton(wxUpdateUIEvent& event);
    void onOkButtonClicked(wxCommandEvent& event);
    void onListClicked(wxCommandEvent &event);
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTDIALOG_H
