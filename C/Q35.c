#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long a = 3;
	unsigned long b;
	unsigned int c = 1;
	char t;
	char z;
	unsigned long d;
	unsigned long e;
	unsigned long f;

	printf ( "2\n" );

	while ( a < 1000000 ) {
		b = 3;
		t = 1;
		while ( b * b <= a ) {
			if ( a % b == 0 ) {
				t = 0;
				break;
			}
			b += 2;
		}

		if ( t == 1 ) {
			e = 1000000;
			z = 7;
			while ( a / e == 0 ) {
				e /= 10;
				z --;
			}
			e = 10;
			f = 1;
			for ( t = z; t > 1; t -- ) f *= 10;
		}
		while ( t == 1 && z > 1 ) {
			d = a / e + f * ( a % e );
			if ( d % 2 == 0 ) {
				t = 0;
				break;
			}
			b = 3;
			while ( b * b <= d ) {
				if ( d % b == 0 ) {
					t = 0;
					break;
				}
				b += 2;
			}
			z --;
			e *= 10;
			f /= 10;
		}

		if ( t == 1 ) {
			c ++;
			printf ( "%d\n", a );
		}

		if ( a % 10 == 9 ) if ( ( a / 10 ) % 10 == 9 ) if ( ( a / 100 ) % 10 == 9 ) if ( ( a / 1000 ) % 10 == 9 ) if ( ( a / 10000 ) % 10 == 9 ) if ( a / 100000 == 0 ) a += 2;
		else a += 100002;
		else if ( ( a / 10000 ) % 10 == 0 ) a += 2;
		else a += 10002;
		else if ( ( a / 1000 ) % 10 == 0 ) a += 2;
		else a += 1002;
		else if ( ( a / 100 ) % 10 == 0 ) a += 2;
		else a += 102;
		else if ( ( a / 10 ) % 10 == 0 ) a += 2;
		else a += 12;
		else a += 2;
	}

	printf ( "\nThe number you are looking for is %d", c );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}