#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "miFunciones.h"


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[]){
   int i=0;
   while(str[i] != '\0'){
       if (i == 0 && str[i] == '-'){
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clearStdin(void){
    setbuf(stdin,NULL);
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    clearStdin();
    scanf("%c",&auxiliar);
    return auxiliar;
}

/**
 * \brief Hace una pausa, similar al system("pause")
 * \param -
 * \return -
 *
 */
void pause(void){
    getChar("");
}



