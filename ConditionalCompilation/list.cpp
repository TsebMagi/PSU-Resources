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
    if(next){
        delete next;
        next = NULL;
    }
    data = 0;
}

lNode* lNode::add(int toAdd){

    if(toAdd < data){
        lNode * temp = new lNode(toAdd);
        temp->next = this;
        return temp;
    }
    if(!next)
        next = new lNode(toAdd);
    else
        next = next->add(toAdd);
    return this;
}

lNode* lNode::remove(int toRemove){
    if(data == toRemove){
        lNode * temp = next;
        next = NULL;
        delete this;
        return temp;
    }
    if(next)
        next = next->remove(toRemove);
    return this;
}

void lNode::display(){
    cout << data << "->";
    if(next)
        next->display();
}

List::List(){
    head = NULL;
}

List::~List(){
    delete head;
}

int List::add(int toAdd){
    if(!head){
        head = new lNode(toAdd);
        return 1;
    }
    head = head->add(toAdd);
    return 1;
}

int List::remove(int toRemove){
    if(!head)
        return 0;
    head = head->remove(toRemove);
    return 1;
}

void List::display(){
    if(head)
        head->display();
    cout << endl;
    return;
}
