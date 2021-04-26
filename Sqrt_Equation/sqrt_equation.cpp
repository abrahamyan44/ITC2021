#include <iostream>
#include <cmath>
using namespace std;


struct complex {
    float real;
    float imag;
};


float common_cases (float a, float b, float c);
float special_cases (float a, float b, float c);


void coef_entering () {
	float a;
	float b;
	float c; 
	cout << "Please enter <a> , <b> and <c> coefficients for ax^2+bx+c=0 equation" << endl;
	cin >> a >> b >> c;
	if (a == 0 || b == 0 || c ==0 ) {
	        special_cases(a, b, c);
	}
        else {
		common_cases(a, b, c);
        }
}
	

float special_cases (float a, float b, float c) {
       float x1;
       float x2;
       	if ( a == 0) {
	    cout << "This is a linear equation" << endl;
	    cout << b << "x + " << c << " = 0" << endl;
            x1 = -c/b;
	    cout <<  "x = -c/b \n x = " << x1 << endl;
	}
        else if ( b == 0 ) {
            cout << a << "x^2 + " << c << " = 0" << endl;
	    if (-c/a >= 0) {
	        x1 = sqrt(-c/a);
                x2 = -sqrt(-c/a);
	    } else {
                cout <<"x1,2 = +/-i * " << sqrt(abs(c/a)) << endl;  	
	   }
	}
	else if (c == 0) {
	    cout << a << "x^2 + " << b << "x  " << "= 0 " << endl;
	    x1 = 0;
            x2 = -b/a;
	    cout << "x1 = " << x1 << "\n x2 = " << x2 << endl;
	}
	else {
	    cout << "Something wrong, please try again";
            coef_entering ();
	}
         return x1;
}


float common_cases (float a, float b, float c) {
        
	cout << a << "x^2 + " << b << "x +" << c << " = 0 \n We have to find  roots"<< endl;
	float D = b*b - 4*a*c;
	cout << "D = b^2 -4ac \n D = " << D << endl;
            if (D > 0) {
		float x1 = (-b + sqrt(D))/2*a;
		float x2 = (-b - sqrt(D))/2*a;
		cout << "D > 0 \n  x1,2 = ( -b +/- sqrt(D) ) / 2a \n x1 = " << x1 << ", x2 = " << x2 <<                  endl;
	       return x1;	
             }
	    else if (D < 0 ) {
		cout << "D < 0 \n  x1,2 = (-b +/- i*sqrt(|D|)) / 2a" << endl;
		complex x1;
		complex x2;
		x1.real = -b;
	        x1.imag = sqrt(-D)/2*a;
                x2.real = -b;
		x2.imag = -sqrt(-D)/2*a;
		cout << "x1 =  " << x1.real << " + i* " << x1.imag << "\n x2 =   " << x2.real << " + i*" << x2.imag << endl;
		return x1.imag ;
            }
	    else {
		float x1 = -b/2*a;
		cout << " x = -b/2a \n x1 = " << x1 << endl;
		return x1;
            } 	        
}


void test_sqr_equation( float d, float f, float g, float expected_result ) {
	cout << "Test for   " << d << "x^2 + " << f << "x + " << g << " = 0 \n Expected to get " << expected_result << endl;
       if (d != 0 && f != 0 && g != 0) {
	       float result = common_cases(d, f, g);
	       if (result == expected_result) {
                    cout << "All right" << endl;
               } else {
                   cout << "expected to get   " << expected_result << "   but got   " << result << endl;
               } 
               cout << endl;
        } else {
	       float result1 = special_cases(d, f, g);
	       if (result1 == expected_result) {
                    cout << "All right" << endl;
               } else {
                   cout << "expected to get   " << expected_result << "   but got   " << result1 << endl;
               } 
               cout << endl;
	}
}


int main() {

       test_sqr_equation(1, 4, 4, -2 );
       test_sqr_equation(1, 5, 4, -1);
       test_sqr_equation(1, 4, 5, 1);  
       test_sqr_equation(0, 4, 4, -1);
       test_sqr_equation(2, 0, -32, 4);  
       test_sqr_equation(1, 4, 0, 0);   
       coef_entering();
	return 0;
}
