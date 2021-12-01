/*------------------------------------------------------------------------
 Implementation of Account class. 
------------------------------------------------------------------------*/

/* 
 * File:   Account.cpp
 * Author: mohamad shehimi-omar Lawand
 * 
 * Created on 26 April 2021, 20:52
 */

#include "Account.h"
#include "Transaction.h"
//--- Definition of constructor

Account::Account(){
    setAccountNumber(0);
    setAccountBalance(0);
    setAccountDescription("");
}

Account::Account(int accountNumber) {
    setAccountNumber(accountNumber);
    setAccountBalance(0);
    setAccountDescription("");
}

Account::Account(int accountNumber, int accountBalance, string description) {
    setAccountNumber(accountNumber);
    setAccountBalance(accountBalance);
    setAccountDescription(description);
}

//--- Definition of setAccountNumber
void Account::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}

//--- Definition of getAccountNumber
int Account::getAccountNumber() {
    return accountNumber;
}

//--- Definition of setAccountBalance
void Account::setAccountBalance(int accountBalance) {
    this->accountBalance = accountBalance;
}

//--- Definition of getAccountBalance
int Account::getAccountBalance() {
    return accountBalance;
}

//--- Definition of setTransactions
void Account::setTransactions(vector<Transaction> accountTransactions) {
    this->accountTransactions.swap(accountTransactions);
}

//--- Definition of getTransactions
vector<Transaction> Account::getTransactions() {
    return accountTransactions;
}

//--- Definition of addTransaction
void Account::addTransaction(Transaction obj) {
    //adding transaction into vector
    accountTransactions.push_back(obj);

    //updating the balance
    if (obj.getWithdraw_deposit()) {
        accountBalance += obj.getAmount();
    } else {
        accountBalance -= obj.getAmount();
    }

}

//--- Definition of display
void Account::display(ostream& out) {
    out << "Account details: " << endl
        << "Description: " << accountDescription << endl
        << "Account Number: " << accountNumber << endl
        << "Balance: " << accountBalance << "$" << endl
        << "Transactions done by this account: " << endl;
    
    if(accountTransactions.size() == 0){
        cout << "none." << endl;
        return;
    }
    
    //loop to display transactions
    for (int i = 0; i < accountTransactions.size(); i++) {

        out << i + 1 << ". " << "Amount:" <<
                accountTransactions[i].getAmount() << "$ / " <<
                "Description:" << accountTransactions[i].getDescription() <<
                " / type: ";

        if (accountTransactions[i].getWithdraw_deposit()) {
            out << "Deposit" << endl;
        } else {
            out << "Withdrawal" << endl;
        }
    }
}

string Account::getAccountDescription() const {
    return accountDescription;
}

void Account::setAccountDescription(string AccountDescription) {
    this->accountDescription = AccountDescription;
}

Account& Account::operator=(const Account& accObj) {
    if (this == &accObj)
        return *this;

    this->accountNumber = accObj.accountNumber;
    this->accountBalance = accObj.accountBalance;
    this->accountDescription = accObj.accountDescription;
    this->accountTransactions=accObj.accountTransactions;
    
    return *this;
}

//--- Definition of overloaded operator<<
ostream& operator<<(ostream& out, Account& accObj) {
    accObj.display(out);
    return out;
}


