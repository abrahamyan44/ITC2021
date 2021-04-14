#include <iostream>

using namespace std;

void ShellSort(const int& count, int* arr)
{
	for(int interval = count / 2; interval > 0; interval /= 2)
	{
		for(int i = interval; i < count; ++i)
		{
			for(int j = i; j >= interval; j -= interval)
			{
				if(arr[j] < arr[j - interval])
				{
					swap(arr[j], arr[j - interval]);
				}
				else
				{
					break;
				}
			}
		}
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

    ShellSort(count, array);
    PrintArray(count, array);
    delete[] array;
    return 0;
}
