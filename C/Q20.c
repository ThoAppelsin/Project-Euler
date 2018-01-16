#include <stdio.h>
#include <time.h>

int main()
{
	int a[200];
	int t;
	int p;

	for ( t = 0; t < 200; t++ ) a[t] = 0;
	a[199] = 1;

	for ( p = 2; p <= 100; p++ ) {
		for ( t = 0; t < 200 ; t++ ) a[t] *= p;
		for ( t = 199; t >= 0; t-- ) {
			while ( a[t] >= 10 ) {
				a[t] -= 10;
				a[t-1]++;
			}
		}
	}

	t = 0;
	p = 0;
	while ( a[t] == 0 ) t++;
	for ( ; t < 200; t++ ) { printf( "%d", a[t] ); p += a[t]; }
	printf ( " is the result" );

	printf ( "\n\nThe number you are looking for is %d", p );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );
	getchar();
}