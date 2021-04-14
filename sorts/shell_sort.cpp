#include <iostream>

using namespace std;


void ShellSort(const int& n, int* a)
{
	for(int interval = n / 2; interval > 0; interval /= 2)
	{
		for(int i = interval; i < n; ++i)
		{
			for(int j = i; j >= interval; j -= interval)
			{
				if(a[j] < a[j - interval])
				{
					swap(a[j], a[j - interval]);
				}
				else
				{
					break;
				}
			}
		}
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
	ShellSort(n, a);
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	delete[] a;
	return 0;
}
