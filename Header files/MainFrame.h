#ifndef PROGETTO_PROGRAMMAZIONE_MAINFRAME_H
#define PROGETTO_PROGRAMMAZIONE_MAINFRAME_H

#include <wx/wx.h>
#include <typeinfo>
#include "Constants.h"
#include "Controller.h"
#include "AccountCollection.h"
#include "AccountView.h"

class MainFrame: public wxFrame {
public:
    explicit MainFrame(const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = MAIN_SIZE);

private:
    Controller *controller;
    AccountCollection *accountCollection;
    AccountView *accountView;
    wxChoice *labelChoice;

    void onListButtonClicked(wxCommandEvent& event);
};


#endif //PROGETTO_PROGRAMMAZIONE_MAINFRAME_H
