// Doug Whitley, Summer 2017, Topic Recitation Code
// Some languages have interfaces unfortunately C++ does not have that built in
// So we pretend to have them via ABCs



class data {
    public:
        data();
        virtual ~data();
        virtual int compare(const data& toCompare)=0;
        virtual void copy(const data& toCopy) = 0;
        virtual void display()=0;
};


class a_name: public data {
    public:
        a_name();
        virtual ~a_name();
        virtual int compare(const a_name& toCompare);
        virtual void copy(const a_name& toCopy);
        virtual void display();
};
