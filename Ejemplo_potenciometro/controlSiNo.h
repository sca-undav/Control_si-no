/****************************************************************************************
* Módulo para control SI-NO
*****************************************************************************************
* Archivo:  controlSiNo.h
* Resumen:  Librería de control si-no elaborada con programación orientada a objetos (POO)
*           para el curso de Sistemas de Control Automático, UNDAV.
* Autor:    Guillermo Caporaletti <gfcaporaletti@undav.edu.ar>
*           (UNDAV, Ingeniería en Informática, Sistemas de Control Automático)
* Fecha:    Abril 2023
* Version:  1.1
* Cambios:  Agrega la función ConfigurarHisteresis().
*           Versión anterior: 1.0 (2021).
*
****************************************************************************************/

#ifndef CONTROL_SINO_H
#define CONTROL_SINO_H
#include "Arduino.h"

/***************************************************************************************/

class SiNo                            // Objeto para control SI-NO.
{
  private:
    boolean EstadoSalida;             // Estado de salida del control SI-NO.
    byte PinSalida;                   // Pin de salida. Si es 0, no actúa 
                                      // (se debe actuar de otra forma).
    float Prende;                     // Nuestro objetivo es que la ENTRADA 
                                      // esté entre Prende y Apaga.
    float Apaga; 
    int Pendiente;                    // +1 si (APAGA>PRENDE): significa que el actuador
                                      //                       hará que SUBA la ENTRADA
                                      // -1 si (APAGA<PRENDE): significa que el actuador
                                      //                       hará que BAJE la ENTRADA
  public:
    SiNo(float PRENDE, float APAGA);  // Constructor. Configura los parámetros 
                                      // PRENDE y APAGA del control si-no.
                                      // Establece por defecto Esdado=false.
    void AgregarSalida(byte PIN);     // Configura un pin de salida para actuar directamente 
                                      // ante cada llamada de la accion Controlar(...)
    boolean Controlar(float ENTRADA); // Devuelve el estado del controlador 
                                      // luego de procesar la ENTRADA.
    void Apagar();                    // Pone Estado en false.
    void Prender();                   // Pone Estado en true.
    boolean Estado();                 // Devuelve el Estado de salida.
    void ConfigurarHisteresis(float PRENDE, float APAGA);
                                      // Configura los límites de la histéresis.
                                      // Es posible cambiar esta configuración 
                                      // durante la ejecución.
};

/***************************************************************************************/

#endif // CONTROL_SINO_H

/******************************************************************** FIN DE ARCHIVO ***/
