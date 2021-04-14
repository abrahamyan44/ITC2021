#include <iostream>

using namespace std;

void BubbleSort(const int& size, int* arr)
{
    bool swapped = false;
    for(int i = 0; i < size; ++i)
    {
        for(int j = 1; j < size - i; ++j)
        {
            if(arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                swapped = true;
            }
        }

        if(!swapped)
        {
            break;
        }
    }

    return;
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

    BubbleSort(count, array);
    PrintArray(count, array);
    delete[] array;
    return 0;
}
