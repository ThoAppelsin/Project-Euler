#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long a;

	printf ( "The number you are looking for is %d", 0 );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}