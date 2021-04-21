#include <iostream>

typedef long long ll;

using namespace std;

ll FindUglyNumber(ll number, int index) {
    if (number == 1 || number % 2 == 0 || number % 3 == 0 || number % 5 == 0) {
        if (index == 0) {
            return number;
        }
        return FindUglyNumber(number + 1, index - 1);
    }
    return FindUglyNumber(number + 1, index);
}

int main() {
    int index;
    cout << "Input ugly number`s index, that you want to find\n" << "(1 is 0th ugly number) " <<endl;
    cin >> index;
    cout << index << "th ugly number: " << FindUglyNumber(1, index) << endl;
    return 0;
}