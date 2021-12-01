/* 
 * File:   main.cpp
 * Author: mohamad shehimi
 *
 * Created on November 2, 2020, 12:54 AM
 */

#include<cstdlib>
#include"CircularLinkedList.h"
#include"Node.h"
#include<iostream>
using namespace std;

//menu that returns the choice of the user

int menu() {
    cout << "choose one of the following choices:" << endl
            << "press the corresponding number" << endl;
    cout << "1. To test if the list is empty" << endl
            << "2. To get the number of nodes in the list" << endl
            << "3. To insert a value at the beginning of the list" << endl
            << "4. To insert a value at the end of the list" << endl
            << "5. To Insert a value at a certain position" << endl
            << "6. To insert a value after another value" << endl
            << "7. To delete the node with a certain value" << endl
            << "8. To delete the node at a certain position" << endl
            << "9. To delete a node from the beginning of the list" << endl
            << "10.To delete a node from the end of the list" << endl
            << "11.To display the list" << endl
            << "12.to quit" << endl << endl << endl;
    int choice;
    cin>>choice;
    while (choice < 1 || choice > 12) {
        cout << "please enter a valid number between 1 and 12!" << endl;
        cin>>choice;
    }

    return choice;
}

int main() {
    CircularLinkedList * origin = new CircularLinkedList();
    int choice = 1;
    //set the correct method to the selected choice
    while (choice != 12) {
        choice = menu();
        switch (choice) {
            case 1:
                //test if empty
                bool YesNo = origin->isEmpty();
                if (YesNo) {
                    cout << "list empty" << endl;
                } else {
                    cout << "List Not empty" << endl;
                }
                break;
                //get number of nodes
            case 2:
                cout << "number of nodes:" << origin->size() << endl;
                break;
            case 3:
                //insert at beginning
                int data;
                cout << "Enter node to insert at beginning:" << endl;
                cin>>data;
                origin->insertAtBeginning(data);
                cout << *origin << endl;
                break;
            case 4:
                //insert at end 
                int Data;
                cout << "Enter node to insert at End:" << endl;
                cin>>Data;
                origin->insertAtEnd(Data);
                cout << *origin << endl;
                break;
            case 5:
                //insert at position
                ElementType value;
                int pos;
                cout << "Enter position to insert at :" << endl;
                cin>>pos;
                cout << "enter value to insert at the position:";
                cin>>value;
                origin->insertAtPos(value, pos);
                cout << *origin << endl;
                break;

            case 6:
               // insert M before N
                int before;
                cout << "Enter value before value:" << endl;
                cin>>before;
                cout << "value to enter before it:" << endl;
                int after;
                cin>>after;
                origin->insertMBeforeN(before, after);
                cout << *origin << endl;
                break;
            case 7:
                //delete a value 
                ElementType n;
                cout << "enter the value of the node to delete:" << endl;
                cin>>n;
                origin->deleteN(n);
                cout << *origin << endl;
                break;
            case 8:
                //delete from position
                int m;
                cout << "enter the position of the node to delete : ";
                cin>>m;
                origin->deleteAtPos(m);
                cout << *origin << endl;
                break;
            case 9:
                //delete at beginning
                origin->deleteAtBeginning();
                cout << *origin << endl;
                break;
            case 10:
                //delete at end 
                origin->deleteAtEnd();
                cout << *origin << endl;
                break;
            case 11:
                //display
                cout << *origin << endl;
                break;
        }

    }
    
    //create two new lists even and odd
   CircularLinkedList * even= new CircularLinkedList();
   CircularLinkedList * odd = new CircularLinkedList();
  
    nodePtr p = origin->getMyfirst();
    int s=origin->size();
    //extract even numbers from origin and insert them to even 
    //and odd numbers inserted to odd
    while (s!=0) {

       
        int num = p->getData();
        //cut even nodes from origin list and insert them to even list
        if (num%2 == 0) {
            
            nodePtr ptr1=origin->cutN(num);
            int dat1=ptr1->getData();
            delete ptr1;
            even->insertAtEnd(dat1);
        } 
        //cut odd nodes 
        else {
            nodePtr ptr2 = origin->cutN(num);
            int dat2 = ptr2->getData();
            delete ptr2;
            odd->insertAtEnd(dat2);
        }
        //re allocate the size and the pointer pointing to my first 
        p=p->getNext();
        p = origin->getMyfirst();
        s=origin->size();
    }
    //display the even and odd lists
    cout << "even " <<*even << endl;
    cout << "odd  " <<*odd << endl;

   return 0;
}

