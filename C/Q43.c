#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void rectify ( char * c, char * ca )
{
	int a = 0;

	while ( *ca > a || *( c + a ) != 0 ) {
		*( c + a + 1 ) += *( c + a ) / 10;
		*( c + a ) %= 10;
		a ++;
	}

	*ca = a;
}

void the_thing ( char * a, char * b, char t, char * c, char * ca )
{
	char d;
	char e;
	for ( d = 9; d >= 0; d -- ) {
		if ( *( b + d ) > t ) continue;
		if ( t == 9 && d == 0 ) continue;
		if ( t == 6 && ( d % 2 != 0 ) ) continue;
		if ( t == 5 && ( *( a + 7 ) + *( a + 6 ) + d ) % 3 != 0 ) continue;
		if ( t == 4 && ( d % 5 != 0 ) ) continue;
		if ( t == 3 && ( *( a + 5 ) * 100 + *( a + 4 ) * 10 + d ) % 7 != 0 ) continue;
		if ( t == 2 && ( *( a + 4 ) - *( a + 3 ) + d ) % 11 != 0 ) continue;
		if ( t == 1 && ( *( a + 3 ) * 100 + *( a + 2 ) * 10 + d ) % 13 != 0 ) continue;
		if ( t == 0 && ( *( a + 2 ) * 100 + *( a + 1 ) * 10 + d ) % 17 != 0 ) continue;
		*( a + t ) = d;
		if ( t == 0 ) {
			for ( e = 9; e >= 0; e -- ) {
				*( c + e ) += *( a + e );
				printf ( "%d", *( a + e ) );
				}
			printf ( "\n" );
			rectify ( c, ca );
		}
		else {
			for ( e = 0; e < 10; e ++ ) if ( *( b + e ) <= t ) *( b + e ) = 0;
			*( b + d ) = t;
			the_thing ( a, b, t - 1, c, ca );
		}
	}
}

int main()
{
	char * a = ( char * ) malloc ( 10 );
	char * b = ( char * ) calloc ( 10, 1 );
	char * c = ( char * ) calloc ( 15, 1 );
	char ca = 0;

	the_thing ( a, b, 9, c, &ca );

	printf ( "\nThe number you are looking for is " );
	for ( ca --; ca >= 0; ca -- ) printf ( "%d", *( c + ca ) );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}