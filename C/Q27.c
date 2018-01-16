#include <stdio.h>
#include <time.h>

int main()
{
	int a, b;
	unsigned char n;
	long d, e;
	char x[13000] = { 0 };
	unsigned char r = 0;
	int ra = 0, rb = 0;

	for ( d = 2; d < 6500; d ++ ) {
		e = d * 2;
		while ( e < 13000 ) {
			x[e] = 1;
			e += d;
		}
	}

	for ( b = 2; b < 1000; b ++ ) for ( a = 1 - b; a < 1000; a ++ ) {
		n = 0;
		d = b;
		while ( d >= 2 ) {
			if ( d >= 13000 ) { printf ( "%u: %d %d %u\n", d, a, b, n ); break; }
			if ( x[d] == 1 ) break;
			n ++;
			d = n * n + a * n + b;
		}
		if ( n > r ) {
			r = n;
			ra = a;
			rb = b;
		}
	}

	printf ( "The number you are looking for is %d", ra * rb );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}