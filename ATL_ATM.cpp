//Anthony Tho Le

/*
 *CSPB 1300 - ATM Final Project
 */

//Final project for CSPB 1300 for FA19 - build a simple ATM machine utilizing C++, that allows the user to perform variety of different transactions
//Core functions must include deposit, transfer, and withdrawals - must also include various elements of enhancements to the program outside of these core functions
//note to self: consider incorporating classes & headers to tidy-up the program

#include <iomanip>
#include <iostream>

using namespace std;


//VARIABLES - declaring all variables before functions for ease of accessibility
int checking = 15750; // variable for user's checking account
int savings = 50000; // variable for user's savings account 
int input; // variable to store user's inputs
int * pointer_acc; // pointer to access & manipulate either checking or savings
int * pointer_acc2; // additional pointer to assist with transfers
double c_x_fund; // variable to store user's input for funds to convert
double * pointer_cx = &c_x_fund; //pointer to utilize for currency exchange; pre-set to point at memory address of c_x_fund
double c_i_1 = 1.33; // variable to store USD -> CAD exchange rate
double c_i_2 = 19.56; // variable to store USD -> MXN exchange rate
double c_i_3 = 0.90; // variable to store USD -> EUR exchange rate
double c_i_4 = 23141.25; // variable to store USD -> JPY exchange rate


//FUNCTIONS - declaring all functions before main() so they can be accessed by main
//declaring function rt so main can call it; definition and description of rt can be found after main
void rt();

//allows user to deposit x amount of funds into their accounts
void deposit(int *ptrD)
{
//create new ptrD which is set to what pointer_acc is pointing at - allowing function to manipulate the values of checking or savings 
    ptrD = pointer_acc;
    cout << "\nEnter deposit amount: \n$";
    cin >> input;
//while loop to catch cases of invalid inputs from user, prompting them to reenter an input - breaks when it is a valid input: repeated in most functions
//cin.clear helps remove the error flag on cin and cin.ignore clears the stream buffer so the user can provide new inputs for validation
    while (!cin || input < 0)
    {
        cout << "\nPlease enter a valid deposit amount: \n$";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input;
        if (cin && input > 0) break;
    }
    cout << "\nDepositing: $" << input << "\n";
    *ptrD += input;
}

//allows user to request x amount of funds be withdrawn from their accounts
void withdrawal(int *ptrW)
{
//create new ptrW which is set to what pointer_acc is pointing at - allowing function to manipulate the values of checking or savings 
    ptrW = pointer_acc;
    cout << "\nEnter withdrawal amount: \n$";
    cin >> input;
    while (!cin || input < 0 || input > *ptrW)
    {
        cout << "\nPlease enter a valid withdrawal amount: \n$";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input;
        if (cin && input >= 0 && input < *ptrW) break;
    }
//while loop to catch cases of user attempting to withdraw all funds in either checking or savings, prompting them to reenter an input
//breaks when it is a valid input: repeated in transfer function
    while (input == *ptrW)
    {
        cout << "\n⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️\n";
        cout << "WARNING: You are attempting to withdraw everything from this account!\n";
        cout << "Here at CSPB 1300, our policy forbids you from withdrawing all of your funds at this moment.\n";
        cout << "⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️\n";
        cout << "\nEnter a new withdrawal amount: \n$";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input ;
        while (!cin || input < 0 || input >= *ptrW)
        {
            cout << "\nEnter a new withdrawal amount: \n$";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input;
            if (cin && input >= 0 && input < *ptrW) break;
        }
        if (cin && input >= 0 && input < *ptrW) break;
    }
    cout << "\nWithdrawing: $" << input << "\n";
    *ptrW -= input;
}

//allows the user to request x amount of funds be transfered between their accounts
void transfer(int *ptrFROM, int *ptrTO)
{
//create new ptrFROM & ptrTO, which is set to what pointer_acc & pointer_acc2 is pointing at - allowing function to manipulate the values of checking & savings 
    ptrFROM = pointer_acc;
    ptrTO = pointer_acc2;
    cout << "\nEnter transfer amount: \n$";
    cin >> input;
    while (!cin || input < 0 || input > *ptrFROM)
    {
        cout << "\nPlease enter a valid transfer amount: \n$";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input;
        if (cin && input >= 0 && input < *ptrFROM) break;
    }
    while (input == *ptrFROM)
    {
        cout << "\n⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️\n";
        cout << "WARNING: You are attempting to transfer everything from this account!\n";
        cout << "Here at CSPB 1300, our policy forbids you from transfering all of your funds at this moment.\n";
        cout << "⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️  ⚠️\n";
        cout << "\nEnter a new transfer amount: \n$";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input ;
        while (!cin || input < 0 || input >= *ptrFROM)
        {
            cout << "\nEnter a new transfer amount: \n$";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input;
            if (cin && input >= 0 && input < *ptrFROM) break;
        }
        if (cin && input >= 0 && input < *ptrFROM) break;
    }
    cout << "\nTransferring: $" << input << "\n";
    *ptrFROM -= input;
    *ptrTO += input;
}

//allows the user to convert their USD to another form of currency; shorten currency exchange to c_x
void c_x(int input)
{
//based on input given in main after selecting "CURRENCY EXCHANGE", program executes the conversion of USD to one of four other currencies
//pointer_cx has already been defined to point towards memory address of c_x_fund prior to this function in "VARIABLES" section above
    if (input == 1)
    {
        cout << "\nPlease enter amount USD you would like to convert to CAD\n";
        cin >> c_x_fund;
        while (cin.fail() || c_x_fund <= 0.00)
        {
            cout << "\nPlease enter a valid amount of USD: \n";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> c_x_fund;
            if (cin.good() && c_x_fund > 0.00) break;
        }
        cout << "\nConverting " << fixed << setprecision(2) << c_x_fund << " USD to CAD\n";
        *pointer_cx *= c_i_1;
        cout << "\nYou now have " << c_x_fund << " CAD\n";
        rt();
    }
    else if (input == 2)
    {
        cout << "\nPlease enter amount USD you would like to convert to MXN\n";
        cin >> c_x_fund;
        while (cin.fail() || c_x_fund <= 0.00)
        {
            cout << "\nPlease enter a valid amount of USD: \n";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> c_x_fund;
            if (cin.good() && c_x_fund > 0.00) break;
        }
        cout << "\nConverting " << fixed << setprecision(2) << c_x_fund << " USD to MXN\n";
        *pointer_cx *= c_i_2;
        cout << "\nYou now have " << c_x_fund << " MXN\n";
        rt();
    }
    else if (input == 3)
    {
        cout << "Please enter amount USD you would like to convert to EUR\n";
        cin >> c_x_fund;
        while (cin.fail() || c_x_fund <= 0.00)
        {
            cout << "\nPlease enter a valid amount of USD: \n";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> c_x_fund;
            if (cin.good() && c_x_fund > 0.00) break;
        }
        cout << "\nConverting " << fixed << setprecision(2) << c_x_fund << " USD to EUR\n";
        *pointer_cx *= c_i_3;
        cout << "\nYou now have " << c_x_fund << " EUR\n";
        rt();
    }
    else if (input == 4)
    {
        cout << "\nPlease enter amount USD you would like to convert to VND\n";
        cin >> c_x_fund;
        while (cin.fail() || c_x_fund <= 0.00)
        {
            cout << "\nPlease enter a valid input: \n";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> c_x_fund;
            if (cin.good() && c_x_fund > 0.00) break;
        }
        cout << "\nConverting " << fixed << setprecision(2) << c_x_fund << " USD to VND\n";
        *pointer_cx *= c_i_4;
        cout << "\nYou now have " << c_x_fund << " VND\n";
        rt();
    }
}

//terminates program
void quit()
{
    cout << "\n";
    cout << "Thank you for using the CSPB 1300 ATM Machine\n";
    cout << "Please have a nice day :)\n";
    exit(0);
}

//menu interface that operates based on user input to execute various functions
int main()
{
    cout << "\nWelcome to the CSPB 1300 ATM Machine\n";
    cout << "******MAIN MENU******\n";
    cout << "[1] DEPOSIT\n";
    cout << "[2] WITHDRAWAL\n";
    cout << "[3] TRANSFER\n";
    cout << "[4] BALANCE INQUIRY\n";
    cout << "[5] CURRENCY EXCHANGE\n";
    cout << "[6] EXIT\n"; 
    cout << "**********************\n";
    cout << "Please select an transaction to perform: \n";
    cin >> input;   
    while (input != 1 && input !=  2 && input != 3 && input != 4 && input != 5 & input!= 6)
    {
        cout << "\nPlease enter a valid input: \n";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input;
        if (input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6) break;
    } 
//based on input, program will execute one of six statements which will then call upon the appropriate function or output the appropiate messages to the user
//after execution of the various statements, the program will then assign pointer_acc to either the memory address of checking or savings to pass into the various functions to utilize
    if (input == 1)
    {
        cout << "\nYou have selected to perform a DEPOSIT\n";
        cout << "Please select an account to access: \n";
        cout << "[1] Checking\n";
        cout << "[2] Savings\n";
        cin >> input;
        while (input != 1 && input !=2)
        {
            cout << "\nPlease enter a valid input: \n";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input;
            if (input == 1 || input ==2) break;
         }
//account balance is printed for the user before & after a functionality is called vs. printed in the function as to enhance UX
//if printed in function, general statement of "Current balance: " & "New balance: " would be utilized, which doesn't tell the user what account that balance is for
//user would have to rely on memory of what account they selected; forego this to improve UX by outputting in main to include addition of what account balance user is being shown
             if (input == 1)
             {
                 pointer_acc = &checking;
                 cout << "\nCurrent checking balance: $" << *pointer_acc <<"\n";
                 deposit(pointer_acc);
                 cout << "\nNew checking balance: $"<< *pointer_acc <<"\n";
                 rt();
             }
             else if (input == 2)
             {
                 pointer_acc = &savings;
                 cout << "\nCurrent savings balance: $" << *pointer_acc <<"\n";
                 deposit(pointer_acc);
                 cout << "\nNew savings balance: $" << *pointer_acc <<"\n";
                 rt();
             }
    }
    else if (input == 2)
    {
        cout << "\nYou have selected to perform a WITHDRAWAL\n";
        cout << "Please select an account to access: \n";
        cout << "[1] Checking\n";
        cout << "[2] Savings\n";
        cin >> input;
        while (input != 1 && input !=2)
        {
            cout<< "\nPlease enter a valid input: \n";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input;
            if (input == 1 || input ==2) break;
        }
        if (input == 1)
        {
            pointer_acc = &checking;
            cout << "\nCurrent checking balance: $" << *pointer_acc <<"\n";
            withdrawal(pointer_acc);
            cout << "\nNew checking balance: $" << *pointer_acc << "\n";
            rt();
        }
        else if (input == 2)
        {
            pointer_acc = &savings;
            cout << "\nCurrent savings balance: $" << *pointer_acc <<"\n";
            withdrawal(pointer_acc);
            cout << "\nNew savings balance: $" << *pointer_acc <<"\n";
            rt();
        }
    }
    else if (input == 3)
    {
        cout << "\nYou have selected to perform a TRANSFER\n";
        cout << "\nPlease select an account to transfer funds from: \n";
        cout << "[1] Checking\n";
        cout << "[2] Savings\n";
        cin >> input;
        while (input != 1 && input != 2)
        {
            cout << "\nPlease enter a valid input: \n";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input;
            if (input == 1 || input ==2) break;
        }
//pointer_acc2 is utilized in both statements to help assign the memory address of the left over account for utilization in the transfer function
//submenu only shows savings to skip redundancy in allowing the user to transfer funds from checking to checking
        if (input == 1) 
        {
            cout << "\nPlease select an account to transfer funds to: \n";
            cout << "[1] Savings\n";
            cin >> input;
            while (input != 1)
            {
                cout << "\nPlease enter a valid input: \n";
                cin.clear();
                cin.ignore(100, '\n');
                cin >> input;
                if (input == 1) break;
            }
            pointer_acc = &checking;
            pointer_acc2 = &savings;
            cout << "\nCurrent checking balance: $" << *pointer_acc << "\n";
            cout << "Current savings balance: $" << *pointer_acc2 << "\n";
            transfer(pointer_acc, pointer_acc2);
            cout << "\nTransfer successful\n";
            cout << "\nNew checking balance: $" << *pointer_acc <<"\n";
            cout << "New savings balance: $" << *pointer_acc2 << "\n";
            rt();
        }            
//submenu only shows checking to skip redundancy in allowing the user to transfer funds from savings to savings
        if (input == 2)
        {
            cout << "\nPlease select an account to transfer funds to: \n";
            cout << "[1] Checking\n";
            cin >> input;
            while (input != 1)
            {
                cout << "\nPlease enter a valid input: \n";
                cin.clear();
                cin.ignore(100, '\n');
                cin >> input;
                if (input == 1) break;
            }
            pointer_acc = &savings;
            pointer_acc2 = &checking;
            cout << "\nCurrent savings balance: $" << *pointer_acc << "\n";
            cout << "Current checking balance: $" << *pointer_acc2 << " \n";
            transfer(pointer_acc, pointer_acc2);            
            cout << "\nTransfer successful \n";
            cout << "\nNew savings balance: $" << *pointer_acc << "\n";
            cout << "New checking balance: $" << *pointer_acc2 << " \n";
            rt();
        }    
    }
//based on input given, program outputs the value stored in checking or savings utilizing a pointer for the user to review
    else if (input == 4)
    {
        cout << "\nYou have selected to perform a BALANCE INQUIRY\n";
        cout << "Please select an account to access: \n";
        cout << "[1] Checking\n";
        cout << "[2] Savings\n";
        cin >> input;
        while (input != 1 && input !=2)
        {
            cout<< "\nPlease enter a valid input: \n";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input;
            if (input == 1 || input ==2) break;
        }
        if (input == 1)
        {
            pointer_acc = &checking;
            cout << "\nCurrent checking balance: $" << *pointer_acc <<"\n";
            rt();
        }
        else if (input == 2)
        {
            pointer_acc = &savings;
            cout << "\nCurrent savings balance: $" << *pointer_acc <<"\n";
            rt();
        }
    }
//based on input given by user, input is passed into c_x to exchange USD to one of four currencies
    else if (input == 5)
    {
        cout << "\nYou have selected to perform a CURRENCY EXCHANGE\n";
        cout << "Please select a currency to convert USD to: \n";
        cout << "[1] CAD\n";
        cout << "[2] MXN\n";
        cout << "[3] EUR\n";
        cout << "[4] VND\n";
        cin >> input;
        while (input != 1 && input != 2 && input != 3 && input != 4)
        {
            cout<< "\nPlease enter a valid input: \n";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input;
            if (input == 1 || input == 2 || input == 3 || input == 4) break;
        }
        if (input == 1)
        {
            c_x(input);
        }
        else if (input == 2)
        {
            c_x(input);
        }
        else if (input == 3)
        {
            c_x(input);
        }
        else if (input == 4)
        {
            c_x(input);
        }
    }
    else if (input == 6)
    {
        quit();
    }
    return (0);
}

//based on input, function with either call for main to restart operation or call for quit to terminate the program
//rt is defined after main so that main can be called for from rt
//rt is called for in balance inquiry and all of the functions above to allow user to return or terminate from any transaction
void rt() 
{
    cout << "\nWould you like to return to the main menu or exit current session?\n";
    cout << "[1] RETURN\n";
    cout << "[2] EXIT\n";
    cin >> input;
    while (input != 1 && input != 2)
    {
        cout << "Please enter a valid input: \n";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input;
        if (input == 1 || input == 2) break;
    }
    if (input == 1)
    {
        main();
    }
    else if (input == 2)
    {
        quit();
    }
}
