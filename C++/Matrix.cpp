#include <iostream>
#include <cassert>

class Matrix
{
private:
        int** m_matrix = 0;
        int m_size = 0;

private:
        void initialize();

public:
        void print() const;
        inline int get_size() const { return m_size; }
 
public:
        Matrix(int size = 0);
        Matrix(const Matrix& other); //copy constructor
        ~Matrix();
       const Matrix operator=(const Matrix&);
      friend std::ostream& operator<<(std::ostream &out, const Matrix& m);

};



std::ostream& operator<<(std::ostream& out, const Matrix& m)

{

        if (0 == m.m_size) {

                assert(0 == m.m_matrix);

                out << "No Matrix";

                return out;

        }

        for (int i = 0; i < m.m_size; i++) {

                for (int j = 0; j < m.m_size; j++) {

                        out << m.m_matrix[i][j] << " ";

                }

                out << std::endl;

        }

        return out;

}


Matrix::Matrix(int n)
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
        initialize();
}

Matrix::Matrix(const Matrix& other){
    m_size=other.m_size;
    if(other.m_matrix)
    {
        m_matrix=new int*[m_size];

        for(int i=0;i<m_size;++i){
            m_matrix[i]=new int[m_size];

            for(int i=0;i<m_size;++i)
            {
                for(int j=0;j<m_size;++j)
                {
                    m_matrix[i][j]=other.m_matrix[i][j];
                }
            }
        }
    }
    std::cout<<"Copy constructor"<<std::endl;
}


void Matrix::initialize()
{
        for (int i = 0; i < m_size; i++) {
                for (int j = 0; j < m_size; j++) {
                        assert(0 != m_matrix);
                        m_matrix[i][j] = 0;
                }
        }

}




const Matrix Matrix::operator=(const Matrix& m){

    Matrix new_mat(m_size);
	for (int i=0; i<m_size; ++i){
		for (int j=0; j<m_size; ++j){
              new_mat.m_matrix[i][j] = m.m_matrix[i][j];
            }
        }
        return new_mat;
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

int main()
{

        std::cout << "Enter matrix size:";
        int n = 0;
        std::cin >> n;
        if (n <= 0) {
                std::cout << "Wrong input" << std::endl;
                return 1;
        }
                Matrix e;
                std::cout<<e;
                Matrix g(e) ;
                Matrix k;
                k=g=e;
        return 0;
}
