#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned



    display(head); //redisplay the list after your function
    destroy(head); 
    return 0;
}
