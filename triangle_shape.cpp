#include <iostream>

void draw_shape(int number)
{
        for (int i = 0; i < number; i++)
        {
                for (int j = 0; j < number*2-1; j++)
                {
                        int k = number*2-2; //number of columns

                        //three conditions
                        if ((i==0 && j%2 == 0) || i==j || k == i+j)
                        {
                                std::cout << "*";
                        }
                        else
                        {
                                std::cout << " ";
                        }
                }
                std::cout << std::endl;
        }
}

int main()
{
        int num;

        std::cout << "Please enter a number: " << std::endl;
        std::cin >> num;

        std::cout << "Here's your triangle: " << std::endl;
        draw_shape(num);

        return 0;
}
