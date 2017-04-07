#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main(){
    float primerOperando=0;
    float segundoOperando=0;
    char seguir='s';
    int opcion=0;
    float total=0;
    while(seguir=='s'){
        printf("\n\n1- Ingresar 1er operando (A=%.2f)\n", primerOperando);
        printf("2- Ingresar 2do operando (B=%.2f)\n", segundoOperando);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n\n");
        printf("9- Salir\n\n");
        printf("Ingrese la opcion deseada: ");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            printf("\nIngrese el 1er operando A: ");
            scanf("%f", &primerOperando);
            break;
        case 2:
            printf("\nIngrese el 2do operando B: ");
            scanf("%f", &segundoOperando);
            break;
        case 3:
            printf("\nEl resultado de la suma entre %2.f y %2.f es: %.2f\n", primerOperando, segundoOperando, total=suma(primerOperando,segundoOperando));
            break;
        case 4:
            printf("\nEl resultado de la diferencia entre %2.f y %2.f es: %.2f\n", primerOperando, segundoOperando, total=diferencia(primerOperando,segundoOperando));
            break;
        case 5:
            cociente(primerOperando,segundoOperando,"\nEl resultado del cociente es: ","\nERROR EN LA DIVISION: EL SEGUNDO OPERANDO TIENE QUE SER DIFERENTE DE 0 (CERO)\n");
            break;
        case 6:
            printf("\nEl resultado del producto entre %2.f y %2.f es: %.2f\n", primerOperando, segundoOperando, total=producto(primerOperando,segundoOperando));
            break;
        case 7:
            factorial(primerOperando, "\nEL factorial es: ", "\nERROR EN EL FACTORIAL: NO EXISTE FACTORIAL NEGATIVOS\n");
            break;
        case 8:
            printf("\nEl resultado de la suma entre %2.f y %2.f es: %.2f\n", primerOperando, segundoOperando, total=suma(primerOperando,segundoOperando));
            printf("\nEl resultado de la diferencia entre %2.f y %2.f es: %.2f\n", primerOperando, segundoOperando, total=diferencia(primerOperando,segundoOperando));
            cociente(primerOperando,segundoOperando,"\nEl resultado del cociente es: ","\nERROR EN LA DIVISION: EL SEGUNDO OPERANDO TIENE QUE SER DIFERENTE DE 0 (CERO)\n");
            printf("\nEl resultado del producto entre %2.f y %2.f es: %.2f\n", primerOperando, segundoOperando, total=producto(primerOperando,segundoOperando));
            factorial(primerOperando, "\nEL factorial es: ", "\nERROR EN EL FACTORIAL: NO EXISTE FACTORIAL NEGATIVOS\n");
            break;
        case 9:
            seguir = 'n';
            break;
        default:
            printf("\n\nERROR: REINGRESE LA OPCION\n\n");
            break;
        }
    }
    return 0;
}
