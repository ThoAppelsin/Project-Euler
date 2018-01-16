#include <stdio.h>

int main()
{
	unsigned long a = 0;
	unsigned long x = 1;
	unsigned long y = 2;
	while ( x <= 4000000 ) { if ( x % 2 == 0 ) a += x; y += x; x = y - x; }
	printf ( "The number you are looking for is %d", a );
	getchar();
}