#ifndef PROGETTO_PROGRAMMAZIONE_BANKACCOUNTVIEW_H
#define PROGETTO_PROGRAMMAZIONE_BANKACCOUNTVIEW_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include "View.h"
#include "Model.h"
#include "Controller.h"
#include "Constants.h"
#include "OperationDialog.h"
#include "DeleteOperationDialog.h"
#include "AccountListView.h"

class BankAccountView : public AccountListView {
public:
    BankAccountView(wxFrame *parent, const wxString& title, const wxString& accountTarget, const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = MAIN_SIZE);
    ~BankAccountView() override;

    void update() override;

private:
    wxStatusBar *statusBar;

    void onNewClicked(wxCommandEvent &event);
    void onDeleteClicked(wxCommandEvent &event);
};


#endif //PROGETTO_PROGRAMMAZIONE_BANKACCOUNTVIEW_H
