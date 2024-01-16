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

class BankAccountView : public View {
public:
    BankAccountView(wxFrame *parent, const wxString& title, const wxString& accountTarget, const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = MAIN_SIZE);
    ~BankAccountView() override;

    void update() override;

private:
    wxString accountTarget;
    wxListView *operationListView;
    wxStatusBar *statusBar;
    wxChoice *labelFilterCtrl;
    wxTextCtrl *amountFilterCtrl;
    wxCheckBox *incomeFilter;

    void onNewClicked(wxCommandEvent &event);
    void onDeleteClicked(wxCommandEvent &event);
    void onSearchClicked(wxCommandEvent &event);
    void onRemoveFiltersClicked(wxCommandEvent &event);
    void onItemListCLicked(wxListEvent &event);
    void createListView(const wxString& account);
    void populateListView(const wxString& account);
};


#endif //PROGETTO_PROGRAMMAZIONE_BANKACCOUNTVIEW_H
