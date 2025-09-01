#include<iostream>
#include<vector>

class Node
{
    private:
        int data;
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

        Node* GetRightPtr()
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
};

class List
{
    private:
        Node* head;
        Node* tail;
        int size;

    public:
        List()
        {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        void Delete()
        {
            Node* x = head;
            while(x != nullptr)
            {
                Node* next = x->GetRightPtr();
                delete x;
                x = next;
            }
        }

        void Append(Node* node)
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
        }

        void Preppend(Node* node)
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
        }

        void Insert(int index, Node* node)
        {
            Node* target = head;
            
            for(int i = 1; i < index; i++)
            {
                target = target->GetRightPtr();
            }

            Node* prev = target->GetLeftPtr();
            target->SetLeftPtr(node);
            node->SetLeftPtr(prev);
            node->SetRightPtr(target);
            prev->SetRightPtr(node);
        }

        void Print()
        {
            Node* x = head;

            while(x != nullptr)
            {
                std::cout << x->GetData() << " ";
                x = x->GetRightPtr();
            }
        }

        int Size()
        {
            Node* x = head;
            while(x != nullptr)
            {
                Node* next = x->GetRightPtr();
                size++;
                x = next;
            }

            return size;
        }

};


int main()
{
    Node* node = new Node(1);
    Node* prequel = new Node(3);
    Node* sequel = new Node(5);
    Node* insert = new Node(11);
    Node* random = new Node(10);

    List abc;

    abc.Append(node);
    abc.Preppend(prequel);
    abc.Append(random);
    abc.Insert(2, insert);

    abc.Print();
    std::cout << "\n" << abc.Size();

    abc.Delete();

    return 0;
}