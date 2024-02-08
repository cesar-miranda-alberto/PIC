/*
            ***** SENSOR TEMPERATURA LM35 *****
            
      El presente código desarrollado en C tiene como finalidad la implementación del
      sensor de temperatura LM35 para calcular la temperatura del ambiente y esta sea
      exhibida a través de una LCD 16X2. El código esta desarrollado para el microcontrolador
      PIC16F877A.
      Fecha: 18-Marzo-2022
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

#include <16f877a.h>                                                                               // Libreria del microcontrolador a utilizar
#device ADC=10                                                                                     // Establece la resolución del ADC
#fuses HS,NOWDT,NOPUT,NOLVP,NOBROWNOUT,NODEBUG                                                     // Fusibles a utilizar
#use delay(clock=20M)                                                                              // Establece la velocidad del oscilador externo
#use standard_io(A)                                                                                // Establece el puerto A para utilizarse
#use standard_io(D)                                                                                // Establece el puerto B para utilizarse
#include <lcd.c>                                                                                   // Libreria de la LCD 16x2

float Temperatura;                                                                                 // Declara variable de tipo flotante para almacenar la temperatura
int caracter = 0xDF;                                                                               // Declara e incializa variable de tipo entero para el signo de grados °

int16 canal_0;                                                                                     // Declara variable entera de 16 bits para el muestreo
float ADC;                                                                                         // Declara variable de tipo flotante para la almacenar los valores digitales
float Vref=5.0;                                                                                    // Declaración e inicialización de tipo flotante para tomar el voltaje de referencia

void main()                                                                                        // Función principal
{
   lcd_init();                                                                                     // Inicialización de la LCD
   set_tris_a(0xFF);                                                                               // Establece el puerto A como entradas para realizar los muestreos
   set_tris_d(0x00);                                                                               // Establece el puerto B como salidas para enviar los datos hacia el LCD
   output_d(0x00);                                                                                 // Establece el estado de inicio del puerto d
   setup_adc(ADC_CLOCK_INTERNAL);                                                                  // Configura el adc utilizando el reloj interno del microcontrolador
   setup_adc_ports(AN0);                                                                           // Asigna el uso del adc en el puerto AN0
   
      while(true)                                                                                  // Ciclo infinito
      {
         set_adc_channel(0);                                                                       //Configura el adc en el canal 0
         delay_us(0);                                                                              // Genra retardo para realizar los muestreos
         canal_0 = read_adc();                                                                     // Realiza los muestreos y los almacena en la variable canal_0
         ADC = (float)(canal_0);                                                                   // Convierte los muestreos a tipo flotante
         Temperatura = 100.0 * Vref *(ADC/1023);                                                   // Convierte los bits a grados centigrados y almacena el valor en la variable
         
         lcd_gotoxy(6,1);                                                                          // Asigna cordenadas del lcd
         printf(lcd_putc,"LM35");                                                                  // Imprime texto en lcd en las cordenadas previamente establecidas
         printf(lcd_putc,"\nTemp= %0.2f%CC",Temperatura,0xDF);                                     // Imprime texto en lcd concatenando el valor de la temperatura con dos números decimales y signo °       
         delay_ms(200);
         
      }
}
