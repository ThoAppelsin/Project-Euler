#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	unsigned int limit = 2500;
	unsigned long altlim = ( 3 * limit * limit - limit ) / 2;
	unsigned long * a = ( unsigned long * ) calloc ( limit + 1, 4 );
	unsigned char * b = ( unsigned char * ) calloc ( altlim + 1, 1 );
	int n;
	int k = 1;
	unsigned long diff = -1;
	char z = 0;

	for ( n = 0; n <= limit; n ++ ) {
		*( a + n ) = ( 3 * n * n - n ) / 2;
		*( b + *( a + n ) ) = 1;
	}

	n = 1;

	while ( k < limit ) {
		if ( diff <= *( a + k + 1 ) - *a ) {
			z = 1;
			break;
		}
		if ( *( a + n + k ) + *( a + n ) > altlim ) {
			n = 1;
			k ++;
			continue;
		}
		if ( *( b + *( a + n + k ) - *( a + n ) ) && *( b + *( a + n + k ) + *( a + n ) ) && *( a + n + k ) - *( a + n ) < diff ) {
			diff = *( a + n + k ) - *( a + n );
		}
		n ++;
	}

	if ( z ) printf ( "The result is certain\n\n" );
	else printf ( "The result is uncertain\n\n" );

	printf ( "The number you are looking for is %d", diff );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}