#include<iostream>
#include<vector>
#include"node.hpp"
#include"list.hpp"

int main()
{
    List abc;
    abc.Append(1);
    abc.Prepend(3);
    abc.Append(5);
    abc.Insert(1, 11);
    abc.Append(10);
   
    //3   *11*    1 5 10

    abc.Delete(1);
    abc.DeleteFirst();
    abc.DeleteLast();
    
    abc.Print();
    std::cout << "\n" << abc.Size();

    abc.DeleteList();

    return 0;
}