/* 
 * File:   main.cpp
 * Authors:mohamad shehimi-Omar lawand
 *
 * Created on April 27, 2021, 11:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"
#include "Account.h"
#include "Tree.h"
using namespace std;

/***** Print Menu Operation *****/
/*---------------------------------------------------------------------
 Prints out a menu of operations for the system

 Precondition: none
 Post-condition: A menu of operations is printed out
----------------------------------------------------------------------*/
int menu();

int main() {
    
    //for default levels
    string descriptions[4],
           description;
    
    int balances[3],
        choice,
        mainAccountId,
        balance,
        amount,
        accountId,
        wd_choice;
  
    Transaction trans; 
   
    cout << "Welcome to MOL accounting system." << endl;
    
    cout << "MOL created 3 sub accounts for the first main account" << endl
         << "Please fill this information:" << endl << endl;
    
    cout << "Please enter description for initial main account: ";
    getline(cin, descriptions[0]);

    cout << endl;
    
    string subAccountNumbers [] = {"first", "second", "third"};
    
    //prompt user to fill  default sub accounts info
    for(int i = 0; i < 3; i++){
        cout <<"Enter balance for " << subAccountNumbers[i] << " sub-account: ";
        cin  >> balances[i];
        
       while(balances[i] < 0){
            cout << "Invalid balance amount. Please enter again: ";
            cin >> balances[i];
        }
        
        cin.ignore();
        
        cout << "Enter description for " << subAccountNumbers[i] <<
                " sub-account: ";
        getline(cin, descriptions[i+1]);
        
        cout<<endl;
    }
    
    //creating initialized tree/system
    Tree system(descriptions, balances);
    
    system.displayMainAccount(1);
    
    cout << endl;         
                 
   //set the correct method to the selected choice
    do {
        choice = menu();
        
        switch (choice) {
            case 1:
                // add a main account
                
                cin.ignore();
                
                cout << "Please enter description for new main account: ";
                getline(cin, descriptions[0]);
                
                //initializing default sub accounts
                for(int i = 0; i < 3; i++){
                    
                    cout <<"Enter balance for " << subAccountNumbers[i] << 
                            " sub-account: ";
                    cin >> balances[i];
                    
                    while(balances[i] < 0){
                        cout << "Invalid balance amount. Please enter again: ";
                        cin >> balances[i];
                    }
                    
                    cin.ignore();
                    
                    cout << "Enter description for " << subAccountNumbers[i] <<
                            " sub-account: ";
                    getline(cin, descriptions[i+1]);
       
                    cout << endl;
                }
                
                //adding main account into the system
                system.addMainAccount(descriptions,balances);
                
                system.displayMainAccount(system.getNumOfMainAccounts());
                cout << endl;
                break;
               
            case 2:
                // add a sub-account
                
                //showing user basic information on main accounts
                system.displayMainsInfo();
                        
                cout << "Enter id of the main account you want to access: ";
                cin >> mainAccountId;
                
                while(!system.checkForNode(mainAccountId)){
                    cout << "Account doesn't exist. Please enter id again: ";
                    cin >> mainAccountId;
                }
                
                //showing user detailed info on chosen main account
                system.displayMainAccount(mainAccountId);
                
                cout << "Enter balance for the new sub-account: ";
                cin >> balance;
                
                while(balance < 0){
                    cout << "Invalid balance amount. Please enter again: ";
                    cin >> balance;
                }
                
                cin.ignore();
                
                cout << "Enter description for the new sub-account: ";
                getline(cin,description);
                
                system.addSubAccount(mainAccountId, balance, description);
                cout << endl;
                
                cout << "Main account after insertion: " << endl;
                system.displayMainAccount(mainAccountId);
                cout << endl;
                
                break;
                
            case 3:
                // add a sibling(branch)
                
                //showing user basic information on main accounts
                system.displayMainsInfo();
                
                cout << "Enter id of main account you want to access: ";
                cin >> mainAccountId;
                
                while(!system.checkForNode(mainAccountId)){
                    cout << "Account doesn't exist. Please enter id again: ";
                    cin >> mainAccountId;
                }
               
                system.displayMainAccount(mainAccountId);
                
                cout << endl;
                cout << "Enter id for this new account: ";
                cin >> accountId;
                
                while(system.checkForNode(accountId) || accountId >= 1 &&
                        accountId <= 9 || accountId < 0){
                    cout << "Invalid input. Please enter valid id: ";
                    cin >> accountId;
                }
               
//                while(accountId < 0 ){
//                    cout << "dr Hamid why input a negative value for account id?";
//                    cin >> accountId;
//                }
                
                cout << "Enter the balance of this account: ";
                cin >> balance;
                
                while(balance < 0){
                    cout << "Invalid balance amount. Please enter again: ";
                    cin >> balance;
                }
                
                cin.ignore();
                cout << "Enter the description: ";
                getline(cin,description);
                
                system.addSibling(accountId, balance, description);
                
                cout << endl;
                
                cout << "Main account after insertion: " << endl;
                system.displayMainAccount(mainAccountId);
                cout << endl;
                
                break;
                
            case 4:
                // Add a transaction
                                 
                //showing user basic information on main accounts
                system.displayMainsInfo();
                
                cout << "Enter id of main account you want to access: ";
                cin >> mainAccountId;
                
                while(!system.checkForNode(mainAccountId)){
                    cout << "Account doesn't exist. Please enter id again: ";
                    cin >> mainAccountId;
                }
                
                cout << endl;
                
                system.displayMainAccount(mainAccountId);
                
                cout << endl;
                
                cout << "Enter the ID of the account you want to do a "
                     << "transaction on: ";
                cin >> accountId;
                
                while(!system.checkForNode(accountId) || accountId >= 1 &&
                        accountId <= 9){
                    cout << "Account doesn't exist. Please enter id again: ";
                    cin >> accountId;
                }
                
                cin.ignore();
                
                cout << "Enter the description of the transaction: ";
                getline(cin,description);
                        
                trans.setDescription(description);
                
                cout << "Do you want to withdraw or deposit?" << endl
                     << "1 for withdraw, 2 for deposit: ";
                cin >> wd_choice;
                    
                while(wd_choice > 2 || wd_choice < 0){
                    cout << "enter a valid choice 1 or 2!";
                    cin >> wd_choice;
                }
                
                if(wd_choice == 1){
                    trans.setWithdraw_deposit(false);
                }
                else if(wd_choice == 2){
                    trans.setWithdraw_deposit(true);
                }
                     
                cout << "Enter the amount needed: ";
                cin >> amount;
                trans.setAmount(amount);
 
                system.addTransaction(trans, accountId);
                
                cout << endl;
                
                system.displayNode(accountId, cout);
                
                cout << endl;
                
                break;
               
            case 5:
                    
                //showing user basic information on main accounts
                system.displayMainsInfo();
                        
                cout << "Enter id of the main account you want to access: ";
                cin >> mainAccountId;
                
                while(!system.checkForNode(mainAccountId)){
                    cout << "Account doesn't exist. Please enter id again: ";
                    cin >> mainAccountId;
                }
                
                //showing user detailed info on chosen main account
                system.displayMainAccount(mainAccountId);
                
                cout << endl;
                cout << "Enter id of account you want to view: ";
                cin >> accountId;
                 
                while(!system.checkForNode(accountId) || accountId >= 1 && accountId <= 9 || accountId < 0){
                    cout << "Invalid input. Please enter valid id: ";
                    cin >> accountId;
                }
                
//                while(accountId < 0){
//                    cout << "dr Hamid why input a negative value for account id?";
//                    cin >> accountId;
//                }
                
                system.displayNode(accountId, cout);
                cout << endl;
                
                break;

            case 6:
                cout << "Enter id of main account you want to view: ";
                cin >> mainAccountId;
                
                system.displayMainAccount(mainAccountId);
                cout << endl;
                
                break;
                
            case 7:
                break;           
        }
        
    } while (choice != 7);
    
    cout<<"Thank you for using MOL accounting system! "<<endl
        <<" System shutting down... "<<endl
        <<" Power off."<<endl;
    
    return 0;
}

int menu() {
    int choice;
    
    cout << "Choose one of the following choices:" << endl
         << "Press the corresponding number" << endl
         << "1. To create a Main Account" << endl           
         << "2. To create a sub-account" << endl
         << "3. To create a branch(sibling) for a sub account"<< endl
         << "4. To make a transaction " << endl
         << "5. Display information of a specific account" << endl
         << "6. To display a Main Account " << endl
         << "7. To quit" << endl
         << "Your choice: ";
    
    cin >> choice;
    
    while (choice < 1 || choice > 7) {
        cout << "please enter a valid number between 1 and 7!";
        cin >> choice;
    }
    
    cout << endl;
    
    return choice;
}

