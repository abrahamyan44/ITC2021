#include <iostream>
#include <cassert>
#include <typeinfo>

class Matrix
{
friend std::ostream& operator<<(std::ostream& out,const Matrix& M);
friend std::istream& operator>>(std::istream& in, Matrix& M); 
	
public:
	Matrix(int); 			//ctor
	Matrix(int, int**); 	//ctor
	Matrix(const Matrix&);  //copy ctor
	~Matrix(); 				//dtor

	Matrix& operator=(const Matrix&);
	bool operator==(const Matrix&) const;	
	Matrix& operator+=(const Matrix&);
	Matrix& operator-=(const Matrix&);
	Matrix& operator*=(const Matrix&);
	Matrix& operator*=(const int&);
	Matrix& operator/=(const Matrix&);
	Matrix& operator%=(const Matrix&);
	int& operator()(int,int);
	const int& operator()(int,int)const;

	void print() const;
	
private:
	void allocate();
	void dellocate();
	void initialize();

private:	
	int** m_matrix;
	int m_size;	
};

bool operator !=(const Matrix&, const Matrix&);
Matrix operator+(Matrix&, const Matrix&);
Matrix operator-(Matrix&, const Matrix&);
Matrix operator*(Matrix&, const Matrix&);
Matrix operator*(Matrix&, const int&);
Matrix operator/(Matrix&, const Matrix&);
Matrix operator%(Matrix&, const Matrix&);


std::ostream& operator<<(std::ostream& out,const Matrix& M) {
	for (int i = 0; i < M.m_size; ++i) {
		for (int j = 0; j < M.m_size; ++j) {
			out << M.m_matrix[i][j];
		}
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in,Matrix& M) {
	for (int i = 0; i < M.m_size; ++i) {
        for (int j = 0; j < M.m_size; ++j) {
			in >> M.m_matrix[i][j];
		}
	}
	return in;
}

void Matrix::allocate() {
	m_matrix = new int*[m_size];
	
	for (int i = 0; i < m_size; ++i) {
		m_matrix[i] = new int[m_size];
	}
}

void Matrix::initialize() {
	for (int i = 0; i < m_size; ++i) {
		for (int j = 0; j < m_size; ++j) {
			assert(0 != m_matrix);
			m_matrix[i][j] = 0;
		}
	}
}

void Matrix::dellocate() {
	for (int i = 0; i < m_size; ++i) {
        delete [] m_matrix[i];
	}
	delete[]  m_matrix;
	m_matrix = 0;
	m_size = 0;
}

Matrix::Matrix(int size)
	: m_matrix(0)
	, m_size(size) {
	if (m_size <= 0){
		return;
	}
	
	allocate();
	assert(0 != m_size);
	assert(size == m_size);
	initialize();
}

Matrix::Matrix(int size, int** matrix)
	: m_size(size) {
	allocate();
	
	for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            assert(0 != m_matrix);
            m_matrix[i][j] = matrix[i][j];
        }
    }
    assert(0 != m_size);
    assert(size == m_size);
}

Matrix::~Matrix() {
	if (0 == m_size) {
 		assert(0 == m_matrix);
		return;
	}
	dellocate();
	//std::cout << "Destructor call: " << std::endl;
}

Matrix::Matrix(const Matrix& M)
	: m_matrix(M.m_matrix)
	, m_size(M.m_size) {
	//std::cout << "copy ctor call: " << std::endl;
	allocate();

	for (int i = 0; i < m_size; ++i) {
		for (int j = 0; j < m_size; ++j) {
			assert(0 != m_matrix);
			m_matrix[i][j] = M.m_matrix[i][j];
		}
	}
	assert(0 != m_size);
	assert(M.m_size == m_size);
}

Matrix& Matrix::operator=(const Matrix& M) {
	//std::cout << "op=  call: " << std::endl;
	if (&M != this) {//check addresses
		dellocate();
		m_size = M.m_size;
		allocate();

		for (int i = 0; i < m_size; ++i) {
			for (int j = 0; j < m_size; ++j) {
				assert(0 != m_matrix);
				m_matrix[i][j] = M.m_matrix[i][j];
			}		
		}
	} else {
		std::cout << "Invalid assignment: " <<std::endl;
	}

	return *this; //all matrix
}

bool Matrix::operator==(const Matrix& M) const {
	//std::cout << "op== call: " << std::endl;

	if (m_size != M.m_size) return false;
	for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
			if (m_matrix[i][j] != M.m_matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool operator!=(const Matrix& M1, const Matrix& M2) {
	return !(M1 == M2);
}

Matrix& Matrix::operator+=(const Matrix& M) {
	//std::cout << "op+= call:" << std::endl;
	
	if (m_size != M.m_size) {
	 	std::cout << "Size does not match!" << std::endl;
	} else {
		for (int i = 0; i < m_size; ++i) {
        	for (int j = 0; j < m_size; ++j) {
				m_matrix[i][j] += M.m_matrix[i][j];
			}
		}
	}
	return *this;	
}

Matrix& Matrix::operator-=(const Matrix& M) {
    if (m_size != M.m_size) {
        std::cout << "Size does not match!" << std::endl;
    } else {
        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                m_matrix[i][j] -= M.m_matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& M) {
    if (m_size != M.m_size) {
        std::cout << "Size does not match!" << std::endl;
    } else {
        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                m_matrix[i][j] *= M.m_matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const int& n) {
	for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            m_matrix[i][j] *= n;
        }
    }
    return *this;
}

Matrix& Matrix::operator/=(const Matrix& M) {   
    if (m_size != M.m_size) {
        std::cout << "Size does not match!" << std::endl;
    } else {
        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                m_matrix[i][j] /= M.m_matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator%=(const Matrix& M) {
    if (m_size != M.m_size) {
        std::cout << "Size does not match!" << std::endl;
    } else {
        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                m_matrix[i][j] %= M.m_matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix operator+(Matrix& M1, const Matrix& M2) {
	return M1 += M2;
}

Matrix operator-(Matrix& M1, const Matrix& M2) {
    return M1 -= M2;
}	

Matrix operator*(Matrix& M1, const Matrix& M2) {
    return M1 *= M2;
}

Matrix operator*(Matrix& M1, const int& n) {
	return M1 *= n;
}

Matrix operator/(Matrix& M1, const Matrix& M2) {
    return M1 /= M2;
}

Matrix operator%(Matrix& M1, const Matrix& M2) {
    return M1 %= M2;
}

int& Matrix::operator()(int i, int j) {
	return m_matrix[i][j];
}

const int& Matrix::operator()(int i, int j) const {
	return m_matrix[i][j];
}

void Matrix::print() const {
	if (0 == m_size || 0 == m_matrix) { 
		std::cout << "No Matrix" << std::endl;
	}
	assert(0 != m_matrix);	
	assert(0 != m_size);
	
	for (int i = 0; i < m_size; ++i) {
		for (int j = 0; j < m_size; ++j) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	/*testing*/
	//initialization
	const int n = 2;
	int** array =  new int*[n];
	for (int i = 0; i < n; ++i) {
	    array[i] = new int[n];
	}

	std::cout << "insert array elements:" << std::endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> array[i][j];
		}
	}
	std::cout << std::endl;	

	Matrix M1(n,array); //ctor
	M1.print();
	/*
	for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
            std::cin >> M3(i,j);
		}
	}
    M3.print();
	*/

	/*
	const int c = 10;
    M3*=c;
    M3.print();
	*/

	/*
	Matrix M4(5);
	M4 = M3;		//assignm
	M4.print();
	*/

	for (int i = 0; i < n; ++i) {
		delete[] array[i];	
	}
	delete[] array;
	return 0;
}
