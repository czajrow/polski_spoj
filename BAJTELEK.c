#include <stdio.h>
#include <stdlib.h>

const int INIT_SIZE = 4;
const int BLACK_INK = 4; // 10, but i count gray area inside black as well
const int GRAY_INK = 6;
const int MIN_COORDINATE = -100001;

typedef struct Vector {
	int *ve;
	int used;
	int size;
} t_Vector;

int compute_ink_in_polygon(t_Vector *v, int ink);
int compute_drawing();
void read_drawing(t_Vector *v);

void add_to_vector(t_Vector *v, int value);
void reuse_vector(t_Vector *v);
void free_vector(t_Vector *v);
t_Vector * make_vector();
void double_size(t_Vector *v);

int main(int argc, char **argv) {

	int n;
	scanf("%d", &n);
	t_Vector *vec = make_vector();

	for (int drawing_num = 0; drawing_num < n; drawing_num++) {

		int result = compute_drawing(vec);
		printf("%d\n", result);
	}

	free_vector(vec);
	return 0;
}

int compute_ink_in_polygon(t_Vector *v, int ink) {
	int prevx = v->ve[0] - MIN_COORDINATE;
	int prevy = v->ve[1] - MIN_COORDINATE;

	int sum_ink = 0;
	for (int i = 1; i < v->used / 2; i++) {
		int x = v->ve[2 * i] - MIN_COORDINATE;
		int y = v->ve[2 * i + 1] - MIN_COORDINATE;

		int dx = prevx - x;

		sum_ink += (( y + prevy ) * ink * dx ) / 2;

		prevx = x;
		prevy = y;
	}
	return sum_ink;
}

int compute_drawing(t_Vector *v) {
	reuse_vector(v);
	read_drawing(v);

	int sum_ink = compute_ink_in_polygon(v, BLACK_INK);

	reuse_vector(v);
	read_drawing(v);

	sum_ink += compute_ink_in_polygon(v, GRAY_INK);

	return sum_ink;
}

void read_drawing(t_Vector *v) {
	int var;

	while(scanf("%d",&var) != EOF) {

		add_to_vector(v, var);
		int used = v->used;

		if (used > 2 && used % 2 == 0 && v->ve[0] == v->ve[used-2] && v->ve[1] == v->ve[used-1]) {
			break;
		}
	}
}

/*
	FUNCTIONS REGARDING VECTORS
*/

void add_to_vector(t_Vector *v, int value) {
	if (v->size == v->used) {
		double_size(v);
	}
	v->ve[v->used++] = value;
}

void reuse_vector(t_Vector *v) {
	v->used = 0;
}

void free_vector(t_Vector *v) {
	free(v->ve);
	free(v);
}

t_Vector * make_vector() {
	t_Vector *v = malloc(sizeof(t_Vector));
	v->size = INIT_SIZE;
	v->used = 0;
	v->ve = malloc(v->size * sizeof(int));
	return v;
}

void double_size(t_Vector *v) {
	int size = v->size * 2;
	v->size = size;
	v->ve = realloc(v->ve, size);
}
