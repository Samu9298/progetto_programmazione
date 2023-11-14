#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTVIEW_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTVIEW_H

#include "../Header files/View.h"
#include "../Header files/Model.h"
#include "../Header files/Controller.h"

class AccountView : public View {
public:
    AccountView(Model *model, Controller *controller);
    ~AccountView() override;

    void update() override;

private:
    Model *model;
    Controller *controller;
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTVIEW_H
