#include <iostream>

//gets two integer values as input and returns the maximum value
//if values are equal, returns  "They are equal!" 
int findMaxValue(int a, int b){
	if(a == b){
		std::cout << "They are equal!" << std::endl;
		return 0; 
	}
	else{
		return a > b ? a : b;
	}
}
//gets two integer values as input and returns the minimum value
//if values are equal, returns "They are equal!"  
int findMinValue(int a, int b){
	if(a == b){
		std::cout << "They are equal!" << std::endl;
		return 0;
	}
	else{
		return a < b ? a : b;
	}
}

//gets two integer values as input and calculate the sum
int calculateSum(int a, int b){
	return a + b;
}


int main(){
	int a, b;
	std::cout << "Insert a: ";
	std::cin >> a;
	std::cout << "Insert b: ";
	std::cin >> b;
	
	std::cout << "Min: " << findMinValue(a,b) << std::endl;
	std::cout << "Max: " << findMaxValue(a,b) << std::endl;
	std::cout << "Sum: " << calculateSum(a,b) << std::endl;


};
