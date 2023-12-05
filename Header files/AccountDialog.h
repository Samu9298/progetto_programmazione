#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTDIALOG_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTDIALOG_H

#include "wx/wx.h"
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
    wxString label = "Empty";
    wxString amount = "0.00";
    wxTextCtrl *labelBox = nullptr;
    wxTextCtrl *amountBox = nullptr;

    //bool TransferDataFromWindow() override;
    //void onUpdateOkButton(wxUpdateUIEvent& event);
    void onOkButtonClicked(wxCommandEvent& event);
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTDIALOG_H
