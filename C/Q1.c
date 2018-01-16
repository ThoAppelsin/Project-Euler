#include <stdio.h>

int main()
{
	int i = 1;
	int a = 0;
	while ( i < 1000 ) { if ( i % 3 == 0 || i % 5 == 0 ) { a += i; } i++; }
	printf ( "The number you are looking for is %d", a );
	getchar();
}