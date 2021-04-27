#include <iostream>
#include <cassert>

int** createMatrix(int size) {
	int** matrix = new int*[size];
	for (int i = 0; i < size; ++i) {
		matrix[i] = new int [size];
	}
	return matrix;
}

void initializMatrix(int** matrix, int size) {
	for (int i = 0; i < size; ++i) { 
    	for (int j = 0; j < size; ++j) {
        		if (i == j) {
            		matrix[i][j] = 2;
       			} else if (i < j) {
            		matrix[i][j] = 0;
        		} else {
            		matrix[i][j] = 1;
        		}
    	}
	}
}
 
void printMatrix(int** matrix, int size) {
	if (0 == matrix || 0 == size) {
		std::cout << "No Matrix" << std::endl;
		return;
	}
	for (int i = 0; i < size; ++i) { 
    	for (int j = 0; j < size; ++j) {
        	std::cout << matrix[i][j] << " ";
    	}
    	std::cout << std::endl;
   	}
}	

void deleteMatrix(int**& matrix, int size) {
	assert(0 != matrix);

	for (int i = 0; i < size; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;

	matrix = 0;
	size = 0;
	assert(0 == matrix);
}

int main()
{
	int size = 0;
	std::cout << "Enter Matrix size: ";
	std::cin >> size;

	if (size <= 0) {
		std::cout << "Invalid input:" << std::endl;
	} else {
	int** Matrix = createMatrix(size);

	assert(0 != Matrix);

	initializMatrix(Matrix, size);	
	printMatrix(Matrix, size);	
	deleteMatrix(Matrix, size);
	printMatrix(Matrix, size);	

	//assert(0 == Matrix);
	}
	return 0;
}
