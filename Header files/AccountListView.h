#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTLISTVIEW_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTLISTVIEW_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include "View.h"
#include "Constants.h"
#include "AccountCollection.h"
#include "OperationDialog.h"
#include "DeleteOperationDialog.h"

class AccountListView : public View {
public:
    AccountListView(wxFrame *parent, const wxString& title, const wxString& accountTarget, const wxPoint& pos = wxDefaultPosition,
    const wxSize& size = MAIN_SIZE);

    ~AccountListView() override;

    void update() override;

protected:
    wxString accountTarget;
    wxListView *operationListView;
    wxChoice *labelFilterCtrl;
    wxTextCtrl *amountFilterCtrl;
    wxCheckBox *incomeFilter;

    void onSearchClicked(wxCommandEvent &event);
    void onRemoveFiltersClicked(wxCommandEvent &event);
    void onItemListCLicked(wxListEvent &event);
    void createListView(const wxString& account);
    void populateListView(const wxString& account);
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTLISTVIEW_H
