#include <iostream>
#include <string>

//function for reversing a given string
std::string reverse_string(std::string str)
{
    std::string reversed_str(str.length(), '\0');
    int j = str.length();

     for (int i=0; i < str.length(); i++)
     {
        reversed_str[--j] = str[i];
     }
        return reversed_str;
}

int main()
{
        std::string str;

        std::cout << "Insert your string, please:" << std::endl;
        getline(std::cin, str);

        std::cout << "Here's the reversed output:" <<std::endl;
        std::cout << reverse_string(str) << std::endl;

        return 0;
}
