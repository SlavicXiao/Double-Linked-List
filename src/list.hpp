#pragma once
#include"node.hpp"

class List
{
    private:
        Node* head;
        Node* tail;
        int size;

    public:
        List();
        void Append(int x);
        void Prepend(int x);
        void Insert(int index, int x);
        
        void DeleteLast();
        void DeleteFirst();
        void Delete(int index);

        void DeleteList();
        void Print();

        int Size();

};