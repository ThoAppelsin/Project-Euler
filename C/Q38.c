#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char works_out ( unsigned char * a )
{
	unsigned long b = 0;
	unsigned long c = 0;
	char d;
	
	for ( d = 0; d < 4; d ++ ) b = 10 * b + *( a + d );
	for ( d = 4; d < 9; d ++ ) c = 10 * c + *( a + d );

	if ( 2 * b == c ) return 1;
	
	return 0;
}

void the_thing ( unsigned char * a, unsigned char * b, unsigned char t, char * z )
{
	unsigned char d;
	unsigned char e;
	for ( d = 9; d > 0; d -- ) {
		if ( *z ) break;
		if ( *( b + d - 1 ) > t ) continue;
		*( a + 9 - t ) = d;
		if ( t == 1 ) {
			if ( works_out ( a ) ) {
				* z = 1;
				break;
			}
		}
		else {
			for ( e = 0; e < 9; e ++ ) if ( *( b + e ) <= t ) *( b + e ) = 0;
			*( b + d - 1 ) = t;
			the_thing ( a, b, t - 1, z );
		}
	}
}

int main()
{
	unsigned char * a = ( unsigned char * ) malloc ( 9 );
	unsigned char * b = ( unsigned char * ) calloc ( 9, 1 );
	char z = 0;

	the_thing ( a, b, 9, &z );

	printf ( "The number you are looking for is " );
	for ( z = 0; z < 9; z ++ ) printf ( "%d", *( a + z ) );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}