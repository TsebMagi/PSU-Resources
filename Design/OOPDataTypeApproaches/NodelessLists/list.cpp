// Doug Whitley
// CS162-202 Recitation Code Examples
// Spring 2017
#include "list.h"
#include <iostream>
using namespace std;

List::List(int data){
    this->data = data;
    next = NULL;
}

List::~List(){
    if(next){
        delete next;
        next = NULL;
    }
    data = 0;
}

List* List::add(int toAdd){

    if(toAdd < data){
        List * temp = new List(toAdd);
        temp->next = this;
        return temp;
    }
    if(!next)
        next = new List(toAdd);
    else
        next = next->add(toAdd);
    return this;
}

List* List::remove(int toRemove){
    if(data == toRemove){
        List * temp = next;
        next = NULL;
        delete this;
        return temp;
    }
    if(next)
        next = next->remove(toRemove);
    return this;
}

void List::display(){
    cout << data << "->";
    if(next)
        next->display();
}
