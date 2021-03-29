#include "gcd.hpp"

int gcd (int a, int b)
{
	if( a == 0 )
   	{
		return b;
	} else if ( b == 0 )
   	{
		return a;
	} else if (a == 1 || b == 1 )
   	{
		return 1;
	} else if(a == b)
	{
		return a;
	}


	if(a > b)
   	{	
		int c = a;
		a = b;
		b = c;
	}

	for(int i = a; i > 0; i--)
   	{	
		if( a%i == 0 && b%i == 0 ) {
			return  i;
		}
	}

	return 0;
}


int ggcd(int a, int b) 
{
	if(a == b)
   	{
		return a;
	}

	while ( a != b ) 
	{
		if( a > b )
	   	{
			return ggcd(a-b, a);
		} else
	   	{
			return ggcd(b-a, a);
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
	cout << "choice < "<< choice <<  " >" << endl;
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
	 file_ganarate();
   	 test1();
	 test2();
	 diff();
	 user_numbers();
	return 0;
}


