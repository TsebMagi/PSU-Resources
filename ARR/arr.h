//arr.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;  //some questions are char * data;
    node * next;
};

class table
{
    public:
    /* These functions are already written */
       table();		//supplied
       ~table();	//supplied
       void build();  	//supplied
       void display();  //supplied
       void ourDisplay();
    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:

    private:
       node ** head; 	//dynamically allocated array
       int size; 	//the array size

       void ourDisplay(node** arr, int size);
       void realDisplay(node*);

       int displayDivisible(node* head, int toDisplay);
};
