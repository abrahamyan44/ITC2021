#include "gcd.hpp"

void file_ganarate() 
{
	ofstream  test;
	test.open("files/test.txt", ios::out);

	if( !test.is_open() )
   	{
		cout << "Something wrong.Can't open test.txt in function file_ganarate." << endl;
	}

	int n = 100;
	int cnt = 0;

	srand( time(0) );	
	while ( cnt < n ) 
	{
	
		int x = random()%1000000;
		int y = random()%1000000;
		test << x << "\t" << y << endl;
		cnt++;
	}
	test.close();
}


void test1() 
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

void test2 ()
{
	int gnum1;
	int gnum2;
	int solution;
	ofstream gout;
	ifstream gin;

	gout.open("files/goutput.txt", ios::out);
	gin.open("files/test.txt", ios::in);

	if( !gout.is_open() )
   	{
		cout << "Something wrong.Can't open gout.txt in function test2." << endl;
	}

	if( !gin.is_open() ) 
	{
		cout << "Something wrong.Can't open test.txt in function test2." << endl;
	}

	while( !gin.eof() ) 
	{
		gin >> gnum1;
		gin >> gnum2;
		solution = ggcd(gnum1, gnum2);
		gout << solution << endl; 
	}
	gout.close();
	gin.close();
}



