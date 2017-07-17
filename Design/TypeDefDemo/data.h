#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;

class data1
{
    public:
        data1(int = 5);
        ~data1();
        int compare(data1&);
        int copy(data1&);
        void display();
    private:
        int myData;
};

class data2
{
    public:
        data2(int = 6);
        ~data2();
        int compare(data2&);
        int copy(data2&);
        void display();
    private:
        int myData;
};

class data3
{
    public:
        data3(char = 'a');
        ~data3();
        int compare(data3&);
        int copy(data3&);
        void display();
    private:
        char myData;
};

#endif // DATA_h
