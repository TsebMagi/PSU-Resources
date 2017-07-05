#ifndef DATA_H
#define DATA_H

#include <cstring>
#include <iostream>
#include <cctype>
using namespace std;


class data
{
    public:
    data();
    ~data();

    void display();
    void edit(char*);
    private:

    char* name;

};

#endif
