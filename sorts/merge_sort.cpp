#include <iostream>

using namespace std;

void DeclareSortedArray (int* arr, int* arr1, int* arr2, int count)
{
	int index1 = 0, index2 = 0;
	for (int i = 0; i < count; ++i)
	{
		if (index2 >= count - count / 2 || (index1 < count / 2 && arr1[index1] < arr2[index2]))
		{
			arr[i] = arr1[index1];
			++index1;
		}
		else
		{
			arr[i] = arr2[index2];
			++index2;
		}
	}	
}

void DivideMyArray (int* arr, int* arr1, int* arr2, int count)
{
    for (int i = 0; i < count / 2; ++i)
    {
		arr1[i] = arr[i];
	}
	for (int i = 0; i < count - count / 2; ++i)
	{
		arr2[i] = arr[i + count / 2];
	}
}


void MergeSort (int count, int* arr)
{
	if(count == 1)
	{
		return;
	}
	if (count == 2)
	{
		if (arr[0] > arr[1])
		{
			swap(arr[0], arr[1]);
		}

		return;
	}
	int* arr1 = new int[count / 2];
	int* arr2 = new int[count - count / 2];
	DivideMyArray(arr, arr1, arr2, count);
	MergeSort(count / 2, arr1);
	MergeSort(count - count / 2, arr2);
	DeclareSortedArray(arr, arr1, arr2, count);
	delete[] arr1;
	delete[] arr2;
}

void PrintArray (const int& count, int* array)
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

    MergeSort(count, array);
    PrintArray(count, array);
    delete[] array;
    return 0;
}
