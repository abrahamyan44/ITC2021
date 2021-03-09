#include <iostream>
#include <cassert>
#include <iomanip>


class Matrix
{
private:
    int** m_matrix;
    int m_size;
    void initialize();

public:
    Matrix(int size = 0);
    Matrix(const Matrix&);
    ~Matrix();

public:
    void print();
    Matrix& operator=(const Matrix&);
};


Matrix::Matrix(int size)
    :m_matrix(0)
    ,m_size(size)
{
    assert(size >= 0);
    if(0 == size)
        return;

    m_matrix = new int*[m_size];
    if(0 == m_matrix){
        std::cout << "Could not allocate memory\n";
        exit(1);
    }
    for (int i=0; i<m_size; i++){
        m_matrix[i] = new int[m_size];
        if(0 == m_matrix){
            std::cout << "Could not allocate memory\n";
            exit(1);
        }
    }

    initialize();
}

Matrix::Matrix(const Matrix& other)
    :m_size(other.m_size)     
{
    m_matrix = new int*[m_size];
    if(0 == m_matrix){
        std::cout << "Could not allocate memory\n";
        exit(1);
    }
    for (int i=0; i<m_size; i++){
        m_matrix[i] = new int[m_size];
        if(0 == m_matrix){
            std::cout << "Could not allocate memory\n";
            exit(1);
        }
    }
    for(int i=0; i<m_size; i++){
        for(int j=0; j<m_size; j++){
           m_matrix[i][j] = other.m_matrix[i][j]; 
        }
    }

}


Matrix& Matrix::operator=(const Matrix& other)
{
    m_size = other.m_size;
    m_matrix = new int*[m_size];
    if(0 == m_matrix){
        std::cout << "Could not allocate memory\n";
    }
    for (int i=0; i<m_size; i++)
    {
        m_matrix[i] = new int [m_size];
        if(0 == m_matrix)
        {
            std::cout << "Could not allocate memory\n";
            exit(1);
        }
    }
    
    for(int i = 0; i < m_size; i++)
        for(int j = 0; j < m_size; j++)
            m_matrix[i][j] = other.m_matrix[i][j];
    
    return *this;
}


void Matrix::initialize()
{
    for (int i=0; i<m_size; i++){
        for (int j=0; j<i; j++){     //below the diagonal
            m_matrix[i][j]=1;
        }

        m_matrix[i][i]=2;     //on the diagonal

        for (int j=i+1; j<m_size; j++){      //above the diagonal
            m_matrix[i][j]=0;
        }
    }
}

void Matrix::print()
{ 
    for (int i=0; i<m_size; i++){
        for (int j=0; j<m_size; j++ ){
            std::cout << std::setw(2) << m_matrix[i][j];
        }
        std::cout << std::endl;
    }
}

Matrix::~Matrix()
{
    for(int i = 0; i < m_size; i++){
        delete[] m_matrix[i];
        m_matrix[i] = 0;
    }
    delete[] m_matrix;
    m_matrix = 0;
}

int main()
{
    int size;
    std::cout << "size = "; std::cin >> size;
    
    Matrix M1(size);
    M1.print();

    Matrix M2 = M1;
    M2.print();

    Matrix M3;
    M3 = M2;
    M3.print();
} 
