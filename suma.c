#include <stdio.h>

#include "suma.h"

Bcd sumaBcd(Bcd x, Bcd y) {
   Bcd carry=0;
   Bcd numerofinal=0;
   for(int i=0;i<64;i+=4){

    Bcd mask1=~((Bcd)-1<<4);
    Bcd numero1= x&mask1;
    Bcd numero2=y&mask1;
    
    Bcd suma= numero1+numero2+carry;
   

    if(suma>9){
     
      
      numerofinal=(numerofinal|((suma-10)<<i)); 
      carry=1;
  
    }

    else{
   
      numerofinal=(numerofinal|(suma<<i));
      carry=0;
    }

    

      x=x>>4;
      y=y>>4;
     
   
   }


   if(carry==1){
      return  0xffffffffffffffff ;
   }
   

  return numerofinal;

}
