#include "clist.h"
using namespace std;

int main()
{
    node * rear = NULL;
    build(rear);
    display(rear);

    //PLEASE PUT YOUR CODE HERE to call the function assigned




    display(rear); //resulting list after your function call!
    destroy(rear);
    
    return 0;
}
