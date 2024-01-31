#include "../Header files/SavingAccountView.h"

SavingAccountView::SavingAccountView(wxFrame *parent, const wxString &title, const wxString &accountTarget, const wxPoint &pos,
                                     const wxSize &size) : View(parent, title, pos, size) {
    this->accountTarget = accountTarget;
    AccountCollection::getInstance()->registerModelObserver(this);

    Bind(wxEVT_PAINT, &SavingAccountView::onPaint, this);

    auto *menuBar = new wxMenuBar();
    auto *operationMenu = new wxMenu();
    auto *addItem = new wxMenuItem(operationMenu, wxID_NEW);
    auto *removeItem = new wxMenuItem(operationMenu, wxID_DELETE);
    auto *operationItem = new wxMenuItem(operationMenu, wxID_ANY, SAVING_VIEW_OPERATION_MENU_ITEM);
    operationMenu->Append(addItem);
    operationMenu->Append(removeItem);
    operationMenu->Append(operationItem);
    Bind(wxEVT_MENU, &SavingAccountView::onNewClicked, this, addItem->GetId());
    Bind(wxEVT_MENU, &SavingAccountView::onDeleteClicked, this, removeItem->GetId());
    Bind(wxEVT_MENU, &SavingAccountView::onOperationClicked, this, operationItem->GetId());


    menuBar->Append(operationMenu, OPERATION_MENU);

    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *progressionTextSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *progressiontext = new wxStaticText(this, wxID_ANY, SAVING_VIEW_PROGRESSION_TITLE);
    progressionTextSizer->Add(progressiontext, 1);

    mainSizer->Add(progressionTextSizer, 0, wxALL | wxEXPAND, DIALOG_BORDER);

    wxBoxSizer *barSizer = new wxBoxSizer(wxHORIZONTAL);
    progressionBar = new wxGauge(this, wxID_ANY, 100);
    progressionPercText = new wxStaticText(this, wxID_ANY,
                                           wxString::Format(wxT("%i"), dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getPercToBudget()) + "%");
    barSizer->Add(progressionBar, 1);
    barSizer->Add(progressionPercText, 0, wxLEFT | wxALIGN_RIGHT, DIALOG_BORDER);
    updateProgressionBar();

    mainSizer->Add(barSizer, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, DIALOG_BORDER);

    SetSizer(mainSizer);
    SetMenuBar(menuBar);

    statusBar = CreateStatusBar(SAVING_ACCOUNT_VIEW_STATUS_BAR_SIZE);
    statusBar->SetStatusText(ACCOUNT_VIEW_AMOUNT);
    statusBar->SetStatusText(wxString::Format(wxT("%.2f"),dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getAmount()), 1);
    statusBar->SetStatusText(SAVING_ACCOUNT_VIEW_BUDGET, 2);
    statusBar->SetStatusText(wxString::Format(wxT("%.2f"),dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getBudgetToReach()), 3);
}

SavingAccountView::~SavingAccountView() {
    AccountCollection::getInstance()->removeModelObserver(this);
}

void SavingAccountView::onNewClicked(wxCommandEvent &event) {
    OperationDialog *operationDialog = new OperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                           wxDefaultPosition, OPERATION_DIALOG_SIZE, accountTarget);

    operationDialog->ShowModal();
    operationDialog->Destroy();
}

void SavingAccountView::onDeleteClicked(wxCommandEvent &event) {
    DeleteOperationDialog *deleteOperationDialog = new DeleteOperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                                             wxDefaultPosition, DELETE_OPERATION_DIALOG_SIZE,
                                                                             accountTarget);
    deleteOperationDialog->ShowModal();
    deleteOperationDialog->Destroy();
}

void SavingAccountView::update() {
    updateProgressionBar();
    wxYield();

    progressionPercText->SetLabel(wxString::Format(wxT("%i"), dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getPercToBudget()) + "%");

    statusBar->SetStatusText(wxString::Format(wxT("%.2f"),dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getAmount()), 1);
    statusBar->SetStatusText(wxString::Format(wxT("%.2f"),dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get())->getBudgetToReach()), 3);

    Refresh();
}

void SavingAccountView::updateProgressionBar() {
    auto *account = dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get());
    progressionBar->SetValue(account->getPercToBudget());
}

void SavingAccountView::onPaint(wxPaintEvent &event) {
    wxPaintDC dc(this);
    RenderPieChart(dc);
}

void SavingAccountView::RenderPieChart(wxDC &dc) {
    SavingAccount *account = dynamic_cast<SavingAccount*>(AccountCollection::getInstance()->getAccountList().at(accountTarget).get());

    std::vector<double> data;
    double total = 0.0;
    for (const auto& labelsTotalIterator : account->getLabelsTotal()) {
        data.push_back(labelsTotalIterator.second);
        total += labelsTotalIterator.second;
    }

    double startAngle = 0.0;
    int centerX = GRAPHIC_CENTER_X;
    int centerY = GRAPHIC_CENTER_Y;
    int radius = GRAPHIC_RADIUS;

    wxFont font(FONT_SIZE, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    dc.SetFont(font);
    dc.DrawText(PIE_CHART_TITLE, PIE_CHART_TITLE_X, PIE_CHART_TITLE_Y);

    if (total > 0) {
        for (int i = 0; i < data.size(); ++i) {
            double angle = 360.0 * (data[i] / total);
            dc.SetBrush(wxBrush(PIE_CHART_COLOURS[i]));
            dc.DrawEllipticArc(centerX - radius, centerY - radius, 2 * radius, 2 * radius, startAngle,
                               startAngle + angle);
            startAngle += angle;
        }

        DrawLegend(dc, true);
    } else {
        dc.SetBrush(*wxTRANSPARENT_BRUSH);
        dc.DrawEllipse(centerX - radius, centerY - radius, 2 * radius, 2 * radius);
        DrawLegend(dc);
    }
}

void SavingAccountView::DrawLegend(wxDC &dc, bool isFull) {
    wxFont font(FONT_SIZE, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    dc.SetFont(font);


    if (isFull) {
        int legendX = LEGEND_CENTER_X;
        int legendY = LEGEND_CENTER_Y;

        SavingAccount *account = dynamic_cast<SavingAccount *>(AccountCollection::getInstance()->getAccountList().at(
                accountTarget).get());
        wxArrayString labels;
        for (const auto &labelsIterator: account->getLabelsTotal()) {
            labels.push_back(labelsIterator.first);
        }

        for (int i = 0; i < labels.size(); ++i) {
            dc.SetBrush(wxBrush(PIE_CHART_COLOURS[i]));
            dc.DrawRectangle(legendX, legendY, 25, 25);
            dc.SetTextForeground(*wxWHITE);
            dc.DrawText(labels[i], legendX + 30, legendY);
            legendY += 30;
        }
    } else {
        int blankLegendX = BLANK_LEGEND_X;
        int blankLegendY = BLANK_LEGEND_Y;
        dc.SetTextForeground(*wxWHITE);
        dc.DrawText(BLANK_LEGEND_TEXT, blankLegendX, blankLegendY);
    }
}

void SavingAccountView::onOperationClicked(wxCommandEvent &event) {
    AccountListView *accountListView = new AccountListView(this, accountTarget + SEPARATOR + ACCOUNT_VIEW, accountTarget);
    accountListView->Show();
}
