#include "Node.h"
//Node constructor that creates a node with data n
Node::Node(ElementType n) {
    this->data = n;
    this->next = NULL;
}
//copy constructor that performs a copy of node orig
Node::Node(const Node& orig) {
    this->data = orig.data;
    this->next = orig.next;
}
//getters
ElementType Node::getData() {
    return this->data;
}

Node * Node::getNext() {
    
    return this->next;
}

//setters
void Node::setData(ElementType d) {
    this->data = d;
}

void Node::setNext(nodePtr n) {
    this->next = n;
}


