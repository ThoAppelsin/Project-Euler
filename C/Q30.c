#include <stdio.h>
#include <time.h>

int main()
{
	int a;
	int b;
	int c;
	int d = 0;
	int e;

	for ( a = 2; a < 355000; a ++ ) {
		b = a;
		c = 0;
		while ( b != 0 ) {
			e = b % 10;
			c += e * e * e * e * e;
			b /= 10;
		}
		if ( c == a ) {
			printf ( "%d ...\n", a );
			d += a;
		}
	}

	printf ( "\nThe number you are looking for is %d", d );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}