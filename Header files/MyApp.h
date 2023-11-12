
#ifndef PROGETTO_PROGRAMMAZIONE_MYAPP_H
#define PROGETTO_PROGRAMMAZIONE_MYAPP_H

#include <wx/wx.h>
#include "MainFrame.h"

class MyApp: public wxApp {
public:
    virtual bool OnInit();

private:
    MainFrame *mainFrame;
};

wxIMPLEMENT_APP(MyApp);

#endif //PROGETTO_PROGRAMMAZIONE_MYAPP_H
