// Doug Whitley
// CS162-202 Recitation Code Examples
// Spring 2017


class lNode{
    public:
        lNode(int = 0);
        ~lNode();
        void setData(int toAdd);
        int compareData(int toCompare);
        void setNext(lNode* setTo);

lNode*& getNext();
        void display();
    private:
        int data;
        lNode * next;
};


class List{

    public:
        List();
        ~List();
        int add(int);
        int remove(int);
        void display();
    private:
        lNode * head;
        int add(int, lNode*&);
        int remove(int, lNode*&);
        void display(lNode*);

};
