#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cout << "Input string: ";
    std::cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        std::cout << s[s.length() - i - 1];
    }
    std::cout << std::endl;
    return 0;
}
