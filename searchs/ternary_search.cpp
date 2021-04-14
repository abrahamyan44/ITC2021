#include <iostream>

using namespace std;

int TernarySearch (const int left, const int right, const int& key, const int* arr)
{
    if (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = left + 2 * (right - left) / 3;
        if (arr[mid1] == key)
        {
            return mid1;
        }
        if (arr[mid2] == key)
        {
            return mid2;
        }
        if (key < arr[mid1])
        {
            return TernarySearch(left, mid1 - 1, key, arr);
        }
        if (key > arr[mid2])
        {
            return TernarySearch(mid2 + 1, right, key, arr);
        }
        return TernarySearch(mid1, mid2, key, arr);
    }

    return -1;
}

int main()
{
    int count, key;
    cout << "Input members count and key\n";
    cin >> count >> key;
    int* array = new int[count];
    cout << "Input array members\n";
    for(int i = 0; i < count; ++i)
    {
        cin >> array[i];
    }
    cout << TernarySearch(0, count - 1, key, array) << endl;
    delete[] array;

    return 0;
}