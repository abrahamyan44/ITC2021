#include <iostream>
using namespace std;

int copy_a(int a ){//this function is working with copy of a
    a = 3;
    return a + 1;
}


int return_reference_a(int &a) {//this function is working with reference of a
    a = 3;
    return a + 1 ;
}

class MyClass {
public:
	static int count;

MyClass() {
    count++;
}
};
int MyClass::count = 0;


class GClass {
    private:
    int Size;
    public:
    int *data;

GClass(int size){
    this -> Size = size;
    this -> data = new int[size];
    for(int i = 0; i < size; ++i){
        data[i] = i;
    }
    std::cout << "called constructor" << std::endl;
    }
GClass (const GClass & other){
    this -> Size = other.Size;
    std::cout << "called copy constructor" << std::endl;
    this -> data = new int[other.Size];
    for(int i = 0; i < other.Size; ++i){
        this -> data[i] = other.data[i];
    }
}
GClass & operator =(const GClass & other){
    std::cout << "Assignment operator" << std::endl;
    this->Size = other.Size;
    if(this -> data != nullptr){
        delete [] this->data;
    }
this -> data = new int[other.Size];
for(int i = 0; i < other.Size; ++i){
    this -> data[i] = other.data[i];
}
return *this;
}

~GClass() {
    std::cout << "called destructor" << std::endl;
}
};





int main()
{
    int a=2;
    std::cout << copy_a(a) << std::endl;
    std::cout << a << std::endl << std::endl;//value of isn't changing


    std::cout << return_reference_a(a)<<std::endl;
    std::cout << a;//value is changing because our function is working with reference of a
    std::cout << std::endl;

//////////////////////////////////////////////////////
MyClass m1 ;
MyClass m2;
std::cout << "count of m1 object = " << m1.count << "\t" << "count of m2 object = " << m2.count << std::endl;//static member of class is same for all objects
///////////////////////////////////////////////////////////////////
GClass g1(10);
GClass g2(2);
g1 = g2;
GClass g3(3);
g1 = g2 = g3;
return 0;
}

