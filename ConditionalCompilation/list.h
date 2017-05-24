// Doug Whitley
// CS162-202 Recitation Code Examples
// Spring 2017


class lNode{
    public:
        lNode(int = 0);
        ~lNode();
        lNode* add(int);
        lNode* remove(int);
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
};
