#include <iostream>

//returns factorial of given value 
int countFactorial(int value){

	if (value == 0 || value == 1){
		return 1;
	}
	else{
		int factorial = 1;
		for(int i = 2; i <= value; i++){
			factorial*=i;
		}
		return factorial;
	}
}

int recursiveFactorial(int value){
	
	if (value == 0 || value == 1)
		return 1;
	if (value == 2)
		return 2;
	else 
		return recursiveFactorial(value - 1) * value;

} 


int main(){
	
	int value;
	std::cout << "Give the number : ";
	std::cin >> value;
	std::cout << "Factorial : " << countFactorial(value) << std::endl;
	std::cout << "Recursive Factorial : " << recursiveFactorial(value) << std::endl;

};
