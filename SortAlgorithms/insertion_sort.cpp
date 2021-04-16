#include <iostream>
using namespace std;

void Swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void InsertionSort(int array[],int size){
	int key;
	int j;
	for (int i = 1; i < size; ++i){
		key = array[i];
		j=i-1;
		while (array[j] > key && j >= 0){
			array[j+1] = array[j];
			j -= 1;
		}
		array[j+1] = key;
	}
}

void Print(int array[],int size){
	for (int i = 0; i < size; ++i){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int array[]={2,82,1,9,6,7,25};
	Print(array,7);
	InsertionSort(array,7);
	Print(array,7);
}
