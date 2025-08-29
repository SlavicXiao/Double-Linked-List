#include<iostream>
#include<vector>

class Node
{
    private:
        int data;
        Node* left_ptr = nullptr;
        Node* rigth_ptr = nullptr;

    public:
    //constructors
        Node()
        {

        }
        
        Node(int x) : data(x){}
        
    //getters
        Node* GetLeftPtr()
        {
            return left_ptr;
        }

        Node* GetRightPtr()
        {
            return rigth_ptr;
        }

        int GetData()
        {
            return data;
        }

    //setters
        void SetLeftPtr(Node* x)
        {
            this->left_ptr = x->GetLeftPtr();
        }

        void SetRightPtr(Node* x)
        {
            this->rigth_ptr = x->GetRightPtr();
        }

        void SetData(int x)
        {
            data = x;
        }
};

class LinkedList
{
    private:


    public:
        LinkedList(){}

        void Append(Node node)
        {

        }

        void Preppend(Node node)
        {
            
        }

        void PrintList()
        {

        }
};

int main()
{
    return 0;
}