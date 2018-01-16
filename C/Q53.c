#include <stdio.h>
#include <time.h>

int main()
{
	unsigned char n;
	unsigned char r;
	unsigned long z;
	unsigned int c = 0;

	for ( n = 1; n <= 100; n ++ ) {
		r = 0;
		z = 1;
		while ( r <= n / 2 ) {
			if ( z > 1000000 ) {
				c += n + 1 - 2 * r;
				break;
			}
			r ++;
			z = z * ( n - r + 1 ) / r;
		}
	}

	printf ( "The number you are looking for is %d", c );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}