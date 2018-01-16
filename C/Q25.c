#include <stdio.h>
#include <time.h>

int main()
{
	unsigned char a[3][1000];
	int b, c, d, e;

	for ( c = 0; c < 3; c++ ) for ( d = 0; d < 1000; d++ ) a[c][d] = 0;
	a[0][999] = 1;
	a[1][999] = 1;
	c = 1;

	for ( b = 998; b >= 0; b-- ) {
		while ( a[0][b] == 0 && a[1][b] == 0 && a[2][b] == 0 ) {
			c++;
			e = c % 3;
			for ( d = b + 1; d < 1000; d++ ) a[e][d] = a[(c+1)%3][d] + a[(c+2)%3][d];
			for ( d = 999; d > b; d-- ) while ( a[e][d] >= 10 ) { a[e][d] -= 10; a[e][d-1]++; }
		}
	}


	printf ( "The number you are looking for is %d", c + 1 );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}