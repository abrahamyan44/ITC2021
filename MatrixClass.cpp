#include <iostream>
#include <cassert>
#include <iomanip>


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


Matrix::Matrix(int size)    //Parameterized constructor
    :m_matrix(0), m_size(size)  //initializer list
{
    std::cout << "Param constructor\n";
    assert(size >= 0);
    if(0 == size)
        return;

    //Dynamic memory allocation
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

    //matrix initialization
    initialize();
}

Matrix::Matrix(const Matrix& other)     //Copy constructor
    :m_size(other.m_size)     
{
    std::cout << "Copy constructor\n";
    //Dynamic memory allocation
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

    //Copying values
    for(int i=0; i<m_size; i++){
        for(int j=0; j<m_size; j++){
           m_matrix[i][j] = other.m_matrix[i][j]; 
        }
    }

}


Matrix& Matrix::operator=(const Matrix& other)
{
    //Memory allocation
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
    
    //Copying values
    for(int i = 0; i < m_size; i++)
        for(int j = 0; j < m_size; j++)
            m_matrix[i][j] = other.m_matrix[i][j];
    
    return *this;
}

Matrix Matrix::operator+(const Matrix& other)   //Addition operator.
{
    assert(m_size == other.m_size);
    Matrix temp(m_size);
    for(int i = 0; i < m_size; i++){
        for(int j = 0; j < m_size; j++)
        {
            temp.m_matrix[i][j] = m_matrix[i][j] + other.m_matrix[i][j];
        }
    }
    return temp;
}

Matrix Matrix::operator-(const Matrix& other)   //Subtraction operator
{
    assert(m_size == other.m_size);
    Matrix temp(m_size);
    for(int i = 0; i < m_size; i++){
        for(int j = 0; j < m_size; j++)
        {
            temp.m_matrix[i][j] = m_matrix[i][j] - other.m_matrix[i][j];
        }
    }
    return temp;
}

Matrix Matrix::operator*(const Matrix& other)   //Multiplying a matrix by another matrix
{
    assert(m_size == other.m_size);
    Matrix temp(m_size);
    for(int i = 0; i < m_size; i++){
        for(int j = 0; j < m_size; j++)
        {
            temp.m_matrix[i][j] = 0;
            for(int k = 0; k < m_size; k++)
            {
                temp.m_matrix[i][j] += m_matrix[i][k] * other.m_matrix[k][j];
            }
        }
    }
    return temp;
}

Matrix Matrix::operator*(const int num) //Multiplying a matrix by constant number
{
    assert( 0 != m_size);
    Matrix temp(m_size);
    for(int i = 0; i < m_size; i++){
        for(int j = 0; j < m_size; j++)
        {
            temp.m_matrix[i][j] = m_matrix[i][j] * num; //Multiply 
        }
    }
    return temp;
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
            std::cout << std::setw(3)<< m_matrix[i][j];
        }
        std::cout << std::endl;
    }
}

Matrix::~Matrix()
{
    std::cout << "Destructor\n";
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
    
    std::cout << "\nAssignment operator.\n";
    Matrix M2 = M1;
    M2.print();

    std::cout << "\nAddition operator.\n";
    Matrix M3;
    M3 = M2 + M1;
    M3.print();
    
    std::cout << "\nSubtraction operator.\n";
    Matrix M4;
    M4 = M2 - M1;
    M4.print();

    std::cout << "\nMultiplying a matrix by another matrix.\n";
    Matrix M5;
    M5 = M3 * M1;
    M5.print();

    std::cout << "\nMultiplying a matrix by constant number.\n";
    Matrix M6;
    M6 = M3 * 3;
    M6.print();
}
