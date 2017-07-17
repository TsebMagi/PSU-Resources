#include "data.h"
#include <iostream>
typedef class data2 dataType;
typedef int keyValue;

//This LLL expectss that any data type that is used has a compare, copy, and display function
//The compare should return an int that signifies less than, greater than, and equal to.
//This LLL also requires that the typedef keyValue is used by the compare function

struct node
{
    dataType data;
    node* next;
};

class LLL
{
    public:
        LLL();
        ~LLL();
        int add(dataType&);
        int remove(dataType&);
        void display();

    private:
        // data members
        node* head;

        // private helpers
        int add(node*&, dataType&);
        int remove(node*&, dataType&);
        void display(node*);
        
        // destructor helper
        int removeAll(node*&);
};
