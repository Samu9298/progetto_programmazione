
#ifndef PROGETTO_PROGRAMMAZIONE_MAINFRAME_H
#define PROGETTO_PROGRAMMAZIONE_MAINFRAME_H
#include <wx/wx.h>
#include "../Header files/Constants.h"

class MainFrame: public wxFrame {
public:
    explicit MainFrame(const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = MAIN_FRAME_SIZE);

private:

};


#endif //PROGETTO_PROGRAMMAZIONE_MAINFRAME_H
