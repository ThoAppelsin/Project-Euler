#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char isitgood ( unsigned long * z, char * a )
{
	unsigned long b = 1;

	while ( 2 * b * b < *z ) {
		if ( *( a + *z - 2 * b * b ) == 0 ) return 1;
		b ++;
	}

	return 0;
}

int main()
{
	char * a = ( char * ) calloc ( 10000, 1 );
	unsigned long z;
	unsigned long q;
	char b = 0;

	for ( z = 2; z < 5000; z ++ ) {
		q = 2 * z;
		while ( q < 10000 ) {
			*( a + q ) = 1;
			q += z;
		}
	}

	*a = 1;
	*( a + 1 ) = 1;

	z = 9;

	while ( z < 10000 ) {
		if ( isitgood ( &z, a ) ) do z += 2; while ( *( a + z ) == 0 );
		else {
			b = 1;
			break;
		}
	}

	if ( b ) {
		printf ( "The number you are looking for is %d", z );
		printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );
	}
	else printf ( "sorry, you'll have to expand the primes list" );

	getchar();
}