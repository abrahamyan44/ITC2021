#include <iostream>

//function that counts minimum of two numbers
int min(int a , int b) {
    int min = a;
    if(b < min) {
        min = b; 
    }
    return min;
}

//function that counts maximum of two numbers
int max(int a , int b ){
    int max = a ;
    if( b > max ) {
        max = b;
    }
    return max;
}

//function that counts sum of two numbers
int sum ( int a , int b ){
    return a + b;
}

int main(){
    int a;
    int b;
    std::cout << "Insert a:";
    std::cin >> a;
    std::cout << "Insert b:";
    std::cin >> b;
    std::cout << "a: "<< a << '\t' << "b: " << b << std::endl;
    std::cout << "Min: " << min(a,b) << std::endl;
    std::cout << "Max: " << max(a,b) << std::endl;
    std::cout << "Sum: " << sum(a,b) << std::endl;
    return 0;
    }
