#include <iostream>

class Matrix
{
private:
		int** matrix;
		int size;
public:
		Matrix(int size = 0);
		Matrix(const Matrix&); //copy constructor
		Matrix(Matrix&&); //move constructor
		Matrix& operator=(const Matrix&); //assignment operator

		Matrix operator+(const Matrix&);
		Matrix operator-(const Matrix&);
		Matrix operator*(const Matrix&);
		friend std::ostream& operator<<(std::ostream&, const Matrix&);
		Matrix operator*(int);

		~Matrix();
};
