#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/param.h>

//char my_puts(char* str) - выводит строку str посимвольно
//size_t my_strlen(const char* str) - возвращает количество символов строки
//char* my_strcpy(char* to, char* from) - копирует в переданную строку
//char* my_strncat(char* str_for_write, char* str_where_write, const size_t size_str_where_write) - дописывает строку в конец
//int my_strcmp(char* first_str, char* second_str) - сравнивает строки
//const char* my_strstr(const char* main_str, const char* search_str) - ищет первое вхождение подстроки в строку

char my_puts(char* str);
size_t my_strlen(const char* str);
char* my_strcpy(char* to, char* from);
char* my_strncat(char* str_for_write, char* str_where_write, const size_t size_str_where_write);
int my_strcmp(char* first_str, char* second_str);
const char* my_strstr(const char* main_str, const char* search_str);

int main() {
    const size_t size_str_where_write = 50;
    char ded_space[size_str_where_write] = {};//строка для копирования в неё

    char ded[size_str_where_write] = "Copy meow me";
    char false_ded[size_str_where_write] = "meow";
    char politeness[] = ", please";

    printf("Size of string = %zu\t right size = 12\n", my_strlen(ded));
    printf("print ded:");
    my_puts(ded);
    printf("Copy string: <%s>\n", my_strcpy(ded_space, ded));
    printf("Concat: <%s>\n", my_strncat(politeness, ded, size_str_where_write));
    printf("ded < false_ded?\t %d\n", my_strcmp(ded, false_ded));
    printf("Find her: %s:\t %s\n", ded, my_strstr(ded, false_ded));
}

size_t my_strlen(const char* str) {
    assert(str != NULL);

    size_t size = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        size++;                                               //printf("size=%zu  %c\n", size, str[i]);
    }

    return size;
}

char my_puts(char* str) {
    assert(str != NULL);

    char buf = '0';
    size_t size = my_strlen(str);

    for (int i = 0; ((size_t)i < size) && str[i] != '\0'; i++) {
        buf = str[i];
        putchar(buf);
    }
    putchar('\n');
    return buf;
}

char* my_strcpy(char* to, char* from) {
    assert(to != NULL);
    assert(from != NULL);

    for (int i = 0; i < ((int)my_strlen(to) + 1); i++) {
        to[i] = from[i];
    }
    return to;
}

char* my_strncat(char* str_for_write, char* str_where_write, const size_t max_size) {
    assert(str_for_write != 0);
    assert(str_where_write != 0);

    size_t len_where = my_strlen(str_where_write);// длина массива в символах

    for (size_t i = len_where; (i < max_size) && (str_for_write[i-len_where] != '\0'); i++) {
        str_where_write[i] = str_for_write[i-len_where];
    }
    return str_where_write;
}

int my_strcmp(char* first_str, char* second_str) {
    assert(first_str != NULL);
    assert(second_str != NULL);

    int iterations = (int) MIN(my_strlen(first_str), my_strlen(second_str));

    for (int i = 0; i < iterations; i++) {
        if (first_str[i] > second_str[i])
            return 1;
        else if (second_str[i] > first_str[i])
            return -1;
        else if (i == iterations - 1)
            return 0;
    }

    return 8;
}

const char* my_strstr(const char* main_str, const char* search_str) {
    assert(main_str != NULL);
    assert(search_str != NULL);

    const char* error_word = "LOX";
    size_t i = 0;

    for (i = 0; i < my_strlen(main_str); i++) {

        bool flag_found = 1;
        //printf("i = %zu\n", i);
        //printf("flag = %d\n", flag_found);

        for (size_t b = i; b < my_strlen(search_str)+i; b++) {

            //printf("flag before compare %d\n", flag_found);

            if (strcmp(&main_str[b+i], &search_str[b]) == -1)
                flag_found = 0;
        }
        if (flag_found)
            return &main_str[i];
    }
    return error_word;
}
