#include <iostream>
#include <exception>
#include <fstream>
#include <stdio.h>
#include <cstring>

typedef long long ll;

ll gcd(ll& , ll& );
void test(std::ifstream&);
void input(ll&,ll&);

int main(int argc, char* argv[]){
	ll x;
        ll y;
        if(argc == 1){
	    bool input_true = true;
	    while(input_true)
		    try{
			  input(x,y);
			  input_true = false;
		    }
		    catch(const std::exception& ex) {
			  std::cerr << ex.what() << std::endl;
			  input_true = true;
		    }

                    std::cout << "The greatest common divisor of X and Y = " 
			<< gcd(x, y) << std::endl;
        }else if(strcmp(argv[1], "test") == 0){
            std::string k = argv[2];
            std::ifstream t_input;
            t_input.open(k);
            test(t_input);
            t_input.close();
        }
        return 0;
}

void input(ll& x, ll&y){
       std::cout << "Enter two integers!" << std::endl;
       std::cout << "X = ";
       std::cin >> x;
       std::cout << "Y = ";
       std::cin >> y;
       if (0 >= x || 0 >= y) {
          throw std::invalid_argument("Invalid argument!");
       }
}

void test(std::ifstream& test){
	std::ofstream fout;
    fout.open("tst.run/output.txt",std::ios::out);
	if (fout.is_open()) {
	    ll a;
	    ll b;
	    while(test >> a >> b){
	    fout << gcd(a,b);
	    fout << "\n";
	    }
	}
	fout.close();
}

ll gcd(ll& a, ll& b){
	while(a != b) {
		if (a > b) {
			a = a - b;	
		} else {
			b = b - a;
		}
	}
	return a;
}
