#pragma once
#include"node.h"

class List
{
    private:
        Node* head;
        Node* tail;
        int size;

    public:
        List();
        void Append(Node* node);
        void Prepend(Node* node);
        void Insert(int index, Node* node);
        void DeleteList();
        void Print();

        int Size();

};