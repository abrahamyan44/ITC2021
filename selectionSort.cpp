#include <iostream>


void Swapp (int& a, int& b) 
{
	int temporary_variable = a;
	a = b;
	b = temporary_variable;
}

void SortArray (int arr[], int array_length) 
{
	for(int i = 0; i < array_length; i ++)
       	{
		int index_of_minimum_element = i;
		for(int j = i + 1; j < array_length; j++)
		{
			if(arr[j] < arr[index_of_minimum_element])
			{
				index_of_minimum_element = j;
			}
		}

		if(index_of_minimum_element != i) 
		{
			Swapp(arr[index_of_minimum_element], arr[i]);
		}
	}
}

void PrintArray (int arr[], int array_length)
{
	for (int i = 0; i < array_length; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

int main () {
	int arr[5] = {11, 3, 55, 7, 99};
	SortArray(arr, 5);
	PrintArray(arr, 5);
	return 0;
}
