// Doug Whitley
// CS162-202 Recitation Code Examples
// Spring 2017
#include "list.h"
#include <iostream>
using namespace std;

lNode::lNode(int data){
    this->data = data;
    next = NULL;
}

lNode::~lNode(){
    next = NULL;
    data = 0;
}

void lNode::setData(int toAdd){
    data = toAdd;
}

int lNode::compareData(int toCompare){
    return toCompare - data;
}

void lNode::setNext(lNode* setTo)
{
    next = setTo;
}

lNode*& lNode::getNext(){
    return next;
}

void lNode::display(){
    cout << data << "->";
}

List::List(){
    head = NULL;
}

List::~List(){
    delete head;
}


int List::add(int toAdd, lNode*& head){
    if(!head){
        head = new lNode(toAdd);
        return 1;
    }
    if(head->compareData(toAdd) < 0)
    {
        lNode * temp = head;
        head = new lNode(toAdd);
        head->setNext(temp);
        return 1;
    }
    return add(toAdd, head->getNext());

}
int List::remove(int toRemove, lNode*& head){
    if(!head)
        return 0;
    if(head->compareData(toRemove) == 0)
    {
        lNode * temp = head;
        head = temp->getNext();
        delete temp;
        return 1;
    }
    return remove(toRemove, head->getNext());
}

int List::add(int toAdd){
    return add(toAdd, head);
}

int List::remove(int toRemove){
    return remove(toRemove, head);
}

void List::display(){
    display(head);
    cout << endl;
}

void List::display(lNode* head){
    if(!head)
        return;
    head->display();
    display(head->getNext());
    return;
}
