/*
            ***** INTERRUPCIÓN EXTERNA *****
       
       El presente código desarrollado en C implementa el uso de la interrupción externa del microcontrolador 
       pic 16f877a utilizando dos displays siete segmentos cátodo común y un led para analizar el funcionamiento
       de las interrupciones.
       
*/
   
#include <16f877a.h>                                                             // Libreria del microcontrolador a utilizar
#fuses HS,NOWDT,NOPUT,NOLVP,NOBROWNOUT,NODEBUG,NOLVP                             // Fusibles a utilizar
#use delay(clock=20M)                                                            // Establece la velocidad del oscilador externo
#use standard_io(D)                                                              // Establece el puerto D como puerto a utilizar
#use standard_io(B)                                                              // Establece el puerto B como puerto a utilizar
#use standard_io(C)                                                              // Establece el puerto C como puerto a utilizar


int valor[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};                     // Crea un vector de diez posiciones con los valores para representar el el display siete segmentos
int i=0,j;                                                                       // Declaración e inicialización de contadores

#INT_EXT                                                                         // Habilita las interrupciones externas
void interrupcion_RB0()                                                          // Función para las interrupciones externas
{
      
              for (int k=0; k<5; k++)                                            // Ciclo for de cinco iteraciones
              {
                     output_toggle(PIN_B4);                                      // Niega el  estado del led
                     delay_ms(250);                                              // Establece retardo de 250ms (0.25Seg)
              }
             delay_ms(1000);                                                     // Establece retardo de 1000ma (1Seg)
             output_c(valor[i++]);                                               // Establece la salida del display siete segmentos con respecto a un valor del vector acorde al contador
         
   if(i>9)                                                                       
   {
      i=0;                                                                       // Reinicia a 0 el contador
   }
}

void main()                                                                      // Función principal
{  
   set_tris_b(0x0F);                                                             // Establece la mitad de los pines del puerto B como entradas y salidas
   set_tris_c(0x00);                                                             // Estabece los pines del puerto c como salida
   set_tris_d(0x00);                                                             // Estabece los pines del puerto c como salida
   output_d(0x00);                                                               // Estabece el estado inicicial del puerto d   
   
   enable_interrupts(INT_EXT);                                                   // Habilita las interrupciones externas
   ext_int_edge(L_TO_H);                                                         // Establece las interrupciones con estado alto
   enable_interrupts(GLOBAL);                                                    // Habilita las interrupciones globales
   output_c(valor[i]);                                                           // Establece el estado inicial del puerto c
   
      while(true)                                                                // Ciclo infinito
      {  
         for (j=0; j<10; j++)                                                    // Bucle for de diez iteraciones correspondientes a los valores del vector
         {
            output_d(valor[j]);                                                  // Establece el estado del puerto d con respecto al valor del vector y su iteración
            delay_ms(1000);                                                      // Establece retardo de 1000ms (1Seg)
         }
         
         if(j==10)                                                               
         {
            j=0;                                                                 // Reinicial el contador j   a 0
         }
     }
}
