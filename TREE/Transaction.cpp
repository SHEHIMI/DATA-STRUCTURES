/*------------------------------------------------------------------------
 Implementation of Transaction class. 
------------------------------------------------------------------------*/

/* 
 * File:   Transaction.cpp
 * Author: mohamad shehimi-Omar lawand
 * 
 * Created on April 27, 2021, 12:03 AM
 */

#include "String.h"
#include "Transaction.h"
#include <iostream>
using namespace std;

//--- Definition of constructor
Transaction::Transaction(){
    amount=0;
    withdraw_deposit=false;
    description="";
}

Transaction::Transaction(int amount, bool withdraw_deposit, string description){

    if(amount<0){
        cerr<<"please enter positive amount!";
        return;
    }
    
    string nil ="";
    
    if(description.compare(nil)==0){
        cerr<<"please enter a description";
        return;
    }
    
    this->amount = amount;
    this->withdraw_deposit = withdraw_deposit;
    this->description = description;
}
//--- Definition of setAmount
void Transaction::setAmount(int amount) {
    this->amount = amount;
}

//--- Definition of getAmount
int Transaction::getAmount() {

    return amount;
}

//--- Definition of setWithdraw_deposit
void Transaction::setWithdraw_deposit(bool WD) {

    this->withdraw_deposit = WD;
}

//--- Definition of getWithdraw_deposit
bool Transaction::getWithdraw_deposit() {
    return withdraw_deposit;
}

//--- Definition of setDescription 
void Transaction::setDescription(string description) {

    this->description = description;
}

//--- Definition of getDescription 
string Transaction::getDescription() {

    return description;
}

//--- Definition of display
void Transaction::display(ostream& out) {
    out << "Amount withdrawn:" << getAmount() <<"$" << endl;
    if (getWithdraw_deposit()) {
        out << "deposit."<<endl;
    } else {
        out << "Withdrawal."<<endl;
    }
    out << "purpose of Transaction : " << getDescription() << endl;
}

//--- Definition of overloaded operator<<
 ostream& operator<<(ostream& out, Transaction& t) {
    t.display(out);
    return out;
}

