/*
            ***** LIQUID CRYSTAL DISPLAY HOLA MUNDO *****
            
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




void main()                                                                      // Función Principal
{  
   lcd_init();                                                                   // Inicialización de la pantalla lcd
   
   while(true)                                                                   // Ciclo para que siempre se ejecute el código
   {
      lcd_gotoxy(1,1);                                                           // Asigna cordenadas
      lcd_putc("\f");                                                            // Limpia el texto de la LCD
      printf(lcd_putc,"Hola Mundo");                                             // Imprime texto en lcd
      delay_ms(1000);                                                            // Genera retardo de 1000ms 
      lcd_putc("\f");                                                            // Limpia el texto en pantalla
      printf(lcd_putc,"\nHola PIC");                                             // Imprime texto en pantalla con un salto de linea
       delay_ms(1000);                                                           // Genera retardo de 1000ms (1SEG)
      lcd_putc("\f");                                                            // Limpia el texto en pantalla
   }
}
