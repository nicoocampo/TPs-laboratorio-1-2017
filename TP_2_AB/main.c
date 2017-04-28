#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CONST 3
int main(){
    char seguir='s';
    int numero=0;
    char validarNumero[9];
    EPersona array[CONST];
    while(seguir=='s'){
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("ELIJA UNA OPCION VALIDA: ");
        scanf("%s", validarNumero);
        if(isnumber(validarNumero)==0){
            printf("\nERROR AL ELEGIR LA OPCION. REINTENTE\n\n");
            validarNumero[0]='\0';
            continue;
        }
        numero=atoi(validarNumero);
        validarNumero[0]='\0';
        switch(numero){
            case 1:
                cargaDatosEstructura(array,CONST);
                break;
            case 2:
                eliminarPersonaEstructura(array, CONST);
                break;
            case 3:
                ordenarEstructurNombre(array, CONST);
                mostrar(array, CONST);
                break;
            case 4:
                graficoEdades(array, CONST);
                break;
            case 5:
                seguir='n';
                break;
            default:
                printf("\nERROR AL ELEGIR LA OPCION. REINTENTE\n\n");
                break;
        }
    }
    return 0;
}
