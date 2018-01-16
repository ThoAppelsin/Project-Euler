#include <stdio.h>
#include <time.h>

int main()
{
	unsigned int a = 2;
	unsigned int r = 0;
	unsigned int ra = 0;
	unsigned int b;
	char z[1000] = { 1, 1 };
	unsigned int t;

	while ( a < 1000 )
	{
		for ( t = 2; t < 1000; t++ ) z[t] = 0;
		t = 1;
		b = 1;
		while ( b < a ) {
			b *= 10;
			t ++;
		}
		b %= a;
		if ( b == 0 ) goto sorry;
		while ( z[b] == 0 ) {
			z[b] = t;
			while ( b < a ) {
				b *= 10;
				t ++;
			}
			b %= a;
			if ( b == 0 ) goto sorry;
		}
		t -= z[b];
		printf ( "%d:\t%d\n", a, t );
		if ( t > r ) {
			r = t;
			ra = a;
		}
sorry:
		a ++;
	}


	printf ( "\nThe number you are looking for is %d with %d recurring digits", ra, r );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}