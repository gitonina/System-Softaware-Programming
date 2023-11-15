#include <stdio.h>
#include <string.h>

void eliminar(char *str, char *pat) {
    int lenpat = strlen(pat);
    int contador1 = 0;
    int contador2 = 1;
    char *originalStr = str; // Guarda el inicio de str para mantener una referencia
    
    while (*str != '\0') {
        if (*str == *pat) {
            if (contador2 < lenpat) {
                pat++;
                contador2++;
                contador1++;
            }

            if (contador2 == lenpat) {
                pat -= contador1;
                contador1 = 0;
                contador2 = 1;

                // Eliminar el patrón de str
                while (*pat != '\0') {
                    *originalStr = *pat;
                    originalStr++;
                    pat++;
                }
                *originalStr = '\0'; // Agregar el carácter nulo al final del nuevo str
            }
        }
         else {
            pat -= contador1;
            contador1 = 0;
            contador2 = 1;
        }

        str++;
    }
}


int main(){
    char s2[] = "111011001";
    eliminar(s2, "10");
    printf("s2: %s\n", s2);
    return 0;
}