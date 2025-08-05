#include <iostream>
#include <fstream>
#include "config.h"

using namespace std;


int main(int argc, const char * argv[]) {
    bool is_auth = false;
    int pin = 1337;
    int balance = 1000;
    int choice;
    int incorrect_tries = 0;
    
    // authorization
    if (is_auth == false){
        int entered_pin;
        while (true){
            if (incorrect_tries >= 3) {
                cout << "You eneter 3+ incorrect pin.\Exiting...\n";
                return 1;
            }
            
            cout << "Enter pin for start use program: ";
            cin >> entered_pin;
            if (entered_pin == pin)
            {
                is_auth = true;
                break;
            }
            else{
                cout << "\nYou enetered incorrect pin, try again\n";
                incorrect_tries += 1;
            }
        }
    }
    
    // read balance from file
    ifstream file_in(BALANCE_FILE_PATH);
    if (file_in.is_open())
    {
        file_in >> balance;
    } else {
        cout << "\nNo balance file found. Using default balance: " << balance << endl;
    }
    
    cout << "[1] Watch balance" << endl;
    cout << "[2] Withdraw money" << endl;
    cout << "[3] Put money" << endl;
    cout << "[4] History" << endl;
    cout << "[5] Exit\n" << endl;
    
    // print menu and choice menu element
    while (true){
        cout << "Enter number: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Your balance: " << balance << endl;
                break;
            
            // WITHDRAW
            case 2: {
                int withdraw_count;
                cout << "Enter withdraw count:";
                cin >> withdraw_count;
                
                if (withdraw_count > balance){
                    cout << "You balance " << balance << " you wanna withdraw "<<withdraw_count << endl;
                }
                else{
                    balance = balance - withdraw_count;
                    
                    ofstream file_out(BALANCE_FILE_PATH);
                    file_out << balance;
                    file_out.close();
                    
                    ofstream history_file(HISTORY_FILE_PATH, ios::app);
                    history_file << "WITHDRAW: -" << withdraw_count << "\n";
                    history_file.close();
                    
                    cout << "\nYour current balance: " << balance << endl;
                }
                break;
            }
            
            // TOPUP
            case 3: {
                int topup_count;
                
                cout << "Enter topup count:";
                cin >> topup_count;
                
                balance = balance + topup_count;
                
                ofstream file_out(BALANCE_FILE_PATH);
                file_out << balance;
                file_out.close();
                
                ofstream history_file(HISTORY_FILE_PATH, ios::app);
                history_file << "TOPUP: +" << topup_count << "\n";
                history_file.close();
                
                cout << "\nYour current balance: " << balance << endl;
                break;
            }
            case 4: {
                ifstream history_file(HISTORY_FILE_PATH);
                if (history_file.is_open()) {
                    string line;
                    cout << "\n==== TRANSACTION HISTORY ====\n";
                    while (getline(history_file, line))
                    {
                        cout << line << endl;
                    }
                    cout << "=============================\n" << endl;
                    history_file.close();
                }
                else
                {
                    cout << "No transaction history found.\n";
                }
                break;
            }
                
            case 5: {
                cout << "Exiting..." << endl;
                return 0;
            }
            }
    }
    
    return 0;
}
