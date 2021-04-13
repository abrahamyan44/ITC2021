#include <iostream>

using namespace std;


void SelectionSort(const int& size, int* a)
{
	for(int i = 0; i < size - 1; ++i)
	{
		int min, index;
		for(int j = i; j < size; ++j)
		{
			if(i == j || min > a[j])
			{
				min = a[j];
				index = j;
			}
		}
		swap(a[i], a[index]);
	}
}


int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	SelectionSort(n, a);
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	delete[] a;
	return 0;
}
