#include <iostream>
#include <cmath>

using namespace std;


int JumpSearch(const int& n, int* a, const int& value)
{
    int step = sqrt(n);
    int start_pos = 0;
    while(a[min(start_pos + step - 1, n - 1)] < value)
    {
        start_pos += step;
        if(start_pos >= n)
        {
            break;
        }
    }
    for(int i = start_pos; i < min(n, start_pos + step); ++i)
    {
        if(a[i] == value)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << JumpSearch(n, a, 5);
    delete[] a;
    return 0;
}