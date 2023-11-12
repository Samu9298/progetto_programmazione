
#ifndef PROGETTO_PROGRAMMAZIONE_OPERATION_H
#define PROGETTO_PROGRAMMAZIONE_OPERATION_H

#include "Constants.h"

class Operation {
public:
    Operation(operationLabel label, float amount, float date, float hour) {
        this->label = label;
        this->amount = amount,
        this->date = date;
        this->hour = hour;
    }

    virtual ~Operation() {

    }

private:
    operationLabel label;
    float amount;
    float date;
    float hour;
};

#endif //PROGETTO_PROGRAMMAZIONE_OPERATION_H
