#include<iostream>
#include"list.h"
#include"node.h"

List::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void List::Append(Node* node)
{
    if(head == nullptr)
    {
        head = node;
    }

    else if(head != nullptr && tail == nullptr)
    {
        tail = node;
        tail->SetLeftPtr(head);
        head->SetRightPtr(tail);
    }

    else
    {
        Node* tailPrev = tail;
        tail = node;
        tailPrev->SetRightPtr(node);
        node->SetLeftPtr(tailPrev);
    }

    size++;
}

void List::Prepend(Node* node)
{
    if(head == nullptr)
    {
        head = node;
    }

    else if(head != nullptr && tail == nullptr)
    {
        tail = head;
        head = node;
        node->SetRightPtr(tail);
    }

    else
    {
        Node* headPrev = head;
        head = node;
        headPrev->SetLeftPtr(node);
        node->SetRightPtr(headPrev);
    }

    size++;
}

void List::Insert(int index, Node* node)
{
    if(index < 0 || index > size)
    {
        std::cout << "Index out of range.";
    }

    else if(index == 0)
    {
        Prepend(node);
    }

    else if(index == size)
    {
        Append(node);
    }

    else if(index == 1)
    {
        Node* next;
        if(head->GetRightPtr() != nullptr)
        {
            next = head->GetRightPtr();
            next->SetLeftPtr(node);
        }

        head->SetRightPtr(node);
        node->SetLeftPtr(head);

    }

    else
    {
        Node* target = head;

        for(int i = 0; i < index; i++)
        {
            target = target->GetRightPtr();
        }

        Node* prev = target->GetLeftPtr();
        target->SetLeftPtr(node);
        node->SetLeftPtr(prev);
        node->SetRightPtr(target);
        prev->SetRightPtr(node);

        size++;
    }
}

void List::DeleteList()
{
    Node* x = head;
    while(x != nullptr)
    {
        Node* next = x->GetRightPtr();
        delete x;
        x = next;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

void List::Print()
{
    Node* x = head;

    while(x != nullptr)
    {
        std::cout << x->GetData() << " ";
        x = x->GetRightPtr();
    }
}

int List::Size()
{
    return size;
}