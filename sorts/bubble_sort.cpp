#include <iostream>

using namespace std;


void BubbleSort(const int& size, int* a)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 1; j < size - i; ++j)
        {
            if(a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
            }
        }
    }

    return;
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
    BubbleSort(n, a);
    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}