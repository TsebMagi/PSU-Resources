//list.h
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    node();
    ~node();
    int data;
    node * next;
};



/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

int displayAll(node* head);

int addAfter2(node* head, int toAdd);

int appendIfDivisible (node*& head, int toAdd);

int modifyAfter2(node*& head);

int addToAll(node* head, int toAdd);

#endif
