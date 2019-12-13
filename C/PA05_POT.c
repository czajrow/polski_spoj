// https://pl.spoj.com/problems/PA05_POT/

#include <stdio.h>

int power( int a, int b );

int map[] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};

int main( int argc, char **argv ) {

	int n;
	scanf( "%d", &n );
	
	while (n--) {
		int a, b;
		scanf( "%d%d", &a, &b );

		a = a % 10;

		int result;
		if ( b == 0) {
			result = 1;
		} else {
			result = power( a, (b - 1) % map[a] + 1 ) % 10;
		}

		printf( "%d\n", result );
	}

	return 0;
}

int power( int a, int b ) {
	int p = 1;
	while ( b-- ) {
		p *= a;
	}
	return p;
}

