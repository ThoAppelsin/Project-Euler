#include <stdio.h>
#include <time.h>

int main()
{
	FILE * a = fopen ( "C:\\Users\\Utkan Gezer\\Documents\\Visual Studio 2012\\Projects\\Project6\\words.txt", "r" );
	char b = 0;
	char t;
	int s;
	char base = 'A' - 1;
	unsigned int c = 0;
	char z[250] = { 0 };

	t = 1;
	s = 1;
	while ( s < 250 ) {
		z[s] = 1;
		t ++;
		s = t * ( t + 1 ) / 2;
	}

	t = getc( a );
	s = 0;

	while ( t != EOF ) {
		if ( t == '\"' ) {
			if ( b == 0 ) {
				b = 1;
			}
			else {
				if ( z[s] ) c ++;
				b = 0;
				s = 0;
			}
		}
		else if ( b == 1 ) s += t - base;
		t = getc( a );
	}

	printf ( "The number you are looking for is %d", c );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}