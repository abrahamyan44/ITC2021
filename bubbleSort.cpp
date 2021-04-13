#include <iostream>

void Swapp (int& a, int& b)
{
	int temporary_variable = a;
	a = b;
	b = temporary_variable;
}

void SortArray (int arr[], int array_length)
{
	for(int j = 0; j < array_length; j++)
	{
		for(int i = 0; i < array_length - j; i++)
		{
			if(arr[i] > arr[i + 1])
			{
				Swapp(arr[i], arr[i + 1]);
			}
		}
	}	
}

void PrintArray (int arr[], int array_length) 
{
	for(int i = 0; i < array_length; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

int main ()
{
	int arr[5] = {9, 7, 5, 4, 0};
	SortArray(arr, 5);
	PrintArray(arr, 5);
	return 0;
}
