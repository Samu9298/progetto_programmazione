#ifndef PROGETTO_PROGRAMMAZIONE_MAINFRAME_H
#define PROGETTO_PROGRAMMAZIONE_MAINFRAME_H

#include <wx/wx.h>
#include <typeinfo>
#include <memory>
#include "Constants.h"
#include "Controller.h"
#include "AccountCollection.h"
#include "BankAccountView.h"
#include "AccountDialog.h"
#include "DeleteAccountDialog.h"

class MainFrame: public wxFrame {
public:
    explicit MainFrame(const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = MAIN_SIZE);

private:
    BankAccountView *accountView;
    wxChoice *labelChoice;
    wxArrayString choices;

    void onListButtonClicked(wxCommandEvent& event);
    void onNewAccountClicked(wxCommandEvent& event);
    void onDeleteAccountClicked(wxCommandEvent& event);
    void updateChoice();
};


#endif //PROGETTO_PROGRAMMAZIONE_MAINFRAME_H
