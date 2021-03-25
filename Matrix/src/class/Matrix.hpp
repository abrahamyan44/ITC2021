#pragma once

class Matrix
{
private:
    int** m_matrix; int m_size;
    void initialize();

public:
    Matrix(int size = 0);
    Matrix(const Matrix&);
    ~Matrix();

public:
    void print();
    Matrix& operator=(const Matrix&);
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix operator*(const int);
};
