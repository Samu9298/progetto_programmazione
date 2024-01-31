#ifndef PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNTVIEW_H
#define PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNTVIEW_H

#include <wx/wx.h>
#include "AccountCollection.h"
#include "OperationDialog.h"
#include "DeleteOperationDialog.h"
#include "AccountListView.h"

class SavingAccountView: public View {
public:
    SavingAccountView(wxFrame *parent, const wxString& title, const wxString& accountTarget, const wxPoint& pos = wxDefaultPosition,
                      const wxSize& size = MAIN_SIZE);

    ~SavingAccountView() override;

    void update() override;

private:
    wxString accountTarget;
    wxStatusBar *statusBar;
    wxGauge *progressionBar;
    wxStaticText *progressionPercText;

    void onNewClicked(wxCommandEvent &event);
    void onDeleteClicked(wxCommandEvent &event);
    void onOperationClicked(wxCommandEvent &event);
    void onPaint(wxPaintEvent &event);
    void updateProgressionBar();
    void RenderPieChart(wxDC& dc);
    void DrawLegend(wxDC& dc, bool isFull = false);
};


#endif //PROGETTO_PROGRAMMAZIONE_SAVINGACCOUNTVIEW_H
