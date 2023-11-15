#include <stdio.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char str[] = "ab";

    char *ptr1 = &str[0];
    char *ptr2 = &str[1];

    swap(ptr1, ptr2);

    printf("Resultado: %s\n", str);

    return 0;
}
