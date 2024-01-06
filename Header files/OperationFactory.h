#ifndef PROGETTO_PROGRAMMAZIONE_OPERATIONFACTORY_H
#define PROGETTO_PROGRAMMAZIONE_OPERATIONFACTORY_H

#include <wx/wx.h>
#include <memory>
#include "BankOperation.h"
#include "Constants.h"

class OperationFactory {
public:
    OperationFactory(OperationFactory& obj) = delete;
    static std::shared_ptr<OperationFactory> getInstance();

    virtual ~OperationFactory();

    std::unique_ptr<BankOperation> createOperation(const wxString &label, const wxString &amount, const wxDateTime &date,
                                                   const wxDateTime &time);

private:
private:
    static std::shared_ptr<OperationFactory> instance;

    OperationFactory() {};
};


#endif //PROGETTO_PROGRAMMAZIONE_OPERATIONFACTORY_H
