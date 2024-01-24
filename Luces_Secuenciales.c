/*
            ***** LUCES SECUENCIALES *****
            
      El siguiente código implementa el uso de las salidas del microcontrolador para hacer luces secuenciales
      simulando las luces de manejo de un automovil, a partir del estado de las diferentes entradas asignadas
      las cuales corresponden a push buttons. El código esta desarrollado en C y orientado al microcontrolador
      PIC16F877A.
      Fecha: 15-Marzo-2022
      Versión: 1.0
      
*/

#include <16f877a.h>                                                             // Libreria del microcontrolador acorde al que se utilizará
#fuses HS,NOWDT,NOPUT,NOLVP,NOBROWNOUT,NODEBUG                                   // Fusibles a utilizar
#use delay (clock=20M)                                                           // Establece la velocidad del oscilador externo
#use standard_io(B)                                                              // Establece que el puerto B será utilizado
#use standard_io(A)                                                              // Establece que el puerto A será utilizado

#define derecha PIN_A0                                                           // Define el pin A0 como derecha
#define izquierda PIN_A1                                                         // Define el pin A1 como izquierda
#define intermi PIN_A2                                                           // Define el pin A2 como intermintente

void main()                                                                      // Función principal
{  
   set_tris_b(0x00);                                                             // Establece los pines del puerto B como salidas
   set_tris_a(0xFF);                                                             // Establece los pines del puerto A como entradas
   output_b(0x00);                                                               // Establece el estado inicial de los pines en estado bajo
   
  while(true)                                                                    // Ciclo while para que siempre se ejecute el código
   {
   
      if(input(derecha) == 1)                                                    // Condición si el estado de la entrada derecha es alto
      {  
         output_b(0b00000001);                                                   // La secuencia de encendido de los led será a la derecha
         delay_ms(100);                                                          // Genera un retardo de 100ms (0.1)Seg entre los encendidos
         output_b(0b00000011);
         delay_ms(100);
         output_b(0b00000111);
         delay_ms(100);
         output_b(0b00001111);
         delay_ms(100);
         output_b(0b00000000);
         delay_ms(100);
      }
         if(input(izquierda) == 1)                                               // Condición si el estado de la entrada izquierda es alto
         {                    
            output_b(0b00010000);                                                // La secuencia de encendido de los led será a la izquierda
            delay_ms(100);
            output_b(0b00110000);
            delay_ms(100);
            output_b(0b01110000);
            delay_ms(100);
            output_b(0b11110000);
            delay_ms(100);
            output_b(0b00000000);
            delay_ms(100);
         }
         
          if(input(intermi) == 1)                                                // Condición si el estado de la entrada intermitente es alto
            {  
               output_b(0b00010001);                                             // La secuencia de encendido de los led será en ambos sentidos de adentro hacia afuera 
               delay_ms(100);
               output_b(0b00110011);
               delay_ms(100);
               output_b(0b01110111);
               delay_ms(100);
               output_b(0b11111111);
               delay_ms(100);
               output_b(0b00000000);
               delay_ms(100);
            }
            
            
   }
}
