#include<iostream>
#include<vector>

class Node
{
    private:
        int data;
        int size = 0;
        Node* left_ptr = nullptr;
        Node* right_ptr = nullptr;

    public:
    //constructors
        Node(){}
        Node(int x) : data(x){}
        
    //getters
        Node* GetLeftPtr()
        {
            return left_ptr;
        }

        Node* GetRigthPtr()
        {
            return right_ptr;
        }

        int GetData()
        {
            return data;
        }

    //setters
        void SetLeftPtr(Node* x)
        {
            this->left_ptr = x;
        }

        void SetRightPtr(Node* x)
        {
            this->right_ptr = x;
        }

        void SetData(int x)
        {
            data = x;
        }

    //other
        void Append(Node* node)
        {
            if(this->GetRigthPtr() == nullptr)
            {
                this->SetRightPtr(node);
                node->SetLeftPtr(this);
            }

            else
            {
                Append(this->GetRigthPtr());
            }
        }

        void Preppend(Node* node)
        {
            if(this->GetLeftPtr() == nullptr)
            {
                this->SetLeftPtr(node);
                node->SetRightPtr(this);
            }
            
            else
            {
                Preppend(this->GetLeftPtr());
            }
        }

        void Insert(Node* node)
        {
            Node* temp = this->GetRigthPtr();
            
            node->SetRightPtr(temp);
            node->SetLeftPtr(this);
            this->SetRightPtr(node);

            temp->SetLeftPtr(node);
        }

        void PrintList()
        {
            Node* nextNode = this;
            while(nextNode != nullptr)
            {
                std::cout << nextNode->GetData() << " ";
                nextNode = nextNode->GetRigthPtr();
            }
        }
};

int main()
{
    Node* node = new Node(1);
    Node* prequel = new Node(3);
    Node* sequel = new Node(5);
    Node* insert = new Node(11);

    node->Append(sequel);
    node->Preppend(prequel);

    node->PrintList();

    return 0;
}