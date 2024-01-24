/*
            *****SEMAFORO*****
        
      Descripción:
      El siguiente código implementa el funcionamiento de un semaforo aplicado a un microcontrolador pic
      16f877a desarrollado en el lenguaje C.
      Versión: 1.0
      Fecha: 07-Febrero-2022
*/

#include <16f877a.h>                                                             // Libreria del microcontrolador a utilizar
#fuses HS,NOWDT,NOPUT,NOLVP,NOBROWNOUT,NODEBUG                                   // Fusibles que se implementarán
#use delay (clock=20M)                                                           // Define la velocidad del oscilador externo en 20mhz
#use standard_io(B)                                                              // Define ek puerto que se utilizará

#define  VERDE PIN_B0                                                            // Define el nombre VERDE al pin B0
#define  AMARILLO PIN_B1                                                         // Define el nomre AMARILLO al pin B1
#define  ROJO  PIN_B2                                                            // Define el nombre ROJO al pin B2

void main()                                                                      // Función principal
{
   
      set_tris_b(0x00);                                                          // Define como salida todos los pine del puerto B
      output_b(0x00);                                                            // Establece en estado bajo (APAGADO) como estado inicial todos los pines del puerto B
      
      while(true)                                                                // Ciclo while para que siempre se ejecute el código dentro del ciclo
      {
         output_high(VERDE);                                                     // Establece en estado alto (ENCENDIDO) el led VERDE
         delay_ms(3000);                                                         // Genera un retardo de 3000ms (3Seg)
         output_low(VERDE);                                                      // Establece en estado bajo (APAGADO) el led VERDE
         
            for(int i=0; i<5; i++)                                               // Crea un ciclo for de cinco iteraciones para parpadeo del led VERDE
            {
               output_high(VERDE);                                               // Establece en estado alto (ENCENDIDO) el led VERDE
               delay_ms(200);                                                    // Genera un retardo de 200ms 0.2Seg
               output_low(VERDE);                                                // Establece en estado bajo (APAGADO) el led VERDE
               delay_ms(200);                                                    // Genera un retardo de 200ms 0.2Seg
            }
            
          output_high(AMARILLO);                                                 // Establece en estado alto (ENCENDIDO) el led AMARILLO
          delay_ms(1000);                                                        // Genera un retardo de 1000ms (1Seg)
          output_low(AMARILLO);                                                  // Establece en estado bajo (APAGADO) el led AMARILLO
          output_high(ROJO);                                                     // Establece en estado alto (ENCENDIDO) el led ROJO
          delay_ms(3000);                                                        // Genera un retardo de 3000ms (3Seg)
          output_low(ROJO);                                                      // Establece en estado bajo (ENCENDIDO) el led ROJO
      
      }
}
