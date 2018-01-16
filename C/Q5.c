#include <stdio.h>
#include <time.h>

int main()
{
	time_t t = time( NULL );
	double ti = (double) t;
	long a = 1;
	long b = 2;
	while ( b <= 20 ) { if ( a % b == 0 ) b++; else { a++; b = 2; } }


	printf ( "\n\nThe number you are looking for is %d", a );
	printf ( "\nCalculated in %f seconds", (double) time( NULL ) );
	getchar();
}