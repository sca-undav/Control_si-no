/****************************************************************************************
* Módulo para control SI-NO
*****************************************************************************************
* Archivo:  controlSiNo.cpp
* Resumen:  Librería de control si-no. 
* Autor:    Guillermo Caporaletti <gfcaporaletti@undav.edu.ar>
*           (UNDAV, Ingeniería en Informática, Sistemas de Control Automático)
* Fecha:    Abril 2023
* Version:  1.1
*
****************************************************************************************/

#include "Arduino.h"
#include "controlSiNo.h"

/****************************************************************************************
* Funciones públicas
****************************************************************************************/

/****************************************************************************************
* Función:  Constructor SiNo(PRENDE, APAGA)
* Resumen:  Configura los parámetros PRENDE y APAGA del control si-no.
*           Establece por defecto Esdado=false y que no hay pin de salida.
****************************************************************************************/
SiNo::SiNo(float PRENDE, float APAGA)
{
  EstadoSalida = false;   // Estado por defecto al iniciar.
  ConfigurarHisteresis( PRENDE, APAGA );
}

/***************************************************************************************/
void SiNo::AgregarSalida(byte PIN)
{
  PinSalida = PIN; 
  if (PinSalida>0) pinMode(PinSalida, OUTPUT);
  if (PinSalida>0) digitalWrite(PinSalida, EstadoSalida);
}

/****************************************************************************************
* Función:  Controlar(ENTRADA)
* Resumen:  Devuelve el estado del controlador luego de procesar la ENTRADA.
*           Si fue seteado un PIN de salida, cambia su estado.
****************************************************************************************/
boolean SiNo::Controlar(float ENTRADA)       // Controla, teniendo en cuenta ENTRADA y Estado previo.
{
  if (((ENTRADA-Prende)*Pendiente)<0) {
    // Debo prender... 
    EstadoSalida = true;
  }
  if (((ENTRADA-Apaga)*Pendiente)>0) {
    // Debo apagar... 
    EstadoSalida = false;
  }
  if (PinSalida>0) digitalWrite(PinSalida, EstadoSalida);
  return EstadoSalida;
}

/****************************************************************************************
* Función:  Apagar()
* Resumen:  Pone en "false" el estado y apaga la salida PIN (si fue configurada).
****************************************************************************************/
void SiNo::Apagar()
{
  EstadoSalida = false;
  if (PinSalida>0) digitalWrite(PinSalida, EstadoSalida);
}

/****************************************************************************************
* Función:  Prender()
* Resumen:  Pone en "true" el estado y prende la salida PIN (si fue configurada).
****************************************************************************************/
void SiNo::Prender()
{
  EstadoSalida = true;
  if (PinSalida>0) digitalWrite(PinSalida, EstadoSalida);
}

/****************************************************************************************
* Función:  Estado()
* Resumen:  Devuelve el estado del controlador si-no.
****************************************************************************************/
boolean SiNo::Estado()
{
  return EstadoSalida;
}

/****************************************************************************************
* Función:  ConfigurarHisteresis
* Resumen:  Establece los umbrales de la histéresis
****************************************************************************************/
void SiNo::ConfigurarHisteresis(float PRENDE, float APAGA)
{
  Prende = PRENDE;
  Apaga = APAGA;
  Pendiente = 1;          // Normalmente, el actuador hace que suba la ENTRADA = MEDICION
                          // (medición de la variable controlada).
  if (Apaga<Prende) Pendiente = -1;   
                          // Esto puede ocurrir cuando se toma como ENTRADA a la señal ERROR
                          // (ERROR = REFERENCIA - MEDICION).
                          // También cuando, por ejemplo, se controla la potencia de 
                          // una heladera, que hace que baje la temperatura. 
}

/******************************************************************** FIN DE ARCHIVO ***/
