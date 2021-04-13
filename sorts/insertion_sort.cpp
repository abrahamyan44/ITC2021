#include <iostream>

using namespace std;


void InsertionSort(const int& size, int* a)
{
    for(int i = 1; i < size; ++i)
    {
        int chosen_member = a[i];
        int j = i;
        while(j > 0 && a[j - 1] > chosen_member)
        {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = chosen_member;
    }
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
    InsertionSort(n, a);
    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}