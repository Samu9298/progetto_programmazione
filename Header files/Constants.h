#ifndef PROGETTO_PROGRAMMAZIONE_CONSTANTS_H
#define PROGETTO_PROGRAMMAZIONE_CONSTANTS_H

#include <wx/wx.h>

//app constants
static const wxString APP_NAME = "Money Balance";
static const wxString HELLO_WORLD = "Hello World";
static const wxString SELECT_ACCOUNT = "Select Account";
static const wxString NEW_ACCOUNT = "New Account";
static const wxString DELETE_ACCOUNT = "Delete Account";
static const wxString LOGO = "../Utilities/Logo.png";
static const wxSize MAIN_FRAME_SIZE = wxSize(1920, 1080);
static const wxSize MAIN_BUTTON_SIZE = wxSize(540, 150);
static const wxSize LOGO_SIZE = wxSize(540, 540);

//operations
enum operationLabel {
    bankDeposit,
    bankWithdraw,
    medicalExpense,
    fun,
    trip,
    food,
    clothes,
    animals
};

#endif //PROGETTO_PROGRAMMAZIONE_CONSTANTS_H
