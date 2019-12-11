#include <stdio.h>

int nww( int a, int b );

int main( int argc, char **argv ) {

	int n;
	scanf( "%d", &n );

	while ( n-- ) {
		int a, b;
		scanf( "%d%d", &a, &b );

		int result = nww( a, b );

		printf( "%d\n", result );
	}

	return 0;
}


int nww( int a, int b ) {

	int x = a;
	int y = b;

	while (x != y )
		if ( x < y )
			x += a;
		else
			y += b;

	return x;
}

