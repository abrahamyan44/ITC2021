#include "vector.hpp"

int main ()
{
    vector<int> arr(4,5);
    arr.push_back(9);
    vector<int> a = arr;
    for(size_t i = 0; i < a.size(); ++i) {
        std::cout<<a[i]<<" ";
    } std::cout << std::endl;
//  a.shrink_to_fit();
    a.reserve(3);
    std::cout <<a.capacity() << std::endl;
    std::cout <<a.size() << std::endl;
     for(size_t i = 0; i < a.size(); ++i) {
        std::cout<<a[i]<<" ";
    } std::cout << std::endl;
    return 0;
}

