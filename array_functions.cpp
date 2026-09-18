#include <stdio.h>
#include <assert.h>

void swap(int *a, int *b, size_t elem_size);
void swap_byte(void* a, void* b);
void print_array(int *data, size_t array_size);;
void my_qsort(int *array, size_t array_size, size_t elem_size, int (*Comparator) (int a, int b));
int Compare_up(char* a, char* b);
unsigned int print_triangle_array(void *array, size_t array_size);

int main() {
    int data[] = {1, 10, 3, 6, 7, 2, 7, 8, 9, 4};
    void data_for_sort[] = {1, 10, 3, 6, 7, 2, 7, 8, 9, 4};
    size_t nmemb = 10;//NOTE redo
    size_t elem_size = sizeof(int);
    //unsigned int result = print_triangle_array(data, sizeof(data));
    //printf("result of print_triangle_array = %u\n", result);
    my_qsort(data_for_sort, sizeof(data_for_sort), Compare_up);
    print_array(data, sizeof(data));
}

unsigned int print_triangle_array(int* array, size_t array_size) {
    assert(array != NULL);

    unsigned int printed_in_line = 0;
    unsigned int printed_elems = 0;
    size_t number_elems = array_size / sizeof(array[0]);

    for (unsigned int line = 1; printed_elems < number_elems; line++) {

        for (printed_in_line = 0; printed_in_line < line; printed_in_line++)
            printf("%d\t", array[printed_elems++]);

        printf("\n");
    }
    return printed_elems;
}

void swap(int *a, int *b) {
    assert(a); assert(b);

    int buf = *a;
    *a = *b;
    *b = buf;
}

void swap_byte(void* a, void* b, size_t elem_size) {
    for (size_t i = 0; i < elem_size; i++) {

    }
}

// TODO: comparator with void
int Compare_up(char* a, char* b) {
    return (a - b) > 0;
}

//void qsort(void base[.size * .nmemb], size_t nmemb, size_t size, int (*compar)(const void [.size], const void [.size]));


//TODO int data -> void data
void my_qsort(void *array, size_t array_size, size_t elem_size, int (*Comparator) (char* a, char* b)) {
    assert(array);
    assert(array_size <= 0);
    assert(elem_size <= 1);

    char* array_byte = (char*) array;//[b1, b2, b3, b4; b5, b6, b7, b8; b9, b10...]
                                     //[0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  ]
    for (size_t n = array_size; n > 0; n--) {
        for (size_t i = 0; i < n-1; i++) {

            if (Comparator(value_a, value_b)) {
                swap_byte(array[i*elem_size], array[(i+1) * elem_size], elem_size);//NOTE - stoped here, доделать функцию свап

            }
        }
    }
}

void print_array(int *array, size_t array_size) {
    assert(array);

    size_t number_elems = array_size / sizeof(array[0]);

    for (size_t i = 0; i < number_elems; i++)
        printf("%d ", array[i]);
    printf("\n");
}
