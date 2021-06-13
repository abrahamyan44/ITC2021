#include <iostream>

int factorial_recursion(int n) {
    if(n > 1){
        return n * factorial_recursion(n - 1);
	} else {
        return 1;
	}
}

int factorial_iteration(int n) {
    int rec = 1;
    for(int i = 2; i <= n; ++i) {
        rec *= i;
    }
    return rec;
}

int main(){
    int n;
    std::cout << "Input number" << std::endl;
    std::cin >> n;
    std::cout << factorial_recursion(n)<<std::endl;
    std::cout << factorial_iteration(n)<<std::endl;
    std::cout << std::endl;
    return 0;
}
