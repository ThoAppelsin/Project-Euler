#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char not_prime_check ( unsigned long * a )
{
	unsigned int b = 3;
	while ( b * b <= *a ) {
		if ( *a % b == 0 ) return 1;
		b += 2;
	}
	return 0;
}

int main()
{
	char n = 2;
	char m;
	char k;
	char c = 11;
	long d, e;
	unsigned long t;
	char *q = ( char * ) malloc ( n );
	unsigned long s = 0;

	*q = 2;
	*( q + 1 ) = 3;
	
	while ( c > 0 ) {
		while ( 1 ) {
			t = *q;
			for ( m = 1; m < n; m ++ ) {
				t = 10 * t + *( q + m );
				if ( not_prime_check( &t ) ) goto sorry;
			}
			for ( m = 2; m < n; m ++ ) {
				t = *( q + n - m );
				for ( k = 1; k < m; k ++ ) {
					t = 10 * t + *( q + n - m + k );
				}
				if ( not_prime_check( &t ) ) goto sorry;
			}
			t = *q;
			for ( m = 1; m < n; m ++ ) t = 10 * t + *( q + m );
			s += t;
			c --;
			printf ( "%d:\t%d\n", 11 - c, t );
sorry:
			if ( *( q + n - 1 ) == 3 ) *( q + n - 1 ) = 7;
			else {
				*( q + n - 1 ) = 3;
				m = 2;
				while ( m < n ) {
					if ( *( q + n - m ) == 1 ) {
						*( q + n - m ) = 3;
						break;
					}
					else if ( *( q + n - m ) == 3 ) {
						*( q + n - m ) = 7;
						break;
					}
					else if ( *( q + n - m ) == 7 ) {
						*( q + n - m ) = 9;
						break;
					}
					else {
						*( q + n - m ) = 1;
						m ++;
					}
				}
				if ( m == n ) {
					if ( *q == 2 ) *q = 3;
					else if ( *q == 3 ) *q = 5;
					else if ( *q == 5 ) *q = 7;
					else break;
				}
			}
		}
		n ++;
		free ( q );
		q = ( char * ) malloc( n );
		*q = 2;
		for ( m = 1; m < n - 1; m ++ ) *( q + m ) = 1;
		*( q + n - 1 ) = 3;
	}

	printf ( "\nThe number you are looking for is %d", s );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}