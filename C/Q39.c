#include <stdio.h>
#include <time.h>

int main()
{
	unsigned int a[250000] = { 0 };
	unsigned int b, d, e;
	unsigned char c[1001] = { 0 };
	unsigned long f;
	unsigned char rec = 0;
	unsigned int r;

	for ( b = 1; b < 500; b ++ ) a[ b * b ] = b;

	for ( b = 1; b < 293; b ++ ) for ( d = b; d < 500; d ++ ) {
		f = b * b + d * d;
		if ( f >= 250000 ) break;
		if ( a[f] == 0 ) continue;
		e = b + d + a[f];
		if ( e > 1000 ) break;
		else c[e] ++;
	}

	for ( e = 0; e < 1001; e ++ ) if ( c[e] > rec ) {
		rec = c[e];
		r = e;
	}

	printf ( "The number you are looking for is %d", r );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}