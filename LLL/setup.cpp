//This program takes a file that contains demo questions of the following format:
//^Q: Question text
//^D: Difficulty Rating (0-5)
//^P: Prototype for the function
//
//Doug Whitley PSU Fall 2016



#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;



//file to write the implementation shells to.
const char impOut[] = "questions.cpp";
//file to read from.
const char inputFile[] = "questions.txt";
//header printed before each question.
const char questionHeader[] = "//Place the prototype in the appropriate .h file\n//Consider:\n//Do you need helper functions?\n//Is head or tail recursion better?\n";



const int LONGIN = 1000;
const int SHORTIN = 20;



int main ()
{
    bool done = false;

    char qInput [LONGIN];
    char dInput [SHORTIN];
    char pInput [LONGIN];
    //file streams
    ifstream in;
    ofstream cppOut;

    //check input and return if it isn't there
    in.open(inputFile);
    if(!in)
    {
        cerr << "No Input File Found!";
        return 0;
    }
    //opens the output file in truncate mode to rewrite it.
    cppOut.open(impOut, ios::trunc);
    //prime the pump
    in.get(qInput,LONGIN,'\n');
    in.ignore();
    while(!in.eof() && !done)
    {
        in.get(dInput,SHORTIN,'\n');
        in.ignore();
        in.get(pInput,LONGIN,'\n');
        in.ignore();
        in.ignore();
        //print out the question header followed by the question.
        cppOut << questionHeader << "//" << qInput+3 << endl 
               << "//The difficulty of this question is: " << dInput+3 <<endl
               << pInput+3 << endl << "{" << endl << "}" <<endl << endl;

        //prime for next step of loop
        in.get(qInput,LONGIN,'\n');
        in.ignore();

        if(qInput[0] == '\0')
            done = true;
    }

    cppOut.close();

}
