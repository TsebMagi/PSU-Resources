#include "data.h"

data::data() 
{
    name = NULL;
}

data::~data()
{
    if(name)
        delete [] name;
    name = NULL;
}

void data::display()
{
    cout << "this is my name: " << this->name << endl;
}

void data::edit(char* name)
{
    if(this->name)
        delete [] this->name;
    this->name = new char[strlen(name)+1];
    strcpy (this->name,name);
}
