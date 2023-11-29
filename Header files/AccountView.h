#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTVIEW_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTVIEW_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include "View.h"
#include "Model.h"
#include "Controller.h"
#include "Constants.h"
#include "OperationDialog.h"

class AccountView : public View, public wxFrame {
public:
    AccountView(Model *model, Controller *controller, wxFrame *parent, const wxString& title,
                const wxPoint& pos = wxDefaultPosition, const wxSize& size = MAIN_SIZE);
    ~AccountView() override;

    void update() override;

private:
    Model *model;
    Controller *controller;
    wxListCtrl *operationListView;

    void onNewClicked(wxCommandEvent &event);
    void populateListView();
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTVIEW_H
