cmake_minimum_required(VERSION 3.22)
project(Progetto_programmazione)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILE "Header files/Operation.h" "Source files/MyApp.cpp" "Header files/MyApp.h" "Source files/MainFrame.cpp" "Header files/MainFrame.h" "Header files/Constants.h"
        "Source files/BankOperation.cpp"
        "Header files/BankOperation.h"
        "Source files/Account.cpp"
        "Header files/Account.h"
        "Source files/AccountFactory.cpp"
        "Header files/AccountFactory.h"
)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
add_executable(Progetto_programmazione "Source files/MyApp.cpp")
add_library(coreLibrary ${SOURCE_FILE})

target_link_libraries(Progetto_programmazione ${wxWidgets_LIBRARIES} coreLibrary)