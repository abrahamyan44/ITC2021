#include <iostream>
#include <string>

using std::string;

//Draws a trangle with asterisk
void Drow_Triangle(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < i; j++)
        {
            std::cout << " ";
        }
        if(0 == i)
        {
            for(int j = 0; j < size; j++)
                std::cout << "* ";
            std::cout << "\n";
        }
        else
        {
            for(int j = i; j < 2*size; j++)
            {
                if(j == i || j == 2*size-i-2)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
            std::cout << "\n";
        }
    }
}

//Reversed passed string
void Reverse_String(string& str)
{
    char temp;
    int size = str.size();
    for(int i = 0; i < size / 2; i++)
    {
        temp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = temp;
    }
}

//Calculate factorial with recursion
int Rfactorial(unsigned int number)
{
    if(0 == number)
    {
        return 1;
    }
    else
        return number * Rfactorial(number - 1);

}

//Calculate factorial with iteration
int Ifactorial(unsigned int num)
{
    int fact = 1;
    for(int i = 2; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int number;
    std::cout << "Enter n: "; std::cin >> number;
    Drow_Triangle(number);

    string txt;
    std::cout << "\nEnter your string: ";
    std::cin.ignore();
    std::getline(std::cin, txt);
    Reverse_String(txt);
    std::cout << "Reversed string: " << txt << "\n\n";

    std::cout << "Enter positive number: "; std::cin >> number;
    std::cout << "Factorial with recursion: " << Rfactorial(number) << std::endl;
    std::cout << "Factorial with iteration: " << Ifactorial(number) << std::endl;

}
