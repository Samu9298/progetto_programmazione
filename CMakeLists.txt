cmake_minimum_required(VERSION 3.22)
project(Progetto_programmazione)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(unit_test)

set(SOURCE_FILE "Source files/MyApp.cpp" "Header files/MyApp.h" "Source files/MainFrame.cpp" "Header files/MainFrame.h"
        "Header files/Constants.h"
        "Source files/BankOperation.cpp"
        "Header files/BankOperation.h"
        "Source files/BankAccount.cpp"
        "Header files/BankAccount.h"
        "Source files/AccountFactory.cpp"
        "Header files/AccountFactory.h"
        "Header files/Model.h"
        "Header files/View.h"
        "Source files/AccountCollection.cpp"
        "Header files/AccountCollection.h"
        "Source files/BankAccountView.cpp"
        "Header files/BankAccountView.h"
        "Source files/Controller.cpp"
        "Header files/Controller.h"
        "Source files/OperationDialog.cpp"
        "Header files/OperationDialog.h"
        "Source files/AccountDialog.cpp"
        "Header files/AccountDialog.h"
        "Source files/DeleteAccountDialog.cpp"
        "Header files/DeleteAccountDialog.h"
        "Source files/DeleteOperationDialog.cpp"
        "Header files/DeleteOperationDialog.h"
        "Source files/OperationFactory.cpp"
        "Header files/OperationFactory.h"
        "Source files/Account.cpp"
        "Header files/Account.h"
        "Source files/SavingAccount.cpp"
        "Header files/SavingAccount.h"
        "Source files/SavingAccountView.cpp"
        "Header files/SavingAccountView.h"
        "Source files/AccountListView.cpp"
        "Header files/AccountListView.h"
)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
add_executable(Progetto_programmazione "Source files/MyApp.cpp")
add_library(coreLibrary ${SOURCE_FILE})

target_link_libraries(Progetto_programmazione coreLibrary ${wxWidgets_LIBRARIES})
target_link_libraries(coreLibrary ${wxWidgets_LIBRARIES})