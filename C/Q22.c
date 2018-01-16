#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *a;
	char b[5500][15];
	int c;
	char d = 0;
	int e = -1;
	char f = 0;
	int g;
	unsigned long h = 0;
	
	a = fopen( "C:\\Users\\Utkan Gezer\\Documents\\visual studio 2012\\Projects\\Project6\\names.txt", "r" );
	
	c = fgetc( a );
	while ( c != EOF ) {
		if (c == 34 ) {
			if ( d ) b[e][f] = 0;
			d = 1 - d;
			if ( d ) {
				e ++;
				f = 0;
			}
			c = fgetc( a );
			continue;
		}
		if ( d ) {
			b[e][f] = c - 64;
			f ++;
		}
		c = fgetc( a );
	}

	qsort( b, e + 1, 15, strcmp );

	f = 0;
	for ( g = 0; g <= e; g ++ ) {
		d = b[g][f];
		while ( d != NULL ) {
			h += d * ( g + 1 );
			f ++;
			d = b[g][f];
		}
		f = 0;
	}

	printf ( "The number you are looking for is %d", h );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}