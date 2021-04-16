#include <iostream>
using namespace std;


void SelectionSort(int array[],int size){
	int min_index;
	for (int i = 0; i < size; ++i){
		min_index = i;
		for(int j = i+1; j < size; ++j){
			if (array[j] < array[min_index]){
				min_index = j;
			}
		}
		if (i != min_index){
			int temp=array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
		}
	}
}


void Print(int array[],int size){
	for (int i = 0; i < size; ++i){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int array[]={2,8,10,9,6,7,25};
	Print(array,7);
	SelectionSort(array,7);
	Print(array,7);
}
