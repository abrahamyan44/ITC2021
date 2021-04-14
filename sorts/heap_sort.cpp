#include <iostream>

using namespace std;

void HeapSwapping(const int& count, int index, int* arr)
{
	int max = index;
	int left = 2 * index + 1, right = 2 * index + 2;
	if(left < count && arr[left] > arr[max])
	{
		max = left;
	}

	if(right < count && arr[right] > arr[max])
	{
		max = right;
	}

	if(max != index)
	{
		swap(arr[max], arr[index]);
		HeapSwapping(count, max, arr);
	}
}

void HeapSort(const int& n, int* a)
{
	for(int i = n / 2 - 1; i >= 0; --i)
	{
		HeapSwapping(n, i, a);
	}

	for(int i = n - 1; i >= 0; --i)
	{
		swap(a[0], a[i]);
		HeapSwapping(i, 0, a);
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

    HeapSort(count, array);
    PrintArray(count, array);
    delete[] array;
    return 0;
}
