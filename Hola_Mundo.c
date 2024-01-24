/*
            ***** HOLA MUNDO *****
   
      Descripción:
      El siguiente código tiene como finalidad implementar el hola mundo de los microcontroladores utilizando
      el lenguaje C aplicado a un microcontrolador PIC.
      
      Fecha: 07-Febrero-2022
      Version: 1.0
    
*/

#include <16f877a.h>                                                             // Libreria del pic acorde al microcontrolador que se implementará
#fuses HS,NOWDT,NOPROTECT,NOLVP,NOPUT,BROWNOUT                                   // Fusibles a utilizar
#use delay(clock= 20M)                                                           // Frecuencia del oscilador externo de 20Mhz
#use standard_io(B)                                                              // Activa el puerto B para utilizar

#define LED PIN_B0                                                               // Asigna el nombre de LED al pin B0


void main()                                                                      //Función Principal
{
   
   set_tris_b(0x00);                                                             // Establece los pines del puerto b como salidas
   output_b(0x00);                                                               // Establece en apagado el estado inicial de los pines
  
   while(true)                                                                   // Ciclo while para que siempre trabaje el microcontrolador 
   {  
      output_high(LED);                                                          // Establece en estado alto el pin B0        
      delay_ms(1000);                                                            // Establece una duración de 1000 milisegundos (1 Seg)  
      
      output_low(LED);                                                           // Establece en estado bajo el pin B0        
      delay_ms(1000);                                                            // Establece una duración de 1000 milisegundos (1 Seg)
      
   }
}

