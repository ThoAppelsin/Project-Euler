#include <stdio.h>
#include <time.h>

int main()
{
	int a[200];
	int b;
	int c;
	int lat1 = 20;
	int lat2 = 20;

	for ( b = 0; b < 200; b++ ) a[b] = 0;
	a[199] = 1;

	for ( b = 2; b <= lat1 + lat2; b++ ) {
		for ( c = 0; c < 200; c++ ) a[c] *= b;
		for ( c = 199; c > 0; c-- ) {
			while ( a[c] >= 10 ) {
				a[c] -= 10;
				a[c-1]++;
			}
		}
	}

	for ( b = 2; b <= lat1; b++ ) {
		for ( c = 0; c < 199; c++ ) {
			a[c+1] += ( a[c] % b ) * 10;
			a[c] /= b;
		}
		a[199] /= b;
	}

	for ( b = 2; b <= lat2; b++ ) {
		for ( c = 0; c < 199; c++ ) {
			a[c+1] += ( a[c] % b ) * 10;
			a[c] /= b;
		}
		a[199] /= b;
	}

	c = 0;
	while ( a[c] == 0 ) c++;

	printf ( "The number you are looking for is " );
	for ( ; c < 200; c++ ) printf( "%d", a[c] );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}