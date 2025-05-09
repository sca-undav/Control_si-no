/****************************************************************************************
* EJEMPLO DE USO controlSiNo.h
*****************************************************************************************
* Archivo:  Ejemplo_potenciometro.ino
* Descripción:
*           Ejemplo para la librería controlSiNo.h
*           Leemos una entrada analógica conectada a un potenciómetro y mostramos en 
*           LED_BUILTIN y en el monitor el resultado de la función de contro si-no.
* 
* UNDAV, Sistemas de Control Automático, 2023.
****************************************************************************************/

/****************************************************************************************
* Librería incluídas
****************************************************************************************/

#include "Arduino.h"
#include "controlSiNo_sca.h"

/****************************************************************************************
* Constantes
****************************************************************************************/

#define pinLed               LED_BUILTIN
#define pinPotenciometro     A0
#define tiempoDelta          500  // Intervalo de tiempo entre muestras (en milisegundos)
#define Objetivo             600
#define Histeresis           200

/****************************************************************************************
* Variables globales
****************************************************************************************/

controlSiNo indicadorLed(pinLed);
int Medicion                 = 0;
bool estadoIndicador         = false;
unsigned long tiempoAnterior = 0;
unsigned long tiempoInicial  = 0;

/****************************************************************************************
* Funciones
****************************************************************************************/

void setup() {
  // Seteos iniciales
  pinMode(pinPotenciometro,INPUT);
  indicadorLed.Configurar(Objetivo, Histeresis, SALIDA_NORMAL);
  Serial.begin(9600);

  // Primer valor de la serie
  tiempoAnterior  = millis();
  tiempoInicial   = tiempoAnterior;
  Medicion        = 0;              // impongo la primer lectura
  estadoIndicador = false;          // idem con el actuador
  Serial.println("Tiempo\tLectura\tEstado");
  mostrar();                        // Muestro el estado inicial!!!
}

/***************************************************************************************/
void loop() {

  // Retardo para garantizar un tiempoDelta entre muestras
  do {
    // Acá pueden ponerse acciones a realizar mientras no se esté midiendo y actuando
     
  } while (millis()<(tiempoAnterior+tiempoDelta));
  tiempoAnterior += tiempoDelta;  // Actualizo el tiempo
  
  // Leo, controlo y muestro
  Medicion = analogRead(pinPotenciometro);
  estadoIndicador = indicadorLed.Controlar(Medicion);
  mostrar();

}

/***************************************************************************************/
void mostrar(){
  Serial.print(tiempoAnterior - tiempoInicial);
  Serial.print("\t");
  Serial.print(Medicion);
  Serial.print("\t");
  Serial.println(estadoIndicador);
}

/***************************************************************************************/
