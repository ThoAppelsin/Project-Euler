#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	unsigned int na, nb, nc;
	char z = 3;
	
	na = 1;
	nb = 1;
	nc = 1;

#define xa ( na * ( na + 1 ) / 2 )
#define xb ( nb * ( 3 * nb - 1 ) / 2 )
#define xc ( nc * ( 2 * nc - 1 ) )

	while ( z > 0 ) {
		if ( xa < xb ) {
			if ( xa < xc ) na ++;
			else if ( xc < xa ) nc++;
			else {
				na ++;
				nc ++;
			}
		}
		else if ( xb < xa ) {
			if ( xb < xc ) nb ++;
			else if ( xc < xb ) nc ++;
			else {
				nb ++;
				nc ++;
			}
		}
		else if ( xa < xc ) {
			na ++;
			nb ++;
		}
		else {
			printf ( "%d\n", xa );
			na ++;
			nb ++;
			nc ++;
			z --;
		}
	}

	na --;
	nb --;
	nc --;

	printf ( "\nThe number you are looking for is %d", xa );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

#undef xa
#undef xb
#undef xc

	getchar();
}