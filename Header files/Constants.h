#ifndef PROGETTO_PROGRAMMAZIONE_CONSTANTS_H
#define PROGETTO_PROGRAMMAZIONE_CONSTANTS_H

#include <wx/wx.h>

//app constants
static const wxString APP_NAME = "Money Balance";
static const wxString ACCOUNT_VIEW = "Operation list";
static const wxString HELLO_WORLD = "Hello World";
static const wxString SELECT_ACCOUNT = "Select Account";
static const wxString NEW_ACCOUNT = "New Account";
static const wxString DELETE_ACCOUNT = "Delete Account";
static const wxString NEW_OPERATION = "Add new operation";
static const wxString REMOVE_OPERATION = "Remove operation";
static const wxString OPERATION_MENU = "Operations";
static const wxString OPERATION_DIALOG_NAME = "Operation";

//operation labels
static const wxString OPERATION_LABEL[] = {"Bank deposit", "Bank withdraw", "Medical Expense", "Fun",
                                           "Trip", "Food", "Clothes", "Animals"};

//size of different elements
static const wxSize MAIN_SIZE = wxSize(1920, 1080);
static const wxSize MAIN_BUTTON_SIZE = wxSize(540, 150);
static const wxSize LOGO_SIZE = wxSize(540, 540);
static const wxSize OPERATION_DIALOG_SIZE = wxSize(720, 300);

//path
static const wxString LOGO_PATH = "../Utilities/Logo.png";

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
