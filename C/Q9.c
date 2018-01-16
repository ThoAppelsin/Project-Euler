#include <stdio.h>

int main()
{
	int a = 1;
	int b = 2;
	int c = 1000 - a - b;

	while ( a * a + b * b != c * c ){
		if ( a < b - 1 ) { a++; c--; }
		else { b++; a = 1; c = 1000 - a - b; }
	}


	printf ( "The numbers you are looking for are %d, %d and %d", a, b, c );
	printf ( "... and %d", a * b * c );
	getchar();
}