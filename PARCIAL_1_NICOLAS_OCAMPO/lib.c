#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CONST 100
#define PRODUCTO 1000
#include "lib.h"
#include "miFunciones.h"

/** \brief Inicializa en 0 el campo estado del array de estructuras
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño del array
 *
 */
void inicializarArrayUsuario(usuario array[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        array[i].estado=0;
        array[i].id=0;
    }
    return;
}


/** \brief Inicializa en 0 el campo estado del array de estructuras
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño del array
 *
 */
void inicializarArrayProducto(producto array[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        array[i].estado=0;
        array[i].idProducto=0;
        array[i].vendido=0;
    }
    return;
}


/** \brief Crea un nuevo usuario en el array de estructuras
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño del array
 *
 */
void nuevoUsuario(usuario array[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(array[i].estado==0)
        {
            clearStdin();
            printf("INGRESE NICKNAME: ");
            scanf("%s", array[i].nick);
            printf("\nINGRESE PASSWORD: ");
            scanf("%s", array[i].pass);
            proximoId(array, CONST, i);
            array[i].estado=1;
            printf("\n\nUSUARIO CREADO SATISFACTORIAMENTE\nNOMBRE: %s\nPASSWORD: %s\nID: %d\n", array[i].nick, array[i].pass, array[i].id);
            pause();
            return;
        }
    }
    printf("\nNO HAY MAS ESPACIO LIBRE PARA USUARIOS\n");
    pause();
}


/** \brief Modifica los campos de la estructura
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño del array
 *
 */
void modificarUsuario(usuario array[], int size)
{
    int i;
    int opcion;
    int numero;
    char validar[CONST];
    printf("\nINGRESE EL ID DEL USUARIO A MODIFICAR: ");
    scanf("%s", validar);
    if(esNumerico(validar))
    {
        numero=atoi(validar);
    }
    else
    {
        printf("\nERROR FATAL, REINTENTE\n");
        pause();
        return;
    }
    for(i=0; i<size; i++)
    {
        if(array[i].id==numero && array[i].estado==1)
        {
            for(;;)
            {
                printf("\nNICKNAME: %s\nPASSWORD: %s\n", array[i].nick, array[i].pass);
                printf("\nESTA SEGURO DE MODIFICAR AL USUARIO?\n1 - SI\n2 - NO\n ");
                scanf("%d", &opcion);
                if(opcion==1)
                {
                    printf("\nINGRESE NUEVO NICKNAME: ");
                    scanf("%s", array[i].nick);
                    printf("\nINGRESE NUEVO PASSWORD: ");
                    scanf("%s", array[i].pass);
                    printf("\n\nUSUARIO MODIFICADO SATISFACTORIAMENTE\n");
                    pause();
                    return;
                }
                else if(opcion==2)
                {
                    printf("\nEL USUARIO NO HA SIDO MODIFICADO\n");
                    pause();
                    return;
                }
            }
        }
    }
    printf("\nNO SE ENCONTRO EL NICKNAME SOLICITADO\n");
    pause();
}


/** \brief baja logica de la estructura
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño del array
 *
 */
void bajaUsuario(usuario array[], int size)
{
    int i;
    int numero;
    int opcion=0;
    char validar[CONST];
    printf("\nINGRESE EL ID DEL USUARIO A DAR DE BAJA: ");
    scanf("%s", validar);
    if(esNumerico(validar))
        numero=atoi(validar);
    else
    {
        printf("\nERROR EN EL INGRESO DEL ID, REINTENTE\n");
        pause();
    }
    for(i=0; i<size; i++)
    {
        if(array[i].id==numero && array[i].estado==1)
        {
            for(;;)
            {
                printf("\nNICKNAME: %s\nPASSWORD: %s\n", array[i].nick, array[i].pass);
                printf("\nESTA SEGURO DE ELIMINAR AL USUARIO?\n1 - SI\n2 - NO\n ");
                scanf("%d", &opcion);
                if(opcion==1)
                {
                    array[i].estado=2;
                    printf("\nUSUARIO ELIMINADO SATISFACTORIAMENTE\n");
                    pause();
                    return;
                }
                else if(opcion==2)
                {
                    printf("\nEL USUARIO NO HA SIDO ELIMINADO DE LA PLATAFORMA\n");
                    pause();
                    return;
                }
            }
        }
    }
    printf("\nNO SE ENCONTRO EL ID SOLICITADO\n");
    pause();
}


/** \brief Calcula el proximo id del usuario
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño de la estructura
 * \param posicion posicion del array donde guardar el id
 *
 */
void proximoId(usuario array[], int size, int posicion)
{
    int i;
    int maxId=-1;
    for(i=0; i<size; i++)
    {
        if(array[i].estado==1 || array[i].estado==2)
        {
            if(array[i].id > maxId)
                maxId = array[i].id;
        }
    }
    array[posicion].id=maxId+1;
    return;
}


/** \brief Calcula el proximo id del producto
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño de la estructura
 * \param posicion posicion del array donde guardar el id
 *
 */
void proximoIdProducto(producto array[], int size, int posicion)
{
    int i;
    int maxId=-1;
    for(i=0; i<size; i++)
    {
        if(array[i].estado==1 || array[i].estado==2)
        {
            if(array[i].idProducto > maxId)
                maxId = array[i].idProducto;
        }
    }
    array[posicion].idProducto=maxId+1;
    return;
}

/** \brief Publica un producto en la estructura producto
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
  * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 *
 */
void publicarProducto(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto)
{
    int i;
    int aux=-1;
    float numero=0;
    int idUsuario;
    char validar[CONST];
    printf("\nINGRESE ID DEL USUARIO: ");
    scanf("%s", validar);
    if(esNumerico(validar))
        idUsuario=atoi(validar);
    else
    {
        printf("\nERROR EN EL INGRESO DEL ID, REINTENTE OPCION\n");
        pause();
    }
    for(i=0; i<sizeUsuario; i++)
    {
        if(arrayUsuario[i].id==idUsuario && arrayUsuario[i].estado==1){
            aux=i;
            break;
        }

    }
    if(aux==-1)
    {
        printf("\nNO SE ENCONTRO LA ID SOLICITADA\n\n");
        return;
    }
    for(i=0; i<sizeProducto; i++)
    {
        if(arrayProducto[i].estado==0)
        {
            arrayProducto[i].aux=aux;
            printf("\nINGRESE NOMBRE DEL PRODUCTO: ");
            scanf("%s", arrayProducto[i].nombre);
            printf("\nINGRESE EL PRECIO DEL PRODUCTO: ");
            scanf("%f", &numero);
            arrayProducto[i].precio=numero;
            printf("\nINGRESE EL STOCK DEL PRODUCTO: ");
            scanf("%d", &aux);
            arrayProducto[i].stock=aux;
            arrayProducto[i].idUsuario=idUsuario;
            proximoIdProducto(arrayProducto, PRODUCTO, i);
            arrayProducto[i].estado=1;
            printf("\n\nPRODUCTO PUBLICADO EXITOSAMENTE!\nNOMBRE: %s \nPRECIO: %.2f\nSTOCK: %d\nID DEL PRODUCTO: %d\n", arrayProducto[i].nombre, arrayProducto[i].precio, arrayProducto[i].stock, arrayProducto[i].idProducto);
            pause();
            return;
        }
    }
    printf("\nNO HAY MAS ESPACIO PARA PUBLICAR PRODUCTOS\n");
    pause();
    return;
}


/** \brief Modifica un producto en la estructura producto
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
  * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 *
 */
void modificarProducto(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto)
{
    int i;
    int aux=-1;
    int flag=0;
    int opcion;
    float numero=0;
    int idUsuario;
    char validar[CONST];
    printf("\nINGRESE ID DEL USUARIO: ");
    scanf("%s", validar);
    if(esNumerico(validar))
        idUsuario=atoi(validar);
    else
    {
        printf("\nERROR EN EL INGRESO DEL ID, REINTENTE OPCION\n");
        pause();
    }
    for(i=0; i<sizeUsuario; i++)
    {
        if(arrayUsuario[i].id==idUsuario && arrayUsuario[i].estado==1){
            aux=i;
            break;
        }

    }
    if(aux==-1)
    {
        printf("\nNO SE ENCONTRO LA ID SOLICITADA\n\n");
        return;
    }
    for(i=0; i<sizeProducto; i++)
    {
        if(arrayProducto[i].estado==1 && idUsuario==arrayProducto[i].idUsuario)
        {
            printf("!\nNOMBRE: %s\nPRECIO: %.2f\nSTOCK: %d\nID DEL PRODUCTO: %d\n", arrayProducto[i].nombre, arrayProducto[i].precio, arrayProducto[i].stock, arrayProducto[i].idProducto);
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("\nNO SE ENCONTRO PRODUCTOS DE ESTE USUARIO\n");
        pause();
        return;
    }
    for(;;)
    {
        printf("\nESTA SEGURO DE MODIFICAR ALGUNO DE LOS PRODUCTOS?\n1 - SI\n2 - NO\n ");
        scanf("%d", &opcion);
        if(opcion==1)
        {
            printf("\nINGRESE ID DEL PRODUCTO A MODIFICAR: ");
            scanf("%s", validar);
            if(esNumerico(validar))
                idUsuario=atoi(validar);
            else
            {
                printf("\nERROR EN EL INGRESO DEL ID, REINTENTE OPCION\n");
                pause();
                return;
            }
            for(i=0; i<sizeProducto; i++)
            {
                if(arrayProducto[i].estado==1 && idUsuario==arrayProducto[i].idProducto)
                {
                    printf("\nINGRESE EL NUEVO NOMBRE DEL PRODUCTO: ");
                    scanf("%s", arrayProducto[i].nombre);
                    printf("\nINGRESE EL NUEVO PRECIO DEL PRODUCTO: ");
                    scanf("%f", &numero);
                    arrayProducto[i].precio=numero;
                    printf("\nINGRESE EL NUEVO STOCK DEL PRODUCTO: ");
                    scanf("%d", &aux);
                    arrayProducto[i].stock=aux;
                    printf("\n\nPRODUCTO PUBLICADO EXITOSAMENTE!\nNOMBRE: %s\nPRECIO: %.2f\nsSTOCK: %d\nID DEL PRODUCTO: %d\n", arrayProducto[i].nombre, arrayProducto[i].precio, arrayProducto[i].stock, arrayProducto[i].idProducto);
                    pause();
                    return;
                }
            }


        }
        else if(opcion==2)
        {
            printf("\nEL PRODUCTO NO HA SIDO MODIFICADO\n");
            pause();
            return;
        }
    }
}


/** \brief Elimina un producto en la estructura producto
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
  * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 *
 */
void eliminarProducto(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto)
{
    int i;
    int flag=0;
    int aux=-1;
    int opcion;
    int idUsuario;
    char validar[CONST];
    printf("\nINGRESE ID DEL USUARIO: ");
    scanf("%s", validar);
    if(esNumerico(validar))
        idUsuario=atoi(validar);
    else
    {
        printf("\nERROR EN EL INGRESO DEL ID, REINTENTE OPCION\n");
        pause();
    }
    for(i=0; i<sizeUsuario; i++)
    {
        if(arrayUsuario[i].id==idUsuario && arrayUsuario[i].estado==1){
            aux=i;
            break;
        }

    }
    if(aux==-1)
    {
        printf("\nNO SE ENCONTRO LA ID SOLICITADA\n\n");
        return;
    }
    for(i=0; i<sizeProducto; i++)
    {
        if(arrayProducto[i].estado==1 && idUsuario==arrayProducto[i].idUsuario)
        {
            printf("!\nNOMBRE: %s\nPRECIO: %.2f\nSTOCK: %d\nID DEL PRODUCTO: %d\n", arrayProducto[i].nombre, arrayProducto[i].precio, arrayProducto[i].stock, arrayProducto[i].idProducto);
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("\nNO SE ENCONTRO PRODUCTOS DE ESTE USUARIO\n");
        pause();
        return;
    }
    for(;;)
    {
        printf("\nESTA SEGURO DE ELIMINAR ALGUNO DE LOS PRODUCTOS?\n1 - SI\n2 - NO\n ");
        scanf("%d", &opcion);
        if(opcion==1)
        {
            printf("\nINGRESE ID DEL PRODUCTO A ELIMINAR: ");
            scanf("%s", validar);
            if(esNumerico(validar))
                idUsuario=atoi(validar);
            else
            {
                printf("\nERROR EN EL INGRESO DEL ID, REINTENTE OPCION\n");
                pause();
                return;
            }
            for(i=0; i<sizeProducto; i++)
            {
                if(arrayProducto[i].estado==1 && idUsuario==arrayProducto[i].idProducto)
                {
                    arrayProducto[i].estado=2;
                    printf("PRODUCTO ELIMINADO EXITOSAMENTE!\nNOMBRE: %s\nPRECIO: %.2f\nsSTOCK: %d\nID DEL PRODUCTO: %d\n", arrayProducto[i].nombre, arrayProducto[i].precio, arrayProducto[i].stock, arrayProducto[i].idProducto);
                    pause();
                    return;
                }
            }
        }
        else if(opcion==2)
        {
            printf("\nEL PRODUCTO NO HA SIDO MODIFICADO\n");
            pause();
            return;
        }
    }
}


/** \brief Realiza una compra
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
  * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 * \return
 *
 */
void realizarCompra(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto)
{
    int i;
    int flag=0;
    int opcion;
    int aux=-1;
    int idUsuario;
    char validar[CONST];
    printf("\nINGRESE ID DEL USUARIO: ");
    scanf("%s", validar);
    if(esNumerico(validar))
        idUsuario=atoi(validar);
    else
    {
        printf("\nERROR EN EL INGRESO DEL ID, REINTENTE OPCION\n");
        pause();
    }
    for(i=0; i<sizeUsuario; i++)
    {
        if(arrayUsuario[i].id==idUsuario && arrayUsuario[i].estado==1){
            aux=i;
            break;
        }

    }
    if(aux==-1)
    {
        printf("\nNO SE ENCONTRO LA ID SOLICITADA\n\n");
        return;
    }
    for(i=0; i<sizeProducto; i++)
    {
        if(arrayProducto[i].estado==1 && idUsuario==arrayProducto[i].idUsuario && arrayProducto[i].stock>0)
        {
            printf("\n--------------------------------------------\n\nNOMBRE: %s\nPRECIO: %.2f\nSTOCK: %d\nID DEL PRODUCTO: %d\n", arrayProducto[i].nombre, arrayProducto[i].precio, arrayProducto[i].stock, arrayProducto[i].idProducto);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNO SE ENCONTRO PRODUCTOS DE ESTE USUARIO\n");
        pause();
        return;
    }
    for(;;)
    {
        printf("\nESTA SEGURO DE COMPRAR ALGUNO DE LOS PRODUCTOS?\n1 - SI\n2 - NO\n ");
        scanf("%d", &opcion);
        if(opcion==1)
        {
            printf("\nINGRESE ID DEL PRODUCTO A COMPRAR: ");
            scanf("%s", validar);
            if(esNumerico(validar))
                idUsuario=atoi(validar);
            else
            {
                printf("\nERROR EN EL INGRESO DEL ID, REINTENTE OPCION\n");
                pause();
                return;
            }
            for(i=0; i<sizeProducto; i++)
            {
                if(arrayProducto[i].estado==1 && idUsuario==arrayProducto[i].idProducto)
                {
                    printf("\nINGRESE LA CANTIDAD DE PRODUCTOS A COMPRAR: \n");
                    scanf("%d", &aux);
                    arrayProducto[i].stock=arrayProducto[i].stock-aux;
                    arrayProducto[i].vendido=arrayProducto[i].vendido+aux;
                    if(arrayProducto[i].stock<0)
                    {
                        printf("\nERROR EN LA COMPRA, NO QUEDA SUFICIENTE STOCK\n");
                        arrayProducto[i].stock=arrayProducto[i].stock+aux;
                        pause();
                        return;
                    }
                    printf("\nINGRESE CALIFICACION PARA EL VENDEDOR (1/10): ");
                    scanf("%d", &aux);
                    arrayUsuario[arrayProducto[i].aux].calificacion=arrayUsuario[arrayProducto[i].aux].calificacion+aux;
                    arrayUsuario[arrayProducto[i].aux].cantidadCalificaciones++;
                    printf("PRODUCTO COMPRADO EXITOSAMENTE!\n");
                    pause();
                    return;
                }
            }
        }
        else if(opcion==2)
        {
            printf("\nEL PRODUCTO NO HA SIDO COMPRADO\n");
            pause();
            return;
        }
    }
}


/** \brief Lista las publicaciones de un usuario
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
  * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 *
 */
void listarPublicacionesUsuario(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto){
    int i;
    int aux=-1;
    int flag=0;
    int idUsuario;
    char validar[CONST];
    printf("\nINGRESE ID DEL USUARIO: ");
    scanf("%s", validar);
    if(esNumerico(validar))
        idUsuario=atoi(validar);
    else
    {
        printf("\nERROR EN EL INGRESO DEL ID, REINTENTE OPCION\n");
        pause();
    }
    for(i=0; i<sizeUsuario; i++)
    {
        if(arrayUsuario[i].id==idUsuario && arrayUsuario[i].estado==1){
            aux=i;
            break;
        }

    }
    if(aux==-1)
    {
        printf("\nNO SE ENCONTRO LA ID SOLICITADA\n\n");
        return;
    }
    for(i=0; i<sizeProducto; i++)
    {
        if(arrayProducto[i].estado==1 && idUsuario==arrayProducto[i].idUsuario)
        {
            printf("\n---------------------------------------\n\nNOMBRE: %s\nPRECIO: %.2f\nSTOCK: %d\nID DEL PRODUCTO: %d\nCANTIDAD VENDIDA: %d\n", arrayProducto[i].nombre, arrayProducto[i].precio, arrayProducto[i].stock, arrayProducto[i].idProducto, arrayProducto[i].vendido);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNO SE ENCONTRO PRODUCTOS DE ESTE USUARIO\n");
        pause();
        return;
    }
    pause();
}



/** \brief lista las publicaciones de todos los usuarios
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
 * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 *
 */
void listarPublicaciones(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto){
    int i;
    int flag=0;
    for(i=0; i<sizeProducto; i++)
    {
        if(arrayProducto[i].estado==1)
        {
            printf("\n------------------------------------------\n\nNOMBRE DEL PRODUCTO: %s\nPRECIO: %.2f\nSTOCK: %d\nID DEL PRODUCTO: %d\nCANTIDAD VENDIDA: %d\nNOMBRE DEL USUARIO: %s\n", arrayProducto[i].nombre, arrayProducto[i].precio, arrayProducto[i].stock, arrayProducto[i].idProducto, arrayProducto[i].vendido, arrayUsuario[arrayProducto[i].aux].nick);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNO SE ENCONTRO PRODUCTOS DISPONIBLES\n");
        pause();
        return;
    }
    pause();
}



/** \brief Lista las ventas y calificaciones de los usuarios
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
 * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 * \return
 *
 */
void listarUsuarios(usuario arrayUsuario[], int size){
    int i;
    float promedio;
    float cantidad;
    float calificacion;

    for(i=0;i<size; i++)
    {
        if(arrayUsuario[i].estado==1)
        {
            if(arrayUsuario[i].cantidadCalificaciones>0)
            {
                calificacion=arrayUsuario[i].calificacion;
                cantidad=arrayUsuario[i].cantidadCalificaciones;
                promedio=calificacion/cantidad;
            }
            else
                promedio=0;

            printf("\n-------------------------------------\nNOMBRE DE USUARIO: %s\nCALIFICACION PROMEDIO: %.2f\n\n", arrayUsuario[i].nick, promedio);
        }
    }
    pause();
}
