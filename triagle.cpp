#include <iostream>

int main() {
    std::cout<<"Input your number: ";
    int n;
    std::cin>>n;
    for(int i = 0; i < n; ++i) {
        std::cout<<"* ";
    }
    std::cout<<std::endl;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            std::cout<<" ";
        }
        std::cout<<"*";
        if(i == n - 1) {
            std::cout<<std::endl;
            break;
        }
        for(int j = 0; j < 2 * n - 3 - 2 * i; ++j) {
            std::cout<<" ";
        }
        std::cout<<"*"<<std::endl;
    }
    return 0;
}