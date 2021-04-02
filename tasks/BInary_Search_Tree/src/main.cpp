#include <iostream>
#include "tree.hpp"
#include <ctime>





int main(){
	srand(time(0));
	Tree tree;
	tree.Insert(5);
	tree.Insert(15);
	tree.Insert(567);
	tree.Print();
	int* array=new int[8];
	array[0]=17;
	array[1]=48;
	array[2]=78;
	array[3]=798;
	array[4]=14;
	array[5]=99;
	array[6]=121;
	Tree tree_(array,7);
	tree_.Print();
	return 0;
}
