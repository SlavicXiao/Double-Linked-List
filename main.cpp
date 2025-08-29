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

    //the good stuff
        void Append(Node head, Node node)
        {
            if(head.GetRightPtr() == nullptr)
            {
                head.SetRightPtr(&node);
                node.SetLeftPtr(&head);
            }

            else
            {
                Append(*head.GetRightPtr(), node);
            }
        }

        void Preppend(Node head, Node node)
        {
            if(head.GetLeftPtr() == nullptr)
            {
                head.SetLeftPtr(&node);
                node.SetRightPtr(&head);
            }
            
            else
            {
                Preppend(*head.GetLeftPtr(), node);
            }
        }

        void Insert(Node node, Node value)
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