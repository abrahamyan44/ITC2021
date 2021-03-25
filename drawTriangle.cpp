#include <iostream>

void drawTriangle(int number){

	for(int i = 1; i <= number; i++){
		
		for(int j = 1; j < i; j++){

			std::cout << " ";		

		}
			
		for(int k = 1; k <= (number*2 - (2*i - 1)); k++ ){

			if(i == 1 || k == 1 || k == (number*2 - (2*i - 1))){

				std::cout << "*";	
			
			}
			else{

				std::cout << " ";

			}
		
		}
		std::cout << std::endl;
	}

}

int main(){

	int number;
	std::cout << "Enter the number : ";
	std::cin >> number;
	drawTriangle(number);

};
