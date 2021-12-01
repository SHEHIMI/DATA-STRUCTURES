#include "CircularLinkedList.h"
#include "Node.h"
#include <cassert>

/* The aim of this CSIS 216 project is to create a circular linked list 
 * and manipulate it in every way possible(insert,add,delete...).
 * 
 * 
 * File:   main.cpp
 * Author: mohamad shehimi
 *
 * Created on November 2, 2020, 12:54 AM
 */

/*----------------------------------------------------------------------
     Construct a Circular Linked List object.
     Precondition:  None
     Postcondition: An empty Circular Linked List object has been constructed;
     mySize is 0, myFirst points to NULL.
   -----------------------------------------------------------------------*/
CircularLinkedList::CircularLinkedList() {
    myFirst = NULL;
    mySize = 0;
}

/*----------------------------------------------------------------------
     Copy a Circular Linked List object.
     Precondition:  None
     Postcondition: An empty Circular Linked List object has been constructed;
   -----------------------------------------------------------------------*/

CircularLinkedList::CircularLinkedList(CircularLinkedList& orig) {

    if (orig.isEmpty()) {
        myFirst = 0;
        mySize = 0;

    } else {
        myFirst = new(nothrow) Node(orig.myFirst->getData());
        //myFirst->setNext(orig.myFirst->getNext());
        //check that memory is available  
        if (myFirst == 0) {
            cerr << "Allocation failed !!!";
            exit(1);
        }
        // node pointer that points to the second node of the orig list
        nodePtr origPtr = orig.myFirst->getNext();

        //node pointer that points to first node of the current list 
        nodePtr tempPtr = myFirst;

        //loop to traverse the list and copy the nodes,stops when the 
        //pointer of the orig list points back to the first node.
        while (origPtr != orig.myFirst) {

            tempPtr->setNext(new Node(origPtr->getData()));
            tempPtr = tempPtr->getNext();
            origPtr = origPtr->getNext();
        }
        //The pointer should point back to the first node 
        tempPtr->setNext(myFirst);

        mySize = orig.mySize;
    }
}

/*----------------------------------------------------------------------
     Destroy a Circular Linked List object.
     Precondition:  None
     Postcondition:The circular linked list object is deleted and memory is
 *   re allocated
   -----------------------------------------------------------------------*/
CircularLinkedList::~CircularLinkedList() {

    nodePtr temp = myFirst;
    //let the pointer next of the last node point to null to delete properly 
    for (int i = 0; i < mySize; i++) {
        temp = temp->getNext();
    }
    temp->setNext(NULL);
    //temp->getNext() = NULL;

    temp = myFirst;
    //loop to traverse and delete each node 
    while (temp != 0) {
        myFirst = temp->getNext();
        delete temp;
        temp = myFirst;
    }
    delete myFirst;
}

/*----------------------------------------------------------------------
 Delete nodes of the list 
     Precondition:  None
     Postcondition: An empty Circular Linked List  has been done;
     mySize is 0, myFirst points to NULL.
   -----------------------------------------------------------------------*/

void CircularLinkedList::clear() {
    while(myFirst!=NULL){
        deleteAtBeginning();     
        }
    this->myFirst = NULL;
    this->mySize = 0;
}

/*----------------------------------------------------------------------
     Check if a list is empty.

     Precondition:  None
     Postcondition: true is returned if the list is empty, false if not.
   -----------------------------------------------------------------------*/
bool CircularLinkedList::isEmpty() const {
    return myFirst == NULL;
}

/*----------------------------------------------------------------------
 check the number of nodes in the list
     Precondition:  None
     Postcondition: true is returned if the list is empty, false if not.
   -----------------------------------------------------------------------*/
int CircularLinkedList::size() {

    return mySize;

}

/*----------------------------------------------------------------------
 search for the first Occurence of n in the nodes 

     Precondition:  None
     Postcondition: Returns a pointer to the first node that has n as data,
     null otherwise.
 
   -----------------------------------------------------------------------*/
nodePtr CircularLinkedList::searchFirstOccurence(ElementType n) {

    nodePtr temp = myFirst;
    while (temp->getNext() != myFirst) {

        if (temp->getData() == n) {
            return temp;
        }
        temp = temp->getNext();
    }
    if (temp->getData() == n) {
        return temp;
    } else {
        return NULL;
    }

}

/*----------------------------------------------------------------------
 Insert a new node at beginning of list

     Precondition:  list not empty.
     Postcondition: A new node is inserted at the beginning of the list.
 
   -----------------------------------------------------------------------*/
void CircularLinkedList::insertAtBeginning(ElementType n) {

    //to insert if list empty 
    if (myFirst == NULL) {
        myFirst = new (nothrow) Node(n);
        //Let first node point to itself 
        myFirst->setNext(myFirst);
        mySize++;

    }// to insert if  list contains  one  node
    else if (mySize == 1) {

        nodePtr Ptr = myFirst;

        nodePtr temp = new (nothrow) Node(n);
        myFirst = temp;
        temp->setNext(Ptr);
        Ptr->setNext(temp);
        mySize++;

    }//TO insert if list contains more than one Node 
    else {
        //Grab the last node 
        nodePtr last;
        last = myFirst;
        while (last->getNext() != myFirst) {
            last = last->getNext();

        }
        //let pointer first grab the initial first node before insert 
        nodePtr first = myFirst;
        //create the new node to insert and let my first point to it.
        nodePtr NEW = new(nothrow) Node(n);
        myFirst = NEW;
        //Let the last node point to the newly inserted node 
        //and the new node point to the initial first node.
        last->setNext(NEW);
        NEW->setNext(first);
        mySize++;

    }

}

/*----------------------------------------------------------------------
 Insert a new node at end of list

     Precondition:  None
     Postcondition: A new node is inserted at the beginning of the list.
 
   -----------------------------------------------------------------------*/
void CircularLinkedList::insertAtEnd(ElementType n) {
    //to insert if list empty 
    if (myFirst == NULL) {
        myFirst = new (nothrow) Node(n);
        //Let first node point to itself 
        myFirst->setNext(myFirst);
        mySize++;
    } else {
        //let end grab the last node
        nodePtr end = myFirst;
        while (end->getNext() != myFirst) {
            end = end->getNext();
        }
        //let the new node be the last node
        nodePtr NEW = new (nothrow) Node(n);
        end->setNext(NEW);
        //let the newly inserted point to the first node
        NEW->setNext(myFirst);
        mySize++;
    }
}

/*----------------------------------------------------------------------
 Insert a new node n at a desired position pos in the  list

     Precondition: position should be valid 
     Postcondition: A new node is inserted at the desired position.
     
   -----------------------------------------------------------------------*/
bool CircularLinkedList::insertAtPos(ElementType n, int pos) {
    
    //check if position is valid 
    if (pos > mySize+1 || pos < 0) {
        cerr << "invalid position!"<<endl;
        return false;
    }

    //to insert at beginning
    if (pos == 1) {
        insertAtBeginning(n);
        return true;
        
    }
    //to insert before end
  /*  else if (pos == mySize) {
       
        return true;
        mySize++;
    }//insert at pos */
    else {
        //grab the node before the position
        nodePtr prev = myFirst;
        for (int i = 2; i < pos; i++) {
            prev = prev->getNext();
        }

        //grab the node at position
        nodePtr POS = myFirst;
        for (int z = 1; z < pos; z++) {
            POS = POS->getNext();
        }
        // let the new previous node point to the new and the new node 
        //point to the original node POS
        nodePtr NEW = new(nothrow) Node(n);
        prev->setNext(NEW);

        NEW->setNext(POS);
        mySize++;
        return true;
    }
    return false;

}

/*----------------------------------------------------------------------
 Insert a new node M before node having N as data in the  list

     Precondition: list should not be empty.
     Postcondition:  M is inserted at the desired position before N.
     
   -----------------------------------------------------------------------*/

bool CircularLinkedList::insertMBeforeN(ElementType m, ElementType n) {
    //check that list is not empty
    bool condition = this->isEmpty();
    assert(condition != true);
    //point to the node holding data N
    nodePtr pos = searchFirstOccurence(n);

    //If node doesn't exist return false
    if (pos == NULL) {
         cout<<"Element not found!"<<endl;
        return false;
    } else {
        //traverse list and locate the index of the node N
        int index = 1;
        nodePtr traverser = myFirst;
        while (traverser != pos) {
            traverser = traverser->getNext();
            index++;
        }

        //insert M before N
        insertAtPos(m, index);
        
        return true;
    }
}

/*----------------------------------------------------------------------
 delete the first node of the list 

     Precondition: list should not be empty.
     Postcondition: first node is deleted 
     
   -----------------------------------------------------------------------*/

void CircularLinkedList::deleteAtBeginning() {
    //if one element exists 
    if (mySize == 1) {
        nodePtr one = myFirst;
        delete one;
        mySize = 0;
        myFirst = NULL;
    } else {
        //check if list empty 
        bool condition = isEmpty();
        assert(condition != true);
        //point to the last node 
        nodePtr last = myFirst;
        while (last->getNext() != myFirst) {
            last = last->getNext();
        }
        //delete the first node and set pointer of last to the
        //new first node(myFirst->next)
        nodePtr deleter = myFirst;
        myFirst = myFirst->getNext();
        delete deleter;
        last->setNext(myFirst);
        mySize--;
    }
}

/*----------------------------------------------------------------------
 delete the last node of the list 

     Precondition: list should not be empty.
     Postcondition: last node is deleted 
     
   -----------------------------------------------------------------------*/

void CircularLinkedList::deleteAtEnd() {
    //if one element exists 
    if (mySize == 1) {
        nodePtr one = myFirst;
        delete one;
        mySize = 0;
        myFirst = NULL;
    } else {
        //check if list empty 
        bool condition = isEmpty();
        assert(condition != true);
        //Point to the last node
        nodePtr end = myFirst;
        while (end->getNext() != myFirst) {
            end = end->getNext();
        }
        //point to the node before the last one
        nodePtr preLast = myFirst;
        for (int i = 1; i < mySize - 1; i++) {
            preLast = preLast->getNext();
        }
        preLast->setNext(myFirst);
        delete end;
        mySize--;
    }
}

/*----------------------------------------------------------------------
 delete the  node at the chosen position 

     Precondition:  list should not be empty.
     Postcondition: last node is deleted.Returns true if node deleted
     false if not.
 
   -----------------------------------------------------------------------*/
bool CircularLinkedList::deleteAtPos(int pos) {
    //check if position is valid 
    if (pos > mySize || pos < 0) {
        cerr << "invalid position!"<<endl;
        return false;
    }
    //to delete first node
    if (pos == 1) {
        deleteAtBeginning();
        mySize--;
        return true;
    }
    //to delete last node
    if (pos == mySize) {
        deleteAtEnd();
        
        return true;
    }
    else{
    //point to the node to be deleted
    nodePtr POS = myFirst;
    for (int i = 1; i < pos; i++) {
        POS = POS->getNext();
    }

    //point to node preceding the one to be deleted
    nodePtr prev = myFirst;
    for (int j = 1; j < pos - 1; j++) {
        prev = prev->getNext();
    }
    //point to node after the one to be deleted
    nodePtr after = POS->getNext();
    //delete the node at pos.
    //set the previous node to point to the one after the deleted node.
    
    prev->setNext(after);
    POS->setNext(NULL);
    delete POS;
    mySize--;
    return true;
    }

}
/*----------------------------------------------------------------------
 deletes the first node that contains n 

     Precondition:  list should not be empty.n should exist.
     Postcondition: node containing n is deleted
 
   -----------------------------------------------------------------------*/


bool CircularLinkedList::deleteN(ElementType n){
     //check if list empty 
        bool condition = isEmpty();
        assert(condition != true);
        nodePtr pos = searchFirstOccurence(n);
        //If node doesn't exist return false
    if (pos == NULL) {
        cout<<"Element not found!"<<endl;
        return false;
        
    } else {
        //traverse list and locate the index of the node that contains n
        int index = 1;
        nodePtr traverser = myFirst;
        while (traverser != pos) {
            traverser = traverser->getNext();
            index++;
        }

        //delete node that contains n
        deleteAtPos(index);
        
        return true;
    }
        return false;
}
/*----------------------------------------------------------------------
 cuts  the  first node that contains n as Data

     Precondition:  list should not be empty.n should exist 
     Postcondition: the Node containing n is removed and a pointer to it 
     is returned.
 
   -----------------------------------------------------------------------*/

nodePtr CircularLinkedList::cutN(ElementType n){
    nodePtr N =searchFirstOccurence(n);
    //if N is the first element to cut 
    if (N == myFirst)
    {
        myFirst=N->getNext();
        N->setNext(NULL);
        mySize--;
      
    }
    //to cut other nodes
    else
    {
        nodePtr p = myFirst;
        while (p->getNext()!= N)
        {
            p=p->getNext();
        }
        p->setNext(N->getNext());
        N->setNext(NULL);
        mySize--;
    }
    if (mySize==0)
        myFirst=NULL;
    return N;
    
}

/*----------------------------------------------------------------------
 Display the list elements 

     Precondition:  list should not be empty.
     Postcondition: return the elements of the list in a formatted way.
 
   -----------------------------------------------------------------------*/
ostream & CircularLinkedList::display(ostream& out)const {

    if (isEmpty()) {
        cout << "Empty List";
    } else {
        nodePtr c = myFirst;
        cout << "List is :  ";
        cout << myFirst->getData() << " ";
        while (c->getNext() != this->myFirst) {
            c = c->getNext();
            out << c->getData() << " ";
        }
    }
    return out;
}

ostream& operator<<(ostream & out, const CircularLinkedList& l) {

    l.display(out);
    return out;

}
/*----------------------------------------------------------------------
 Get the myFirst node of the list 
     Precondition:  none
     Postcondition: returns myFirst
 
   -----------------------------------------------------------------------*/
 nodePtr CircularLinkedList::getMyfirst(){
    return myFirst;
    
}


