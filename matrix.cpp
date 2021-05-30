#include <iostream>
#include <cassert>
#include "matrix.h"

Matrix::Matrix(int s) : matrix(0), size(s)
{
		std::cout << "The size of matrix is: " << s << std::endl;
		assert(s >= 0);
		if(s == 0)
		{
				return;
		}
		matrix=new int*[s];
		for(int i=0; i < s; i++)
		{
				matrix[i]=new int[s];
		}
		assert(matrix != 0);
		assert(size == s);
		for(int i=0; i < s; i++)
		{
				for(int j=0; j < s; j++)
				{
						matrix[i][j]=0;
				}
		}
}

Matrix::Matrix(const Matrix& other) : size(other.size)
{
		std::cout << "Copied" << std::endl;

        matrix = new int*[size];
        for (int i=0; i < size; i++) {
                matrix[i] = new int[size];
        }

        for (int i=0; i < size; i++) {
                for (int j=0; j < size; j++) {
                        matrix[i][j] = other.matrix[i][j];
                }
        }
}

Matrix& Matrix::operator=(const Matrix& other)
		
{
		std::cout << "Assigned" << std::endl;
		size=other.size;
		matrix = new int*[size];
        assert(matrix!=0);
		for(int i = 0; i < size; i++) {
				matrix[i] = new int[size];
        }
            for (int i=0; i < size; i++) {
				for(int j = 0; j < size; j++) {
						matrix[i][j] = other.matrix[i][j];
				}
		}
		return *this;
}

Matrix::Matrix(Matrix&& other) 
{
		std::cout << "Moved" << std::endl;
		matrix=other.matrix;
		size=other.size;
}

Matrix Matrix::operator+ (const Matrix& other)
{
		if(size != other.size)
		{
				std::cout << "Size is not convenient for +ing"
						<< std::endl;
				Matrix m;
                return m;
		} else {
				Matrix new_matrix(size);
				for(int i=0; i < size; i++)
				{
						for(int j=0; j < size; j++)
						{
							new_matrix.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
						}
				}
				return new_matrix;
		}
}

Matrix Matrix::operator- (const Matrix& other)
{
		if(size != other.size)
		{
				std::cout << "Size is not convenient for -ing" << std::endl;
				Matrix m;
				return m;
		} else {
				Matrix new_matrix(size);
				for(int i=0; i < size; i++)
				{
						for(int j=0; j < size; j++)
						{
								new_matrix.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
						}
				}
				return new_matrix;
        }
}

Matrix Matrix::operator* (const Matrix& other)
{
		Matrix new_matrix(size);
		if(size != other.size)
		{
				std::cout << "Size is not convenient for *ing" << std::endl;
				exit(1);
		} else {
		for(int i=0; i < size; i++)
		{
				for(int j=0; j < size; j++)
				{
                        new_matrix.matrix[i][j]=0;
						for(int k=0; k < size; k++)
						{
								new_matrix.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
						}
				}
		}
		return new_matrix;
            }
}

Matrix Matrix::operator* (int number)
{
        Matrix new_matrix(size);
		if(size==0)
		{
				assert(matrix==0);
		}
		for(int i=0; i < size; i++)
				{
						for(int j=0; j < size; j++)
						{
								new_matrix.matrix[i][j] = matrix[i][j] *  number;
						}
				}
		return new_matrix;
}

std::ostream& operator<<(std::ostream& out, const Matrix& other)
{
		if(other.size==0)
		{
				assert(other.matrix==0);
				out << "Size is not convenient for creating matrix with <<";
				out << std::endl;
				return out;
		}
		for(int i=0; i < other.size; i++)
		{
				for(int j=0; j < other.size; j++)
				{
						out << other.matrix[i][j] << " ";
				}
				out << std::endl;
		}
		return out;
}

Matrix::~Matrix()
{
		std::cout << "Destructed" << std::endl;
		if(size==0)
		{
				assert(matrix==0);
				return;
		}
		for(int i=0; i < size; i++)
		{			
                matrix[i]=0;
		}
		delete[] matrix;
		matrix=0;
		size=0;
}


int main()
{
		int number;
		std::cout << "Insert a number, please: ";
		std::cin >> number;
		if(number <= 0)
		{
				std::cout << "Please insert POSITIVE integer: " << std::endl;
				return 1;
		}
		
				Matrix m1(number);
				std::cout << m1 << std::endl;
				Matrix m2(number);
                Matrix m3(number), m4(number), m5(number), m6(number), m7(number);
                m3 = m1 + m2;
                m4 = m1 - m2;
                m5 = m1 * m2;
                m6 = m1 * 5;
                m7 = m1;
				std::cout << "Here is the sum\n" << m3 << std::endl;
				std::cout << "Here is the sub\n" << m4 << std::endl;
				std::cout << "Here is the multiplication\n" << m5 << std::endl;
				std::cout << "Here is the multiplication with number\n" << m6 << std::endl;
                std::cout << "Assignment operator:\n" << m7 << std::endl;
                
	            return 0;
}
