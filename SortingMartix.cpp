#include <iostream>
#include <ctime>

int** CreateMatrix(int size)
{
	int** matrix = new int*[size];
	for (int i = 0; i < size; ++i) {
		matrix[i] = new int[size];
	}
	return matrix;
}

void InitializeMatrixWithRandomNumbers(int** Matrix, int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			Matrix[i][j] = rand()%89 + 10;
		}
	}
}

void PrintMatrix(int** matrix, int size)
{
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void DeleteMatrix(int**& matrix, int size)
{
	for(int i = 0; i < size; ++i){
		delete[]matrix[i];
	}
	delete[]matrix;
	matrix=0;
}

void Swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
int Partition(int** Matrix, int start, int end,int size){
	int wall = start - 1;
	int pivot = Matrix[end / size][end % size];
	int row;
	int column;
	for (int i = start; i < end; ++i) {
		row = i / size;
		column = i % size;
		if (Matrix[row][column] <= pivot) {
			wall++;
			Swap(&Matrix[row][column], &Matrix[wall / size][wall % size]);
		}
	}
	Swap(&Matrix[end / size][end % size], &Matrix[(wall + 1)/size][(wall + 1) % size]);
	return wall + 1 ;
}

void QuickSortForMatrix(int**& Matrix, int start, int end, int size)
{	
	if (start < end) {
		int temporary = Partition(Matrix, start, end, size);
		QuickSortForMatrix(Matrix, start, temporary - 1, size);
		QuickSortForMatrix(Matrix, temporary + 1, end, size);
	}

}

int main()
{	srand(time(0));
	int** Matrix = CreateMatrix(4);
	PrintMatrix(Matrix, 4);
	std::cout << std::endl;
	InitializeMatrixWithRandomNumbers(Matrix, 4);
	std::cout << std::endl;
	PrintMatrix(Matrix, 4);
	QuickSortForMatrix(Matrix, 0, 15, 4);
	std::cout << std::endl;
	PrintMatrix(Matrix, 4);
	return 0;
}

















