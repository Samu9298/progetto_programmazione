#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTVIEW_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTVIEW_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <array>
#include "View.h"
#include "Model.h"
#include "Controller.h"
#include "Constants.h"
#include "OperationDialog.h"
#include "DeleteOperationDialog.h"

class AccountView : public View, public wxFrame {
public:
    AccountView(wxFrame *parent, const wxString& title, const wxString& accountTarget, const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = MAIN_SIZE);
    ~AccountView() override;

    void update() override;

private:
    wxString accountTarget;
    wxListCtrl *operationListView;

    void onNewClicked(wxCommandEvent &event);
    void onDeleteClicked(wxCommandEvent &event);
    void createListView(const wxString& account);
    void populateListView(const wxString& account);
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTVIEW_H
