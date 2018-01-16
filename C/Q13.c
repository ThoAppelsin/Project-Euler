#include <stdio.h>

int main()
{
	FILE *f;
	char a[100][50];
	unsigned long b[100];
	char x;
	char y;

	f = fopen( "C:\\Users\\Utkan Gezer\\Documents\\Visual Studio 2012\\Projects\\Project6\\hey.txt", "r" );

	for ( x = 0; x < 100; x++ ) for ( y = 0; y < 50; y++ ) {
		do a[x][y] = (char) fgetc( f ); while ( a[x][y] == 10 );
		a[x][y] -= 48;
	}

	for ( y = 0; y < 100; y++ ) b[y] = 0;

	for ( x = 0; x < 100; x++ ) for ( y = 49; y >= 0; y-- ) {
		b[y+50] += a[x][y];
		while ( b[y+50] >= 10 ) {
			b[y+50] -= 10;
			b[y+49]++;
		}
	}

	for ( x = 99; x >= 0; x-- ) {
		while ( b[x] >= 10 ) {
			b[x] -= 10;
			b[x-1]++;
		}
	}

	x = 0;
	while ( b[x] == 0 ) x++;

	printf ( "The number you are looking for is " );
	for ( ; x < 100; x++ ) printf( "%d", b[x] );

	getchar();
}