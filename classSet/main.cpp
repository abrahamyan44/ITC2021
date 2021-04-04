#include "Set.hpp"

void testing()
{
	// testing ctor and operator<<
	int a[15] = { 3, 6, 1, 3, 8, 9, 9, 8, 8, 2, 11, 14, 2, 14, 2 };
	Set s1(15, a);
	std::cout << "s1 is: " << s1;

	// testing Contains
	std::cout << "s1 contains 20: " << s1.Contains(20) << std::endl;
	std::cout << "s1 contains 2: " << s1.Contains(2) << std::endl;

	// testing copy ctor and operator=
	Set s2(s1);
	std::cout << "s2 is: " << s2;
	int b[7] = { 2, 2, 2, 2 };
	Set s3(7, b);
	std::cout << "s3 is: " << s3;
	s2 = s3;
	std::cout << "after s2 = s3 s2 is: " << s2;

	// testing IsSubSet, operator==, operator&=, operator|=, operator-=
	int c[7] = { 3, 6, 1, 3, 8, 9, 9 };
	Set s4(7, c);
	std::cout << "s4 is: " << s4;
	std::cout << "is s4 subset for s1: " << s1.IsSubSet(s4) << std::endl;
	std::cout << "is s2 subset for s1: " << s1.IsSubSet(s2) << std::endl;
	std::cout << "are s1 and s2 equal: " << (s1 == s2) << std::endl;
	std::cout << "are s2 and s3 equal: " << (s3 == s2) << std::endl;
	s2 &= s1;
	std::cout << "after s2 &= s1 s2 is: " << s2;
	s3 |= s1;
	std::cout << "after s3 |= s1 s3 is: " << s3;
	s1 -= s4;
	std::cout << "after s1 -= s4 s1 is: " << s1;
	
}

int main()
{
	testing();
	return 0;
}
