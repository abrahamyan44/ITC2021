#include <iostream>
#include <string>

int main() {
    std::string s;
    char x;
    int n;

    std::cout<<"Input your string: ";
    std::cin>>s;
    n = s.length();
    for(int i = 0; i < n/2; ++i) {
        x = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = x;
    }
    std::cout<<s<<std::endl;
    return 0;
}