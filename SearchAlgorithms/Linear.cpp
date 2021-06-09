#include <iostream>
using namespace std;

int LinearSearch(int arr[], int size, int element) {
	for(int i =0; i < size; ++i) {
		if(arr[i] == element) {
			return i;
			break;
		}
	}
	return -1;
}

int main() 
{
	int size = 5;
	int numbersArray[size]{};
	int element = 0;
	cout << "Enter 5 numbers" << endl;
	for(int i = 0; i < size; ++i) {
		cin >> numbersArray[i];
	}
	cout << endl;

	cout << "Enter number you want to search" << endl;
	cin >> element;

	cout << "arr [ " <<  LinearSearch(numbersArray, size, element) << " ]" << endl; 

	return 0;	
}
