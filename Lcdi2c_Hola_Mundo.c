/*
            ****** LCD I2C *****
          
      El presente código desarrollado en C tiene como finalidad la implementación del protocolo i2c a través de
      un lcd 16x2 donde se exhibirá texto de hola mundo a manera de comprobar el funcionamiento del código.
      El código esta dirigido al microcontrolador PIC16F877A.
      
*/

#include <16f877a.h>                                                                      // Agrega la libreria del microcontrolador que se utilizará
#fuses HS,NOWDT,NOPUT,NOLVP,NOBROWNOUT,NODEBUG,NOLVP,NOPROTECT                            // Establecen los fusibles que se utilizarán
#use delay(clock=20M)                                                                     // Establece la velocidad del reloj externo
#use standard_io(D)                                                                       // Establece el puerto que se utilizará
#use I2C(MASTER, SDA=PIN_C4, SCL=PIN_C3, FAST)                                            // Configuración de los parámetros 
#include <i2c_flex_LCD.c>                                                                 // Incluye la libreria del protocolo i2c

#define ADDRESS_LCD 0X4E                                                                  // Configura la dirección del Circuito Integrado

void main()                                                                               // Función Principal
{
   lcd_init(0x4E, 16, 2);
   
      while(true)
      {
               lcd_gotoxy(1,1);                                                           // Asigna cordenadas
               lcd_putc("\f");                                                            // Limpia el texto de la LCD
               printf(lcd_putc,"Hola Mundo");                                             // Imprime texto en lcd
               delay_ms(1000);                                                            // Genera retardo de 1000ms 
               lcd_putc("\f");                                                            // Limpia el texto en pantalla
               printf(lcd_putc,"\ndesde el i2c");                                         // Imprime texto en pantalla con un salto de linea
                delay_ms(1000);                                                           // Genera retardo de 1000ms (1SEG)
               lcd_putc("\f");                                                            // Limpia el texto en pantalla
      }
}

