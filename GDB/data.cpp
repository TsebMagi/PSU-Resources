#include "data.h"

data::data() 
{
    // constructors need to initialize everything to null equivalents
    name = NULL;
}

data::~data()
{
    // safety check
    if(name)
        delete [] name;
    // after deletion make sure to set vars to null equivalents
    name = NULL;
}

void data::display()
{
    // display the var, not just the class or struct
    cout << "this is my name: " << this->name << endl;
}

void data::edit(char* name)
{
    // use [] for array deletion
    if(this->name)
        delete [] this->name;
    // remember the +1
    this->name = new char[strlen(name)+1];
    strcpy (this->name,name);
}
