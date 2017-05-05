#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CONST 100
#define PRODUCTO 1000
#define CHAR 100

typedef struct
{
 char nick[CHAR];
 char pass[CHAR];
 int calificacion;
 int cantidadCalificaciones;
 int id;
 int estado;//0 para vacio, 1 para ocupado, 2 para borrado
}usuario;

typedef struct
{
    char nombre[CONST];
    int stock;
    float precio;
    int idUsuario;
    int estado;
    int idProducto;
    int vendido;
    int aux;
}producto;


/** \brief Calcula el proximo id del usuario
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño de la estructura
 * \param posicion posicion del array donde guardar el id
 *
 */
void proximoId(usuario array[], int size, int posicion);


/** \brief Crea un nuevo usuario en el array de estructuras
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño del array
 *
 */
void nuevoUsuario(usuario array[], int size);


/** \brief Inicializa en 0 el campo estado del array de estructuras
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño del array
 *
 */
void inicializarArrayProducto(producto array[], int size);


/** \brief nicializa en 0 el campo estado del array de estructuras
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño del array
 *
 */
void inicializarArrayUsuario(usuario array[], int size);


/** \brief Modifica los campos de la estructura
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño del array
 *
 */
void modificarUsuario(usuario array[], int size);


/** \brief baja logica de la estructura
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño del array
 *
 */
void bajaUsuario(usuario array[], int size);


/** \brief Calcula el proximo id del producto
 *
 * \param usuario array[] Array de estructuras
 * \param size tamaño de la estructura
 * \param posicion posicion del array donde guardar el id
 *
 */
void proximoIdProducto(producto array[], int size, int posicion);


/** \brief Publica un producto en la estructura producto
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
  * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 * \return
 *
 */
void publicarProducto(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto);


/** \brief Modifica un producto en la estructura producto
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
  * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 * \return
 *
 */
void modificarProducto(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto);


/** \brief Elimina un producto en la estructura producto
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
  * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 *
 */
void eliminarProducto(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto);


/** \brief Realiza una compra
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
  * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 *
 */
void realizarCompra(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto);


/** \brief Lista las publicaciones de un usuario
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
  * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 *
 */
void listarPublicacionesUsuario(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto);


/** \brief lista las publicaciones de todos los usuarios
 *
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
 * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 *
 */
void listarPublicaciones(usuario arrayUsuario[], producto arrayProducto[], int sizeUsuario, int sizeProducto);


/** \brief Lista las ventas y calificaciones de los usuarios
 * \param usuario arrayUsuario[] Array de estructuras
 * \param producto arrayProducto[] Array de estructuras
 * \param sizeUsuario tamaño del array usuario
 * \param sizeProducto tamaño del array producto
 *
 */
void listarUsuarios(usuario arrayUsuario[], int);
