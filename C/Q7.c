#include <stdio.h>

int main()
{
	int a = 2;
	int c = 0;
	int b = 2;
	int n;

	printf( "Order: ");
	scanf( "%d", &n );
	getchar();

	while ( 1 ) {
		if ( a == b ) { c++; if ( c == n ) break; b = 2; a++; }
		else if ( a % b == 0 ) { a++; b = 2; }
		else b++;
	}

	printf ( "The number you are looking for is %d", a );
	getchar();
}