#include <stdio.h>
#include <time.h>

int ispalindromic ( char * c, char * d )
{
	int a = 0;

	while ( a < *d / 2 ) {
		if ( c[a] != c[ *d - a - 1 ] ) return 0;
		a ++;
	}
	return 1;
}

void rectify ( char * c, char * d )
{
	int a = 0;

	while ( *d > a || c[a] != 0 ) {
		c[a+1] += c[a] / 10;
		c[a] %= 10;
		a ++;
	}

	*d = a;
}

int main()
{
	int limit = 10000;

	char a[6] = { 1 };
	char b[30] = { 0 };
	char c[30] = { 0 };

	char ax = 1;
	char bx = 0;
	char cx = 0;

	char t;
	char z;
	int count = 0;

	while ( a[4] == 0 ) {
		for ( t = 0; t < ax; t ++ ) {
			b[t] = a[t] + a[ ax - t - 1 ];
		}
		bx = ax;
		rectify ( b, &bx );
		z = 1;
		while ( ispalindromic( b, &bx ) == 0 ) {
			if ( z >= 50 ) {
				count ++;
				break;
			}
			for ( t = 0; t < bx; t ++ ) {
				c[t] = b[ bx - t - 1 ];
			}
			cx = bx;
			for ( t = 0; t < cx; t ++ ) {
				b[t] += c[t];
			}
			rectify ( b, &bx );
			z ++;
		}
		for ( t = 0; t < bx; t ++ ) {
			b[t] = 0;
			c[t] = 0;
		}
		a[0] ++;
		rectify ( a, &ax );
	}

	printf ( "The number you are looking for is %d", count );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}