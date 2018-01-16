#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long a;
	unsigned long t;
	unsigned long r;
	unsigned int c;
	unsigned int rc = 0;

	for ( a = 1; a < 1000000; a += 2 ) {
		t = a;
		c = 1;
		while ( t != 1 ) {
			c++;
			if ( t % 2 == 1 ) t = 3 * t + 1;
			else t /= 2;
		}
		if ( rc < c ) {
			rc = c;
			r = a;
		}
	}

	printf ( "The number you are looking for is %d with %d elements in its chain", r, rc );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}