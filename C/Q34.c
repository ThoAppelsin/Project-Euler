#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long a[10];
	char b;
	char c;
	unsigned long d;
	unsigned long e;
	unsigned long f;
	unsigned long g = 0;

	for ( b = 0; b < 10; b ++ ) {
		a[b] = 1;
		for ( c = 2; c <= b; c ++ ) {
			a[b] *= c;
		}
	}

	for ( d = 10; d < 41000; d ++ ) {
		e = 0;
		f = d;
		while ( f != 0 ) {
			e += a[ f % 10 ];
			f /= 10;
		}
		if ( e == d ) {
			printf ( "%d\n", d );
			g += d;
		}
	}


	printf ( "\nThe number you are looking for is %d", g );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}