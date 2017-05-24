#include "data.h"

data::data() 
{
}

data::~data()
{
    if (name)
        delete [] name;
}

void data::display()
{
    cout << "this is my name: " << this->name+1 << endl;
}

void data::edit(char* name)
{
    if(this->name)
        delete [] this->name;
    this->name = new char[strlen(name)+1];
    strcpy (this->name+1,name);
}
