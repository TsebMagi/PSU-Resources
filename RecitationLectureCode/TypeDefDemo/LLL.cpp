#include "LLL.h"
// public functions
LLL::LLL()
{
    head = NULL;
}



LLL::~LLL()
{
    removeAll(head);
}



int LLL::add(dataType& toAdd)
{
    return add(head, toAdd);
}



int LLL::remove(dataType& toRemove)
{
    return remove(head, toRemove);
}



void LLL::display()
{
    return display(head);
}



// private helpers
int LLL::add(node*& head, dataType& toAdd)
{
    if(!head)
    {
        head = new node;
        head->next = NULL;
        head->data.copy(toAdd);
        return 1;
    }

    if(head->data.compare(toAdd) < 0)
    {
        node* temp = head;
        head = new node;
        head->data.copy(toAdd);
        head->next = temp;
        return 1;
    }

    return add(head->next, toAdd);
}



int LLL::remove(node*& head, dataType& toRemove)
{
    if(!head)
        return 0;
    if((head->data.compare(toRemove)) == 0)
    {
        node* temp = head;
        head= head->next;
        delete temp;
        return 1;
    }
    return remove(head->next, toRemove);
}



void LLL::display(node* head)
{
    if(!head)
        return;
    head->data.display();
    return display(head->next);
}



// destructor helper
int LLL::removeAll(node*& head)
{
    if(!head)
        return 0;
    removeAll(head->next);
    delete head;
    head = NULL;
    return 1;
}
