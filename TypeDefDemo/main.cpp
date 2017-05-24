#include "LLL.h"



int main()
{
    LLL myList;

    for(int i = 0; i < 8; ++i)
    {
        data3 someData(i + 'a');
        myList.add(someData);
    }

    myList.display();

    for(int i = 0; i < 7; ++i)
    {
        //myList.remove(i);
    }
}
