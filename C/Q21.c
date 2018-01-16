#include <stdio.h>
#include <time.h>

int main()
{
	int a, b, c, d;
	int e = 0;

	for ( a = 1; a < 10000; a++ ) {
		c = 0;
		d = 0;
		for ( b = 2; b * b < a; b++ ) if ( a % b == 0 ) {
			c += b;
			c += a / b;
		}
		c += 1;
		if ( b * b == a ) c += b;
		if ( c == a ) continue;
		for ( b = 2; b * b < c; b++ ) if ( c % b == 0 ) {
			d += b;
			d += c / b;
		}
		d += 1;
		if ( b * b == c ) d += b;
		if ( d == a ) e += a;
	}

		
	printf ( "The number you are looking for is %d", e );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}