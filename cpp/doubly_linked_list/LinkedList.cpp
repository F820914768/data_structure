#include "LinkedList.h"
#include <iostream>
using namespace std;

// Constructor function for LinkedList Node
template<typename T> Node<T>::Node()
{
    value = NULL;
    next = nullptr;
    previous = nullptr;
}


// Constructor of Doubly-linked list
template<typename listType> LinkedList<listType>::LinkedList()
{
    cout << "construct a linked list" << endl;
    front = new Node<listType>;
    end = new Node<listType>;
    front->next = end;
    front->previous = end;
    end->previous = front;
    end->next = front;
}

// add value at the end of Doubly-linked list
template<typename T> void LinkedList<T>::push_back(T value)
{
    Node<T>* new_node_ptr  = new Node<T>;
    new_node_ptr->value = value; 
    Node<T>* temp = end->previous;
    new_node_ptr->next = end;
    new_node_ptr->previous = temp;
    end->previous = new_node_ptr;
    temp->next = new_node_ptr;
}

// add value at the front of doubly-linked list
template<typename T> void LinkedList<T>::add_front(T value)
{
    Node<T>* new_node_ptr  = new Node<T>;
    new_node_ptr->value = value;
    Node<T>* temp = front->next;
    front->next = new_node_ptr;
    temp->previous = new_node_ptr;
    new_node_ptr->next = temp;
    new_node_ptr->previous = front;
}

// get nth value of doubly-linked list
template<typename T> T LinkedList<T>::get_nth_item(int slice)
{
    Node<T>* current = front;
    cout << "get nth item" << endl;
    for (int i = 0; i <= slice; ++i)
    {
        current = current->next;
        if (current->value == NULL)
        {
            return NULL;
        }
    }
    return current->value;
}


// get the first item of doubly-linked list
template<typename T> T LinkedList<T>::get_front()
{
    return front->next->value;
}


// get the last item of doubly-linked list
template<typename T> T LinkedList<T>::get_end()
{
    return end->previous->value;
}


// whether or not the list is empty
template<typename T> bool LinkedList<T>::is_empty()
{
    return (front->next == end);   
}


// print all the value in doubly linked list
template<typename T> void LinkedList<T>::print(ostream &out) const
{
    Node<T>* current = front->next;

    while (current->value != NULL)
    {
        out << current->value << " ";
        current = current->next;
    } 
}


// pop out the last value of doubly-linked list, then delete the last node
template<typename T> T LinkedList<T>::pop()
{
    if (is_empty()){
        cout << "list empty" << endl;
        return NULL;
    }
    Node<T>* current = end->previous;
    T value = current->value;
    end->previous = current->previous;
    current->previous->next = end;
    delete current;
    return value;
}


// overloading of << operator for linked list
template<typename T> ostream& operator<<(ostream &out, const LinkedList<T> & list)
{
    list.print(out);
    return out;
}


// overloading of [] operator for linked list
template<typename T> T LinkedList<T>::operator[](int i)
{
    return get_nth_item(i);
}



int test(){
    LinkedList<int> list ;

    list.push_back(3);
    list.push_back(7);
    list.push_back(2);
    cout << list[1] << endl;
    cout << list << endl;
    cout << list.pop() << endl;
    cout << list << endl;
    return 1;
}