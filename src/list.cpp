#include<iostream>
#include"list.hpp"
#include"node.hpp"

List::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void List::Append(int x)
{
    Node* node = new Node(x);

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

void List::Prepend(int x)
{
    Node* node = new Node(x);

    if(head == nullptr)
    {
        head = node;
    }

    else if(head != nullptr && tail == nullptr)
    {
        tail = head;
        head = node;
        head->SetRightPtr(tail);
        tail->SetLeftPtr(head);
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

void List::Insert(int index, int x)
{
    Node* node = new Node(x);

    if(index < 0 || index > size)
    {
        std::cout << "Index out of range.\n";
    }


    else if(index == 0)
    {
        Prepend(node->GetData());
    }

    else if(index == size)
    {
        Append(node->GetData());
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

void List::DeleteLast()
{
    if(tail != nullptr)
    {
        Node* target = tail;
        tail = tail->GetLeftPtr();
        tail->SetRightPtr(nullptr);

        delete target;
        size--;
    }
    
    else if (head != nullptr)
    {
        Node* target = head;
        head = nullptr;
        
        delete target;
        size--;
    }

    else
    {
        std::cout << "The list is empty. ";
    }
}

void List::DeleteFirst()
{
    if(head != nullptr && tail == nullptr)
    {
        head = nullptr;
        size--;
    }

    else if(head != nullptr)
    {
        Node* target = head;
        head = head->GetRightPtr();

        delete target;
        size--;
    }

    else
    {
        std::cout << "The list is empty. ";
    }
}

void List::Delete(int index)
{
    if(size == 0)
    {
        std::cout << "The list is empty. ";
    }

    else if(index < 0 || index > size)
    {
        std::cout << "Index out of range. ";
    }

    else if(index == 0) DeleteFirst();
    else if(index == size - 1) DeleteLast(); 

    else
    {
        Node* target = head;

        int i;
        for(i = 0; i < index; i++)
        {
            target = target->GetRightPtr();
        }

        Node* prev = target->GetLeftPtr();
        Node* next = target->GetRightPtr();
        prev->SetRightPtr(next);
        next->SetLeftPtr(prev);

        delete target;
        size--;
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