// Doug Whitley
// CS162-202 Recitation Code Examples
// Spring 2017


class List{
    public:
        List(int = 0);
        ~List();
        List* add(int);
        List* remove(int);
        void display();
    private:
        int data;
        List * next;
};
