#include <iostream>

/*
  Linked List:
    Operations:
      - void build(x)

      - int get_at(i)
      - void set_at(i,value)

      - void insert_first(int value)
      - void delete_first()
      - void insert_last(int value) //Same as above,so the below methods I wouldn't write.
      - void delete_last()

      - bool insert_at(i,value)
      - bool delete_at(i)
*/

struct LinkNode
{
    int item;
    LinkNode* pointer;

    /*
        According to Google's style guidebook,it is not a recommended way to use struct same as class.
        It had better just use struct to store members but not methods.
    */

    void intil(LinkNode& v)
    {
        v.item = NULL;
        v.pointer = nullptr;
    }
};


class LinkedList
{
public:
    void build(int x);

    int get_at(int i);
    void set_at(int i,int value);

    void insert_first(int value);
    void delete_first();

    LinkedList(/* args */);
private:
    LinkNode* head;
    int size;
};

LinkedList::LinkedList(/* args */)
{
}

void LinkedList::build(int x)
{
    LinkNode Listhead;
    Listhead.intil(Listhead);

    head = &Listhead;

    LinkNode* cursor; //cursor is to point the index.
    cursor = head;

    Listhead.pointer = new LinkNode();

    for (int i = 1; i < x; i++)
    {
        cursor->pointer = new LinkNode(); //It means the pointed node's pointer point to new node.'->' is for pointer's operation of a pointed object's member.Besides,I love '->',it looks so elegant.
        cursor = (cursor->pointer);
    }

    size = x;
}

int LinkedList::get_at(int i)
{
    LinkNode* cursor = head;
    int v = 0;
    while (v != i)
    {
        cursor = (cursor->pointer);
        v++;
    }
    return cursor->item;
}

void LinkedList::set_at(int i,int value)
{
    LinkNode* cursor = head;
    int v = 0;
    while (v != i)
    {
        cursor = (cursor->pointer);
        v++;
    }
    cursor->item = value;
}

void LinkedList::insert_first(int value)
{
    LinkNode p;
    p.item = value;
    p.pointer = head;

    head = &p;
    size++;
}

void LinkedList::delete_first()
{
    LinkNode* temp = head->pointer;
    delete head;
    head = temp;
    size--;
}

int main()
{
    LinkedList test;
    test.build(5);
    test.set_at(3,10);
    std::cout << test.get_at(0);
}
