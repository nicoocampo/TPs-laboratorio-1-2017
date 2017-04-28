#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {
    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;
/**
 * @brief Comprueba si se ingreso numeros en una cadena
 * @param  aux[] Cadena a revisar
 * @return 0 si contiene caracteres, 1 si contiene solo numeros
 */
int isnumber(char aux[]);
/**
 * @brief Recorre el array y busca el dni pasado por parametro.
 *
 * @param array array de estructuras que se pasa como parametro.
 * @param size el largo del array de estructuras
 * @param dni el dni a ser buscado en el array.
 * @return 1 si no lo encontro, 0 si lo encontro.
 */
int dniRepetido(EPersona array[], int, int);
/**
 * @brief Cuenta los rango de edades
 *
 * @param array el array de estructuras que se pasa como parametro.
 * @param opciones parametro que se utiliza para seleccionar que rango de edades a contar.
 * @return La cantidad de edades para el rango seleccionado.
 */
int conteoEdades(EPersona array[], int, int);
/**
 * @brief Da de baja a una persona del array de estructuras.
 *
 * @param array el array de estructuras a recorrer.
 * @param size tamaño del array.
 */
void eliminarPersonaEstructura(EPersona array[], int);
/**
 * Da de alta a un empleado del array de estructuras.
 * @param array el array de estructuras a recorrer.
 * @param size tamaño del array.
 */
void cargaDatosEstructura(EPersona array[],int);
/**
 * @brief Ordena la cadena de estructuras por nombre.
 *
 * \param array La cadena de estructuras a ordenar
 * \param size Tamaño del array de estructuras
 */
void ordenarEstructurNombre(EPersona array[], int);
/**
 * @brief Muestra en pantalla el array de estructuras.
 *
 * @param array La cadena de estructuras a mostrar en pantalla
 * @param size El largo de la cadena de estructuras
 */
void mostrar(EPersona array[], int);
/**
 * Grafica con '*' las edades
 * @param array La cadena de estructuras
 * @param size El largo de la cadena de estructuras.
 */
void graficoEdades(EPersona array[], int);
#endif // FUNCIONES_H_INCLUDED
