// https://pl.spoj.com/problems/TMUL/

#include <stdio.h>
#include <string.h>


int multiply( char *a, int a_len, char *b, int b_len, char *result ); // return length of result
void reset_vector( char *vector, int n );

const int MAX_DIGITS = 4;

int main( int argc, char **argv ) {

	int n;
	scanf( "%d", &n );

	char a[MAX_DIGITS];
	char b[MAX_DIGITS];
	int a_len;
	int b_len;
	char result[2 * MAX_DIGITS];

	while( n-- ) {
		reset_vector( a, MAX_DIGITS );
		reset_vector( a, MAX_DIGITS );
		reset_vector( result, 2 * MAX_DIGITS );

		scanf( "%s%s", a, b );
		a_len = ( int ) strlen( a );
		b_len = ( int ) strlen( b );

		int r = multiply( a, a_len, b, b_len, result );

		if ( r == -1 ) {
			printf( "0\n" );
			continue;
		}

		char res[r + 1];
		int count = 0;
		for (int i = r; i >= 0; i-- ) {
			res[count++] = result[i];
		}

		printf( "%s\n", res );
	}

	return 0;
}

int multiply( char *a, int a_len, char *b, int b_len, char *result ) {

	int i_n1 = 0;
	int i_n2 = 0;

	for (int i = a_len - 1; i >= 0; i--) {
		int carry = 0;
		int n1 = a[i] - '0';

		i_n2 = 0;

		for (int j = b_len - 1; j >= 0; j--) {
			int n2 = b[j] - '0';

			int sum = n1 * n2 + ( result[i_n1 + i_n2] - '0' ) + carry;

			carry = sum / 10;

			result[i_n1 + i_n2] = sum % 10 + '0';

			i_n2++;
		}
		if (carry > 0) {
			result[i_n1 + i_n2] += carry;
		}
		i_n1++;
	}
	
	int i = 2 * MAX_DIGITS - 1;
	
	while (i >= 0 && result[i] == '0')
		i--;

	return i;
}

void reset_vector( char *vector, int n ) {
	while ( n-- )
		vector[n] = '0';
}

