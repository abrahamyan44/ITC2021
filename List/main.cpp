#include <iostream>
#include "List.cpp"

int main()
{
    List<float> b;
    List<float> a(8.3,4.6);
    std::cout << a.Size() << std::endl;
    a.Print();
    a.Insert(2,22.4);
    b = a;
    a.Insert(6,33.6);
    a.Print();
    b.Print();
    a.Erase(5);
    a.Print();
    std::cout << a.Size() << std::endl;
    a.Insert(0,0.3);
    a.Insert(1,1.6);
    a.Insert(12,27);
    a.Print();
    a.Erase(0);
    a.Print();
    a.Erase(4);
    a.Print();
    a.Erase(2);
    a.Print();
}
