#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	char * a = ( char * ) calloc ( 1000000, 1 );
	unsigned long * b = ( unsigned long * ) calloc ( 80000, 4 );
	unsigned long z;
	unsigned long q;
	unsigned long s;
	unsigned long c;
	unsigned long rec = 0;
	unsigned long rs;

	for ( z = 2; z < 500000; z ++ ) {
		q = 2 * z;
		while ( q < 1000000 ) {
			*( a + q ) = 1;
			q += z;
		}
	}

	*a = 1;
	*( a + 1 ) = 1;

	q = 0;

	for ( z = 2; z < 1000000; z ++ ) if ( *( a + z ) == 0 ) {
		*( b + q ) = z;
		q ++;
	}

	z = 0;

	while ( z + rec < q ) {
		s = *( b + z );
		c = 1;
		while ( s < 1000000 && z + c < q ) {
			if ( *( a + s ) == 0 && rec < c ) {
				rec = c;
				rs = s;
			}
			s += *( b + z + c );
			c ++;
		}
		z ++;
	}

	printf ( "The number you are looking for is %d with the chain length %d", rs, rec );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}