#include"node.hpp"

//constructors
    Node::Node()
    {
        
    }
    Node::Node(int x)
    {
        data = x;
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
