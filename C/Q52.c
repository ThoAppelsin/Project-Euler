#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void resort ( unsigned char * a )
{
	char b = 9;
	char c;
	unsigned char t;

	while ( b > 0 ) { 
		for ( c = 0; c < b; c ++ ) if ( * ( a + c ) > * ( a + c + 1 ) ) {
			t = * ( a + c );
			* ( a + c ) = * ( a + c + 1 );
			* ( a + c + 1 ) = t;
		}
		b --;
	}
}

void multiply ( unsigned char * a, unsigned char b, unsigned char * c )
{
	char d;

	for ( d = 0; d < 10; d ++ ) *( c + d ) = a[d] * b;
	d = 9;
	while ( d >= 0 ) {
		if ( *( c + d ) >= 10 ) {
			if ( d < 1 ) {
				printf ( "oeehh" );
				return;
			}
			*( c + d ) -= 10;
			*( c + d - 1 ) += 1;
		}
		else d --;
	}
}

char isitgood ( unsigned char * a )
{
	unsigned char b[10] = { 0 };
	unsigned char * c;
	unsigned char d = 0;
	unsigned char e = 6;
	char t = 1;

	while ( d < 10 ) {
		b[d] = a[d];
		d ++;
	}

	resort ( b );

	while ( e > 1 && t ) {
		c = ( unsigned char * ) malloc ( 10 );
		multiply ( a, e, c );
		resort ( c );
		for ( d = 0; d < 10; d ++ ) if ( *( c + d ) != b[d] ) {
			t = 0;
			break;
		}
		e --;
		free ( c );
	}
	if ( t ) return 1;
	else return 0;
}

void increment ( unsigned char * a )
{
	char b = 9;
	char len = 0;

	while ( a[len] == 0 ) len ++;
	
	a[9] ++;
	while ( a[b] >= 10 ) {
		a[b] -= 10;
		b --;
		if ( b < 0 ) {
			printf ( "oeehh" );
			return;
		}
		if ( b == len && a[b] == 1 ) a[b] = 10;
		else a[b] ++;
	}
}

int main()
{
	unsigned char a[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	char b = 0;

	while ( !isitgood( a ) ) increment ( a );

	while ( a[b] == 0 ) b ++;

	printf ( "The number you are looking for is " );
	for ( ; b < 10; b ++ ) printf( "%d", a[b] );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}