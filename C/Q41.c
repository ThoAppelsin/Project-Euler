#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char prime_check ( unsigned char * a, unsigned char * digits )
{
	unsigned long b = 0;
	unsigned int c;

	if ( *( a + *digits - 1 ) % 2 == 0 ) return 0;
	
	for ( c = 0; c < *digits; c ++ ) b = 10 * b + *( a + c );
	c = 3;
	while ( c * c <= b ) {
		if ( b % c == 0 ) return 0;
		c += 2;
	}

	return 1;
}

void the_thing ( unsigned char * a, unsigned char * b, unsigned char t, unsigned char * digits, char * z )
{
	unsigned char d;
	unsigned char e;
	for ( d = *digits; d > 0; d -- ) {
		if ( *z ) break;
		if ( *( b + d - 1 ) > t ) continue;
		*( a + *digits - t ) = d;
		if ( t == 1 ) {
			if ( prime_check ( a, digits ) ) {
				* z = 1;
				break;
			}
		}
		else {
			for ( e = 0; e < *digits; e ++ ) if ( *( b + e ) <= t ) *( b + e ) = 0;
			*( b + d - 1 ) = t;
			the_thing ( a, b, t - 1, digits, z );
		}
	}
}

int main()
{
	unsigned char digits = 9;

	unsigned char * a = ( unsigned char * ) malloc ( digits );
	unsigned char * b = ( unsigned char * ) calloc ( digits, 1 );
	unsigned char t = digits;
	char z = 0;

	while ( digits > 0 ) {
		the_thing ( a, b, t, &digits, &z );
		if ( z ) break;
		else {
			digits --;
			t = digits;
			free ( a );
			free ( b );
			a = ( unsigned char * ) malloc ( digits );
			b = ( unsigned char * ) calloc ( digits, 1 );
		}
	}

	printf ( "The number you are looking for is " );
	for ( z = 0; z < digits; z ++ ) printf ( "%d", *( a + z ) );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}