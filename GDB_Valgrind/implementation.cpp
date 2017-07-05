#include "list.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


node::node(){
    data = 0;
}


node::~node(){
    delete next;
    next = NULL;
}


// This function should display the list and return the number of nodes contained by the list.
int displayAll(node* head){
    if(!head) return 0;

    cout << head->data << "->";
    
    return displayAll(head->next);
}


// This function should add the arg toAdd after each '2' found in the list and return the number of items added to the list.
int addAfter2(node* head, int toAdd){
    int ret = 0;
    node* temp = NULL;
    
    if(!head) return 0;
    
    if(head->data == 2)
        temp =  head->next;
        head->next = new node;
        head->next ->data = toAdd;
        head->next ->next = temp;
        ++ret;
    return ret + addAfter2(head->next, toAdd);
}


// This function will add the arg toAdd to the end of the list if the arg divides the data in the last element of the list 
// it will return the remainder of the division operation.
int appendIfDivisible (node*& head, int toAdd){
    int ret = -1;
    
    if(!head) return ret;
    
    if(!head->next){
        ret += head->data % toAdd;
        if(!ret)
        {
            node* temp = new node;
            temp->data  = toAdd;
            temp->next = NULL;
            head->next  = temp;
        }
        return ret;
    }
    return appendIfDivisible(head->next, toAdd);
}


// This function will remove each node that occurs after a 2 and return the number removed.
int modifyAfter2(node*& head){
    int ret = 0;

    if(!head) return 0;

    if(head->next && head->data == 2){
        node*temp = head;
        head = temp->next;
        delete temp;
        ++ret;
    }

    return ret + modifyAfter2(head->next);

}


// This Function will add the arg toAdd to each element and then return the new sum of the list.
int addToAll(node* head, int toAdd){

    if(!head) return 0;

    head->data += toAdd;

    return head->data + addToAll(head, toAdd);
}



