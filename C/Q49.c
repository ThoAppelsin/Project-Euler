#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int a;
	int b;
	char * c = ( char * ) malloc ( 8 );
	char d;
	int e;
	char f;
	char g;
	char * z = ( char * ) calloc ( 10000, 1 );

	for ( a = 3; a < 5000; a += 2 ) {
		b = 2 * a;
		while ( b < 10000 ) {
			*( z + b ) = 1;
			b += a;
		}
	}
	
	*z = 1;
	*( z + 1 ) = 1;
	*( z + 4 ) = 1;
	
	for ( a = 1001; a <= 9997; a += 2 ) {
		if ( *( z + a ) == 1 ) continue;
		for ( b = 2; b <= ( 9999 - a ) / 2; b += 2 ) {
			if ( *( z + a + b ) == 1 || *( z + a + b + b ) == 1 ) continue;
			for ( d = 1; d < 8; d ++ ) *( c + d ) = 0;
			*c = a % 10;
			e = a / 10;
			for ( d = 1; d < 4; d ++ ) {
				f = 0;
				while ( f < d ) {
					if ( *( c + f ) > e % 10 ) {
						for ( g = d; g >= f; g -- ) {
							*( c + g + 1 ) = *( c + g );
						}
						break;
					}
					f ++;
				}
				*( c + f ) = e % 10;
				e /= 10;
			}
			*( c + 4 ) = ( a + b ) % 10;
			e = ( a + b ) / 10;
			for ( d = 5; d < 8; d ++ ) {
				f = 4;
				while ( f < d ) {
					if ( *( c + f ) > e % 10 ) {
						for ( g = d; g >= f; g -- ) {
							*( c + g + 1 ) = *( c + g );
						}
						break;
					}
					f ++;
				}
				*( c + f ) = e % 10;
				e /= 10;
			}
			if ( *c != *( c + 4 ) || *( c + 1 ) != *( c + 5 ) || *( c + 2 ) != *( c + 6 ) || *( c + 3 ) != *( c + 7 ) ) continue;
			*( c + 4 ) = ( a + b + b ) % 10;
			e = ( a + b + b ) / 10;
			for ( d = 5; d < 8; d ++ ) {
				f = 4;
				while ( f < d ) {
					if ( *( c + f ) > e % 10 ) {
						for ( g = d; g >= f; g -- ) {
							*( c + g + 1 ) = *( c + g );
						}
						break;
					}
					f ++;
				}
				*( c + f ) = e % 10;
				e /= 10;
			}
			if ( *c != *( c + 4 ) || *( c + 1 ) != *( c + 5 ) || *( c + 2 ) != *( c + 6 ) || *( c + 3 ) != *( c + 7 ) ) continue;
			printf ( "%d ~ %d ~ %d\n", a, a + b, a + b + b );
		}
	}

	printf ( "\nThe number you are looking for is one of those" );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}