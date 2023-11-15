#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void eliminar(char *str,char *pat){
     char *ptr1=str; //fijo
     char *ptr2=str; //se va moviendo
     char *ptr3=pat; //al patron
     char *ptr4=ptr2; //vaya reemplazando las palabras
     int contador=0;   
     while(*ptr2 != '\0'){
       if(*ptr2 == *ptr3){
        while(*ptr2 == *ptr3 && *ptr3 !='\0' ){
            contador++;  
            ptr2++;
            ptr3++;
        }   
      if(*ptr3 != *ptr2  && *ptr3 !='\0'){

         while(contador!=0){         
            *str= *ptr4;
            contador--;
            ptr4++;
            str++;
            ptr3=pat;
            
         }
      }
           if(*ptr3== '\0'){

            contador=0;

            ptr3=pat;
            ptr4=ptr2;         
        }      
       }
       else {
           *str=*ptr4;
              str++;
           contador=0;
           ptr2++;
           ptr4++;

       }     
     }   
     *str= '\0';
     str=ptr1;

}



 char *eliminados(char *str,char *pat){
    char* a=malloc(strlen(str)+1); //hago una copia para str
    strcpy(a,str);
    eliminar(a,pat); //elimio el patro de a
    char* r=malloc(strlen(a)+1); //palabra ya eliminada
    strcpy(r,a); //la copio en a
    free(a);
    return r;

}
