// Doug Whitley
// CS162-202 Recitation Code Examples
// Spring 2017

#include "list.h"
#include <iostream>
using namespace std;

int main(){
    // Make List object in Main.
    List myList;
    
    // Add at head repeatedly.
    cout << "Adding 10-1 in reverser order" << endl;
    for(int i = 10; i > 0; --i)
        myList.add(i);

    // Add at Tail repeatedly.
    cout << "Adding 12-22 in order" << endl;
    for (int i = 12; i < 22; ++i)
        myList.add(i);

#ifdef TEST_ADD
    // Testing the basic add cases for an LLL.
    cout << "Adding  0 at front of List" << endl;
    myList.add(0);
    cout << "Adding 99 at end of List" << endl;
    myList.add(99);
    cout << "Adding  50 internal to List" << endl;
    myList.add(50);
    myList.display();
#endif

#ifdef TEST_REMOVE
    // Testing the basic removal cases for an LLL.
    cout << "Removinging 0 from front of List" << endl;
    myList.remove(0);
    cout << "Removing 50 internal to the List" << endl;
    myList.remove(50);
    cout << "Removing 99 from the end of the List" << endl;
    myList.remove(99);
    cout << "Removing item not in List (999)" << endl;
    myList.remove(999);
#endif
    // Display List.
    myList.display();
}
