#include "../Header files/AccountFactory.h"

AccountFactory *AccountFactory::getInstance() {
    if (instance == nullptr)
        instance = new AccountFactory();
    return instance;
}
