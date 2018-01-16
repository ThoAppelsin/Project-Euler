#include <stdio.h>

int main()
{
	int a[2000];
	int n = 1999;
	int p;
	int t;
	for ( t = 0; t <= 1999; t++ ) a[t] = 0;
	a[0] = 1;

	for ( p = 1; p <= 1000; p++ ) {
		for ( t = 0; t <= 1999; t++ ) a[t] *= 2;
		for ( t = 0; t <= 1998; t++ ) while ( a[t] >= 10 ) { a[t] -= 10; a[t+1] += 1; }
	}

	t = 0;
	while ( a[n] == 0 && n > 0 ) n--;
	printf ( "The number you are looking for is " );
	while ( n >= 0 ) { if ( n % 3 == 2 ) printf( " " ); printf( "%d", a[n] ); t += a[n]; n--; }
	printf( "\n\n\n ... or just %d", t );

	getchar();
}