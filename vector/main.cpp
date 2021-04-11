#include "vector.hpp"

int main ()
{
    Vector<int> array(4,5);
    array.PushBack(9);
    Vector<int> new_array = array;
    for (size_t i = 0; i < new_array.Size(); ++i) {
        std::cout << new_array[i] <<" ";
    } std::cout << std::endl;
//  new_array.ShrinkToFit();
    new_array.Reserve(3);
    std::cout << new_array.Capacity() << std::endl;
    std::cout << new_array.Size() << std::endl;
    for (size_t i = 0; i < new_array.Size(); ++i) {
        std::cout << new_array[i] << " ";
    } std::cout << std::endl;
    return 0;
}

