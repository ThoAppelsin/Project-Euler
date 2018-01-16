#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	char limit = 4;
	
	unsigned long size = 150000;
	char * a = ( char * ) calloc ( size + 1, 1 );
	char * d = ( char * ) calloc ( size + 1, 1 );
	unsigned long b, c;
	char q;
	char z = 0;

	for ( b = 3; b <= size / 2; b += 2 ) {
		c = 2 * b;
		while ( c <= size ) {
			*( a + c ) = 1;
			c += b;
		}
	}

	*a = 1;
	*( a + 1 ) = 1;
	*( a + 4 ) = 1;

	for ( b = 3; b <= size; b += 2 ) {
		if ( *( a + b ) == 0 ) {
			c = b;
			while ( c <= size ) {
				*( d + c ) += 1;
				c += b;
			}
		}
	}

	b = 2;
	c = b;
	while ( c <= size ) {
		*( d + c ) += 1;
		c += b;
	}

	b = 2;
	q = 0;
	while ( b <= size ) {
		if ( *( d + b ) == limit ) {
			q ++;
			if ( q == 1 ) c = b;
			if ( q == limit ) {
				z = 1;
				break;
			}
		}
		else {
			q = 0;
		}
		b ++;
	}

	if ( z ) printf ( "The number you are looking for is %d", c );
	else printf ( "Sorry, failed to find one, you'll have to adjust the size" );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}