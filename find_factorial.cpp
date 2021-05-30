#include <iostream>

int find_recursive_factorial(int number)
{
        if (number == 1)
        {
                return 1;
        }
        return number * find_recursive_factorial(number-1);
}

int find_iterative_factorial(int number)
{
        int factorial=1;
        for (int i=1; i <= number; i++)
        {
                factorial*=i;
        }
        return factorial;
}

int main()
{
        int number;
        std::cout << "Insert a number and expect recursively factorial of that number:" << std::endl;
        std::cin >> number;

        std::cout << find_recursive_factorial(number) << std::endl;

        std::cout << "And here's an iterative answer: " << std::endl;
        std::cout << find_iterative_factorial(number) << std::endl;

        return 0;
}
