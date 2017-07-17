#include "LLL.h"
#include <iostream>
using namespace std;


int main()
{
    LLL myList;

    for(int i = 53; i < 71; ++i)
    {
        dataType someData(i);
        myList.add(someData);
    }
    cout << "List after adding 53 - 70" << endl;
    myList.display();

    for(int i = 70; i > 60; --i)
    {
        dataType toRemove(i);
        myList.remove(toRemove);
    }
    cout << "List after removing 70 - 59" << endl;
    myList.display();
    return 0;
}
