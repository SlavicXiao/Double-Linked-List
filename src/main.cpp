#include<iostream>
#include<vector>
#include"node.hpp"
#include"list.hpp"

int main()
{
    Node* node = new Node(1);
    Node* prequel = new Node(3);
    Node* sequel = new Node(5);
    Node* insert = new Node(11);
    Node* random = new Node(10);

    List abc;

    abc.Append(node);
    abc.Prepend(prequel);
    abc.Append(sequel);

    abc.Insert(2, insert);
    abc.Print();
    
    abc.Append(random);
   
    //3   *11*    1 5 10

    abc.Print();
    std::cout << "\n" << abc.Size();

    abc.DeleteList();

    return 0;
}