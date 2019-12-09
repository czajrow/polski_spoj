#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
	int *v;
	int used;
	int size;
} t_Vector;

t_Vector make_vector();
void double_size(t_Vector *v);

int main(int argc, char **argv) {

	int n;
	scanf("%d", &n);

	for (int drawing_num = 0; drawing_num < n; drawing_num++) {
		t_Vector v = make_vector();

		int var, count = 0;
		while(scanf("%d",&var) != EOF) {
			if (v.size == v.used) {
				double_size(&v);
			}
			v.v[count++] = var;
			v.used++;
			if (count > 2 && count % 2 == 0 && v.v[0] == v.v[count-2] && v.v[1] == v.v[count-1]) {
				break;
			}
		}

		for (int i = 0; i < v.used; i++) {
			printf("%d ", v.v[i]);
		}
		printf("\n");
		free(v.v);
	}

	return 0;
}

t_Vector make_vector() {
	t_Vector v;
	v.size = 4;
	v.used = 0;
	v.v = malloc(v.size * sizeof(int));

	return v;
}


void double_size(t_Vector *v) {
	int size = v->size * 2;
	v->size = size;
	v->v = realloc(v->v, size);
}

