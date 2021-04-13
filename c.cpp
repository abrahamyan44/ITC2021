#include <iostream>

struct matrix {
    int** a;
    int size;

    matrix() {
        a = nullptr;
        size = 0;
    }
    matrix(int n) {
        size = n;
        create_matrix();
    }
    matrix(const matrix& m) {
        size = 0;
        a = 0;
        (*this) = m;
    }
    void create_matrix() {
        a = new int*[size];

        for(int i = 0; i < size; ++i) {
            a[i] = new int[size];
            for(int j = 0; j < size; ++j) {
                a[i][j] = 0;
            }
        }
    }

    void change_matrix_size(const int& s) {
        matrix x(*this);
        delete_matrix();
        size = s;
        create_matrix();
        for(int i = 0; i < x.size; ++i) {
            for(int j = 0; j < x.size; ++j) {
                a[i][j] = x.a[i][j];
            }
        }
    }

    matrix& operator=(const matrix& m);
    matrix& operator+=(const matrix& m);
    matrix& operator-=(const matrix& m);
    matrix& operator*=(const int& s);
    matrix operator*(const matrix& m);
    matrix operator+(const matrix& m) {
        matrix b(*this);
        return (b += m);
    }
    matrix operator-(const matrix& m) {
        matrix b(*this);
        return (b -= m);
    }
    matrix operator*(const int& s) {
        matrix b(*this);
        return (b *= s);
    }
    matrix& operator*=(const matrix& m) {
        matrix b(*this);
        (*this) = b * m;
        return *this;
    }

    void print_matrix() {
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                std::cout << a[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void delete_matrix() {
        if(size == 0) {
            return;
        }
        for(int i = 0; i < size; ++i) {
            delete[] a[i];
        }
        delete[] a;
    }

    ~matrix() {
        delete_matrix();
    }
};

matrix& matrix::operator+=(const matrix& m) {
    if(size < m.size) {
        change_matrix_size(m.size);
    }
    for(int i = 0; i < m.size; ++i) {
        for(int j = 0; j < m.size; ++j) {
            a[i][j] += m.a[i][j];
        }
    }
    return *this;
}

matrix& matrix::operator-=(const matrix& m) {
    if(size < m.size) {
        change_matrix_size(m.size);
    }
    for(int i = 0; i < m.size; ++i) {
        for(int j = 0; j < m.size; ++j) {
            a[i][j] -= m.a[i][j];
        }
    }
    return *this;
}

matrix& matrix::operator=(const matrix& m) {
    delete_matrix();
    size = m.size;
    create_matrix();
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            a[i][j] = m.a[i][j];
        }
    }

    return *this;
}

matrix& matrix::operator*=(const int& s) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            a[i][j] *= s;
        }
    }

    return *this;
}

matrix matrix::operator*(const matrix& m) {
    matrix a2(m);
    matrix a1(*this);
    if(a1.size == 0 && a2.size == 0) {
        return a1;
    }
    if(a1.size < a2.size) {
        a1.change_matrix_size(a2.size);
    }
    else if(a1.size > a2.size) {
        a2.change_matrix_size(a1.size);
    }
    matrix b(a1.size);
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            int ans = 0;
            for(int k = 0; k < size; ++k) {
                ans += (a1.a[i][k] * a2.a[k][j]);
            }
            b.a[i][j] = ans;
        }
    }
    return b;
}

void setup_matrix(matrix& b) {
    for(int i = 0; i < b.size; ++i) {
        for(int j = 0; j < b.size; ++j) {
            if(i<j) {
                b.a[i][j] = 0;
            } else if(i>j) {
                b.a[i][j] = 1;
            } else {
                b.a[i][j] = 2;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int width;
    std::cout<<"Input width of matrix"<<std::endl;
    std::cin>>width;
    matrix a(width), b(5), c;
    setup_matrix(a);
    setup_matrix(b);
    c = a * b;
    c.print_matrix();
    std::cout<<"\n";
    c = a;
    c *= b;
    c.print_matrix();
    return 0;
}