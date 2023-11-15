#include <string.h>
#include <stdio.h>
int countWords(char *s) {
    int palabras = 0;
    while (*s) {
        if (*s != ' ') {
            palabras++;
            while (*s && *s != ' ') {
                s++;
            }
        } else {
            s++;
        }
    }
    return palabras;
}


int strCmp(char *s1, char *s2) {
    char c1;
    char c2;

    for (;;) {
      c1= *s1;
      c2= *s2;

      if (c1==0)
        break;

      if (c1!=c2)
        break;

      s1++;
      s2++;
    }

    return c1 - c2;
}

void sort(char **a, int n) {
  char **ult= &a[n-1];
  char **p= a;
  while (p<ult) {
    int lena=countWords(p[0]);
    int lenb=countWords(p[1]);

   int t1= lena -lenb;

    if (t1 <= 0)
      p++;
    else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= a;
    }
  }
}

