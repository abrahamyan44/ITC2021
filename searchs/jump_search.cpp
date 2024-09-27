#include <iostream>
#include <cmath>

using namespace std;


int JumpSearch (const int& count, int* arr, const int& value)
{
    int step = sqrt(count);
    int start_pos = 0;
    while (arr[min(start_pos + step - 1, count - 1)] < value)
    {
        start_pos += step;
        if (start_pos >= count)
        {
            break;
        }
    }
    for (int i = start_pos; i < min(count, start_pos + step); ++i)
    {
        if (arr[i] == value)
        {
            return i;
        }
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
    cout << JumpSearch(count, array, key);
    delete[] array;
    return 0;
}