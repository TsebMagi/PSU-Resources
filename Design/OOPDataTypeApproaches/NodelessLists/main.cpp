// Doug Whitley
// CS162-202 Recitation Code Examples
// Spring 2017

#include "list.h"
#include <iostream>
using namespace std;

int main(){
    // Make List object in Main.
    List * myList = NULL;

    // Add at head repeatedly.
    cout << "Adding 10-1 in reverser order" << endl;
    for(int i = 10; i > 0; --i)
    {
        if(!myList)
            myList = new List(i);
        else
            myList = myList -> add(i);
    }
    // Add at Tail repeatedly.
    cout << "Adding 12-22 in order" << endl;
    for (int i = 12; i < 22; ++i)
    {
        if(!myList)
            myList = new List(i);
        else
            myList = myList -> add(i);
    }
    // Testing the basic add cases for an LLL.
    cout << "Adding  0 at front of List" << endl;
    if(!myList)
        myList = new List(0);
    else
        myList = myList -> add(0); 
    cout << "Adding 99 at end of List" << endl;

    if(!myList)
        myList = new List(99);
    else
        myList = myList -> add(99);

    cout << "Adding  50 internal to List" << endl;
    if(!myList)
        myList = new List(50);
    else
        myList = myList -> add(50);
    myList -> display();
    cout << endl;
    // Testing the basic removal cases for an LLL.
    cout << "Removinging 0 from front of List" << endl;
    myList = myList -> remove(0);
    cout << "Removing 50 internal to the List" << endl;
    myList = myList -> remove(50);
    cout << "Removing 99 from the end of the List" << endl;
    myList = myList -> remove(99);
    cout << "Removing item not in List (999)" << endl;
    myList = myList -> remove(999);
    // Display List -> 
    myList -> display(); 
    cout << endl;
}
