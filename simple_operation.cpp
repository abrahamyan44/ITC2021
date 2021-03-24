#include <iostream>
#include <string>

//the function for finding the minimum of two integer numbers
int find_min (int a, int b)
{
        if ( a < b )
        {
            return a;
        }
        else
        {
            return b;
        }
}

//the function for finding the maximum of two integer numbers
int find_max (int a, int b)
{
        if ( a > b )
        {
            return a;
        }
        else 
        {
            return b;
        }
}

//the function for finding the sum of two integer numbers 
int find_sum (int a, int b)
{
        return a+b;
}

int main()
{
        int num1,num2;
        std::cout << "Hi! You're going to insert two integer numbers. Let's start!" << std::endl;
        std::cout << "Insert the first number: ";
        std::cin >> num1;   
        std::cout << "Insert the second number: ";
        std::cin >> num2;
        std::cout << std::endl;

        std::cout << "Your first input is " << num1 << " and the second is " << num2 << std::endl;
        std::cout << std::endl;

        std::cout << "The minimum of your numbers is " << find_min (num1, num2) << std::endl;
        std::cout << "The maximum of your numbers is " << find_max (num1, num2) << std::endl;
        std::cout << "The sum of your numbers is " << find_sum (num1, num2) << std::endl;

        return 0;
}
