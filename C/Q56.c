#include <stdio.h>
#include <time.h>

void digit_sum ( unsigned int * c, unsigned int * t, int d )
{
	while ( d >= 0 ) {
		*t += c[d];
		d --;
	}
}

void rectify ( unsigned int * c, int * d )
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
	int a;
	int b;
	unsigned int c[210];
	int d;
	int e;
	unsigned int t;
	unsigned int rec = 0;
	int ra;
	int rb;

	for ( a = 99; a > 90; a -- ) {
		for ( d = 1; d < 210; d ++ ) c[d] = 0;
		c[0] = a;
		d = 1;
		rectify ( c, &d );
		for ( b = 2; b < 100; b ++ ) {
			for ( e = 0; e < d; e ++ ) {
				c[e] *= a;
			}
			rectify ( c, &d );
			t = 0;
			digit_sum ( c, &t, d - 1 );
			if ( t > rec ) {
				rec = t;
				ra = a;
				rb = b;
			}
		}
	}

	printf ( "The number you are looking for is %d (%d^%d)", rec, ra, rb );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}