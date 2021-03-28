#include <iostream>
#include <fstream>
#include "gcd.hpp"

int gcd(int a, int b){
		if(a == b){
				return a;
		}
		if(a > b){
				return gcd(a - b, b);
		}
		
		return gcd(a, b - a);
}

void test(){
		std::fstream inputFile;
		std::fstream outputFile;
		outputFile.open("../tst/output.txt");
		int value;
		inputFile.open("../tst/input.txt");
		int a=0;
		int b=0;
		int count=0;

		while( inputFile >> value ){
				if(count == 1){
						b = value;
						count++;
						outputFile<<gcd(a,b)<<"\n";
						a = 0;
						b = 0;
						count = 0;

        }	
				else if(count == 0){
						a = value;
						count++;
				}

		}
		outputFile.close();
		inputFile.close();

}

int main(){
		test();
		return 0;
}
