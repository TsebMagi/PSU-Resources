#include "list.h"
#include "Pic.h"
#include <iostream>
#include <fstream>
using namespace std;



Pic ListPic(node* head);
Pic nodeToPic(node* toPic);

int main()
{
    Pic toDisplay();
    node * head = NULL;
    build(head);
    display(head);

    Pic myNode = nodeToPic(head);
    myNode.displayPic();
    cout << "above is the node" << endl;
    return 0;
}

Pic ListPic(node* head)
{

}

Pic nodeToPic(node* toPic)
{
    string tb = "---";
    string side = "|";
    Pic ret(tb);
    Pic sides(side);
    ret.alignLeft(sides);
    return ret;
}
