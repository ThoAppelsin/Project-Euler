#include <stdio.h>

int main()
{
	long a1 = 600851;
	long a2 = 475143;
	long b = 2;
	char hehe = 0;
	while ( a2 != 1 ) {
		if ( ( ( a1 % b ) * ( 1000000 % b ) + ( a2 % b ) ) % b == 0 ) {
			hehe = 1;
			a2 = ( ( a1 % b ) * 1000000 + a2 ) / b;
			a1 /= b;
			printf ( "%d ", b );
		}
		else {
			b += 1;
			if ( hehe ) { printf ( "\n" ); hehe = 0; }
		}
	}


	printf ( "\n\nThe number you are looking for is %d", b );
	getchar();
}