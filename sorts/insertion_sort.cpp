#include <iostream>

using namespace std;

void InsertionSort(const int& size, int* arr)
{
    for(int i = 1; i < size; ++i)
    {
        int chosen_member = arr[i];
        int j = i;
        while(j > 0 && arr[j - 1] > chosen_member)
        {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = chosen_member;
    }
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

    InsertionSort(count, array);
    PrintArray(count, array);
    delete[] array;
    return 0;
}
