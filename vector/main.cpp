#include "vector.hpp"

int main ()
{
    Vector<int> array (4,5);
    array.PushBack (9);
    Vector<int> arr = array;
    for (size_t i = 0; i < arr.Size(); ++i) {
        std::cout << arr[i] <<" ";
    } std::cout << std::endl;
//  array.ShrinkToFit();
    arr.Reserve (3);
    std::cout << arr.Capacity() << std::endl;
    std::cout << arr.Size() << std::endl;
    for (size_t i = 0; i < arr.Size(); ++i) {
        std::cout << arr[i] << " ";
    } std::cout << std::endl;
    return 0;
}
