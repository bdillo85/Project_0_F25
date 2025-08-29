#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t charset_size = sizeof(charset) - 1;

    for (size_t i = 0; i < size; i++) {
        int key = rand() % charset_size;
        str[i] = charset[key];
    }
    str[size] = '\0';
}

char* rand_string_alloc(size_t size)
{
    char *s = malloc(size + 1);
    if (s) {
        rand_string(s, size);
    }
    return s;
}

int main()
{
    srand((unsigned)time(NULL));

    size_t size = 10;
    char *str = rand_string_alloc(size);

    printf("Today's random word: %s\n", str);
    free(str);

    return 0;
}