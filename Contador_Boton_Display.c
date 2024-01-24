/*
            ***** CONTADOR DISPLAY 7 SEGMENTOS PUSH BUTTON *****
        
        El presente c�digo implementa de un incrementador que estar� aumentando con respecto el usuario presione el push button
        al mismo tiempo que el n�mero resultante del contador ser� exhibido en un display de siete segmentos c�todo com�n la 
        cuenta m�xima ser� al 9. El c�digo esta orientado al microcontrolador PIC16F877A.
		Fecha: 13-Marzo-2022
		Versi�n: 1.0
*/

#include <16f877a.h>                                                             // Libreria del microcontrolador que se utilizar�
#fuses HS,NOWDT,NOPUT,NOLVP,NOBROWNOUT,NODEBUG                                   // Fusibles a utilizar
#use delay(clock=20M)                                                            // Establece la velocidad del oscilador externo
#use standard_io(B)                                                              // Establece que el puerto B ser� utilizado
#use standard_io(A)                                                              // Establece que el puerto B ser� utilizado

#define boton PIN_A0                                                             // Define al pin A0 como boton

int valor[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};                     // Se crea un vector tipo entero de diez posiciones con los valores bcd
int i=0;                                                                         // Declara e inicializa la variable de incrementador tipo entero para llevar la cuenta

void main()                                                                      // Funci�n principal
{  
   set_tris_b(0x00);                                                             // Establece los pines del puerto B como salidas                                    
   set_tris_A(0xFF);                                                             // Establece los pines del puerto A como entradas
   output_b(0x00);                                                               // Establece el valor inicial de los pines del puerto B en 0 APAGADO
   
      while(true)                                                                // Ciclo while para que siempre se ejecute el c�digo
      {  
         
         if(input(boton) == 1)                                                   // Condici�n si en boton es presionado
         {
            delay_ms(500);                                                       // Genra un retardo de 500ms 0.5Seg
            i++;                                                                 // La variable i se incrementa en uno
         }

       output_b(valor[i]);                                                       // Especifica que el valor de la salida del puerto b es equivalente al valor del vector en la posici�n del incrementador
       
            if(i>9)                                                              // Condici�n si el valor del incrementador es mayor a 9
            {
               i=0;                                                              // El incrementador se reinicia
            }
         
      }
}  
