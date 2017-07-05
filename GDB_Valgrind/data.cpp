#include "data.h"

data::data() 
{
}

data::~data()
{
        delete [] name;
}

void data::display()
{
    cout << "this is my name: " << this << endl;
}

void data::edit(char* name)
{
    if(this->name)
        delete this->name;
    this->name = new char[strlen(name)];
    strcpy (this->name,name);
}
