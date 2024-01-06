#include "../Header files/OperationFactory.h"

std::shared_ptr<OperationFactory> OperationFactory::instance = nullptr;

std::shared_ptr<OperationFactory> OperationFactory::getInstance() {
    if (instance == nullptr)
        instance = std::shared_ptr<OperationFactory>(new OperationFactory);
    return instance;
}

std::unique_ptr<BankOperation> OperationFactory::createOperation(const wxString &label, const wxString &amount,
                                                                 const wxDateTime &date, const wxDateTime &time) {
    double amountNumber;
    amount.ToDouble(&amountNumber);
    std::unique_ptr<BankOperation> newOperation = std::make_unique<BankOperation>(BankOperation(label,OPERATION_LABELS.at(label),
                                                                                                (float)amountNumber, date, time));
    return newOperation;
}

OperationFactory::~OperationFactory() {

}
