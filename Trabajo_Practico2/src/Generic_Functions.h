
#ifndef GENERIC_FUNCTIONS_H_
#define GENERIC_FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define L 25 // Tamanio cadena de caracteres


//OBTENCION DATOS
/**
 * @fn void GetStrings(char[], char[], int)
 * @brief --> Permite el ingreso de una cadena de caracteres guardando el dato.
 *
 * @param message --> Mensaje.
 * @param aux --> Array donde se guarda el dato;
 * @param tam --> Tamanio del array.
 */
void getStrings(char message[], char aux[], int tam);

/**
 * @fn int GetInt(char[], char[])
 * @brief --> Permite el ingreso de un dato entero, verifica de que sea un numero entero, junto con la funcion ValidarInt y lo retorna.
 *
 * @param mensaje --> Mensaje para el usuario.
 * @param messageError --> Mensaje en caso de error.
 * @return --> Retorna el numero en caso de que pase la validacion.
 */
int getInt(char mensaje[], char messageError[]);

/**
 * @fn int GetIntRange(char[], char[], int, int)
 * @brief --> Permite el ingreso de un numero entero de acuerdo a un rango, valida junto a la funcion ValidarInt
 * y retorna el numero en caso de serlo, retorna 0 si no lo es.
 *
 * @param mensaje --> Mensaje al usuario.
 * @param messageError --> Mensaje de error.
 * @param min_range --> Rango minimo.
 * @param max_range --> Rango maximo.
 * @return --> Retorna el numero en caso de que pase la validacion, o 0 de lo contrario.
 */
int getEnteroRango(char *mensaje, char *messageError, int min_range, int max_range);

/**
 * @fn float GetFloat(char[], char[])
 * @brief --> Permite el ingreso de un numero flotante de acuerdo a un rango, valida junto a la funcion ValidarFloat
 * y retorna el numero en caso de serlo, retorna 0 si no lo es.
 *
 * @param mensaje --> Mensaje al usuario.
 * @param messageError --> Mensaje de error.
 * @return --> Retorna el numero en caso de que pase la validacion, o 0 de lo contrario.
 */
float getFlotante(char mensaje[], char messageError[]);

/**
 * @fn char getChar(char[], char[])
 * @brief Verifica que el caracter ingresado sea s o n, si es cualquiera de ambos casos
 * retorna dicho caracter, de lo contrario retorna un error.
 *
 * @param mensaje --> Mensaje al usuario.
 * @param messageError --> Mensaje de error
 * @return --> Caracter s o n.
 */
char getCaracter(char mensaje[], char messageError[]);

/**
 * @fn void Get_OnlyAlphabetStringWithSpaces(char[], char[], char[], int)
 * @brief --> Permite el ingreso de un array de caracteres con espacios, valida que contenga espacios con
 * Validate_OnlyAlphabetWithSpaces y retorna el array cargandolo de manera referencial a la variable aux.
 *
 * @param MSJ --> Mensaje al usuario.
 * @param ERROR_MSJ --> Mensaje de error.
 * @param aux --> Array listo para ser cargado.
 * @param TAM --> Tamanio del array.
 */
void get_StringConEspacios(char MSJ[], char ERROR_MSJ[], char aux[], int TAM);

/**
 * @fn int eGen_ObtenerID(int)
 * @brief --> Genera un id incremental de acuerdo a un punto donde se quiere que comienze.
 *
 * @param Gen_idIncremental --> Punto donde se quiere comenzar a incrementar el id.
 * @return --> retorno del id incrementado.
 */
int eGen_ObtenerID(int Gen_idIncremental);


/**
 * @fn float TurnIntoFloat(char[])
 * @brief --> Transforma el array que recibe en numero flotante.
 *
 * @param stringdata --> Array a transfrormar.
 * @return --> Flotante ya modificado.
 */
float turnIntoFloat(char stringdata[]);


/**
 * @fn int TurnIntoInt(char[])
 * @brief --> Transforma el array que recibe en numero entero.
 *
 * @param stringdata --> Array a transfrormar.
 * @return --> Entero ya modificado.
 */
int turnIntoInt(char stringdata[]);

//VALIDACIONES
/**
 * @fn int Validate_OnlyAlphabetWithSpaces(char[])
 * @brief  --> Valida que la cadena ingresada presente espacios, si contiene algun espacio retorna 1, en caso contrario 0.
 *
 * @param aux --> Cadena a verificar
 * @return --> Retorno de espacios presentes 1, de lo contrario es 0.
 */


/**
 * @fn int ValidarFloat(char[])
 * @brief --> Valida que el dato sea flotante, si lo es retorna 1, en caso contrario 0.
 *
 * @param validfloat --> Dato a verificar.
 * @return --> Retorno de numero flotante es 1, de lo contrario es 0.
 */
int validarFloat(char validfloat[]);

/**
 * @fn char Validarchar(char)
 * @brief --> Valida que el dato ingresado sea caracter, si lo es retorna 1, en caso contrario 0.
 *
 * @param caracter --> Dato a verificar.
 * @return --> Retorno de caracter es 1, de lo contrario es 0.
 */
char validarchar(char caracter);

/**
 * @fn int ValidarInt(char[])
 * @brief --> Valida que el dato ingresado sea un entero, si lo es retorna 1, en caso contrario 0.
 *
 * @param numero --> Dato a verificar.
 * @return --> Retorno de entero es 1, de lo contrario es 0.
 */
int validarInt(char numero[]);

/**
 * int validarNumero(char* numero)
 *
 * @param numero // Valida que la cadena ingresada sea numerica.
 * @return // Retorna el numero entero en caso de serlo de lo contrario retorna -1.
 */
int validarNumero(char* numero);

/**
 * int validarNumeroExcluyeSignos(char* numero)
 *
 * @param numero // Valida que un numero sea positivo.
 * @return // Retorna el numero entre en case de serlo de lo contrario retorna -1.
 */
int validarNumeroExcluyeSignos(char* numero);

int validate_OnlyAlphabetWithSpaces(char aux[]);


#endif /* GENERIC_FUNCTIONS_H_ */


