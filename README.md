# Control_si-no
Autor: Guillermo Caporaletti  <gfcaporaletti@undav.edu.ar>  
Colaboradores: Juan Manuel Castellano, Francisco A. D'Eramo, Agustín López, Iván Morán, Yoel Pedemonte.  
Versión: 1.1  
Fecha: Abril 2023  
## Resumen
Esta librería implementa la acción de control si-no para Arduino. Utiliza programación orientada a objetos en C++. Se puede configurar el pin de salida. Su estado dependerá de la función control() y otras funciones. 
## Modo de uso
- Cuando se define el objeto SiNo OBJETO_A_CONTROLAR, se debe especificar los valores de encendido y apagado.
- Si se desea asociar el control a un pin específico de salida, se debe ejecutar: OBJETO_A_CONTROLAR.AgregarSalida().
- El control se hace con la función OBJETO_A_CONTROLAR.Controlar(). También pueden utilizarse las funciones Apagar y  Prender.

Revisar declaraciones del objeto en controlSiNo.h. Hay un ejemplo de uso dentro de este repositorio. Para que el módulo funcione, basta con incluir los archivos .h y .cpp en la carpeta del proyecto Arduino. 
