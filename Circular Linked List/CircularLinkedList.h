

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include<iostream.h>
#include "Node.h"
typedef int ElementType;
typedef Node * nodePtr;
using namespace std;

class CircularLinkedList {
    
public:
   
    CircularLinkedList();
    CircularLinkedList(CircularLinkedList& orig);
    ~CircularLinkedList();
    void clear();
    bool isEmpty() const ;
    int size();
    nodePtr searchFirstOccurence(ElementType n);
    void insertAtBeginning(ElementType n);
    void insertAtEnd(ElementType n);
    bool insertAtPos(ElementType n, int pos);
    bool insertMBeforeN(ElementType m, ElementType n);
    void deleteAtBeginning();
    void deleteAtEnd();
    bool deleteAtPos(int pos);
    bool deleteN(ElementType n);
    nodePtr cutN(ElementType n);
    ostream& display(ostream & out)const;
    friend ostream& operator<<(ostream& out, const CircularLinkedList& l);
    nodePtr getMyfirst();
private:
    nodePtr myFirst;// A pointer that points to the first node of the list 
    int mySize;//An integer that indicates the number of nodes in the list 
};

#endif /* CIRCULARLINKEDLIST_H */

