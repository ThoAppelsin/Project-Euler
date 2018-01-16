#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long a = 3;
	unsigned long c = 2;
	unsigned long b = 3;
	unsigned long d = 0;

	while ( a < 2000000 ) {
		while ( c > 1000000000 ) { c -= 1000000000; d++; }
		if ( a < b * b ) { c += a; b = 3; a += 2; }
		else if ( a % b == 0 ) { a += 2; b = 3; }
		else b += 2;
	}

	printf ( "The number you are looking for is %u, plus %u times 1 billion", c, d );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );
	getchar();
}