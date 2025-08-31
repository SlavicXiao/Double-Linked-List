#include<iostream>
#include<vector>

class Node
{
    private:
        int data;
        int size = 0;
        Node* left_ptr = nullptr;
        Node* rigth_ptr = nullptr;

    public:
    //constructors
        Node(){}
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

    //other
        void Append(Node node)
        {
            if(this->GetRightPtr() == nullptr)
            {
                this->SetRightPtr(&node);
                node.SetLeftPtr(this);
            }

            else
            {
                Append(*this->GetRightPtr());
            }
        }

        void Preppend(Node node)
        {
            if(this->GetLeftPtr() == nullptr)
            {
                this->SetLeftPtr(&node);
                node.SetRightPtr(this);
            }
            
            else
            {
                Preppend(*this->GetLeftPtr());
            }
        }

        void Insert(Node node, Node value)
        {
            Node* temp = node.GetRightPtr();
            node.SetRightPtr(&value);
            value.SetLeftPtr(&node);
            value.SetRightPtr(temp);
        }

        void PrintList()
        {
            Node* nextNode = this->GetLeftPtr();
            while(nextNode != nullptr)
            {
                std::cout << this->GetData() << " ";
                nextNode = nextNode->GetLeftPtr();
            }
        }
};

int main()
{
    Node node(1);
    Node prequel(3);
    Node sequel(5);

    node.Append(sequel);
    node.Preppend(prequel);

    node.PrintList();

    return 0;
}