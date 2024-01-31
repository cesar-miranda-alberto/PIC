/*
            ***** LIQUID CRYSTAL DISPLAY CONTADOR *****
            
      El presente código desarrollado en C tiene como finalidad la implementación del uso de la pantalla LCD donde
      se mostrará un texto y este se limpiará cada determinado tiempo. El código esta implementado en el microcontrolador
      PIC16F877A.
      Fecha: 16-Marzo-2021
      Versión: 1.0
      
      donde:
      ------------------------------------------------
      | PIN DEL MICROCONTROLADOR   |   PIN DE LA LCD |
      |        PIN_D0              |        E        |
      |        PIN_D1              |        RS       |
      |        PIN_D2              |        RW       |
      |        PIN_D4              |        D4       |
      |        PIN_D5              |        D5       |
      |        PIN_D6              |        D6       |
      |        PIN_D7              |        D7       |
      ------------------------------------------------
      
*/
#include <16f877a.h>                                                             // Libreria del microcontrolador a utilizar
#fuses HS,NOWDT,NOPUT,NOLVP,NOBROWNOUT,NODEBUG                                   // Fusibles que se utilizarán
#use delay(clock=20M)                                                            // Establece velocidad del oscilador externo
#include <lcd.c>                                                                 // Incluye la libreria de la lcd
#use standard_io(D)                                                              // Define el puerto que se utilizará

int valor;

void main()                                                                      // Función Principal
{  
   lcd_init();                                                                   // Inicialización de la pantalla lcd
   set_tris_d(0x00);                                                             // Establece los pines del puerto D como salidas
   output_d(0x00);                                                               // Establece el estado inicial de los pines en estado bajo (APAGADO)
           
   while(true)                                                                   // Ciclo para que siempre se ejecute el código
   {
     for(valor=0; valor<10; valor++)                                             // Ciclo for de diez iteraciones para el contador
         {  
              lcd_gotoxy(1,1);                                                   // Asigna las cordenadas al texto
              printf(lcd_putc,"CONTADOR");                                       // Imprime texto de titulo en pantalla 
              printf(lcd_putc,"\nNumero =%1D", valor);                           // Imprime texto en pantalla lcd concatenando el valor de la iteración
              delay_ms(500);                                                     // Genera retardo de 500 ms (0.5Seg)
         }           
         
         lcd_putc("\f");                                                         // Limpia el texto en pantalla
         delay_ms(2000);                                                         // Genera retardo de 2000ms (2Seg)
   }
}
