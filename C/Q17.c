#include <stdio.h>
#include <time.h>

int main()
{
	char a[10] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 };
	char b[10] = { 0, 3, 6, 6, 5, 5, 5, 7, 6, 6 };
	char x[10] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
	char c[10] = { 0, 10, 10, 12, 11, 11, 10, 12, 12, 11 };
	unsigned int e[20];
	char y;
	char ax, bx, cx;
	
	for ( y = 0; y < 20; y++ ) e[y] = 0;

	for ( cx = 0; cx < 10; cx++ ) for ( bx = 0; bx < 10; bx++ ) for ( ax = 0; ax < 10; ax++ ) {
		if ( bx != 1 ) e[19] += a[ax] + b[bx] + c[cx];
		else e[19] += x[ax] + c[cx];
		if ( cx > 0 && ax + bx > 0 ) e[19] += 3;
		for ( y = 19; y > 0; y-- ) while ( e[y] >= 10 ) { e[y] -= 10; e[y-1]++; }
	}

	e[19] += 11;
	for ( y = 19; y > 0; y-- ) while ( e[y] >= 10 ) { e[y] -= 10; e[y-1]++; }

	y = 0;
	while ( e[y] == 0 ) y++;

	printf ( "The number you are looking for is " );
	for ( ; y < 20; y++ ) printf ( "%d", e[y] );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}