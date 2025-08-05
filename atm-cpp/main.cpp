#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int balance = 1000;
    int choice;
    
    cout << "[1] Watch balance" << endl;
    cout << "[2] Withdraw money" << endl;
    cout << "[3] Put money" << endl;
    cout << "[4] Exit\n" << endl;
    
    while (true){
    cout << "Enter number: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "Your balance: " << balance << endl;
            break;
            
        case 2: {
            int withdraw_count;
            cout << "Enter withdraw count:";
            cin >> withdraw_count;
            balance = balance - withdraw_count;
            cout << "\nYour current balance: " << balance << endl;
            break;
        }
        case 3: {
            int topup_count;
            cout << "Enter topup count:";
            cin >> topup_count;
            balance = balance + topup_count;
            cout << "\nYour current balance: " << balance << endl;
            break;
        }
        case 4: {
            cout << "Existing..." << endl;
            return 0;
        }
        }
    }
    
    return 0;
}
