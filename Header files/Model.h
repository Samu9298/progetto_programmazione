#ifndef PROGETTO_PROGRAMMAZIONE_MODEL_H
#define PROGETTO_PROGRAMMAZIONE_MODEL_H

#include "../Header files/View.h"

class Model {
public:
    virtual ~Model() {};
    virtual void notify() = 0;
    virtual void registerModelObserver(View *view) = 0;
    virtual void removeModelObserver(View *view) = 0;
};

#endif //PROGETTO_PROGRAMMAZIONE_MODEL_H
