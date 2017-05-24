//Picture class for use with Karla Fant's proficiency Demos to facilitate testing
//Doug Whitley 11/15/16
#include <iostream>
#include <cstring>
#include <cctype>
#include <sstream>
#include <string>
using namespace std;



class Pic
{
    public:

        //cosntructors
        Pic();
        Pic(const Pic &);
        Pic(int);
        Pic(string);
        Pic(char*);
        Pic(int h,int w,string lines[]);
        //operators
        Pic& operator = (const Pic&);
        //destructor
        ~Pic();

        //alignment
        void alignTop(const Pic&);
        void alignLeft(const Pic&);
        void alignRight(const Pic&);
        void alignCenter(const Pic&);
        void alignBottom(const Pic&);

        //display the pic
        void displayPic();
        void create(int);
        void create(string);
        void create (char*);
    private:
        int h;
        int w;
        string * lines;
        //helper
        string intToString(int a);
        string replicate(char toRep,int numReps);
};
