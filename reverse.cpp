#include <iostream>
#include <string.h>

using std::string;

void ReverseString(string s)
{
	string rev;
	int ln = s.length()-1;

	for (int i = ln; i >= 0; --i) {	
		rev += s[i];
	}
	std::cout << rev << std::endl;
}

int main()
{
	string str;
	std::cout << "Enter a string: ";
	std::cin >> str;

    //function call
    ReverseString(str);
}
