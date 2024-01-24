/*
            *****CONTADOR DISPLAY 7 SEGMENTOS*****
      
      El siguiente c√≥digo implementa un contador del 0 al 9 representado en un
      display de 7 segmentos de c√°todo com√∫n, utilizando el microcontrolador pic
      16f877a y el c√≥digo desarrollado en C.
      Fecha: 13-Marzo-2022
      Versi√≥n: 1.0
*/

#include <16F877A.h>                                                             // Libreria del microcontrolador acorde al que se utilizar·
#fuses HS,NOWDT,NOPUT,NOLVP,NOBROWNOUT,NODEBUG                                   // Fusibles a utilizar
#use delay(clock=20M)                                                            // Define la velocidad del oscilador externo
#use standard_io(B)                                                              // Define el puerto que se utilizar·

int valor[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};                     // Declara e inicializa un vector de tipo entero de diez posiciones con los valores en bcd

void main()                                                                      // FunciÛn principal
{
      set_tris_b(0x00);                                                          // Define los pines del puerto B como salida
      output_b(0x00);                                                            // Establece el estado inicial de los pines en estado bajo (APAGADO)

      while(true)                                                                // Ciclo while para ejecutar el cÛdigo 
      {
            for(int n=0; n<10; n++)                                              // Ciclo for de diez iteraciones correspondientes a los valores del vector
            {
                output_b(valor[n]);                                              // Establece el estado de los pines acorde al valor de la iteraciÛn
                delay_ms(1000);                                                  // Genera un retardo de 1 segundo 
            }
            
            
      }
   }
