#include <stdio.h>
#include <time.h>

char ispan ( unsigned int a, unsigned int b, unsigned int c ) {
	char z[10] = { 1 };

	while ( a != 0 ) {
		if ( z[a%10] == 0 ) {
			z[a%10] = 1;
			a /= 10;
		}
		else return 0;
	}
	
	while ( b != 0 ) {
		if ( z[b%10] == 0 ) {
			z[b%10] = 1;
			b /= 10;
		}
		else return 0;
	}

	while ( c != 0 ) {
		if ( z[c%10] == 0 ) {
			z[c%10] = 1;
			c /= 10;
		}
		else return 0;
	}

	for ( a = 1; a < 10; a ++ ) if ( z[a] == 0 ) return 0;

	return 1;
}

int main()
{
	unsigned int a = 1000;
	unsigned int b;
	unsigned int c;
	unsigned int s = 0;

	while ( a < 10000 ) {
		b = 2;
		while ( b * b < a ) {
			if ( a % b == 0 ) {
				c = a / b;
				if ( ispan( a, b, c ) ) {
					printf ( "%d = %d * %d\n", a, c, b );
					s += a;
					break;
				}
			}
			b ++;
		}
		a ++;
	}

	printf ( "\nThe number you are looking for is %d", s );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}