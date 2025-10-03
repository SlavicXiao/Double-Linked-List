#include"node.hpp"

//constructors
    Node::Node()
    {
        left_ptr = nullptr;
        right_ptr = nullptr;
    }
    Node::Node(int x)
    {
        data = x;
        left_ptr = nullptr;
        right_ptr = nullptr;
    }
    
//getters
    Node* Node::GetLeftPtr()
    {
        return Node::left_ptr;
    }

    Node* Node::GetRightPtr()
    {
        return Node::right_ptr;
    }

    int Node::GetData()
    {
        return data;
    }

//setters
    void Node::SetLeftPtr(Node* x)
    {
        this->left_ptr = x;
    }

    void Node::SetRightPtr(Node* x)
    {
        this->right_ptr = x;
    }

    void Node::SetData(int x)
    {
        data = x;
    }
