#include <stdio.h>

// https://pl.spoj.com/problems/PRIME_T/

int is_prime(int k);

int main(int argc, char **argv) {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		if (is_prime(k)) {
			printf("TAK\n");
		} else {
			printf("NIE\n");
		}
	}

	return 0;
}


int is_prime(int k) {

	if (k == 1 || k == 4) {
		return 0;
	}

	int d = 2;
	while (d * d <= k) {
		if (k % d++ == 0) {
			return 0;
		}
	}
	return 1;
}

