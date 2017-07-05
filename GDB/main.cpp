#include "list.h"
#include "data.h"
#include <iostream>
#include <fstream>
using namespace std;

const char fileName[] = "names.txt";

int readInfo();

int main()
{
    node * head = NULL;
    build(head);
    display(head);
    int returnCatch = 0;

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    // Should match the called display.
    displayAll(head);


    cout << "Number of nodes added after 2s: " << addAfter2(head, 9005) << endl;
    // should now have '9001' after each 2 in the list.
    display(head);

    // if the last node is divisible by 5 then a 5 will be added.
    returnCatch = appendIfDivisible (head, 5);
    if(!returnCatch)
        cout << "Node appended!" << endl;
    else
        cout << "Node not appended!" << endl;
    // Depending on last node there will either be a new 5 added or nothing added.
    display(head);


    cout << "Number of nodes remoeved after 2s: " << modifyAfter2(head) << endl;
    // Should have removed all the '9001' added by addAfter2
    display(head);

    
    cout << "Sum after adding 1 to each node: " << addToAll(head, 1);
    // Should see each node as incremented.
    display(head); //redisplay the list after your function
    
    destroy(head); 

    // This should print each name found in names.txt
    readInfo();

    return 0;
}



int readInfo()
{
    char input[200];
    data myData;

    ifstream fIn;
    fIn.open(fileName);


    fIn.get(input,199,':');
    fIn.ignore();
    while(!fIn.eof())
    {

        myData.edit(input);
        myData.display();
        fIn.get(input,3,':');
        fIn.ignore();
    }

}
