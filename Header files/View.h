#ifndef PROGETTO_PROGRAMMAZIONE_VIEW_H
#define PROGETTO_PROGRAMMAZIONE_VIEW_H

#include <wx/wx.h>

class View : public wxFrame {
public:
    View(wxFrame *parent, const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(parent, wxID_ANY, title, pos, size) {};

    virtual ~View() {};
    virtual void update() = 0;
};

#endif //PROGETTO_PROGRAMMAZIONE_VIEW_H