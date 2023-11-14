#include "../Header files/MyApp.h"
#include "../Header files/Constants.h"
#include "../Header files/AccountFactory.h"

bool MyApp::OnInit() {
    this->mainFrame = new MainFrame(APP_NAME);
    mainFrame->Show(true);
    SetTopWindow(this->mainFrame);
    AccountFactory *accountFactory = nullptr;
    return true;
}