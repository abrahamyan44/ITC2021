#include "gcd.hpp"

void test()
{
	int num1;
	int num2;
	int result;
	ifstream input;
	ofstream output; 
	
	output.open("files/output.txt", ios::out);
	input.open("files/test.txt");
	
	if( !output.is_open() ) 
	{
		cout << "Something wrong.Can't open output.txt in function test1." << endl;
	}

	if( !input.is_open() )
   	{
		cout << "Something wrong.Can't open input.txt in function test1." << endl;
	}

	while( !input.eof() )
   	{
		input >> num1;
		input >> num2;
		result = gcd(num1, num2);
		output << result << endl;
	}	
	output.close();
	input.close();
}


