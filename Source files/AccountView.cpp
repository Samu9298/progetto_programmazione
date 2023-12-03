#include "../Header files/AccountView.h"

AccountView::AccountView(Model *model, Controller *controller, wxFrame *parent, const wxString& title,
                         const wxPoint& pos, const wxSize& size) : wxFrame(parent, wxID_ANY, title, pos, size) {
    this->model = model;
    this->model->registerModelObserver(this);

    auto *menuBar = new wxMenuBar();
    auto *operationMenu = new wxMenu();
    auto *addItem = new wxMenuItem(operationMenu, wxID_NEW);
    auto *removeItem = new wxMenuItem(operationMenu, wxID_DELETE);
    operationMenu->Append(addItem);
    Bind(wxEVT_MENU, &AccountView::onNewClicked, this, addItem->GetId());
    operationMenu->Append(removeItem);

    menuBar->Append(operationMenu, OPERATION_MENU);

    auto *operationListPanel = new wxPanel(this);
    operationListView = new wxListView(operationListPanel);
    //TODO: implement the costruction of the list: width of the column

    operationListView->AppendColumn("ID");
    operationListView->AppendColumn("Name");


    auto *operationListSizer = new wxBoxSizer(wxHORIZONTAL);
    operationListSizer->Add(operationListView, 1,wxEXPAND);

    operationListPanel->SetSizer(operationListSizer);
    SetMenuBar(menuBar);
}

AccountView::~AccountView() {
    this->model->removeModelObserver(this);
}

void AccountView::update() {
    populateListView();
    this->Show(true);
}

void AccountView::populateListView() {
    operationListView->InsertItem(0, "Prova 1");
    operationListView->SetItem(0, 1, "Prova 1");

    operationListView->InsertItem(1, "Prova 2");
    operationListView->SetItem(1, 1, "Prova 2");
}

void AccountView::onNewClicked(wxCommandEvent &event) {
    OperationDialog *operationDialog = new OperationDialog(this, wxID_ANY, OPERATION_DIALOG_NAME,
                                                           wxDefaultPosition,OPERATION_DIALOG_SIZE);
    operationDialog->ShowModal();
    operationDialog->Destroy();
}
