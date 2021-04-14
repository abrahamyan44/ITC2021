#include <iostream>

using namespace std;

void SelectionSort(const int& size, int* arr)
{
	for(int i = 0; i < size - 1; ++i)
	{
		int min, index;
		for(int j = i; j < size; ++j)
		{
			if(i == j || min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		}
		swap(arr[i], arr[index]);
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

    SelectionSort(count, array);
    PrintArray(count, array);
    delete[] array;
    return 0;
}