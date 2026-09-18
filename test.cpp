#include <stdio.h>
#include <assert.h>

unsigned int print_triangle_array(int *array, size_t array_size);
void bubble_sort_int_array(int *array, size_t array_size);
void swap(int *a, int *b);
void print_array(int *data, size_t array_size);

const int canary = 4570;

int main() {
    int data[] = {0, 1, 10, 3, 6, 7, 2, 7, 8, 9, 4, 0};
    data[0] = canary;
    data[sizeof(data)/sizeof(data[0])-1] = canary;
    data = &data[1];
    bubble_sort_int_array(data, sizeof(data));
    print_array(data, sizeof(data));
}



void swap(int *a, int *b) {
    int buf = *a;
    *a = *b;
    *b = buf;
}

void bubble_sort_int_array(int *array, size_t array_size) {
    assert(array);

    size_t number_elems = array_size / sizeof(array[0]) - 2; //NOTE - canary

    for (size_t n = number_elems; n > 0; n--) {
        for (size_t i = 1; i < n+1; i++) {

            //printf("i=%zu\n", i);
            assert(array[i] != canary);

            if (array[i] > array[i+1])
                swap(&array[i], &array[i+1]);
        }
    }
}

void print_array(int *array, size_t array_size) {
    assert(array);

    size_t number_elems = array_size / sizeof(array[0]);

    for (size_t i = 1; i < number_elems-1; i++)
        printf("%d ", array[i]);
    printf("\n");
}
