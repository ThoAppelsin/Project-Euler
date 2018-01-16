#include <stdio.h>
#include <time.h>

void rectify ( long * c )
{
	char a = 0;

	while ( 9 > a ) {
		c[a+1] += c[a] / 10;
		c[a] %= 10;
		a ++;
	}

	c[9] %= 10;
}

int main()
{
	long a[10] = { 3, 3, 4, 8, 2 };

	long b;
	char c;
	for ( b = 0; b < 7830457 / 26; b ++ ) {
		for ( c = 0; c < 10; c ++ ) a[c] *= 67108864;
		rectify ( a );
	}

	for ( b = 0; b < 7830457 % 26; b ++ ) {
		for ( c = 0; c < 10; c ++ ) a[c] *= 2;
		rectify ( a );
	}

	a[0] ++;
	rectify ( a );

	printf ( "The number you are looking for is " );
	for ( c = 9; c >= 0; c -- ) printf( "%d", a[c] );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}