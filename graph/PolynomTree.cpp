#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool IsSymbolOperation(char symbol) {
    return (symbol == '+' || symbol == '/' || symbol == '*' || symbol == '-');
}

bool IsLetter(char symbol) {
    return (symbol >= 'a' && symbol <= 'z') || (symbol <='Z' && symbol >= 'A') || (symbol >= '0' || symbol <= '9');
}

bool IsExpressionValid(string s) {
    if (IsSymbolOperation(s[0]) || IsSymbolOperation(s[s.length() - 1])) {
        return false;
    }
    stack<char> brackets;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            continue;
        }
        if (s[i] == '(') {
            if (i > 0 && IsLetter(s[i - 1])) {
                return false;
            }
            brackets.push('(');
        } else if (s[i] == ')') {
            if (i < s.length() - 1 && IsLetter(s[i + 1])) {
                return false;
            }
            if (brackets.empty()) {
                return false;
            } else {
                brackets.pop();
            }
        } else if (IsSymbolOperation(s[i])) {
            if (s[i - 1] == '(' || s[i + 1] == ')' || IsSymbolOperation(s[i - 1]) || IsSymbolOperation(s[i + 1])) {
                return false;
            }
        } else if (IsLetter(s[i])) {
            if ((i > 0 && IsLetter(s[i - 1])) || (i < s.length() - 1 && IsLetter(s[i + 1]))) {
                return false;
            }
        } else {
            return false;
        }
    }
    return brackets.empty();
}

int main() {
    string s;
    cin >> s;
    vector<vector<char>> v;
    if (IsExpressionValid(s)) {

    } else {
        cout << "Your expression not valid" << endl;
    }

    return 0;
}