#include <stdio.h>
#include <stdlib.h>

const int INITIAL_VECTOR_SIZE = 4;
const int MIN_COORDINATE = -100001;
const int BLACK_INK = 4;
const int GRAY_INK = 6;

typedef struct p {
    int x;
    int y;
} pair_t;

typedef struct {
    int size;  // capacity
    int n;     // actual size
    pair_t *d; // data
} cont_t;

// logics..
int compute_drawing();
void read_line(cont_t *data);
int count_ink(cont_t *data, int ink);

// structs...
cont_t *init_cont( int );
int cont_resize( cont_t * );

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int result = compute_drawing();
        printf("%d\n", result);
    }

    return 0;
}

int compute_drawing() {
    cont_t *black = init_cont( INITIAL_VECTOR_SIZE );
    cont_t *gray = init_cont( INITIAL_VECTOR_SIZE );

    read_line(black);
    read_line(gray);

    // count_ink
    int sum_ink;
    sum_ink = count_ink(black, BLACK_INK);
    sum_ink += count_ink(gray, GRAY_INK);

    free(black->d);
    free(black);
    free(gray->d);
    free(gray);
    return sum_ink;
}

void read_line(cont_t *data) {
    int x, y;

    while(scanf( "%d%d", &x, &y ) != EOF) {
        if( data->size == data->n && !cont_resize( data ) ) {
            fprintf( stderr, "End of memory... Can't resize vector.\n" );
            exit(EXIT_FAILURE);
        }
        data->d[data->n].x = x - MIN_COORDINATE;
        data->d[data->n].y = y - MIN_COORDINATE;
        data->n++;
        if ( data->n > 1 && data->d[0].x == data->d[data->n - 1].x && data->d[0].y == data->d[data->n - 1].y) { break; }
    }
}

int count_ink(cont_t *data, int ink) {
    int prevx = data->d[0].x;
    int prevy = data->d[0].y;
    int sum_ink = 0;

    for (int i = 1; i < data->n; i++) {
        int x = data->d[i].x;
        int y = data->d[i].y;

        int dx = prevx - x;

        sum_ink += (( y + prevy ) * ink * dx ) / 2;

        prevx = x;
        prevy = y;
    }
    return sum_ink;
}

// vectors...

cont_t *init_cont(int initial_size) {
    cont_t *c = malloc(sizeof *c);
    if (c == NULL) {
        return NULL;
    }
    (*c).d = malloc(initial_size * sizeof *(c->d));
    if (c->d == NULL) {
        free(c);
        return NULL;
    }
    c->size = initial_size;
    c->n = 0;
    return c;
}

int cont_resize(cont_t *c) {
    pair_t *nd = realloc(c->d, 2 * c->size * sizeof *nd);
    if (nd == NULL) {
        return 0;
    }
    else {
        c->d = nd;
        c->size *= 2;
        return 1;
    }
}
