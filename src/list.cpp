#include<iostream>
#include"list.hpp"
#include"node.hpp"

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
    std::cout << "Words \n";
    if(index < 0 || index > size)
    {
        std::cout << "Index out of range.\n";
        std::cout << "Index: " << index << "\n";
        std::cout << "Size: " << size << "\n";
    }


    else if(index == 0)
    {
        std::cout << "After range\n";
        Prepend(node);
    }

    else if(index == size)
    {
        std::cout << "After range1\n";
        Append(node);
    }

    /*
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
    */

    else
    {
        std::cout << "After range3\n";
        Node* target = head;

        for(int i = 0; i < index; i++)
        {
            target = target->GetRightPtr();
        }
        std::cout << "After loop";

        std::cout << target->GetData() << " ";
        std::cout << target->GetLeftPtr()->GetData() << " ";

        Node* prev = target->GetLeftPtr();
        std::cout << prev->GetData() << " ";


        target->SetLeftPtr(node);
        node->SetLeftPtr(prev);
        node->SetRightPtr(target);

        std::cout << target->GetLeftPtr()->GetData() << " ";
        
        prev->SetRightPtr(node);

        std::cout << "the end";

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