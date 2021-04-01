#include <iostream>

static int s;   //it is stored in the static space
int g;          //it is stored in the static space

int* func()
{
    //memory allocation
    int* ptr = new int; // ptr stored in the heap
    *ptr = 10;
    std::cout << "*ptr = " << *ptr << std::endl;
    std::cout << "ptr = " << ptr << std::endl;
    std::cout << "&ptr = " << &ptr << std::endl;
    return ptr;
}

int main()
{
    static int l = 5;   //it is stored in the static space
    float f = 4.2;      //it is stored in the stack
    int* a = func();
    std::cout << "*a= " << *a << std::endl;
    std::cout << "a = " << a << std::endl;  
    std::cout << "&a = " << &a << std::endl;
    std::cout << "static global s = " << s << "\taddres s = " << &s << std::endl;
    std::cout << "static local l = " << l << "\taddres l = " << &l << std::endl;
    std::cout << "global g = " << g << "\t\taddres g = " << &g << std::endl;
    std::cout << "local f = " << f << "\t\taddres f = " << &f << std::endl;
    
    delete a;
}
