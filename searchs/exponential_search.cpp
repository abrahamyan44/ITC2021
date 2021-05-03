#include <iostream>

using namespace std;

int ExponentialSearch (int start, int end, int* arr, const int& key)
{
    if (arr[start] == key) {
        return start;
    }
    if (end - start <= 1)
    {
        if (arr[end] == key) {
            return end;
        }
        return -1;
    }
    int step = 1;
    int start_pos = start;
    while (arr[min(start_pos + step - 1, end)] < key)
    {
        if (start_pos > end) {
            return -1;
        }
        start_pos += step;
        step *= 2;
    }
    return ExponentialSearch(start_pos, min(start_pos + step - 1, end), arr, key);
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
    cout << ExponentialSearch(0, count - 1, array, key) << endl;
    delete[] array;
    return 0;
}