#ifndef PROGETTO_PROGRAMMAZIONE_CONTROLLER_H
#define PROGETTO_PROGRAMMAZIONE_CONTROLLER_H

#include "wx/wx.h"
#include "AccountFactory.h"
#include "AccountCollection.h"

class Controller {
public:
    Controller(Controller& obj) = delete;
    static Controller *getInstance();

    virtual ~Controller();

    void createAccount(const wxString &label, const wxString &amount);
    void deleteAccount(const wxString &label);

private:
    static Controller *instance;

    Controller() {};
};


#endif //PROGETTO_PROGRAMMAZIONE_CONTROLLER_H
