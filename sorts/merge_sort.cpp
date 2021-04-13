#include <iostream>

using namespace std;


void MergeSort(int n, int* a)
{
	if(n == 1)
	{
		return;
	}
	if(n == 2)
	{
		if(a[0] > a[1])
		{
			swap(a[0], a[1]);
		}

		return;
	}
	int* a1 = new int[n / 2];
	int* a2 = new int[n - n / 2];
    for(int i = 0; i < n / 2; ++i)
    {
		a1[i] = a[i];
	}
	for(int i = 0; i < n - n / 2; ++i)
	{
		a2[i] = a[i + n / 2];
	}
	MergeSort(n / 2, a1);
	MergeSort(n - n / 2, a2);
	int index1 = 0, index2 = 0;
	for(int i = 0; i < n; ++i)
	{
		if(index2 >= n - n / 2 || (index1 < n / 2 && a1[index1] < a2[index2]))
		{
			a[i] = a1[index1];
			++index1;
		}
		else
		{
			a[i] = a2[index2];
			++index2;
		}
	}
	delete[] a1;
	delete[] a2;
}


int main()
{
	int n;
    cout << "Input element count\n";
    cin >> n;
    int* a = new int[n];
    cout << "Input elements\n";
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	MergeSort(n, a);
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	delete[] a;
	return 0;
}
