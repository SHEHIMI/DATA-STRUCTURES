/*------------------------------------------------------------------------
 Implementation of Tree class.
------------------------------------------------------------------------*/

/*
 * File:   Tree.cpp
 * Author: Mohamad shehimi - Omar lawand
 *
 * Created on April 30, 2021, 4:00 PM
 */

#include "Tree.h"
#include "Account.h"
#include "Transaction.h"

using namespace std;

//--- Definition of constructor
Tree::Node::Node(Account data) {
    this->data = data;
    nextSibling = NULL;
    firstChild = NULL;
}

//optional
Tree::Tree(int numOfLevels, string descriptions[], int balances[]) {
    
    this->levels[1] = 1;

    numOfMainAccounts = 0;

    //initialize the first main account and its 4 sub-accounts
    addMainAccount(descriptions, balances);

    for (int i = 1; i < numOfLevels; i++) {
        addSubAccount(1, balances[i - 1], descriptions[i]);
    }
}

Tree::Tree(string descriptions[], int balances[]) {

    //default level for the tree is 4
    this->levels[1] = 1;

    numOfMainAccounts = 0;

    addMainAccount(descriptions, balances);
}

//--- Definition of addMainAccount
void Tree::addMainAccount(string descriptions[], int balances[]) {

    if (numOfMainAccounts == 9) {
        cout << "Main account limit reached." << endl;
        return;
    }

    //case of no existing main accounts
    if (numOfMainAccounts == 0) {
        //initializing main account
        Account first(1, 0, descriptions[0]);

        //initialize myRoot
        myRoot = new Node(first);

        //placing sub accounts in all the levels
        for (int i = 0; i < 3; i++) {
            //initializing sub accounts
            addSubAccount(1, balances[i], descriptions[i + 1]);
        }

        numOfMainAccounts++;
        return;
    }

    //case of adding extra main accounts

    NodePtr mainPointer = myRoot;

    //traversing to last existing account
    for (int i = 1; i < numOfMainAccounts; i++) {
        mainPointer = mainPointer->nextSibling;
    }

    int newAccountId = mainPointer->data.getAccountNumber() + 1;

    //creating new main account
    Account newMainAccount(newAccountId, 0, descriptions[0]);
    
    levels[newAccountId] = 1;

    mainPointer->nextSibling = new Node(newMainAccount);

    for (int i = 0; i < 3; i++) {
        //initializing sub accounts
        addSubAccount(newAccountId, balances[i], descriptions[i + 1]);
    }

    numOfMainAccounts++;
}

//--- Definition of addSibling
void Tree::addSibling(int accountId, int accountBalance, string description) {

    int numOfDigits = 0,
       temp = accountId,
        firstDigit=0;

    //get the number of digits of the id
    while (temp != 0) {
        //getting the id of the main account
        firstDigit = temp;

        temp /= 10;
        ++numOfDigits;
    }

    //point to the root 
    NodePtr mainPointer = myRoot;

    //traversing to the correct main account
    for (int i = 1; i < firstDigit; i++) {
         mainPointer = mainPointer->nextSibling;
    }

    //traverse to the right levels
    for (int i = 1; i < numOfDigits; i++) {
        mainPointer = mainPointer->firstChild;
    }

    //pointers to traverse siblings
    NodePtr siblingPointer = mainPointer->nextSibling;

    //creating new account
    Account newAccount(accountId, accountBalance,description);

    //node to be added into the tree
    NodePtr newNode = new Node(newAccount);

    //case of no existing siblings
    if (siblingPointer == NULL) {
        //adding the node into the tree
        mainPointer->nextSibling = newNode;
        

        //update sub-account balance
        int newBalance = getAccountBalance(mainPointer->data.getAccountNumber())
                          + accountBalance;
        putAccountBalance(mainPointer->data.getAccountNumber(), newBalance);

        //updating the balance of main account
        int newMainBalance = getAccountBalance(firstDigit) + accountBalance;
        putAccountBalance(firstDigit, newMainBalance);
 
        return;
    }

    //case of adding new sibling before existing first sibling
    if (accountId < siblingPointer->data.getAccountNumber()) {
        //adding the node into the tree
        
        newNode->nextSibling = siblingPointer;

        //updating the pointer in the tree
        mainPointer->nextSibling = newNode;

        //updating balance of the sub account
        int newBalance = getAccountBalance(mainPointer->data.getAccountNumber())
                            + accountBalance;
        putAccountBalance(mainPointer->data.getAccountNumber(), newBalance);

        //updating the balance of main account
        int newMainBalance = getAccountBalance(firstDigit) + accountBalance;
        putAccountBalance(firstDigit, newMainBalance);

        return;
    }

    //next sibling of siblingPointer
    NodePtr secondSibling = siblingPointer->nextSibling;

    //case of adding a sibling in between the first and last
    while (secondSibling != NULL) {
        if (accountId > siblingPointer->data.getAccountNumber() && 
                accountId < secondSibling->data.getAccountNumber()) {
         
            newNode->nextSibling = secondSibling;
            siblingPointer->nextSibling = newNode;
         
            //updating balance of the sub account
            int newBalance = 
                      getAccountBalance(mainPointer->data.getAccountNumber()) + 
                      accountBalance;
            putAccountBalance(mainPointer->data.getAccountNumber(), newBalance);

            //updating the balance of main account      
            int newMainBalance = getAccountBalance(firstDigit) + accountBalance;
            putAccountBalance(firstDigit, newMainBalance);

            return;
        }

        siblingPointer = siblingPointer->nextSibling;
        secondSibling = secondSibling->nextSibling;
    }

    //case of adding a sibling at the end 
    siblingPointer->nextSibling = newNode;
   
    //updating balance of the sub account
    int newBalance = getAccountBalance(mainPointer->data.getAccountNumber()) +
                                                                 accountBalance;
    putAccountBalance(mainPointer->data.getAccountNumber(), newBalance);

    //updating the balance of main account
    int newMainBalance = getAccountBalance(firstDigit) + accountBalance;
    putAccountBalance(firstDigit, newMainBalance);
}

//--- Definition of addSubAccount
void Tree::addSubAccount(int mainAccountId, int balance, string description) {

    NodePtr mainPointer = myRoot;
    
    //traversing to the specified main account
    for (int i = 1; i < mainAccountId; i++) {
        mainPointer = mainPointer->nextSibling;
    }

    //traversing to the last sub account
    while (mainPointer->firstChild != NULL) {
        mainPointer = mainPointer->firstChild;
    }

    //integer representing the number of the sub Account to be added 
    int subAccountID = mainPointer->data.getAccountNumber() * 10;

    //creating new sub account
    Account newAccount(subAccountID, balance, description);

    //creating a node for the new sub account
    NodePtr newNode = new Node(newAccount);

    //point to the newly created sub Account
    mainPointer->firstChild = newNode;

    //update the total balance in the main account
    int newMainBalance = getAccountBalance(mainAccountId) + balance;
    putAccountBalance(mainAccountId, newMainBalance);

    //increment the levels
    levels[mainAccountId]++;

}

//--- Definition of addTransaction
void Tree::addTransaction(Transaction transObj, int accountId) {

    int numOfDigits = 0,
        temp = accountId,
        firstDigit;

    //get the number of digits of the id
    while (temp != 0) {
        //getting the id of the main account
        firstDigit = temp;

        temp /= 10;
        ++numOfDigits;
    }

    // point to the root
    NodePtr mainPointer = myRoot;

    //traverse the tree to find the MAIN Account 
    for (int i = 1; i < firstDigit; i++) {
        mainPointer = mainPointer->nextSibling;
    }

    //find the sub account
    for (int i = 1; i < numOfDigits; i++) {
        mainPointer = mainPointer->firstChild;
    }

    //To store if sub account or sibling, true if sub account, false if sibling
    bool sub_OR_sibling;

    //check if it's a sub-account  
    if (mainPointer->data.getAccountNumber() == accountId) {
        sub_OR_sibling = true;
    }
    else {
        sub_OR_sibling = false;
    }

    if (transObj.getWithdraw_deposit()) {

        //case of deposit

        //case of sub account 
        if (sub_OR_sibling) {
            //updating the sub-account
            mainPointer->data.addTransaction(transObj);

            //update the main account balance
            int newBalance = transObj.getAmount() + 
                                getAccountBalance(firstDigit);
            putAccountBalance(firstDigit, newBalance);

        }
        else {
            //case of sibling 

            //updating the sibling
            NodePtr siblingAccount = getNode(accountId);
            siblingAccount->data.addTransaction(transObj);

            //update the sub-account balance
            int newSubBalance = transObj.getAmount() + 
                                        mainPointer->data.getAccountBalance();
            putAccountBalance(mainPointer->data.getAccountNumber(), 
                                                        newSubBalance);

            //updating the main account balance
            int newMainBalance = getAccountBalance(firstDigit) + 
                                                        transObj.getAmount();
            putAccountBalance(firstDigit, newMainBalance);
        }
    }
    else {
        //case of withdraw

        //withdraw from sub account
        if (sub_OR_sibling) {
            //case of withdrawal is greater than total balance
            if (transObj.getAmount() > mainPointer->data.getAccountBalance()) {
                cout << "cannot perform a transaction, " <<
                        "not enough balance in account!" << endl;
                return;
            }

            int sum = 0;
            //get the sum of balances of siblings
            if(mainPointer->nextSibling != NULL){
                NodePtr siblingPointer = mainPointer->nextSibling;

                while (siblingPointer->nextSibling != NULL) {
                    sum += siblingPointer->data.getAccountBalance();
                    siblingPointer = siblingPointer->nextSibling;
                }

            //case of withdrawal of amount is greater than the sum of siblings
                if (transObj.getAmount() > sum) {
                    cout << "cannot perform a transaction, " <<
                         "not enough balance in account!" << endl;
                    return;
                }
            }

            //update the balance of sub-account
            mainPointer->data.addTransaction(transObj);

            //update the balance of main account
            int newBalance = getAccountBalance(firstDigit) - 
                                                        transObj.getAmount();
            putAccountBalance(firstDigit, newBalance);
        }
        else {

            //case of sibling 
            NodePtr siblingAccount = getNode(accountId);

            //case of withdrawal is greater than total balance
            if (transObj.getAmount() > siblingAccount->data.getAccountBalance())
            {
                cout << "cannot perform a transaction, " <<
                        "not enough balance in account!" << endl;
                return;
            }

            //update sibling account balance
            siblingAccount->data.addTransaction(transObj);

            //update sub-account balance
            int newSubBalance = 
                       getAccountBalance(mainPointer->data.getAccountNumber()) - 
                       transObj.getAmount();
            putAccountBalance(mainPointer->data.getAccountNumber(), 
                                                                newSubBalance);

            //update the balance of main account
            int newMainBalance = getAccountBalance(firstDigit) - 
                                                          transObj.getAmount();
            putAccountBalance(firstDigit, newMainBalance);
        }
    }
}

//--- Definition of checkForNode
bool Tree::checkForNode(int accountId) {

    // point to the root
    NodePtr mainPointer = myRoot;

    //traverse the tree to check if node exists
    while (mainPointer != NULL) {
        NodePtr accountPointer = mainPointer;
        //traversing the sub accounts
        for (int i = 0; i < levels[mainPointer->data.getAccountNumber()]; i++) {
            // checking the sub accounts of the  main account
            if (accountId == accountPointer->data.getAccountNumber())
                return true;

            NodePtr siblingPointer = accountPointer->nextSibling;
            //traverse the siblings of a sub account
            while (siblingPointer != NULL) {
                if (siblingPointer->data.getAccountNumber() == accountId)

                    return true;

                siblingPointer = siblingPointer->nextSibling;
            }

            accountPointer = accountPointer->firstChild;
        }
        mainPointer = mainPointer->nextSibling;
    }

    //if node doesn't exist return false
    return false;
}

//--- Definition of getNode
Tree::NodePtr Tree::getNode(int accountId) {

    // point to the root
    NodePtr mainPointer = myRoot;

    //traverse the tree to check if node exists
    while (mainPointer != NULL) {
        NodePtr accountPointer = mainPointer;

        //traversing the sub accounts
        for (int i = 0; i < levels[mainPointer->data.getAccountNumber()]; i++) {
            // checking the sub accounts of the  main account
            if (accountId == accountPointer->data.getAccountNumber())
                return accountPointer;

            NodePtr siblingPointer = accountPointer->nextSibling;
            //traverse the siblings of a sub account
            while (siblingPointer != NULL) {
                if (siblingPointer->data.getAccountNumber() == accountId)

                    return siblingPointer;

                siblingPointer = siblingPointer->nextSibling;
            }

            accountPointer = accountPointer->firstChild;
        }
        mainPointer = mainPointer->nextSibling;
    }

}

//--- Definition of putAccountBalance
void Tree::putAccountBalance(int accountId, int accountBalance) {
    NodePtr account = getNode(accountId);

    account->data.setAccountBalance(accountBalance);
}

//--- Definition of getAccountBalance
int Tree::getAccountBalance(int accountId) {
    NodePtr account = getNode(accountId);

    return account->data.getAccountBalance();

}

//--- Definition of getNumOfMainAccounts
int Tree::getNumOfMainAccounts(){
    return numOfMainAccounts;
}

//--- Definition of displayNode
void Tree::displayNode(int accountId, ostream& out) {
    //check if node exists
    if (!checkForNode(accountId)) {
        cout << "Account doesn't exist" << endl;

        return;
    }

    //point to the Account/Node to be displayed
    NodePtr account = getNode(accountId);

    account->data.display(out);
}

//--- Definition of displayMainsInfo
void Tree::displayMainsInfo() {
    
    NodePtr mainsPointer = myRoot;
    
    while(mainsPointer!=NULL){
        
        cout <<mainsPointer->data.getAccountNumber()<< " : " << 
                mainsPointer->data.getAccountDescription() << endl;
        mainsPointer = mainsPointer->nextSibling;
    }
}

//--- Definition of displayMainAccount
void Tree::displayMainAccount(int mainAccountId) {
    
   if(!checkForNode(mainAccountId)){
       cout<<"Account doesn't exist!"<<endl;
       return;
     }
   
    //point to the root
    NodePtr mainPointer = myRoot;
    
    //get the main account to display
    for (int i = 1; i < mainAccountId; i++) {
        mainPointer = mainPointer->nextSibling;
    }

    //display the main account
    cout <<"MAIN no." << mainAccountId << ": "
         << mainPointer->data.getAccountDescription() << "["
         << mainPointer->data.getAccountBalance() << "$]" << endl << endl;

    for (int i = 0; i < levels[mainAccountId] - 1; i++) {
        // To reach the sub accounts
        mainPointer = mainPointer->firstChild;

        cout << mainPointer->data.getAccountNumber() << ":     "
             << mainPointer->data.getAccountDescription() << "["
             << mainPointer->data.getAccountBalance() << "$]";

        //display siblings  
        if(mainPointer->nextSibling != NULL){
            cout<< " -------- ";
            
            NodePtr siblingPointer = mainPointer->nextSibling;
            
            while (siblingPointer != NULL) {

                cout << siblingPointer->data.getAccountNumber() << ": "
                    << siblingPointer->data.getAccountDescription() << "["
                    << siblingPointer->data.getAccountBalance() << "$]";

                if (siblingPointer->nextSibling != NULL) {
                    cout << "  ------------- ";
                }

                siblingPointer = siblingPointer->nextSibling;
            }
        }
        cout << endl;
    }
}

