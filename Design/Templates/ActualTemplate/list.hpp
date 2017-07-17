// Doug Whitley
// CS162-202 Recitation Code Examples
// Spring 2017
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;

// Template for the Node Class
// The Class V must allow for the ==, =, <<, and - operations.
template <class V>
class node{
    public:
        node(V = 0);
        ~node();
        void setData(V toAdd);
        V compareData(V toFind);
        void setNext(node* toConnect);
        node*& getNext();

        void display();
    private:
        V data;
        node* next;
};


// Template for the List Class
// The Class V must allow for the ==, =, <<, and - operations because the node template requires it.
template <class V> 
class List{

    public:
        List();
        ~List();
        V add(V toAdd);
        V remove(V toRemove);
        void display();
    private:
        node<V>* head;
        V add(V, node<V>*& head);
        V remove(V, node<V>*& head);
        void display(node<V>* head);

};

// Templated class methods must be preceeded by the line below.
// Note that the V class allows the class to be instantiated as whatever type we want that maintains the needed
// funtionality; node<int>, node<char> are both allowed by this, as well as all primitive types.
template <class V>
node<V>::node(V data){
    this->data = data;
    next = NULL;
}

// If we have a type that cannot be assigned '0' we must specialize the template which we will show an example later.
template <class V>
node<V>::~node(){
    next = NULL;
    data = 0;
}

// Since the = operator is used here whatever V is must have the = operator overloaded or inately usable.
template <class V>
void node<V>::setData(V toAdd){
    data = toAdd;
}

// As with the = operator the same rules apply here with the - operator. If the needed operators are not supplied it 
// will cause a runtime error.
template <class V>
V node<V>::compareData(V toCompare){
    return toCompare - data;
}

// Even If we aren't using V in the function we need to template because the node types need to know what they are
// templated as.
template <class V>
void node<V>::setNext(node<V>* setTo)
{
    next = setTo;
}

// Normal getNext Function.
template <class V>
node<V>*& node<V>::getNext(){
    return next;
}

// Here are examples of template specialization.
// This display will print "INT" if the node is of node<int> type
template<>
void node<int>::display(){
    cout << "INT: " << data << "->";
} 

// This display will print "CHAR" if the node is of node<char> type
template<>
void node<char>:: display(){
    cout << "CHAR: " << data << "->";
}

// If the node is not a <char> nor an <int> then the template will use this version of display
// The V type needs to support the << operation as well.
template <class V>
void node<V>::display(){
    cout << data << "->";
}

// Constructor
template <class V>
List<V>::List(){
    head = NULL;
}

// Broken Destructor
// Fix this
template <class V>
List<V>::~List(){
    delete head;
}

// recursive add function.
template <class V>
V List<V>::add(V toAdd, node<V>*& head){
    if(!head){
        head = new node<V>(toAdd);
        return 1;
    }
    if(head->compareData(toAdd) < 0)
    {
        node<V> * temp = head;
        head = new node<V>(toAdd);
        head->setNext(temp);
        return 1;
    }
    return add(toAdd, head->getNext());

}

// Recursive remove function.
template <class V>
V List<V>::remove(V toRemove, node<V>*& head){
    if(!head)
        return 0;
    if(head->compareData(toRemove) == 0)
    {
        node<V> * temp = head;
        head = temp->getNext();
        delete temp;
        return 1;
    }
    return remove(toRemove, head->getNext());
}

// public wrapper to recursive add
template <class V>
V List<V>::add(V toAdd){
    return add(toAdd, head);
}

// public wrapper to recursive remove
template <class V>
V List<V>::remove(V toRemove){
    return remove(toRemove, head);
}

// public wrapper to recursive display
template <class V>
void List<V>::display(){
    display(head);
    cout << endl;
}

// recursive display
template <class V>
void List<V>::display(node<V>* head){
    if(!head)
        return;
    head->display();
    display(head->getNext());
    return;
}
