#include <stdio.h>
#include <time.h>

void rectify ( char * c, int * d )
{
	int a = 0;

	while ( *d > a || c[a] != 0 ) {
		c[a+1] += c[a] / 10;
		c[a] %= 10;
		a ++;
	}

	*d = a;
}

int main()
{
	char a[100] = { 0 };
	char b = 1;
	int d = 0;
	char p = 0;
	char e;
	unsigned int count = 0;

	while ( b < 10 ) {
		for ( e = 1; e < d; e ++ ) a[e] = 0;
		a[0] = b;
		d = 1;
		p = 1;
		while ( d == p ) {
			count ++;
			p ++;
			for ( e = 0; e < d; e ++ ) a[e] *= b;
			rectify ( a, &d );
		}
		b ++;
	}


	printf ( "The number you are looking for is %d", count );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}