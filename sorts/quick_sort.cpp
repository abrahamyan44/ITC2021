#include <iostream>

using namespace std;


void QuickSort(int start, int wall, int end, int* a)
{
    if(start >= end)
    {
        return;
    }
    if(start + 1 == end)
    {
        if(a[start] > a[end])
        {
            swap(a[start], a[end]);
        }
        return;
    }
    for(int i = wall; i < end; ++i)
    {
        if(a[i] < a[end])
        {
            swap(a[wall], a[i]);
            ++wall;
        }
    }
    swap(a[wall], a[end]);
    QuickSort(start, start, wall - 1, a);
    QuickSort(wall + 1, wall + 1, end, a);
}


int main()
{
    int n;
    cout << "Input element count\n";
    cin >> n;
    int* a = new int[n];
    cout << "Input elements\n";

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    QuickSort(0, 0, n - 1, a);
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}
