#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int cmp( const void * a, const void * b )
{
	int c = * ((int *) a) - * ((int *) b);
	char d = 0;
	while (c == 0 && d < 24) {
		d ++;
		c = * (((int *) a) + d) - * (((int *) b) + d);
	}
	return c;
}

int main()
{
	char a[25] = { 2 };
	unsigned int b;
	char c;
	char d;
	char e = 0;
	int f;
	unsigned int *z = (unsigned int *) malloc ( 99 * 99 * 25 * 4 );
	unsigned int y;

	for ( c = 3; c < 100; c += 2  ) {
		for ( d = 3; d < c; d ++ ) if ( c % d == 0 ) break;
		if ( d == c ) { e ++; a[e] = c; }
	}
	
	for ( c = 0; c < 99; c ++ ) {
		d = 0;
		f = c + 2;
		y = 0;
		while ( d < 25 ) {
			if ( f % a[d] == 0 ) {
				f /= a[d];
				y ++;
			}
			else {
				for ( e = 0; e < 99; e ++ ) *(z + 25 * ( 99 * c + e ) + d ) = y * ( e + 2 );
				y = 0;
				d ++;
			}
		}
	}
	
	qsort ( z, 99 * 99, 25 * 4, cmp );

	f = 1;
	b = 1;
	d = 0;
	while ( f < 9801 ) {
		if ( *( z + 25 * f + d ) != *( z + 25 * f + d - 25 ) ) {
			b ++;
			f ++;
			d = 0;
		}
		else if ( d == 24 ) {
			f ++;
			d = 0;
		}
		else d ++;
	}

	free( z );

	printf ( "The number you are looking for is %d", b );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}