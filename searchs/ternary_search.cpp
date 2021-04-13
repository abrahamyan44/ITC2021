#include <iostream>

using namespace std;


int TernarySearch(const int l, const int r, const int& key, const int* arr)
{
    if(l <= r)
    {
        int mid1 = l + (r - l) / 3, mid2 = l + 2 * (r - l) / 3;
        if(arr[mid1] == key)
        {
            return mid1;
        }
        if(arr[mid2] == key)
        {
            return mid2;
        }
        if(key < arr[mid1])
        {
            return TernarySearch(l, mid1 - 1, key, arr);
        }
        if(key > arr[mid2])
        {
            return TernarySearch(mid2 + 1, r, key, arr);
        }
        return TernarySearch(mid1, mid2, key, arr);
    }

    return -1;
}


int main()
{
    int n, k;
    cin >> n >> k;
    int* a = new int[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << TernarySearch(0, n - 1, k, a) << endl;
    delete[] a;
    return 0;
}