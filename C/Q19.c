#include <stdio.h>
#include <time.h>

int main()
{
	int a = 0;
	int b;
	int c;
	int z = 0;

	a = ( a + 365 ) % 7;

	for ( b = 1901; b < 2001; b ++ ) {
		for ( c = 1; c < 13; c ++ ) {
			if ( a == 6 ) z ++;
			if ( c == 2 ) { if ( b % 4 == 0 ) a = ( a + 29 ) % 7; else a = ( a + 28 ) % 7; }
			else if ( c == 4 || c == 6 || c == 9 || c == 11 ) a = ( a + 30 ) % 7;
			else a = ( a + 31 ) % 7;
		}
	}



	printf ( "The number you are looking for is %d", z );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}