#include <stdio.h>
#include <stdlib.h>
#define CONST 100
#define PRODUCTO 1000
#define CHAR 100
#include "miFunciones.h"
#include "lib.h"

int main(){
    int opcion;
    char validar[CHAR];
    usuario arrayUsuario[CONST];
    producto arrayProducto[PRODUCTO];
    inicializarArrayProducto(arrayProducto, PRODUCTO);
    inicializarArrayUsuario(arrayUsuario, CONST);
    for(;;){
        printf("\n1 - ALTA DE USUARIO\n");
        printf("\n2 - MODIFICAR USUARIO\n");
        printf("\n3 - BAJA DE USUARIO\n");
        printf("\n4 - PUBLICAR PRODUCTO\n");
        printf("\n5 - MODIFICAR PUBLICACION\n");
        printf("\n6 - CANCELAR PUBLICACION\n");
        printf("\n7 - COMPRAR PRODUCTO\n");
        printf("\n8 - LISTAR PUBLICACIONES DE USUARIOS\n");
        printf("\n9 - LISTAR PUBLICACIONES\n");
        printf("\n10 - LISTAR USUARIOS\n");
        printf("\nOPCION: ");
        scanf("%s", validar);
        if(esNumerico(validar)==0){
            printf("OPCION NO VALIDA\n\n");
            continue;
        }
        opcion=atoi(validar);
        switch(opcion){
            case 1:
                nuevoUsuario(arrayUsuario, CONST);
                break;
            case 2:
                modificarUsuario(arrayUsuario, CONST);
                break;
            case 3:
                bajaUsuario(arrayUsuario, CONST);
                break;
            case 4:
                publicarProducto(arrayUsuario, arrayProducto, CONST, PRODUCTO);
                break;
            case 5:
                modificarProducto(arrayUsuario,arrayProducto, CONST, PRODUCTO);
                break;
            case 6:
                eliminarProducto(arrayUsuario, arrayProducto, CONST, PRODUCTO);
                break;
            case 7:
                realizarCompra(arrayUsuario, arrayProducto, CONST, PRODUCTO);
                break;
            case 8:
                listarPublicacionesUsuario(arrayUsuario, arrayProducto, CONST, PRODUCTO);
                break;
            case 9:
                listarPublicaciones(arrayUsuario,arrayProducto, CONST, PRODUCTO);
                break;
            case 10:
                listarUsuarios(arrayUsuario, CONST);
                break;
            default:
                printf("OPCION NO VALIDA\n\n");
                break;
        }
    }
    return 0;
}
