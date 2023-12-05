#ifndef PROGETTO_PROGRAMMAZIONE_CONSTANTS_H
#define PROGETTO_PROGRAMMAZIONE_CONSTANTS_H

#include <wx/wx.h>

//app constants
static const wxString APP_NAME = "Money Balance";
static const wxString ACCOUNT_VIEW = "Operation list";
static const wxString NEW_ACCOUNT = "New Account";
static const wxString DELETE_ACCOUNT = "Delete Account";
static const wxString REMOVE_OPERATION = "Remove operation";
static const wxString OPERATION_MENU = "Operations";
static const wxString OPERATION_DIALOG_NAME = "Operation";
static const wxString CHOOSE_ACCOUNT = "Choose your account:";
static const wxString ACCOUNT_DIALOG_LABEL = "Label";
static const wxString ACCOUNT_DIALOG_AMOUNT = "Amount";
static const wxString ACCOUNT_DIALOG_OK = "Ok";
static const wxString ACCOUNT = "Account";
static const wxString OPERATION_DIALOG_LABEL = "Label";
static const wxString OPERATION_DIALOG_DATE = "Date";
static const wxString OPERATION_DIALOG_AMOUNT = "Amount";
static const wxString OPERATION_DIALOG_HOUR = "Hour";

//errors
static const wxString ACCOUNT_ERROR = "Account not created: one or more field are empty";

//operation labels
static const wxString OPERATION_LABEL[] = {"Bank deposit", "Bank withdraw", "Medical Expense", "Fun",
                                           "Trip", "Food", "Clothes", "Animals"};

//size of different elements
static const wxSize MAIN_SIZE = wxSize(1920, 1080);
static const wxSize MAIN_BUTTON_SIZE = wxSize(540, 150);
static const wxSize LOGO_SIZE = wxSize(540, 540);
static const wxSize OPERATION_DIALOG_SIZE = wxSize(720, 350);
static const wxSize MAIN_LABEL_TEXT_SIZE = wxSize(150, 50);
static const wxSize ACCOUNT_DIALOG_SIZE = wxSize(500, 252);
static const wxSize DELETE_ACCOUNT_DIALOG_SIZE = wxSize(500, 205);
static const int LABEL_CHOICE_BORDER = 5;
static const int DIALOG_BORDER = 15;

//path
static const wxString LOGO_PATH = "../Utilities/Logo.png";

#endif //PROGETTO_PROGRAMMAZIONE_CONSTANTS_H
