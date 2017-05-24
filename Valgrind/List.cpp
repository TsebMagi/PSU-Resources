// Valgrind Demo
// Doug Whitley
// Spring 17

#include <iostream>
using namespace std;

class List{

    public:
        List();
        ~List();
        int add(int toAdd);
        int remove(int toRemove);
        void display();
    
    private:
            List * tail;            
            int data;
            bool used;
}


List::List(){
    tail  = NULL;
    data = 0;
    used = false;
}


List::~List(){
    if(tail)
        delete tail;
    tail = NULL;
}


int List::add(int toAdd){
    if (!used){
        data = toAdd;
        used = true;
        return;
    }
    if(tail)
        return tail->add(toAdd);
    tail = new List();
    return tail->add(toAdd);
}


int List::remove(int toRemove){
    if (data == toRemove)
    {
        data = tail->data;
        List * temp = tail;
        tail = temp->tail;
        delete temp;
        return 1;
    }
    if(tail->data == toRemove)
    {
        List * temp = tail;
        tail = temp->tail;
        delete temp;
        return 1;
    }
    if(tail)
        return tail->remove(toRemove);
    return 0;
}


void List::display(){
}

