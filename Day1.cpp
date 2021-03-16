#include <iostream>

int min(int x, int y)   //finds the least of the two numbers
{
    int result;
    result = (x < y) ? x : y;
    return result;
}

int max(int x, int y)   //finds the biggest of the two numbers
{
    int result;
    result = (x > y) ? x : y;
    return result;
}

int sum(int x, int y)   //calculate the sum of two numbers
{
    return(x + y);
}

int main()
{
    int a, b;
    std::cout << "Insert a: "; std::cin >> a;
    std::cout << "Insert b: "; std::cin >> b;
    std::cout << "a: " << a << "\tb: " << b <<std::endl;
    std::cout << "Min: " << min(a,b) << std::endl;
    std::cout << "Max: " << max(a,b) << std::endl;
    std::cout << "Sum: " << sum(a,b) << std::endl;
}
