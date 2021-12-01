/*------------------------------------------------------------------------
 Header file for Transaction class. 
 purpose: This file defines basic operations for a Transaction in an accounting system.
 It contains the amount of the transaction,whether it's a credit or debit,and the purpose
 of the transaction.
 
 Basic operations are:
     constructor:          creates an object Transaction.
     setAmount:            Sets the amount to be withdrawn or deposited
     getAmount:            Returns the amount
     setWithdraw_deposit:  Sets either a credit or debit transaction
     getWithdraw_deposit:  Returns true if credit,false if debit
     setDescription:       Sets the description/purpose of transaction
     getDescription:       Returns the description
     display:              Displays Transaction details
     operator<<:           overloaded output operator
------------------------------------------------------------------------*/

/* 
 * File:   Transaction.h
 * Authors:mohamad shehimi-Omar lawand
 *
 * Created on April 27, 2021, 12:03 AM
 */

#ifndef TRANSACTION_H
#define	TRANSACTION_H

#include <string>
#include <iostream>
using namespace std;

class Transaction {
public:
    
     /*------------------------------------------------------------------------
      Construct an empty transaction object

      Precondition: none
      Post-condition: Set each of the amount,withdraw_deposit and description to null
     -----------------------------------------------------------------------*/
    Transaction();
    
    /*------------------------------------------------------------------------
      Construct a Transaction object with specified amount,description,debit/credit

      Precondition: amount should be positive,string should not be null
      Post-condition: A transaction has been constructed
     -----------------------------------------------------------------------*/
    Transaction(int amount, bool withdraw_deposit, string description);
    
    /*------------------------------------------------------------------------
     Sets the amount to be transacted;Takes an unsigned integer

      Precondition: amount should be positive.
      Post-condition: The amount has been set
     -----------------------------------------------------------------------*/
    void setAmount(int amount);
    
    /*------------------------------------------------------------------------
     Returns the amount transacted

      Precondition: none.
      Post-condition: Returns the amount
     -----------------------------------------------------------------------*/
    int getAmount();
    
    /*------------------------------------------------------------------------
     sets whether a transaction is debit or credit;Takes a bool parameter 

      Precondition: none.
      Post-condition: Set to true if credit,false if debit
     -----------------------------------------------------------------------*/
    void setWithdraw_deposit(bool Withdraw_deposit);
    
    /*------------------------------------------------------------------------
     returns the type of transaction withdraw or deposit

      Precondition: none
      Post-condition: Returns true if its a deposit,false if it's a withdraw
     -----------------------------------------------------------------------*/
    bool getWithdraw_deposit();
    
    /*------------------------------------------------------------------------
     Sets the description/reason for the transaction;Takes a string parameter

      Precondition: String shouldn't be null
      Post-condition:The description string is set.
     -----------------------------------------------------------------------*/
    void setDescription(string description);
    
    /*------------------------------------------------------------------------
      Returns the description/reason for the transaction

      Precondition: none
      Post-condition: returns the description
     -----------------------------------------------------------------------*/
    string getDescription();
    
    /*------------------------------------------------------------------------
     Displays the Transaction

      Precondition: none
      Post-condition: The Transaction info is displayed
     -----------------------------------------------------------------------*/
    void display(ostream& out);
    
    /*------------------------------------------------------------------------
     overloads the output stream operator;Takes an ostream and transaction 
     object as parameters

      Precondition: none
      Post-condition: returns an output stream reference
     -----------------------------------------------------------------------*/
    friend ostream& operator<<(ostream& out, Transaction& t);
    
private:
    int amount;//The amount of transaction
    bool withdraw_deposit;//Boolean value,true if deposit and false if withdraw
    string description;//The reason for the transaction
};

#endif	/* TRASACTION_H */

