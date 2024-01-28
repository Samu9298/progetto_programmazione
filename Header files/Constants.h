#ifndef PROGETTO_PROGRAMMAZIONE_CONSTANTS_H
#define PROGETTO_PROGRAMMAZIONE_CONSTANTS_H

#include <wx/wx.h>
#include <array>
#include <map>
#include <vector>
#include <wx/colour.h>

//app constants
static const wxString APP_NAME = "Money Balance";
static const wxString ACCOUNT_VIEW = "Operation list";
static const wxString NEW_ACCOUNT = "New Account";
static const wxString DELETE_ACCOUNT = "Delete Account";
static const wxString OPERATION_MENU = "Operations";
static const wxString OPERATION_DIALOG_NAME = "Operation";
static const wxString CHOOSE_ACCOUNT = "Choose your account:";
static const wxString ACCOUNT_DIALOG_LABEL = "Label";
static const wxString ACCOUNT_DIALOG_AMOUNT = "Amount";
static const wxString ACCOUNT_DIALOG_BUDGET = "Budget (only for Saving account)";
static const wxString ACCOUNT_DIALOG_OK = "Ok";
static const wxString ACCOUNT = "Account";
static const wxString OPERATION_DIALOG_LABEL = "Label";
static const wxString OPERATION_DIALOG_DATE = "Date";
static const wxString OPERATION_DIALOG_AMOUNT = "Amount";
static const wxString OPERATION_DIALOG_HOUR = "Hour";
static const wxString OPERATION_DIALOG_OK = "Ok";
static const wxString SEPARATOR = ",";
static const wxString ACCOUNT_TYPE_STRING = "Type";
static const wxString SAVING_ACCOUNT = "Saving account";
static const std::vector<wxColour> PIE_CHART_COLOURS = {wxColour(255, 0, 0), wxColour(0, 255, 0),
                                                        wxColour(0, 0, 255), wxColour(255, 255, 0),
                                                        wxColour(255, 0, 255), wxColour(0, 255, 255),
                                                        wxColour(128, 0, 128)};

//errors
static const wxString ACCOUNT_ERROR = "Account not created: one or more field are empty";
static const wxString ACCOUNT_FOUND_ERROR = "Account not created: label already used";
static const wxString LOADING_ACCOUNT_ERROR = "Account not created: file not correctly loaded";
static const wxString OPERATION_ERROR = "Operation not created: one or more field are empty";
static const wxString OPENING_FILE_ERROR = "Error: file not correctly loaded";

//operation labels
static const std::map<wxString, bool> OPERATION_LABELS = {{"Bank deposit", true}, {"Bank withdraw", false},
                                               {"Medical expense", false}, {"Fun", false},
                                               {"Trip", false}, {"Food", false},
                                               {"Clothes", false}, {"Animals", false},
                                               {"Salary", true}, {"Saved", true}};
enum AccountType {
    Bank, Saving
};

static const std::map< wxString, AccountType> ACCOUNT_TYPE = {{"Bank account", Bank},
                                                             {"Saving account", Saving}};

//constants for BankAccountView
static const wxString VIEW_COLUMN[] = {"Label", "Amount", "Date", "Time"};
static const int BANK_ACCOUNT_VIEW_STATUS_BAR_SIZE = 2;
static const int SAVING_ACCOUNT_VIEW_STATUS_BAR_SIZE = 4;
static const wxString ACCOUNT_VIEW_AMOUNT = "Amount";
static const wxString SAVING_ACCOUNT_VIEW_BUDGET= "Budget to reach";
static const wxString ACCOUNT_VIEW_FILTER_LABEL = "Label";
static const wxString ACCOUNT_VIEW_FILTER_AMOUNT = "Amount";
static const wxString ACCOUNT_VIEW_FILTER_INCOME = "Income";
static const wxString ACCOUNT_VIEW_SEARCH = "Search";
static const wxString ACCOUNT_VIEW_REMOVE_FILTERS = "Remove all filters";

//constants for SavingAccountView
static const wxString SAVING_VIEW_PROGRESSION_TITLE = "Goal percentage reached";

//size of different elements
static const wxSize MAIN_SIZE = wxSize(1920, 1080);
static const wxSize MAIN_BUTTON_SIZE = wxSize(540, 150);
static const wxSize LOGO_SIZE = wxSize(540, 540);
static const wxSize OPERATION_DIALOG_SIZE = wxSize(500, 350);
static const wxSize DELETE_OPERATION_DIALOG_SIZE = wxSize(500, 200);
static const wxSize MAIN_LABEL_TEXT_SIZE = wxSize(150, 50);
static const wxSize ACCOUNT_DIALOG_SIZE = wxSize(500, 350);
static const wxSize DELETE_ACCOUNT_DIALOG_SIZE = wxSize(500, 205);
static const int LABEL_CHOICE_BORDER = 5;
static const int DIALOG_BORDER = 15;
static const int ACCOUNT_VIEW_BORDER = 15;

//path
static const wxString LOGO_PATH = "../Utilities/Logo.png";

#endif //PROGETTO_PROGRAMMAZIONE_CONSTANTS_H
