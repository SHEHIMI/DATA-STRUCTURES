/*------------------------------------------------------------------------
 Header file for Account class. 
 This file defines basic operations for an account in an accounting system.
 It contains the account number, balance and the various transactions made
 with this account.
 
 Basic operations are:
    constructor:           creates an Account object
    setAccountNumber:      Sets account number
    getAccountNumber:      Returns account number
    setAccountBalance:     Sets account balance
    getAccountBalance:     Returns account balance
    setTransactions:       Sets vector of transactions
    getTransactions:       Returns vector of transactions
    addTransactions:       Adds a transaction made by the account
    setAccountDescription: Adds a purpose for the Account being made
    getAccountDescription: Returns  a description of the Account.
    display:               Displays account details
    operator<<:            overloaded output operator
------------------------------------------------------------------------*/

/* 
 * File:   Account.h
 * Author: mohamad shehimi-Omar lawand
 *
 * Created on 26 April 2021, 20:52
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <iostream>
#include "Transaction.h"
#include <string>

using namespace std;

class Account {
public:
    /******** Function Members ********/

    /***** class constructor *****/

    /*------------------------------------------------------------------------
      Construct an Account object.Takes integers accountNumber and balance and 
      a string description as  parameters 

      Precondition:   Account number and balance should be valid.
      Post-condition: Account has been initialized
    -----------------------------------------------------------------------*/
    Account(int accountNumber, int accountBalance,string desc);
    
    /*------------------------------------------------------------------------
      Construct an Account object.Takes an accountNumber as parameter

      Precondition: account number should be valid
      Post-condition: Account has been initialized
    -----------------------------------------------------------------------*/
    Account(int accountNumber);
    
    /*------------------------------------------------------------------------
      Construct an empty Account object.

      Precondition:  none
      Post-condition: Account has been initialized
    -----------------------------------------------------------------------*/
    Account();
    
    /***** set account number operation *****/
    /*----------------------------------------------------------------------
     Sets the accountNumber(ID)

     Precondition:   sent account object should not be null
     Post-condition: object is copied
    -----------------------------------------------------------------------*/
    void setAccountNumber(int accountNumber);

    /***** get account number operation *****/
    /*----------------------------------------------------------------------
     returns the account number

    Precondition: none
    Post-condition: Account number is returned
    -----------------------------------------------------------------------*/
    int getAccountNumber();

    /***** set account balance operation *****/
    /*----------------------------------------------------------------------
     sets the account balance;takes a positive integer parameter 

    Precondition: account balance should be positive integer
    Post-condition: The account balance is set
    -----------------------------------------------------------------------*/
    void setAccountBalance(int accountBalance);

    /***** get account balance operation *****/
    /*----------------------------------------------------------------------
     returns the balance of the Account

    Precondition:   none
    Post-condition: The Account balance is returned
    -----------------------------------------------------------------------*/
    int getAccountBalance();

    /***** set transactions operation *****/
    /*----------------------------------------------------------------------
     Sets the transactions ; Takes a vector of all transactions performed

    Precondition:   none
    Post-condition: The transactions are set 
    -----------------------------------------------------------------------*/
    void setTransactions(vector<Transaction> accountTransactions);

    /***** get transactions operation *****/
    /*----------------------------------------------------------------------
     returns the vector containing the transactions

    Precondition:   none
    Post-condition: The vector container of transactions is returned 
    -----------------------------------------------------------------------*/
    vector<Transaction> getTransactions();

    /***** add a transaction operation *****/
    /*----------------------------------------------------------------------
     Adds a transaction made by the Account;Takes a transaction object as parameter

    Precondition:   Transaction object not null
    Post-condition: A transaction is recorded
    -----------------------------------------------------------------------*/
    void addTransaction(Transaction T);

    /*****Get Account description operation *****/
    /*----------------------------------------------------------------------
     Returns The description/purpose of the account

    Precondition:   none
    Post-condition: Description of the account is returned
    -----------------------------------------------------------------------*/
    string getAccountDescription() const;

    /*****Set Account description operation *****/
    /*----------------------------------------------------------------------
     sets the Account description;Takes a string as parameter 

    Precondition:   String should not be null
    Post-condition: The account description is set
    -----------------------------------------------------------------------*/
    void setAccountDescription(string AccountDescription);

    /***** display operation *****/
    /*------------------------------------------------------------------------
    Displays the Account details;Takes an ostream as parameter

     Precondition:   none
     Post-condition: The account info is displayed
    -----------------------------------------------------------------------*/
    void display(ostream& out);
    
    /*------------------------------------------------------------------------
     overloads the assignment operator; Takes an Account object as parameter

      Precondition:   none
      Post-condition: returns a reference to this object
     -----------------------------------------------------------------------*/
    Account& operator=(const Account& accObj);
    
    /***** non-member function *****/
    /*------------------------------------------------------------------------
     overloads the output stream operator; Takes an ostream and transaction 
     object as parameters

      Precondition:   none
      Post-condition: returns an output stream reference.
     -----------------------------------------------------------------------*/
    friend ostream& operator<<(ostream& out, Account& accObj);

private:
    
    int accountNumber,            // represents the account number
    accountBalance;               //represents balance in the account
    vector<Transaction> accountTransactions;  //vector of Transactions
    string accountDescription;    //represents the purpose of the Account
};

#endif /* ACCOUNT_H */
