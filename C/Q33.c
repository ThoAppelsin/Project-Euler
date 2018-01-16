#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long a, b, c;
	unsigned char xa[4] = { 0 }, xb[4] = { 0 };
	unsigned char t = 0;

	for ( a = 10; a < 100; a ++ ) {
		if ( a % 11 == 0 ) continue;
		for ( b = a + 1; b < 100; b ++ ) {
			if ( b % 11 == 0 ) continue;
			if ( ( ( a % 10 == b / 10 ) && a * ( b % 10 ) == b * ( a / 10 ) ) || ( ( a / 10 == b % 10 ) && a * ( b / 10 ) == b * ( a % 10 ) ) ) {
				printf ( "%d / %d\n", a, b );
				xa[t] = a;
				xb[t] = b;
				t ++;
			}
		}
	}

	a = 1;
	b = 1;

	for ( t = 0; t < 4; t ++ ) {
		a *= xa[t];
		b *= xb[t];
	}

	while ( a % 2 + b % 2 == 0 ) {
		a /= 2;
		b /= 2;
	}

	c = 3;

	while ( c <= a && c <= b ) {
		if ( a % c + b % c == 0 ) {
			a /= c;
			b /= c;
		}
		else c += 2;
	}

	printf ( "\nThe number you are looking for is %d", b );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}