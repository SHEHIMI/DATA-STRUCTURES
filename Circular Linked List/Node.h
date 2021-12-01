/*the purpose of this class is to create a node object to be used in the 
 *circularLinkedList class
 *File:Node.h
 */

#ifndef NODE_H
#define NODE_H
typedef int ElementType;

#include <iostream>
class Node {
    

public:
    typedef Node * nodePtr;
    Node(ElementType n);
    Node(const Node& orig);
    ElementType getData();
    Node * getNext();
    void setData(ElementType d);
    void setNext(nodePtr n);
    
private:
    ElementType data;//data member that stores a value of the node 
    nodePtr next;//data member that points to the next node 

};

#endif /* NODE_H */

