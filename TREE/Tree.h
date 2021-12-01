/*------------------------------------------------------------------------
 Header file for Tree class. 
 purpose: To create An abstract data type of a modified binary tree to simulate
 an accounting system.  
 
 Basic operations are:
     constructor:             initializes a tree object
     two-arg constructor:     initializes a default tree object
     addMainAccount:          Adds a main account to the tree 
     addSubAccount:           Adds a sub account 
     addTransaction:          Adds a transaction on a specific account
     DisplayNode:             Displays a node (Account)
     addSibling:              Adds a sibling to a sub-Account
     displayMainAccount:      Displays a Main Account
     displayMainsInfo:        Display the descriptions of all main accounts
 ------------------------------------------------------------------------*/

/* 
 * File: Tree.h
 * Authors: Mohamad shehimi - Omar lawand
 *
 * Created on April 30, 2021, 4:00 PM
 */

#ifndef TREE_H
#define TREE_H
#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <string>
using namespace std;

class Tree {
    
private:
    
    class Node{
        
    public :
        /***** Node class constructor *****/
        
        /*---------------------------------------------------------------------
          Construct a Node object; Takes an Account object as parameter

          Precondition: none
          Post-condition: A node filled with account data is created.
          firstChild, nextSibling, prevSibling are all set to NULL.
        ----------------------------------------------------------------------*/
        Node(Account data);
        
        /**Data members of class Node**/
        
        Account data;
	Node * firstChild;//points to the next sub account
        Node * nextSibling;//points to  next sibling node
      
    };
    typedef Node* NodePtr;
    
     /******** Function Members ********/
    
public:
    
    /***** class constructor *****/
    
    /*------------------------------------------------------------------------
      Construct an Tree object; Takes an integer representing the number of 
      levels,string array of descriptions and integer array of balances

      Precondition: none
      Post-condition: A tree with custom number of levels has been constructed.
     -----------------------------------------------------------------------*/
    Tree(int numOflevels, string descriptions[], int balances[]); 
    
    /*****two-arg constructor *****/ 
    
    /*------------------------------------------------------------------------
      Construct a default Tree object;string array of descriptions and integer 
      array of balances

      Precondition: descriptions and balances array not null
      Post-condition: A tree with default number(4) of levels has been 
      constructed
    -----------------------------------------------------------------------*/
    Tree(string descriptions[], int balances[]);
    
    /*------------------------------------------------------------------------
      Adds a Main Account to the tree;Takes a string array of descriptions and 
      integer array of balances

      Precondition: balances is valid and descriptions are not null
      Post-condition: A main account is added to the tree
    -----------------------------------------------------------------------*/
    void addMainAccount(string descriptions[], int balances[]);
    
    /*****Add sibling account operation *****/
    /*------------------------------------------------------------------------
      Adds a sibling to an Account;
      Takes an integer balance and string description as parameter.

      Precondition: accountId doesn't exist, account balance is valid, string
      is not null.
      Post-condition: A sibling account has been added to the tree
     -----------------------------------------------------------------------*/
    void addSibling(int accountId, int accountBalance, string description);
     
    /***** Add a sub account operation*****/
    /*------------------------------------------------------------------------
      Adds a sub-account under a main account;
      Takes an integer balance,string description as parameter

      Precondition: mainAccountId exists,balance is valid, string is not null
      Post-condition: A sub account account has been added to the tree
     -----------------------------------------------------------------------*/
    void addSubAccount(int mainAccountId, int balance, string description);
     
    /*****Add a Transaction operation*****/
    /*------------------------------------------------------------------------
      Adds a transaction to be made from sub account or a sibling account;
      Takes as parameter an integer representing the Id of the account  
      
      Precondition: accountId exists and it's not a main account
      Post-condition: A transaction is done on the account
     -----------------------------------------------------------------------*/
    void addTransaction(Transaction transObj, int accountId);
     
     /*****Check for Node operation*****/
    /*------------------------------------------------------------------------
      Checks if a Node exists or not; Takes an integer as parameter
      
      Precondition: integer is not a negative number
      Post-condition: returns true if Node exists,false otherwise
     -----------------------------------------------------------------------*/
    bool checkForNode(int accountId);
    
     /*****Get a Node operation*****/
    /*------------------------------------------------------------------------
     Searches and returns a pointer to a specific Node(Account)
      
      Precondition:Account should exist
      Post-condition:The Node pointer is returned
     -----------------------------------------------------------------------*/
    NodePtr getNode(int accountId) ;
    
     /*****Set balance operation*****/
    /*------------------------------------------------------------------------
      Inserts a balance for an account; Takes an integer accountId and integer
      balance as parameters parameters.
      
      Precondition: account exists
      Post-condition: account balance is set
     -----------------------------------------------------------------------*/
    void putAccountBalance(int accountId, int balance);    
    
     /*****Get balance operation*****/
    /*------------------------------------------------------------------------
      Gets the balance of a specific account; Takes an integer accountId as 
      parameters.
      
      Precondition: account exists
      Post-condition: account balance is returned
     -----------------------------------------------------------------------*/
    int getAccountBalance(int accountId);
     
    /*****Get Number of Main Accounts operation*****/
    /*------------------------------------------------------------------------
      Returns the total number of existing main accounts;
      
      Precondition: none.
      Post-condition: numOfMainAccounts is returned
     -----------------------------------------------------------------------*/
    int getNumOfMainAccounts();
    
    /*****Display a Node operation*****/
    /*------------------------------------------------------------------------
      Displays a specific Node(Account)
      
      Precondition:Account should exist
      Post-condition:The node details are displayed
     -----------------------------------------------------------------------*/
    void displayNode(int accountId, ostream& out);
     
    /*****Display Mains info operation*****/
    /*------------------------------------------------------------------------
      Displays the information of the main accounts
      
      Precondition: none
      Post-condition: The description and number of main accounts is displayed
     -----------------------------------------------------------------------*/
     
    void displayMainsInfo();
     
    /*****Display a tree operation*****/  
    /*------------------------------------------------------------------------
      Displays the tree in a formatted structure; Takes an ostream as parameter
      
      Precondition: Tree is not empty
      Post-condition: The tree is displayed
     -----------------------------------------------------------------------*/
    void displayMainAccount(int MainAccountId);
         
private:
  NodePtr  myRoot;     //points to the MAIN(first) account 
  int levels[10],      //represents the number of levels in each main account, index 0 is not used
  numOfMainAccounts;   //number of main accounts present
};

#endif /* TREE_H */

