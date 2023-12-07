cmake_minimum_required(VERSION 3.22)
project(Progetto_programmazione)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILE "Source files/MyApp.cpp" "Header files/MyApp.h" "Source files/MainFrame.cpp" "Header files/MainFrame.h" "Header files/Constants.h"
        "Source files/BankOperation.cpp"
        "Header files/BankOperation.h"
        "Source files/Account.cpp"
        "Header files/Account.h"
        "Source files/AccountFactory.cpp"
        "Header files/AccountFactory.h"
        "Header files/Model.h"
        "Header files/View.h"
        "Source files/AccountCollection.cpp"
        "Header files/AccountCollection.h"
        "Source files/AccountView.cpp"
        "Header files/AccountView.h"
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
)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
add_executable(Progetto_programmazione "Source files/MyApp.cpp")
add_library(coreLibrary ${SOURCE_FILE})

target_link_libraries(Progetto_programmazione ${wxWidgets_LIBRARIES} coreLibrary)