#include <iostream>
#include <ctime>

using namespace std;

void SortingMatrixWithQuickSort(int** matrix, int start, int end, const int& column) {
	if (start > end) {
		return;
	}
	if (start >= end - 1) {
		if (matrix[start / column][start % column] > matrix[end / column][end % column]) {
			swap(matrix[start / column][start % column], matrix[end / column][end % column]);
		}
		return;
	}

	int	wall = start;
	for (int i = wall; i < end; ++i) {
		if (matrix[i / column][i % column] < matrix[end / column][end % column]) {
			swap(matrix[i / column][i % column], matrix[wall / column][wall % column]);
			++wall;
		}
	}
	swap(matrix[end / column][end % column], matrix[wall / column][wall % column]);

	SortingMatrixWithQuickSort(matrix, start, wall - 1, column);
	SortingMatrixWithQuickSort(matrix, wall + 1, end, column);
}

void Print(int** matrix, int row, int column) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	srand(time(NULL));
	int row, column;
	cout << "Input matrix row and column" << endl;
	cin >> row >> column;
	int** matrix = new int*[row];
	for (int i = 0; i < row; ++i) {
		matrix[i] = new int[column];
		for (int j = 0; j < column; ++j) {
			matrix[i][j] = rand() % 100;
		}
	}
	SortingMatrixWithQuickSort(matrix, 0, row * column - 1, column);
	Print(matrix, row, column);
	return 0;
}
