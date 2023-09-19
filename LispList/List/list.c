#include <stdio.h>
#include <stdlib.h>

typedef struct cons {
    void *car;
    struct cons *cdr;
} cons;

cons *cons_create(void *car, cons *cdr) {
    cons *cell = malloc(sizeof(cons));
    cell->car = car;
    cell->cdr = cdr;
    return cell;
}

void cons_free(cons *cell) {
    if (cell != NULL) {
        cons_free(cell->cdr);
        free(cell);
    }
}

int list_depth(cons *cell) {
    if (cell == NULL) {
        return 0;
    } else if (cell->cdr == NULL) {
        return 1;
    } else {
        int max_depth = 0;
        cons *current_cell = cell->cdr;
        while (current_cell != NULL) {
            int depth = list_depth((cons *) current_cell->car);
            if (depth > max_depth) {
                max_depth = depth;
            }
            current_cell = current_cell->cdr;
        }
        return max_depth + 1;
    }
}

int list_length(cons *cell) {
    int length = 0;
    cons *current_cell = cell;
    while (current_cell != NULL) {
        length++;
        current_cell = current_cell->cdr;
    }
    return length;
}

cons *list_search(cons *cell, void *value) {
    if (cell == NULL) {
        return NULL;
    } else if (cell->car == value) {
        return cell;
    } else if (cell->cdr == NULL) {
        return NULL;
    } else {
        cons *current_cell = cell->cdr;
        while (current_cell != NULL) {
            cons *result = list_search((cons *) current_cell->car, value);
            if (result != NULL) {
                return result;
            }
            current_cell = current_cell->cdr;
        }
        return NULL;
    }
}

int main() {
    cons *inner_list = cons_create("c", cons_create("d", NULL));
    cons *outer_list = cons_create("b", cons_create(inner_list, NULL));
    outer_list = cons_create("a", cons_create(outer_list, NULL));

    // Testing list_depth
    int depth = list_depth(outer_list);
    printf("Depth: %d\n", depth); // prints "Depth: 3"

    // Testing list_length
    int length = list_length(outer_list);
    printf("Length: %d\n", length); // prints "Length: 3"

    // Testing list_search
    cons *result = list_search(outer_list, "c");
    if (result != NULL) {
        printf("Found: %s\n", (char *) result->car); // prints "Found: c"
    } else {
        printf("Not found\n");
    }

    // Freeing memory
    cons_free(outer_list);
    return 0;
}

