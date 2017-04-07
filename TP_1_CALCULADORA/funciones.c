#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Suma 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a sumar
 * @param segundoOperando El segundo numero a sumar
 * @return El resultado de la suma
 */
float suma(float primerOperando, float segundoOperando){
    float total=primerOperando+segundoOperando;
    return total;
}
/**
 * @brief Resta 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a restar
 * @param segundoOperando El segundo numero a restar
 * @return El resultado de la resta
 */
float diferencia(float primerOperando, float segundoOperando){
    float total=primerOperando-segundoOperando;
    return total;
}
/**
 * @brief Multiplica 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a multiplicar
 * @param segundoOperando El segundo numero a multiplicar
 * @return El resultado de la suma
 */
float producto(float primerOperando, float segundoOperando){
    float total=primerOperando*segundoOperando;
    return total;
}
/**
 * @brief Divide 2 operandos y devuelve el resultado
 * @param primerOperando El primer numero a sumar
 * @param segundoOperando El segundo numero a sumar
 * @param mensaje Mensaje mostrado en pantalla con el resultado
 * @param mensajeError Mensaje mostrado en pantalla al dividir por cer0
 */
void cociente(float primerOperando, float segundoOperando, char mensaje[], char mensajeError[]){
    if(segundoOperando==0){
        printf("%s", mensajeError);
        return;
    }
    float total=primerOperando/segundoOperando;
    printf("%s %.2f\n", mensaje, total);
}
/**
 * @brief Hace el factorial del numero ingresado
 * @param operando El numero a sacar el factorial
 * @param mensaje Mensaje mostrado en pantalla con el resultado
 * @param mensajeError Mensaje mostrado en pantalla al ingresar un valor negativo
 */
void factorial(float operando, char mensaje [], char mensajeError []){
    if(operando<0){
        printf("%s %.0f", mensajeError, operando);
        return;
    }
    else if(operando==1 || operando==0){
        printf("%s %i", mensaje, 1);
        return;
    }
    int total=operando;
    while(operando>1){
        operando--;
        total=total*operando;
    }
    printf("%s %i", mensaje, total);
    return;
}

