#include <stdio.h>
#include <time.h>

unsigned char length_returner ( unsigned long * a )
{
	unsigned long c = 1;
	unsigned char d = 0;
	while ( *a / c != 0 ) {
		c *= 10;
		d ++;
	}
	return d;
}

unsigned char digit_returner ( unsigned long a, unsigned char b )
{
	unsigned char d = length_returner( &a );
	d -= b;
	while ( d > 0 ) {
		a /= 10;
		d --;
	}
	return a % 10;
}

int main()
{
	unsigned long a = 1;
	unsigned long b = 0;
	unsigned long c = 0;
	unsigned char d = 7;
	unsigned long e = 1;
	unsigned char t;

	while ( d > 0 ) {
		while ( b < a ) {
			c ++;
			b += length_returner ( &c );
		}
		t = digit_returner( c, a - b + length_returner ( &c ) );
		printf ( "%d\n", t );
		e *= t;
		d --;
		a *= 10;
	}
			


	printf ( "\nThe number you are looking for is %d", e );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}