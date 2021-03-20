#include <iostream> 

void displayShape(int n)
{
	if (n <= 0 ) {
		std::cout << "Invalid input: ";
	}
	for (int i = n; i > 0; --i) {
		for (int k = i; k < n; ++k) {
        	std::cout << " ";
		}
      	
		for (int j = 1; j <= i ; ++j) {
        	if (j == 1 || j == i || i == n) {
            	std::cout << " *";
         	} else {
            	std::cout << "  ";
         	}
		}
		std::cout<<std::endl;
	}
}
  
int main()
{	
	//initialization
	int rows = 0;

	std::cout << "Enter number of rows: ";
	std::cin >> rows;

	//function call
	displayShape(rows);
	return 0;
}
