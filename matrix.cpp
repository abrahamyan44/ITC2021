//I have slightly changed the initialize function so that the matrix is filled with non-zero values.
// I wrote the + = operators, as well as the initilize_with_default_values function , which fills in the matrix, as it was said in the task. 
//I commented out some of the lines because there were problems. I'll ask you about it in class))



#include <iostream>
#include <cassert>


class Matrix
{
private:
        int** m_matrix = 0;
        int m_size = 0;
private:
        void initialize(int value);
	void initialize_with_default_values();
public:
        void print() const;
        inline int get_size() const { return m_size; }
//        Matrix(int size = 0, int value = 0);
        Matrix(const Matrix& x);
        ~Matrix();
        const Matrix& operator=(const Matrix& x);
	const Matrix operator+(const Matrix& x);
	Matrix(int size = 0);


};

Matrix::Matrix(int n)
        : m_matrix(0)
        , m_size(n)
{
        std::cout << "Constructor with default values, n = " << n << std::endl;
        assert(n >= 0);
        if (n == 0) {
                return;
        }
        m_matrix = new int*[n];
        for (int i = 0; i < n; i++) {
                m_matrix[i] = new int[n];
        }
        assert(0 != m_matrix);
        assert(n == m_size);
        initialize_with_default_values();
}
/*
Matrix::Matrix(int n,int value)
        : m_matrix(0)
        , m_size(n)
{
        std::cout << "Constructor n = " << n << std::endl;
        assert(n >= 0);
        if (n == 0) {
                return;
        }
        m_matrix = new int*[n];
        for (int i = 0; i < n; i++) {
                m_matrix[i] = new int[n];
        }
        assert(0 != m_matrix);
        assert(n == m_size);
        initialize(value);
}
*/
Matrix::Matrix(const Matrix& x)
        : m_matrix(x.m_matrix)
        , m_size(x.m_size)
{
        std::cout << "Copy Constructor" << std::endl;


}

void Matrix::initialize(int value)
{
        for (int i = 0; i < m_size; i++) {
                for (int j = 0; j < m_size; j++) {
                        assert(0 != m_matrix);
                        m_matrix[i][j] = value;
                }
        }

}
void Matrix::initialize_with_default_values()
{
        for (int i = 0; i < m_size; i++) {
                for (int j = 0; j < m_size; j++) {

                        assert(0 != m_matrix);
			if (i == j){
			
				m_matrix[i][j] = 2;
			}
			else if (j < i){
                        
                                m_matrix[i][j] = 1;
                        }
			else if (j > i){
                        
                                m_matrix[i][j] = 0;
                        }

                }
        }

}

const Matrix& Matrix::operator=(const Matrix& x)
{
	
	m_size = x.m_size;
	for (int i = 0; i < m_size; i++){
		for (int j = 0; j < m_size; j++){
                	assert(0 != m_matrix);
			m_matrix[i][j] = x.m_matrix[i][j];
		}
	}
        return *this;
}

const Matrix Matrix::operator+(const Matrix& x)
{
	Matrix sum_matrix(m_size); 
	m_size = x.m_size;
        for (int i = 0; i < m_size; i++){
                for (int j = 0; j < m_size; j++){
                        assert(0 != m_matrix);
                        sum_matrix.m_matrix[i][j] = m_matrix[i][j] + x.m_matrix[i][j];
                }
        }
        return sum_matrix;




}

void Matrix::print() const
{
        if (0 == m_size) {
                assert(0 == m_matrix);
                std::cout << "No Matrix" << std::endl;
                return;
        }
        for (int i = 0; i < m_size; i++) {
                for (int j = 0; j < m_size; j++) {
                        std::cout << m_matrix[i][j] << " ";
                }
                std::cout << std::endl;
        }
        std::cout << std::endl;
}

Matrix::~Matrix()
{
        std::cout << "Destructor" << std::endl;
        if (0 == m_size) {
                assert(0 == m_matrix);
                return;
        }
        for(int i = 0; i < m_size; ++i) {
                delete[] m_matrix[i];
        }
        delete[] m_matrix;
        m_matrix = 0;
        m_size = 0;
}

/*const Matrix& Matrix::operator+(const Matrix& x){
	

}*/

int main(){


        std::cout << "Enter matrix size:";
        int n = 0;
        int value1,value2 = 0;
	std::cin >> n;
        if (n <= 0) {
                std::cout << "Wrong input" << std::endl;
                return 1;
        }
        /*{
                Matrix e;
                e.print();
                Matrix k = e;
                k.print();
        }
        {
                Matrix m(n);
                m.print();
                //Matrix f = m;
                //f.print();
                Matrix g;
                g = m;  
                g.print();
        }
        { 
                Matrix* p = new Matrix(n);
                p->print();
                delete p;
        }
	
	{
		std::cin >> value1 >> value2;
		Matrix k(n,value1);
		Matrix p(n,value2);
	
		Matrix sum = k + p;
		sum.print();

	}*/
	{

		Matrix def(n);
		def.print();
	}
















        return 0;
}
