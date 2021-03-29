#include "gcd.hpp"

int gcd(int a, int b) 
{
	if(a == b) {
		return a;
	}

	while ( a != b )
   	{	
		if( a > b )
	   	{
			return gcd(a-b, a);
		} else
	   	{
			return gcd(b-a, a);
		}
	}
	return 0;
}

void user_numbers() 
{
	int a;
	int b;

	cout << "Please, enter two integers." << endl;
	cin >> a >> b ;
	cout << "gcd( " << a <<", " << b <<" ) = " << gcd(a, b) << endl;
	continue_function();
}


void continue_function()
{
	int choice;
	cout << "Do you want to continue? \n 1.Yes \n 2.no" << endl;
	cin >> choice;
	cout << "choice"<< choice << endl;

	switch(choice)
   	{
		case 1:
		user_numbers();

		case 2:
		break;

		default:
		cout << "Something wrong. Please try agayn." << endl;
		continue_function();
	}


}

int main () 
{
   	 test();
	 diff();
	 user_numbers();
	return 0;
}


