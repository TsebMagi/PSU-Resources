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

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    displayAll(head);

    addAfter2(head, 9001);

    cout << modifyAfter(head) << " Nodes not changed by add after" << endl;

    node* temp = head;

    head = head->next;

    delete temp;

    display(head); //redisplay the list after your function
    destroy(head); 

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
    while(!fIn.eof())
    {

        myData.edit(input);
        myData.display();

        fIn.get(input,3,':');
        fIn.ignore();
    }

}
