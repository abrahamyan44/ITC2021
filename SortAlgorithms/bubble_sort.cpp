#include <iostream>
using namespace std;


void Swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int array[],int size){
	bool swapped=false;
	for (int i = 0; i < size ; ++i){
		for (int j = 0; j < size-i; ++j){
			if (array[j] > array[j+1]){
				Swap(&array[j],&array[j+1]);
				swapped = true;
			}
		}
		if (swapped == false){
			break;
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
	int array[]={2,3,4,5,1};
	Print(array,5);
	BubbleSort(array,5);
	Print(array,5);
}
