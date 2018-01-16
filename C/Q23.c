#include <stdio.h>
#include <time.h>

int main()
{
	unsigned int a = 10;
	unsigned int c = 0;
	unsigned int b;
	unsigned int d;
	unsigned int e[6965];
	unsigned long s = 0;
	char q[28124] = { 0 };

	while ( a < 28123 ) {
		b = 2;
		d = 1;
		while ( b * b < a ) {
			if ( a % b == 0 ) d += b + a / b;
			b ++;
		}
		if ( b * b == a ) d += b;
		if ( d > a ) {
			e[c] = a;
			c ++;
		}
		a ++;
	}

	a = 1;
	
	for ( c = 0; c < 6965; c ++ ) {
		for ( b = c; b < 6965; b ++ ) {
			d = e[c] + e[b];
			if ( d < 28124 ) q[ e[c] + e[b] ] = 1;
			else break;
		}
	}

	for ( c = 1; c < 28124; c ++ ) if ( !q[c] ) s += c;

	printf ( "The number you are looking for is %d", s );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}