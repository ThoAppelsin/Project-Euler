#include <stdio.h>
#include <time.h>
#define z 10

int main()
{
	int a[z];
	char b;
	char c;
	int d = 1000000;
	char e[z-1] = { 0 };
	char f[z];

	for ( b = 0; b < z; b ++ ) {
		a[b] = 1;
		f[b] = b;
		for ( c = 0; c < b; c ++ ) a[b] *= c + 2;
	}
	
	d -= 1;
	b = z-1;
	while ( b >= 0 ) {
		if ( d >= a[b] ) {
			d -= a[b];
			e[z-2-b] ++;
		}
		else b --;
	}

	printf ( "The number you are looking for is " );
	for ( b = 0; b < z-1; b ++ ) {
		printf ( "%d", f[e[b]] );
		for ( c = e[b]; c < z-1-b; c ++ ) {
			f[c] = f[c+1];
		}
	}
	printf ( "%d", f[0] );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}