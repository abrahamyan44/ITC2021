#include <iostream>
#include <cmath>

int square(int x)
{
        return pow(x,2);
}

int square_root(int x)
{
        return sqrt(x);
}

int descriminate(int a, int b, int c)
{
        return square(b)-4*a*c;
}

float find_the_only_root(int a, int b)
{
        float x=(float)-b/(float)(2*a);
        return x;
}

float find_the_second_part_of_root(int a, int b, int c)
{
        float x=(float)square_root(descriminate(a,b,c))/(float)(2*a);
        return x;
}

float find_the_first_root(int a, int b, int c)
{
        return find_the_only_root(a,b)+find_the_second_part_of_root(a,b,c);
}

float find_the_second_root(int a, int b, int c)
{
        return find_the_only_root(a,b)-find_the_second_part_of_root(a,b,c); 
}

int main()
{
        int a,b,c;
        std::cout << "Please enter 3 numbers as a, b, c"<<std::endl;
        std::cin >> a >> b >> c;

    if(a!=0)
    {
        if(descriminate(a,b,c)<0)
        {
            std::cout << "\nThere is no root"<<"\nPlease try again"<<std::endl;
        }
        else if(descriminate(a,b,c)==0)
        {
            std::cout << "\nGood news you have 1 root, which is " <<
                    find_the_only_root(a,b)<<std::endl;
        }
        else
        {
            std::cout << "\nHey, you have 2 roots, which are " << 
                    find_the_first_root(a,b,c) << " and " << 
                    find_the_second_root(a,b,c) << std::endl;
        }
    }
    else if (b==0)
    {
            if (c==0)
            {
                    std::cout << "Your root belongs to R " <<std::endl;
            }
            else
            {
                    std::cout << "Invalid answer: " << c << " is equal to 0\n" <<
                            "Please try to enter other values\n ";
            }
    }
    else
    {
        std::cout << "\nYour only root is " << (float)-c/(float)b << std::endl; 
    }
        return 0;
}
