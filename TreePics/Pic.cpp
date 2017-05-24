#include "Pic.h"
//implementation of the Pic class



Pic::Pic()
{
    h = 0;
    w = 0;
    lines = NULL;
}



Pic::Pic(int h, int w, string lines[])
{
    this->h = h;
    this->w = w;
    for(int i = 0; i < h; ++i)
        this->lines[i] = lines[i];
}



Pic::Pic(const Pic & to_copy)
{
    h = to_copy.h;
    w = to_copy.w;
    lines = new string[h];
    for (int i = 0; i < h; ++i)
        lines[i] = to_copy.lines[i];
}



string Pic::intToString(int a)
{
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}



Pic::Pic(int toPic)
{
    this->create(toPic);
}



Pic::Pic(string toPic)
{
    this->create(toPic);
}



Pic::Pic(char* toPic)
{
    string caster(toPic);
    h = 1;
    lines = new string[h];
    lines[0] = caster;
    w = lines[0].length();
}



//destructor
Pic::~Pic()
{
    if(lines)
    {
        delete[] lines;
        lines = NULL;
    }
}



Pic& Pic::operator = (const Pic& toCopy)
{
    h = toCopy.h;
    w = toCopy.w;
    lines = new string[h];
    for (int i = 0; i < h; ++i)
        lines[i] = toCopy.lines[i];
    return *this;
}



//alignment
void Pic::alignTop(const Pic& that)
{
    //setup the new width which is equal to the width of each pic.
    int newW = this->w + that.w;
    //set up new height which is the max of the two pics
    int newH = max(this->h, that.h);
    //set up new lines
    string newLines[newH];
    for (int i = 0; i< newH; ++i)
    {
        //if we are below the point that one pic fails then simply compose the pics
        if(i < h && i < that.h)
            newLines[i] = lines[i] + that.lines[i];
        else if (h > that.h)
        {
            int pad = newW - w;
            string padding = replicate(' ', pad);
            newLines[i] += lines[i];
            newLines[i] += padding;
        }
        else if (that.h > h)
        {
            int pad = newW - that.w;
            string padding = replicate(' ',pad);
            newLines[i] += padding;
            newLines[i] += that.lines[i];
        }
    }

    if(lines)
    {
        delete [] lines;
        lines = NULL;
    }
    w = newW;
    h = newH;
    lines = new string[h];
    for (int i = 0; i < h; ++i)
        lines[i] = newLines[i];

}



void Pic::alignLeft(const Pic& that)
{
    //setup the new width which is equal to the width of each pic.
    int newW = max(this->w,that.w);
    //set up new height which is the max of the two pics
    int newH = this->h + that.h;
    //set up new lines
    string newLines[newH];
    for (int i = 0; i< newH; ++i)
    {
        //still in first picture
        if(i < h)
        {
            int pad = newW - w;
            if(pad > 0)
            {
                string padding = replicate(' ', pad);
                lines[i] += padding;
                newLines[i] += padding;
            }
            else
                newLines[i] = lines[i];
        }
        //outside of first picture
        else
        {

            int pad = newW - that.w;
            if(pad > 0)
            {
                string padding = replicate(' ', pad);
                
                newLines[i] += that.lines[i];
                newLines[i] += padding;
            }
            else
                newLines[i] = that.lines[i];
        }
    }
    if(lines)
    {
        delete [] lines;
        lines = NULL;
    }
    w = newW;
    h = newH;
    lines = new string[h];
    for (int i = 0; i < h; ++i)
        lines[i] = newLines[i];
}


void Pic::alignRight(const Pic& that)
{
    //setup the new width which is equal to the width of each pic.
    int newW = max(this->w,that.w);
    //set up new height which is the max of the two pics
    int newH = this->h + that.h;
    //set up new lines
    string newLines[newH];
    for (int i = 0; i< newH; ++i)
    {
        //still in first picture
        if(i < h)
        {
            int pad = newW - w;
            if(pad > 0)
            {
                string padding = replicate(' ', pad);
                newLines[i] += padding;
                newLines[i] += lines[i];
            }
            else
                newLines[i] = lines[i];
        }
        //outside of first picture
        else
        {

            int pad = newW - that.w;
            if(pad > 0)
            {
                string padding = replicate(' ', pad);
                newLines[i] += padding;
                newLines[i] += that.lines[i];
            }
            else
                newLines[i] = that.lines[i];
        }
    }

    if(lines)
    {
        delete [] lines;
        lines = NULL;
    }
    w = newW;
    h = newH; 
    lines = new string[h];
    for (int i = 0; i < h; ++i)
        lines[i] = newLines[i];
}



void Pic::alignCenter(const Pic& that)
{
}



void Pic::alignBottom(const Pic& that)
{
}



//display the pic
void Pic::displayPic()
{
    for(int i = 0; i < h; ++i)
        cout << lines[i] << endl;
}



void Pic::create(const int toPic)
{
    string caster = intToString(toPic);
    this->create(caster);
}



void Pic::create(const string toPic)
{
    h = 1;
    w = toPic.length();
    lines = new string[h];
    lines[0] = toPic;
    //cout << lines[0];
}



string Pic::replicate(const char toRep,const int numReps)
{
    string ret = "";
    for (int i = 0; i < numReps; ++i)
        ret += toRep;
    return ret;
}
