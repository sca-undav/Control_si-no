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

#include "controlSiNo.h"

/****************************************************************************************
* Constantes
****************************************************************************************/

const byte pinPotenciometro = A0;
const byte pinLed = LED_BUILTIN;
const long tiempoDelta=500; // Intervalo de tiempo entre muestras (en milisegundos)
const unsigned int Objetivo=600;
const unsigned int Histeresis=200;

/****************************************************************************************
* Variables globales
****************************************************************************************/

int Lectura = 0;
SiNo indicadorLed(Objetivo-Histeresis, Objetivo+Histeresis);
bool estadoIndicador = false;
unsigned long tiempoAnterior = 0;
unsigned long tiempoInicial = 0;

/****************************************************************************************
* Funciones
****************************************************************************************/

void setup() {
  // Seteos iniciales
  pinMode(pinPotenciometro,INPUT);
  indicadorLed.AgregarSalida(LED_BUILTIN); //pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);

  // Primer valor de la serie
  tiempoAnterior = millis();
  tiempoInicial = tiempoAnterior;
  Lectura = 0;                // impongo la primer lectura
  estadoIndicador = false;    // idem con el actuador
  Serial.println("Tiempo\tLectura\tEstado");
  mostrar();  // Muestro el estado inicial!!!
  
}

/***************************************************************************************/
void loop() {

  // Retardo para garantizar un tiempoDelta entre muestras
  do {
    // Acá pueden ponerse acciones a realizar mientras no se esté midiendo y actuando
     
  } while (millis()<(tiempoAnterior+tiempoDelta));
  tiempoAnterior += tiempoDelta;  // Actualizo el tiempo
  
  // Leo, controlo y muestro
  Lectura = analogRead(pinPotenciometro);
  estadoIndicador = indicadorLed.Controlar(Lectura);
  mostrar();

}

/***************************************************************************************/
void mostrar(){
  Serial.print(tiempoAnterior - tiempoInicial);
  Serial.print("\t");
  Serial.print(Lectura);
  Serial.print("\t");
  Serial.println(estadoIndicador);
}

/***************************************************************************************/
