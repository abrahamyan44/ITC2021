#include <iostream> 
#include <cmath>

int solves_quadratic_equation (int a, int b, int c, float &x1, float &x2)
{
    int Dscr = b*b - 4*a*c;
    if (Dscr<0)    //Discriminant is negative
    {
	return -1;
    }
    else
    {
        if (Dscr == 0)    //Discriminant is zero
	{
	    x1 = (-1*b)/(2*a);
	    return 0;
	}
	else    //Discriminant is positive
	{
	    x1 = (-1*b + sqrt(Dscr))/(2*a);
	    x2 = (-1*b - sqrt(Dscr))/(2*a);
	    return 1;
	}
    }
}

int main()
{
    int a,b,c;
    float x1, x2;
    std::cin >> a >> b >> c;
    switch ( solves_quadratic_equation(a,b,c,x1,x2) )
    {
        case -1:
	    std::cout << "There are two complex roots.\n";
	    break;
	case 0:
	    std::cout << "One real root, " << x1 << std::endl;
	    break;
	case 1:
	    std::cout << "Two distinct roots, " << x1 << " and " << x2 << std::endl;
	    break;
    }

}
