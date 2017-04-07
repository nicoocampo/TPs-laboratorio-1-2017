#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/**
 * @brief Suma 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a sumar
 * @param segundoOperando El segundo numero a sumar
 * @return El resultado de la suma
 */
float suma(float, float);
/**
 * @brief Resta 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a restar
 * @param segundoOperando El segundo numero a restar
 * @return El resultado de la resta
 */
float diferencia(float, float);
/**
 * @brief Multiplica 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a multiplicar
 * @param segundoOperando El segundo numero a multiplicar
 * @return El resultado de la suma
 */
float producto(float, float);
/**
 * @brief Divide 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a sumar
 * @param segundoOperando El segundo numero a sumar
 * @param mensaje Mensaje mostrado en pantalla con el resultado
 * @param mensajeError Mensaje mostrado en pantalla al dividir por cer0
 */
void cociente(float, float, char [], char []);
/**
 * @brief Hace el factorial del numero ingresado
 * @param operando El numero a sacar el factorial
 * @param mensaje Mensaje mostrado en pantalla con el resultado
 * @param mensajeError Mensaje mostrado en pantalla al ingresar un valor negativo
 */
void factorial(float, char [], char []);
#endif // FUNCIONES_H_INCLUDED
