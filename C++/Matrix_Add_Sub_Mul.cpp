#include <iostream>
#include <cassert>
#include <ctime>

class Matrix 
{
    public:
    Matrix(int m_row=0,int m_col=0);    
    void print() const;
    int** m_matrix;
    int m_row;
    int m_col;
    void initialize();
    ~Matrix();
};

Matrix::Matrix(int n,int m)
:m_matrix(0)
,m_row(n)
,m_col(m)
{
        assert(n >= 0 && m >= 0);
        if (n == 0 || m==0) {
                return;
        }
        m_matrix = new int*[n];
        for (int i = 0; i < n; i++) {
                m_matrix[i] = new int[m];
        }
        assert(0 != m_matrix);
        assert(n == m_row && m==m_col);
        initialize();
}

void Matrix::initialize() {
     for (int i = 0; i < m_row; i++) 
        for (int j = 0; j < m_col; j++) {
        assert(0 != m_matrix);
        m_matrix[i][j] = rand()%100;
      }
   }


void Matrix::print() const {
        if (0 == m_row || 0 == m_col) {
                assert(0 == m_matrix);
                std::cout << "No Matrix" << std::endl;
                return;
        }
    for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_col; j++) {
                    std::cout << m_matrix[i][j] << " ";
            }
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

void sum_matrixes(Matrix& m1, Matrix& m2) {
    std::cout << "Sum of 2 matrix is\n";
    for(int i = 0; i < m1.m_row; ++i) {
        for(int j = 0; j < m1.m_col; ++j) {
            std::cout << m1.m_matrix[i][j] + m2.m_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void sub_matrixes(Matrix& m1, Matrix& m2) {
    std::cout << "Subtract of 2 matrix is\n";
    for(int i=0;i<m1.m_row;++i) {
        for(int j=0;j<m1.m_col;++j) {
            std::cout<<m1.m_matrix[i][j]-m2.m_matrix[i][j]<<" ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void mul_matrix_integer(Matrix& m) {
    int val;
    std::cout << "Input integer value" << std::endl;
    std::cin >> val;
    std::cout << "Multiply of  matrix and constant value is is\n";
    for(int i = 0; i < m.m_row; ++i) {
        for(int j = 0; j < m.m_col; ++j) {
            std::cout << m.m_matrix[i][j]*val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


Matrix::~Matrix()
{
        if (0 == m_row && 0==m_col) {
                assert(0 == m_matrix);
                return;
        }
        for(int i = 0; i < m_row; ++i) {
                delete[] m_matrix[i];
        }
        delete[] m_matrix;
        m_matrix = 0;
        m_row = 0;
        m_col = 0;
}


int main(){
    srand(time(0));
    Matrix m(5,5);
    m.print();
    Matrix m1(5,5);
    m1.print();
    sum_matrixes(m,m1);
    sub_matrixes(m,m1);
    mul_matrix_integer(m1);

    return 0;
}
