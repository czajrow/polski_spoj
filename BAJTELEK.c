#include <stdio.h>
#include <stdlib.h>

const int INIT_SIZE;

typedef struct Vector {
	int *v;
	int used;
	int size;
} t_Vector;

int compute_drawing();
void read_drawing(t_Vector *v);

void reuse_vector(t_Vector *v);
void free_vector(t_Vector *v);
t_Vector * make_vector();
void double_size(t_Vector *v);

int main(int argc, char **argv) {

	int n;
	scanf("%d", &n);
	t_Vector *v = make_vector();

	for (int drawing_num = 0; drawing_num < n; drawing_num++) {

		int result = compute_drawing(v);
		printf("%d\n", result);

	}

	free_vector(v);
	return 0;
}

int compute_drawing(t_Vector *v) {
	reuse_vector(v);
	read_drawing(v);

	// for (int i = 0; i < v->used; i++) {
	// 	printf("%d ", v->v[i]);
	// }
	// printf("\n");

	return 0;
}

void read_drawing(t_Vector *v) {
	int var, count = 0;

	while(scanf("%d",&var) != EOF) {
		if (v->size == v->used) {
			double_size(v);
		}
		v->v[count++] = var;
		v->used++;
		if (count > 2 && count % 2 == 0 && v->v[0] == v->v[count-2] && v->v[1] == v->v[count-1]) {
			break;
		}
	}
}

/*
	MATH
*/


/*
	FUNCTIONS REGARDING VECTORS
*/

void reuse_vector(t_Vector *v) {
	v->used = 0;
}

void free_vector(t_Vector *v) {
	free(v->v);
	free(v);
}

t_Vector * make_vector() {
	t_Vector *v = malloc(sizeof(t_Vector));
	v->size = INIT_SIZE;
	v->used = 0;
	v->v = malloc(v->size * sizeof(int));

	return v;
}

void double_size(t_Vector *v) {
	int size = v->size * 2;
	v->size = size;
	v->v = realloc(v->v, size);
}
