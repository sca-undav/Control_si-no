# Control_si-no
Autor: Guillermo Caporaletti  <gfcaporaletti@undav.edu.ar>  
Colaboradores: Juan Manuel Castellano, Francisco A. D'Eramo, Agustín López, Iván Morán, Yoel Pedemonte.  
Versión: 2.0  
Fecha: Mayo 2025  
## Resumen
Esta librería implementa la acción de control si-no para Arduino. Utiliza programación orientada a objetos en C++. Se puede configurar el pin de salida. Su estado dependerá de la función control() y otras funciones. 
## Modo de uso
- Cuando se define el objeto controlSiNo OBJETO_A_CONTROLAR, se debe especificar el pin de salida o dejarlo en 0 (en cuyo caso se operará desde fuera del módulo).
- Se debe utilizar la funci{on OBJETO_A_CONTROLAR.Configurar() para establecer el valor objetivo y la histéresis.
- El control se hace con la función OBJETO_A_CONTROLAR.Controlar(). También pueden utilizarse las funciones Apagar y Prender.

Revisar declaraciones del objeto en controlSiNo_sca.h. Hay un ejemplo de uso dentro de este repositorio. Para que el módulo funcione, basta con incluir los archivos .h y .cpp en la carpeta del proyecto Arduino. 
