#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
using namespace std;


/*
Node for doubly-linked list
*/
template <typename T> class Node
{
public:
    T value;
    Node* next;
    Node* previous;

    Node();
//    ~Node();
};




/*
Template for doubly-linked list
*/
template <typename T> class LinkedList
{
    public:
        LinkedList();
//        ~LinkedList();
        T get_front();
        T get_end();
        T pop();
        T get_nth_item(int slice);
        void push_back(T value);
        void add_front(T value);
        bool is_empty();
        void print(ostream &out) const;
        T operator[](int i);
    private:
        Node<T>* front;
        Node<T>* end;
        
};

template<typename T> ostream& operator<<(ostream & out, const LinkedList<T> & list);


#endif