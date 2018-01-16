#include <stdio.h>
#include <time.h>

int main()
{
	char a[3];
	FILE * f = fopen ( "C:\\docs\\ProjectEuler\\Question59\\cipher1.txt", "r" );
	char b[1201];
	int c = 0;
	char zero = '0';
	int t;
	char num = 0;

	while ( c < 1201 ) {
		t = fgetc( f );
		if ( t == ',' ) {
			b[c] = num;
			num = 0;
			c ++;
		}
		else num = num * 10 + t - zero;
	}

	fclose( f );

	for ( c = 0; c < 1201; c ++ ) printf ( "%c", b[c] );

	printf ( "\n\nThe number you are looking for is %d", 0 );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}