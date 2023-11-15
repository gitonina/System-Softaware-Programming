#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

#define size (81)

int main(int argc, char *argv[]) {
   if(argc!=4){ // nombre del archivo+llave+ valor asociado, no puede tener un input distinto de esto
    fprintf(stderr, "Uso: ./definir <diccionario> <llave> <definicion>\n");
    exit(1);
   }
   

   char buff[size]; //un arreglo de tamaño size, que guarda la linea en si
   char *arch=argv[1], *llave = argv[2], *valor = argv[3];  //llave apunta a la llave, valor apunta al valor xd, o la definicion de la llave.
   //este vendria a ser el largo de lo que esta a la derecha de los dos puntos
   int lenllave=strlen(llave);
   FILE *Dicc = fopen(arch, "r+"); //abrir el archivo que contiene el diccionario, este apunta a la primera letra del archivo
    

   
 
   if(!Dicc){ //si hay un error al abrir el archivo, enetonces deberiamos tirar el error con perror, y tirar exit1, que sirver justamente para tirar errores.
     perror(arch);
     exit(1);
   }
    
    int lenLine = 0;
   if(fgets(buff, size, Dicc) != NULL) lenLine = strlen(buff); //tamaño del buffer, que como no es NULL, cumple con ser del tamaño de la linea
    //codigo de rial
      
    //ya sea si el archivo esta vacio o ya tiene algo escrito, queremos escribir donde se pueda escribir, es decir 
    //donde no este nada escrito, y la vieja confiable es poner el puntero al final del archivo
   fseek(Dicc, 0, SEEK_END);
   int lenArch = ftell(Dicc); //tamaño del archivo
   int lines = lenArch/lenLine; //numero de lineas del archivo
   int n = hash_string(llave)%lines, j=lines;//donde tengo que insertar la llave

 
  
  //n=34, lines=46, lenline=80
  
  while(j--){
    
    fseek(Dicc, n*(81), SEEK_SET); //donde se va a poner la llave del diccionario
    fread(buff,lenllave,1,Dicc);
    //esto retorna el valor de si lo que sale en la linea, que ente caso seria la llave,
    fseek(Dicc,n*81,SEEK_SET);
   
                                      //es igual a lo que en el puntero llave que definimos arriba. 
     
    // la llave y lo que sale en el txt son iguales.
    if(strcmp(llave,buff)==0){
        fprintf(stderr, "La llave alimento ya se encuentra en el diccionario\n");
        exit(1);
     //Como ya esta en el archivo, entonces no hay que hacer nada y por lo tanto se termina el programa
    }                  
     //obtenemos la primera letra de donde esta ubicado el cursor.
      
  
     
    if(buff[0]==' ') { //caso donde es una linea vacia entera. Aqui ponemos que 
     
      fprintf(Dicc,"%s:%s",llave,valor);
       return 0;
    } 

     n++;
     n%=lines;
   
   //if(++n>lines)n=0;
   

  }
  
    fprintf(stderr, "%s: el diccionario esta lleno\n", arch);
     exit(1);
  //caso donde no puedo insertar la llave 

  fclose(Dicc);

 
}