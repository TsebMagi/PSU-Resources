#include "data.h"
data1::data1(int init)
{
    myData = init;
}



data1::~data1()
{
}



int data1::compare(data1& toCompare)
{
    return myData - toCompare.myData; 
}



int data1::copy(data1& toCopy)
{
    myData = toCopy.myData;
    return 1;
}



void data1::display()
{
    cout << "This is a data1 conatining: " << myData << " " <<  endl; 
}



data2::data2(int init)
{
    myData = init;
}



data2::~data2()
{
}



int data2::compare(data2& toCompare)
{
    return myData - toCompare.myData; 
}


int data2::copy(data2& toCopy)
{
    myData = toCopy.myData;
    return 1;
}


void data2::display()
{
    cout << "This is a data2 conatining: " << myData << " " << endl; 
}



data3::data3(char init)
{
    myData = init;
}



data3::~data3(){}



int data3::compare(data3& toCompare)
{ 
    return myData - toCompare.myData; 
}



int data3::copy(data3& toCopy)
{
    myData = toCopy.myData;
    return 1;
}



void data3::display()
{
    cout << "This is a data3 conatining: " << myData << " " << endl; 
}
