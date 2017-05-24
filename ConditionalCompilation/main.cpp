// Doug Whitley
// CS162-202 Recitation Code Examples
// Spring 2017

#include "list.h"
#include <iostream>
using namespace std;

int main(){
    List myList;
    for(int i = 10; i > 0; --i)
        myList.add(i);
#ifdef TEST_ADD
    myList.add(0);
    myList.add(99);
    myList.add(50);
#endif
    myList.display();
#ifdef TEST_REMOVE
    myList.remove(0);
    myList.remove(99);
    myList.remove(999);
#endif
    myList.display();
}
