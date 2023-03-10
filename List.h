#pragma once
#include<iostream>
#include<fstream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T);

};

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(istream& is);
    void insert_front(T);
    void insert_back(T);
    T delete_front();
    T delete_back();
    bool is_empty();
    void display();
    T length();
    void search(T);

    void duplicate_even();
    void reverse();
    void delete_not_unique();

private:
    Node<T>* head;
    Node<T>* tail;
    int size;

};
#include "List.tpp"
