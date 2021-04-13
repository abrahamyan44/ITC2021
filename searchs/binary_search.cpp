#include <iostream>

using namespace std;


int BinarySearch(const int l, const int r, const int& key, const int* arr)
{
    if(l <= r)
    {
        int mid = (l + r) / 2;
        if(arr[mid] == key)
        {
            return mid;
        }
        if(key > arr[mid])
        {
            return BinarySearch(mid + 1, r, key, arr);
        }
        return BinarySearch(l, mid - 1, key, arr);
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
    cout << BinarySearch(0, n - 1, k, a) << endl;
    delete[] a;
    return 0;
}