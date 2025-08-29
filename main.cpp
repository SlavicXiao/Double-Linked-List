#include<iostream>
#include<vector>
#include<initializer_list>

class Node
{
    private:
        int data;
        Node* left_ptr = nullptr;
        Node* rigth_ptr = nullptr;

    public:

    //constructors
        Node()
        {}

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
        std::vector<Node> array;

    public:
        LinkedList(){}
        LinkedList(std::initializer_list<int> values)
        {
            for(auto v : values)
            {
                Node node(v);
                array.push_back(node);
            }
            Link();
        }

        void Link()
        {
            if(array.size() > 1)
            {
                for(int i = 0; i < array.size() - 1; i++)
                {
                    array[i].SetLeftPtr(array[i + 1].GetLeftPtr()); 
                }

                for(int i = array.size() - 1; i > 0; i--)
                {
                    array[i].SetRightPtr(array[i - 1].GetRightPtr());
                }
            }
        }
};


int main()
{

    return 0;
}