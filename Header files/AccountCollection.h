#ifndef PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H
#define PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H

#include <list>
#include "Model.h"

class AccountCollection : public Model {
public:
    void notify() override;

    void registerModelObserver(View *view) override;

    void removeModelObserver(View *view) override;

private:
    std::list<View *> observers;
};


#endif //PROGETTO_PROGRAMMAZIONE_ACCOUNTCOLLECTION_H
