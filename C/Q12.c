#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long a;
	unsigned long b = 0;
	unsigned long f;
	int c = 0;
	int t;
	int d;
	
	for ( a = 1; c <= 500; a++ ) {
		c = 1;
		b += a;
		f = b;
		d = 2;
		t = 1;
		while ( f != 1 ) {
			while ( f % d == 0 ) { f /= d; t++; }
			c *= t;
			t = 1;
			d++;
		}
	}

	printf ( "The number you are looking for is %d with %d divisors", b, c );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}