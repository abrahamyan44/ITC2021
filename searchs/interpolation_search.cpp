#include <iostream>

using namespace std;

int InterpolationSearch (const int left, const int right, const int& key, const int* arr)
{
    if (left <= right)
    {
        int mid = left + ((key - arr[left]) * (right - left) / (arr[right] - arr[left]));
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            return InterpolationSearch(mid + 1, right, key, arr);
        }
        return InterpolationSearch(left, mid - 1, key, arr);
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
    cout << InterpolationSearch(0, count - 1, key, array) << endl;
    delete[] array;
    return 0;
}