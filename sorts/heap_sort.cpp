#include <iostream>

using namespace std;


void HeapSwapping(const int& n, int index, int* a)
{
	int max = index;
	int left = 2 * index + 1, right = 2 * index + 2;
	if(left < n && a[left] > a[max])
	{
		max = left;
	}

	if(right < n && a[right] > a[max])
	{
		max = right;
	}

	if(max != index)
	{
		swap(a[max], a[index]);
		HeapSwapping(n, max, a);
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
	HeapSort(n, a);
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	delete[] a;
	return 0;
}
