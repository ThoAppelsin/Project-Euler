#include <stdio.h>
#include <time.h>

int main()
{
	unsigned long a;
	char x, y, z;
	char q[20];
	char w, t;
	char c;
	unsigned long s = 0;

	for ( x = 1; x < 10; x ++ ) {
		a = x;
		w = 0;
		while ( a != 0 ) {
			q[w] = a % 2;
			a /= 2;
			w ++;
		}
		w --;
		t = w;
		c = 1;
		while ( t > w / 2 ) {
			if ( q[t] != q[w-t] ) {
				c = 0;
				break;
			}
			t --;
		}
		if ( c ) {
			printf ( "%d\n", x );
			s += x;
		}
	}

	for ( x = 1; x < 10; x ++ ) {
		a = 11 * x;
		w = 0;
		while ( a != 0 ) {
			q[w] = a % 2;
			a /= 2;
			w ++;
		}
		w --;
		t = w;
		c = 1;
		while ( t > w / 2 ) {
			if ( q[t] != q[w-t] ) {
				c = 0;
				break;
			}
			t --;
		}
		if ( c ) {
			printf ( "%d\n", 11 * x );
			s += 11 * x;
		}
	}
	
	for ( x = 1; x < 10; x ++ ) for ( y = 0; y < 10; y ++ ) {
		a = 101 * x + 10 * y;
		w = 0;
		while ( a != 0 ) {
			q[w] = a % 2;
			a /= 2;
			w ++;
		}
		w --;
		t = w;
		c = 1;
		while ( t > w / 2 ) {
			if ( q[t] != q[w-t] ) {
				c = 0;
				break;
			}
			t --;
		}
		if ( c ) {
			printf ( "%d\n", 101 * x + 10 * y );
			s += 101 * x + 10 * y;
		}
	}

	for ( x = 1; x < 10; x ++ ) for ( y = 0; y < 10; y ++ ) {
		a = 1001 * x + 110 * y;
		w = 0;
		while ( a != 0 ) {
			q[w] = a % 2;
			a /= 2;
			w ++;
		}
		w --;
		t = w;
		c = 1;
		while ( t > w / 2 ) {
			if ( q[t] != q[w-t] ) {
				c = 0;
				break;
			}
			t --;
		}
		if ( c ) {
			printf ( "%d\n", 1001 * x + 110 * y );
			s += 1001 * x + 110 * y;
		}
	}

	for ( x = 1; x < 10; x ++ ) for ( y = 0; y < 10; y ++ ) for ( z = 0; z < 10; z ++ ) {
		a = 10001 * x + 1010 * y + 100 * z;
		w = 0;
		while ( a != 0 ) {
			q[w] = a % 2;
			a /= 2;
			w ++;
		}
		w --;
		t = w;
		c = 1;
		while ( t > w / 2 ) {
			if ( q[t] != q[w-t] ) {
				c = 0;
				break;
			}
			t --;
		}
		if ( c ) {
			printf ( "%d\n", 10001 * x + 1010 * y + 100 * z );
			s += 10001 * x + 1010 * y + 100 * z;
		}
	}

	for ( x = 1; x < 10; x ++ ) for ( y = 0; y < 10; y ++ ) for ( z = 0; z < 10; z ++ ) {
		a = 100001 * x + 10010 * y + 1100 * z;
		w = 0;
		while ( a != 0 ) {
			q[w] = a % 2;
			a /= 2;
			w ++;
		}
		w --;
		t = w;
		c = 1;
		while ( t > w / 2 ) {
			if ( q[t] != q[w-t] ) {
				c = 0;
				break;
			}
			t --;
		}
		if ( c ) {
			printf ( "%d\n", 100001 * x + 10010 * y + 1100 * z );
			s += 100001 * x + 10010 * y + 1100 * z;
		}
	}

	printf ( "\nThe number you are looking for is %d", s );
	printf ( "\n... and took %d / %d seconds to compute that", clock(), CLOCKS_PER_SEC );

	getchar();
}