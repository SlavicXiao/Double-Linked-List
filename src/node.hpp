#pragma once

class Node
{
    private:
        int data;
        Node* left_ptr = nullptr;
        Node* right_ptr = nullptr;

    public:
    //constructors
        Node();
        Node(int x);
        
    //getters
        Node* GetLeftPtr();

        Node* GetRightPtr();

        int GetData();

    //setters
        void SetLeftPtr(Node* x);

        void SetRightPtr(Node* x);

        void SetData(int x);
};