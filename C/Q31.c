#include <stdio.h>
#include <time.h>

int main()
{
	unsigned char a[7] = { 0 };
	unsigned char b[7] = { 200, 100, 50, 20, 10, 5, 2 };
	unsigned char c;
	unsigned int s;
	unsigned int t = 0;
	unsigned char z = 0;

	while ( a[0] == 0 ) {
		s = 0;
		for ( c = 0; c < 7; c ++ ) s += a[c] * b[c];
		if ( s <= 200 ) {
			t ++;
			a[6] ++;
			z = 0;
		}
		else {
			a[6-z] = 0;
			a[5-z] ++;
			z ++;
		}
	}

	t ++;	

	printf ( "The number you are looking for is %d", t );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}