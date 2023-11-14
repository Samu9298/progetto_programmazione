#include "../Header files/MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size):
    wxFrame(nullptr, wxID_ANY, title, pos, size) {

    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    wxPNGHandler *pngHandler = new wxPNGHandler;
    wxImage::AddHandler(pngHandler);
    wxStaticBitmap *image = new wxStaticBitmap(this, wxID_ANY, wxBitmap(LOGO, wxBITMAP_TYPE_PNG), wxDefaultPosition, LOGO_SIZE);
    mainSizer->Add(image, 0, wxALIGN_CENTER);

    wxButton *listButton = new wxButton(this, wxID_ANY, SELECT_ACCOUNT, wxDefaultPosition,MAIN_BUTTON_SIZE);
    mainSizer->Add(listButton, 0, wxALIGN_CENTER);

    wxButton *createButton = new wxButton(this, wxID_ANY, NEW_ACCOUNT, wxDefaultPosition,MAIN_BUTTON_SIZE);
    mainSizer->Add(createButton, 0, wxALIGN_CENTER);

    wxButton *deleteButton = new wxButton(this, wxID_ANY, DELETE_ACCOUNT, wxDefaultPosition,MAIN_BUTTON_SIZE);
    mainSizer->Add(deleteButton, 0, wxALIGN_CENTER);

    SetSizer(mainSizer);
}