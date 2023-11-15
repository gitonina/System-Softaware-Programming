# System-Software-Programming
## This course is mainly developed on C. This course is about how we can programm in a effcient way, but also, how a computer works and by knowing that, learn other type of languages, like assembly. The following text is what we had to do through this course in every homework. 

## Tarea1

#### El formato BCD o *Binary Coded Decimal*  se usa para representar números enteros positivos en base 10.  Cada cifra decimal del número se codifica en binario en 4 bits.  Por ejemplo el número 60219 se codifica como 0b0110 0000 0010 0001 1001, en donde el 0110 codifica el 6, el 0000 el 0, el 0010 el 2, el 0001 el 1 y el 1001 el 9.  La ventaja es que al anotar la secuencia de bits en hexadecimal se lee exactamente el mismo número representado en BCD, es decir 0x60219.  Observe que las secuencias 0b1010 … 0b1111 o 0xa … 0xf no pueden ocurrir y que 0x60219 representa en BCD el número 60219 mientras que el mismo 0x60219  representa  en  binario  el  número  393753  (9  + 1\*16+2\*162+6\*164).

#### Programe la función *sumaBcd* que retorna la suma de 2 números en formato BCD, almacenados en enteros sin signo de 64 bits, es decir *unsigned long long*.  El número más grande representable puede tener hasta 16 cifras decimales.  Si el resultado de la suma tiene 17 cifras decimales se produce desborde y Ud. debe retornar 0xffffffffffffffff.  El encabezado de la función *sumaBcd* es:

#### typedef unsigned long long **Bcd**; Bcd ![](Aspose.Words.c265c1e0-dacd-40f2-8200-8d2fa8ffa043.001.png)**sumaBcd**(Bcd x, Bcd y);

#### Ejemplo de uso:

#### Bcd a= sumaBcd(0x60219, 0x1); *// a es 0x60220![](Aspose.Words.c265c1e0-dacd-40f2-8200-8d2fa8ffa043.002.png)*

#### Bcd b= sumaBcd(0x199305, 0x9781); *// b es 0x209086*

### Bcd c= sumaBcd(0x9999999999999999, 0x1); *// c es 0xfff...ffff*

#### Observe que no sirve sumar directamente los números en BCD con el operador + de C porque 0x60219 + 0x1 es 0x6021A, que es una secuencia de bits inválida en BCD.  Por lo tanto Ud. necesita separar las cifras decimales de a 4 bits y sumar exactamente como aprendió a hacerlo en enseñanza básica.

#### *Restricciones*:

#### - Ud. no puede usar los operadores de multiplicación, división o módulo (\* / %).  Use los operadores de bits eficientemente.
#### - No se permite convertir los números a binario, sumarlos con + y convertir el resultado a BCD.
#### - Se descontará medio punto por no usar el estilo de indentación de Kernighan como se explica en [esta sección](https://wiki.dcc.uchile.cl/cc3301/principios#agrupacion_de_instrucciones) de los apuntes.
#### - El estándar de C no especifica el resultado para desplazamientos mayores o iguales al tamaño del operando.  Sanitize rechaza el desplazamiento *x<<nbits* cuando *nbits* es mayor o superior a la cantidad de bits de *x*.

#### ***Instrucciones***
####  El directorio *T1* contiene los archivos (a) *test-suma.c* que prueba si su tarea funciona y compara su eficiencia con la solución del profesor, (b) *prof.ref-x86\_64 y prof.ref- aarch64* con los binarios ejecutables de la solución del profesor, (c) *suma.h* que incluye el encabezado de la función pedida, y (d) *Makefile* que le servirá para compilar y ejecutar su tarea.  Ud. debe programar la función *sumaBcd*  en el archivo *suma.c*.

#### Pruebe su tarea bajo Debian 11 de 64 bits nativo o virtualizado con VirtualBox, Vmware, QEmu o WSL 2.  **Ejecute el comando *make* sin parámetros**.  Le mostrará las opciones que tiene para compilar su tarea. 

#### Cuando pruebe su tarea con *make run* asegúrese que su computador esté configurado en modo alto rendimiento y que no estén corriendo otros procesos intensivos en uso de CPU al mismo tiempo.  De otro modo podría no lograr la eficiencia solicitada.



## Tarea2
#### ***Parte a.-*** Programe la función:

#### void **eliminar**(char \*str, char \*pat);

#### Esta función elimina del string *str* todas las apariciones del patrón *pat*. Ejemplos:

#### char s1[]= "**las** pa**las** van"; // *13 caracteres* eliminar(s1, "las"); // s1 es " pa van" (7 caracteres) char s2[]= "11**10**1**10**01";

#### eliminar(s2, "10"); // s2 es "11101"

#### *Restricciones*: Ud. no puede usar el operador de subindicación [ ], ni su equivalente *\*(p+i)*.  Use ++ *--* *p+i* o *p-i*.  Por razones de eficiencia, Ud. no puede usar *malloc*  o declarar un arreglo para pedir memoria adicional.  Use múltiples punteros para direccionar distintas partes del string.

#### ***Parte b.-*** Programe la función:

#### char \***eliminados**(char \*str, char \*pat);![ref1]

#### Esta función entrega un nuevo string en donde se han eliminado del string *str* todas las apariciones del patrón *pat*.  Ejemplos:

#### char \*s1= eliminados("**las** pa**las** van", "las");           // s1 es " pa van" (7 caracteres)

#### char \*s2= eliminados("11**10**1**10**01", "10");

#### `          `// s2 es "11101"

#### *Restricciones:* Ud. no puede usar el operador de subindicación [ ], ni su equivalente *\*(p+i)*. Use ++ o *p+i*.  Para recorrer el string use aritmética de punteros.  Use *malloc* para pedir memoria para el string resultante. Debe pedir exactamente la cantidad de bytes que necesita el resultado, no más.  Para el primer ejemplo debe pedir 8 bytes, para el segundo 6 bytes.  Si pide más memoria que la que necesita, el test de uso de memoria podría agotar la memoria de su computador haciendo que se ponga muy lento antes de que el programa falle.

#### ***Instrucciones***

#### El directorio *T2* contiene los archivos (a) *test-elim.c* que prueba si su tarea funciona y compara su eficiencia con la solución del profesor, (b) *prof.ref-x86\_64 y prof.ref- aarch64* con los binarios ejecutables de la solución del profesor, (c) *elim.h*  que incluye los encabezados de las funcion pedidas, y (d) *Makefile* que le servirá para compilar y ejecutar su tarea.  **Ejecute en un** **terminal el comando *make***  para recibir instrucciones adicionales. 

Cuando pruebe su tarea con *make run* asegúrese que su computador esté configurado en modo alto rendimiento y que no estén corriendo otros procesos intensivos en uso de CPU al mismo tiempo.  De otro modo podría no lograr la eficiencia solicitada.

## Tarea3
En un *recorrido en orden* de un árbol binario, se visita recursivamente primero el subárbol izquierdo, luego se visita la raíz y finalmente se visita recursivamente el subárbol derecho.  Considere que se está visitando un nodo T al recorrer un árbol binario en orden.  Se define como *previo* a T el nodo que se visitó anteriormente, y como *próximo* el nodo que se visitará a continuación.  Estudie el lado derecho de la figura de ejemplo.  Programe en el archivo *prev.c* la función *asignarPrev* que asigna los campos *prev* y *prox* agregados a la estructura de los nodos de un árbol *t*.  El encabezado de la ![](foto1.png)

función se muestra a la derecha.  El typedef struct nodo { parámetro *\*pprev*  es de entrada y  int x;

salida.  El nodo previo del primer  struct nodo \*izq, \*der;  struct nodo \***prev**, \***prox**; nodo  visitado  (el  nodo  1  en  el } **Nodo**;

ejemplo) debe ser el nodo apuntado void **asignarPrev**(Nodo t, inicialmente por *\*pprev* (nodo 0) y             Nodo \*\*pprev);

el nodo próximo del último nodo en

ser visitado (nodo 5) debe ser NULL.  En *\*pprev*  debe quedar finalmente la dirección del último nodo visitado (nodo 5).  En el siguiente ejemplo de uso las variables *t* y *prev* son de tipo Nodo \*.

*prev t asignarPrev( t prev![](foto2.png)![](foto3.png)![](foto4.png)*

3   *t, &prev);* 3![](foto5.png)

0 0

1 5 1 5

2 4 *izq prev* 2 4 *der prox*

***Restricción***: Su solución debe tomar tiempo linealmente proporcional al número de nodos en el árbol *t*.

*Ayuda*: Cuando visite el nodo T, su nodo previo es *\*pprev*.  Asigne NULL a su nodo próximo por ahora.  Si el nodo previo a T no es NULL, T es el nodo próximo del nodo previo a T.  Antes de continuar el recorrido, asigne T a *\*pprev*.

***Instrucciones***
El directorio *T3* contiene los archivos (a) *test-prev.c* que prueba si su tarea funciona y compara su eficiencia con la solución del profesor, (b) *prof.ref-x86\_64 y prof.ref-aarch64* con los binarios ejecutables de la solución del profesor,

(c) *prev.h*  que incluye los encabezados de las funcion pedidas, (d) *Makefile* que le servirá para compilar y ejecutar su tarea, y (e) *prev.cbf* para que pueda probar su tarea con *codeblocks*.  **Ejecute en un terminal el comando *make*** para recibir instrucciones adicionales.  

Cuando pruebe su tarea con *make run* asegúrese que su computador esté configurado en modo alto rendimiento y que no estén corriendo otros procesos intensivos en uso de CPU al mismo tiempo.  De otro modo podría no lograr la eficiencia solicitada.

## Tarea 4
El archivo de texto *dicc.txt*  que viene a continuación almacena un diccionario representado como una [tabla de hashing cerrado](https://es.wikipedia.org/wiki/Tabla_hash#Direccionamiento_abierto_o_hashing_cerrado).

*celular:aparato portatil de un sistema de telefonia celular casa:edificacion construida para ser habitada![](foto6.png)*

*posada:establecimiento economico de hospedaje para viajeros alimento:sustancia ingerida por un ser vivo*

Todas las líneas son de 80 caracteres más el fin de línea (caracter '\n'). Se usa el caracter ':' para separar la llave de su valor asociado.  Una línea que contiene solo espacios en blanco no contiene ninguna definición.

Escriba en el archivo *definir.c* un programa que agregue una llave al diccionario.  El siguiente es un ejemplo de uso:

$ make definir.bin

$ ./definir.bin dicc.txt bolsillo "bolsa pequena"

En donde el primer parámetro es el nombre del archivo que contiene el diccionario, el segundo es la llave definida y el tercero es la definición. En el archivo *definir.c*, Ud. deberá programar la función:

`            `*int main(int argc, char \*argv[ ]);*

***Requerimientos***

- Abra el archivo del diccionario en modo "r+" para poder leerlo y escribirlo.  Es decir:  *fopen(..., "r+")*.
- Calcule el tamaño y el número de líneas en el archivo usando [*fseek y ftell*](https://www.u-cursos.cl/ingenieria/2022/2/CC3301/1/novedades/r/20220927155854C53EDE38F0EE7B__archivos2.pdf).
- **Debe ser eficiente.**  Use *hash\_string(llave)* módulo número de líneas del archivo para calcular el número de línea en donde debe ir la llave definida.  Luego use [fseek y fread](https://www.u-cursos.cl/ingenieria/2022/2/CC3301/1/novedades/r/20220927155854C53EDE38F0EE7B__archivos2.pdf) para leer esa línea.  Si esa línea está desocupada reescriba esa misma línea para agregar la definición en esa misma línea.  Si no, lea las líneas que vienen a continuación hasta encontrar una línea en blanco y reescríbala para agregar la defición en esa línea.  El archivo es circular: si llega al final, continúe desde el comienzo.
- Está prohibido leer el archivo completo, salvo si el archivo está lleno. Debe diagnosticar las situaciones de error en la salida estándar de

errores.  En caso de error termine el programa de inmediato.  Estos son los errores que debe diagnosticar:

- No se puede abrir el archivo.  Debe diagnosticar este error con *perror*.
- La llave ya estaba definida en el diccionario.

El test de prueba incluido verifica que Ud. diagnostique estos errores con exactamente el mismo mensaje que entrega la solución de referencia incluida en formato binario. Puede probar la solución de referencia con un diccionario y llave específica.  Por ejemplo:

$ ./prof.ref-$(arch) dicc.txt bolsillo "bolsa pequena" Vea el diccionario resultante con el comando: less dicc.txt

Cada ejecución de *definir*  modifica el diccionario.  Para restaurarlo ejecute el comando: bash mk-dicc.sh

***Instrucciones***

Ejecute el comando *make* sin parámetros en el directorio *T4* para recibir instrucciones acerca del archivo en donde debe programar su solución (*T4/definir.c*), cómo compilar y probar su solución, los requisitos que debe cumplir para aprobar la tarea (*make run-san*, *make run-g* y *make run*) y cómo entregar su tarea por U-cursos (*make zip*).

*
