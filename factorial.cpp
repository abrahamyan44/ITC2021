#include <iostream>

int calculate_factorial(int n) {
    if(n <= 1) {
        return 1;
    }
    return n * calculate_factorial(n - 1);
}

int main() {
    int n, ans1 = 1, ans2 = 1;
    std::cout << "Input positive number: ";
    std::cin >> n;
    for(int i = 2; i <= n; ++i) {
        ans1 *= i;
    }
    ans2 = calculate_factorial(n);
    std::cout<<"Answer with iterative method: "<<ans1<<std::endl;
    std::cout<<"Answer with recursive method: "<<ans2<<std::endl;
    return 0;
}