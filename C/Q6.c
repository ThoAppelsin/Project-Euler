#include <stdio.h>

int main()
{
	long a = 0;
	long b;
	for ( b = 1; b <= 100; b++ ) a += b;
	a *= a;
	for ( b = 1; b <= 100; b++ ) a -= b * b;


	printf ( "The number you are looking for is %d", a );
	getchar();
}