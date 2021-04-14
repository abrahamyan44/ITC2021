#include <iostream>

using namespace std;

void QuickSort(int start, int wall, int end, int* arr)
{
    if(start >= end)
    {
        return;
    }
    if(start + 1 == end)
    {
        if(arr[start] > arr[end])
        {
            swap(arr[start], arr[end]);
        }
        return;
    }
    for(int i = wall; i < end; ++i)
    {
        if(arr[i] < arr[end])
        {
            swap(arr[wall], arr[i]);
            ++wall;
        }
    }
    swap(arr[wall], arr[end]);
    QuickSort(start, start, wall - 1, arr);
    QuickSort(wall + 1, wall + 1, end, arr);
}

void PrintArray(const int& count, int* array)
{
    for (int i = 0; i < count; ++i)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    int count;
	cout << "Input element count\n";
    cin >> count;
    int* array = new int[count];
	cout << "Input elements\n";
    for (int i = 0; i < count; ++i) {
        cin >> array[i];
    }

    QuickSort(0, 0, count - 1, array);
    PrintArray(count, array);
    delete[] array;
    return 0;
}
