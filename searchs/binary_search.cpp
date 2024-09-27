#include <iostream>

using namespace std;

int BinarySearch (const int left, const int right, const int& key, const int* arr)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            return BinarySearch(mid + 1, right, key, arr);
        }
        return BinarySearch(left, mid - 1, key, arr);
    }

    return -1;
}

int main()
{
    int count;
    int key;
    cout << "Input members count and key\n";
    cin >> count >> key;
    int* array = new int[count];
    cout << "Input array members\n";
    for (int i = 0; i < count; ++i)
    {
        cin >> array[i];
    }
    cout << BinarySearch(0, count - 1, key, array) << endl;
    delete[] array;
    return 0;
}