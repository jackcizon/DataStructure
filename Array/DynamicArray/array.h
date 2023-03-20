#define array_INIT_CAPACITY 4


typedef struct array {
    void **items;
    int capacity;
    int total;
} array;

array* init(void);
int total(array *);
static void resize(array *, int);
void add(array *, void *);
void set(array *, int, void *);
void *get(array *, int);
void delete(array *, int);
void _free(array *);
