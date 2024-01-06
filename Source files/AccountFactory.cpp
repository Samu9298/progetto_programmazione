#include <memory>

#include "../Header files/AccountFactory.h"

std::shared_ptr<AccountFactory> AccountFactory::instance = nullptr;

std::shared_ptr<AccountFactory> AccountFactory::getInstance() {
    if (instance == nullptr)
        instance = std::shared_ptr<AccountFactory>(new AccountFactory());
    return instance;
}

std::unique_ptr<Account> AccountFactory::createAccount(AccountType type, const wxString &label, const wxString &amount) {
    double amountNumber;
    amount.ToDouble(&amountNumber);

    switch (type) {
        case Bank:
            return std::make_unique<BankAccount>(label, (float)amountNumber);
        case Saving:
            return std::make_unique<SavingAccount>(label, (float)amountNumber);
        default:
            return nullptr;
    }
}

AccountFactory::~AccountFactory() {

}
