#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CONST 3
/**
 * @brief Comprueba si se ingreso numeros en una cadena
 * @param  aux[] Cadena a revisar
 * @return 0 si contiene caracteres, 1 si contiene solo numeros
 */
int isnumber(char aux[]){
    int i=0;
    int retorno = 0;
    while(aux[i]!='\0'){
        if(isdigit(aux[i]) == 0){
            retorno = 0;
            break;
        }
        retorno = 1;
        i++;
    }
    return retorno;
}
/**
 * Da de alta a un empleado del array de estructuras.
 * @param array el array de estructuras a recorrer.
 * @param size tamaño del array.
 */
void cargaDatosEstructura(EPersona array[], int size){
    char validarNumero[10];
    long int numero=0;
    int i=0;
    int flag=0;
    for(i=0;i<size;i++){
        if(array[i].estado==1)
            continue;
        printf("\nINGRESE DNI (SIN PUNTOS|SOLO 8 DIGITOS): ");
        scanf("%s", validarNumero);
        numero=atoi(validarNumero);
        if(isnumber(validarNumero)==0 || numero<10000000 || numero>99999999){
            printf("\n\nERROR FATAL EN LA CARGA DE DATOS, REINTENTE OPCION\n\n");
            return;
        }
        if(dniRepetido(array, CONST, numero)){
            printf("\nD.N.I. YA CARGADO EN EL SISTEMA\n");
            return;
        }
        array[i].dni=numero;
        printf("\nINGRESE NOMBRE: ");
        scanf("%s", array[i].nombre);
        printf("\nINGRESE EDAD (RANGO 0-199): ");
        scanf("%s", validarNumero);
        numero=atoi(validarNumero);
        if(isnumber(validarNumero)==0 || numero<0 || numero>200){
            printf("\n\nERROR FATAL EN LA CARGA DE DATOS, REINTENTE OPCION\n\n");
            return;
        }
        array[i].edad=numero;
        array[i].estado=1;
        flag=1;
        printf("CARGA EXITOSA");
        break;
    }
    if(flag==0){
        printf("\n\nNO HAY MAS ESPACIO PARA CARGA DE EMPLEADOS\n\n");
        return;
    }
    return;
}
/**
 * @brief Da de baja a una persona del array de estructuras.
 *
 * @param array el array de estructuras a recorrer.
 * @param size tamaño del array.
 */
void eliminarPersonaEstructura(EPersona array[], int size){
    char validarNumero[10];
    long int numero=0;
    int i=0;
    char seguir;
    printf("\nINGRESE DNI (SIN PUNTOS|SOLO 8 DIGITOS): ");
    scanf("%s", validarNumero);
    fflush(stdin);
    if(isnumber(validarNumero)==0){
        printf("\n\nERROR FATAL EN LA CARGA DE DATOS, REINTENTE OPCION\n\n");
        return;
    }
    numero=atoi(validarNumero);
    for(i=0;i<size;i++){
        if(array[i].dni==numero && array[i].estado==1){
            printf("\nNOMBRE: %s\nDNI: %d\nEDAD: %d\n",array[i].nombre,array[i].dni, array[i].edad);
            for(;;){
                fflush(stdin);
                printf("\nDESEA ELIMINAR A ESTE EMPLEADO?(s/n): ");
                scanf("%c", &seguir);
                if(seguir=='s' || seguir=='n'){
                    break;
                }
            }
            if(seguir=='s'){
                printf("\nEMPLEADO BORRADO EXITOSAMENTE\n");
                array[i].estado=0;
                return;
            }
            printf("\nEL EMPLEADO NO A SIDO ELIMINADO DEL SISTEMA\n");
            return;
        }
    }
    printf("\nNO SE ENCONTRO AL EMPLEADO\n");
    return;
}
/**
 * @brief Ordena la cadena de estructuras por nombre.
 *
 * \param array La cadena de estructuras a ordenar
 * \param size Tamaño del array de estructuras
 */
void ordenarEstructurNombre(EPersona array[], int size){
    int i;
    int flagSwap=1;
    EPersona aux;
    while(flagSwap){
        flagSwap = 0;
        for(i = 0; i<size-1 ; i++){
            if(strcmp(array[i].nombre,array[i+1].nombre)>1 && array[i].estado==1 &&array[i+1].estado==1){
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                flagSwap = 1;
            }
        }
    }
}
/**
 * @brief Muestra en pantalla el array de estructuras.
 *
 * @param array La cadena de estructuras a mostrar en pantalla
 * @param size El largo de la cadena de estructuras
 */
void mostrar(EPersona array[], int size){
    int i;
    for(i = 0; i<size ; i++){
        if(array[i].estado==1){
            printf("\nNOMBRE: %s\nDNI: %d\nEDAD: %d\n",array[i].nombre,array[i].dni, array[i].edad);
        }
    }
    printf("\n----------------------------------------------\n");
}
/**
 * @brief Recorre el array y busca el dni pasado por parametro.
 *
 * @param array array de estructuras que se pasa como parametro.
 * @param size el largo del array de estructuras
 * @param dni el dni a ser buscado en el array.
 * @return 0 si no lo encontro, 1 si lo encontro.
 */
int dniRepetido(EPersona array[], int size, int dni){
    int i=0;
    for(i=0;i<size;i++){
        if(array[i].dni==dni && array[i].estado==1)
            return 1;
    }
    return 0;
}
/**
 * Grafica con '*' las edades
 * @param array La cadena de estructuras
 * @param size El largo de la cadena de estructuras.
 */
void graficoEdades(EPersona array[], int size){
    int i=0;
    int edad=0;
    int arrayEdades[2];
    arrayEdades[0]=conteoEdades(array,CONST, 1);
    arrayEdades[1]=conteoEdades(array,CONST, 2);
    arrayEdades[2]=conteoEdades(array,CONST, 3);
    if(arrayEdades[0] >= arrayEdades[1] && arrayEdades[0] >= arrayEdades[2]){
        edad=arrayEdades[0];
    }
    else{
        if(arrayEdades[1] >= arrayEdades[0] && arrayEdades[1] >= arrayEdades[2]){
            edad=arrayEdades[1];
        }
        else{
            edad=arrayEdades[2];
        }
    }
    for(i=edad; i>0; i--){
        printf("|");
        if(i<= arrayEdades[0]){
                printf("*");
        }
        if(i<= arrayEdades[1]){
            printf("\t*");
        }
        if(i<= arrayEdades[2]){
            printf("\t\t*");
        }
        printf("\n");
    }
    printf("---------------------");
    printf("\n|<18\t19-35\t>35");
    return;
}
 /**
 * @brief Cuenta los rango de edades
 *
 * @param array el array de estructuras que se pasa como parametro.
 * @param opciones parametro que se utiliza para seleccionar que rango de edades a contar.
 * @return La cantidad de edades para el rango seleccionado.
 */
int conteoEdades(EPersona array[], int size, int opciones){
    int edad=0;
    int i=0;
    switch(opciones){
    case 1:
        for(i=0;i<size;i++){
            if(array[i].estado==1 && array[i].edad<=18){
                    edad++;
            }
        }
        break;
    case 2:
        for(i=0;i<size;i++){
            if(array[i].estado==1 && array[i].edad>18 && array[i].edad<=35){
                edad++;
            }
        }
        break;
    case 3:
        for(i=0;i<size;i++){
            if(array[i].estado==1 && array[i].edad>35){
                edad++;
            }
        }
        break;
    }
    return edad;
}
