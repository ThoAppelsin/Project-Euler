#include <stdio.h>
#include <time.h>

int main()
{
	char ch = 0;
	int a;
	int b;
	int c;
	int x;
	int che;
	for ( a = 9; a > 0; a-- ) {
		for ( b = 9; b >= 0; b-- ) {
			for ( c = 9; c >= 0; c-- ) {
				x = 100001 * a + 10010 * b + 1100 * c;
				for ( che = 100; che <= 999; che++ ) { if ( x % che == 0 && x / che <= 999 && x / che >= 100 ) { ch = 1; break; } }
				if ( ch ) break;
			}
			if ( ch ) break;
		}
		if ( ch ) break;
	}


	printf ( "The number you are looking for is %d", x );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );
	getchar();
}