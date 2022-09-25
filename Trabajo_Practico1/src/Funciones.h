/*
 * Funciones.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Cespedes Braian
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define buffer_size 50

/**
 * @fn ShowAssociations()
 * brief => Muestra las confederaciones disponibles
 */
void ShowAssociations();

/***
 * @fn ShowPlayers(int* pArquero, int* pDefensa,  int* pDelantero, int* pMedioCampo)
 * @brief => Muestra la cantidad de jugadores actuales que se encuentran en el sistema
 * @param pArquero => Puntero
 * @param pDefensa => Puntero
 * @param pDelantero => Puntero
 * @param pMedioCampo => Puntero
 */
void ShowPlayers(int* pArquero, int* pDefensa,  int* pDelantero, int* pMedioCampo);

/**
 * @fn void ShowPrices(float* priceHospedaje, float* priceComida, float* priceTransporte)
 * @brief => Muestra la informacion recibida por punteros en consola.
 * @param priceHospedaje => Primer puntero a mostrar.
 * @param priceComida => Segundo puntero a mostrar.
 * @param priceTransporte => Tercer puntero a mostrar.
 *  */
void ShowPrices(float* priceHospedaje, float* priceComida, float* priceTransporte);

/**
 * @fn int ValidateInt(char* stringImput)
 * @brief => Valida que la cadena de caracteres sea numerica entera.
 * @param stringImput => Cadena de caracteres a validar.
 * @return => Devuelve 1 si la cadena es solo numerica y entera, de lo contrario retorna 0.
 */

int ValidateInt(char* stringImput);

/**
 * @fn int GetIntRange(char *mensaje, char *messageError, int min_range, int max_range)
 * @brief --> Permite el ingreso de un numero entero de acuerdo a un rango, valida junto a la funcion ValidateInt
 * y retorna el numero en caso de serlo, retorna 0 si no lo es.
 *
 * @param mensaje => Mensaje al usuario.
 * @param messageError => Mensaje de error.
 * @param min_range => Rango minimo.
 * @param max_range => Rango maximo.
 * @return => Retorna el numero en caso de que pase la validacion, o 0 de lo contrario.
 */

int GetIntRange(char *mensaje, char *messageError, int min_range, int max_range);


/**
 * @fn int GetInt(char* mensaje, char* messageError)
 * @brief => Permite el ingreso de un dato entero, verifica de que sea un numero entero, junto con la funcion ValidarInt y lo retorna.
 * @param mensaje => Mensaje para el usuario.
 * @param messageError => Mensaje en caso de error.
 * @return => Retorna el numero en caso de que pase la validacion.
 */

int GetInt(char* mensaje, char* messageError);

/**
 * @fn int TurnIntoInt(char* stringdata)
 * @brief => Convierte una cadena de texto en entero.
 * @param stringdata => Cadena a convertir.
 * @return => Retorna el valor de la cadena en entero.
 */

int TurnIntoInt(char* stringdata);

/**
 * @fn ParseInt(char* stringData)
 * @brief => Parsea una cadena a entero.
 * @param stringData => Cadena a parsear a entero.
 * @return => Retorna la cadena parseada a entero.
 */

int ParseInt(char stringdata[]);

/***
 * @fn AveragePlayers(int totalPlayers, float totalAsociations)
 * @param totalPlayers => Cantidad de jugadores
 * @param totalAsociations => Cantidad de jugadores por confederacion
 * @return => El porcentaje de jugadores pertenecientes a una confederacion sobre el total de jugadores ingresados
 */

float AveragePlayers(int totalPlayers, float totalAsociations);

/**
 * @fn int ValidateIntRange(char* stringImput, int rangeOptions)
 * @brief => Valida que la cadena ingresada sea entero y este en rango.
 * @param stringImput => Cadena a validar.
 * @param rangeOptions => Rango de opciones.
 * @return => 1 si cumple condicion, de lo contrario 0.
 */
int ValidateIntRange(char* stringImput, int rangeOptions);

/**
 * @fn int ParseInt(char* stringData)
 * @brief => Parsea cadena de caracteres a entero.
 * @param stringData => Cadena a parsear.
 * @return => Cadena ya parseada a entero.
 */
int ParseInt(char* stringData);

/**
 * @fn float GetNum(char* welcomeMessage, char* errorMessage)
 * @brief => Permite el ingreso de datos del usuario, valida que cumpla la condicion que sea numerico.
 * @param welcomeMessage => Mensaje de solicitud al usuario.
 * @param errorMessage => Mensaje en caso de error.
 * @return => Retorna el numero parseado a float del usuario.
 */
float GetNum(char* welcomeMessage, char* errorMessage);

/**
 * @fn int ValidateFloat(char* stringImput)
 * @brief => Permite validar que la cadena ingresada sea flotante.
 * @param stringImput => Cadena a validar.
 * @return => En caso de que sea una cadena de flotantes retorna 1, de lo contrario 0.
 */
int ValidateFloat(char* stringImput);

/**
 * @fn ParseFloat(char* stringImput)
 * @brief => Parsea a flotante la cadena ingresada.
 * @param stringImput => Cadena a parsear.
 * @return => Cadena ya parseada a flotante.
 */
float ParseFloat(char* stringImput);

/***
 * @fn SecondaryMenu(char* message1, char* message2, char* message3, char* message4, float* pHospedaje, float* pComida, float* pTransporte);
 * @brief Reproducde un menu secundario para la carga de precios de las aerolineas.
 * @param message1 => Mensaje a mostrar
 * @param message2 => Mensaje a mostrar
 * @param message3 => Mensaje a mostrar
 * @param message4 => Mensaje a mostrar
 * @param pHospedaje => Puntero
 * @param pComida => Puntero
 * @param pTransporte => Puntero
 */
void SecondaryMenu(char* message1, char* message2, char* message3, char* message4, float* pHospedaje, float* pComida, float* pTransporte);

/***
 * @fn PlayersMenu(char* message1, char* message2, char* message3, char* message4, char* message5, int* pArquero, int* pDefensa, int* pDelantero, int* pMedioCampo,
		 int* pAfc, int* pCaf, int* pConcaf, int* pConmebol, int* pUefa, int* pOFC, int* pJugadores)
 * @brief Menu disponible para la carga de jugadores del plantel
 * @param message1 => Mensaje a mostrar
 * @param message2 => Mensaje a mostrar
 * @param message3 => Mensaje a mostrar
 * @param message4 => Mensaje a mostrar
 * @param message5 => Mensaje a mostrar
 * @param pArquero => Puntero
 * @param pDefensa => Puntero
 * @param pDelantero => Puntero
 * @param pMedioCampo => Puntero
 * @param pAfc => Puntero
 * @param pCaf => Puntero
 * @param pConcaf => Puntero
 * @param pConmebol => Puntero
 * @param pUefa => Puntero
 * @param pOFC => Puntero
 * @param pJugadores => Puntero
 */

void PlayersMenu(char* message1, char* message2, char* message3, char* message4, char* message5, int* pArquero, int* pDefensa, int* pDelantero, int* pMedioCampo,
		 int* pAfc, int* pCaf, int* pConcaf, int* pConmebol, int* pUefa, int* pOFC, int* pJugadores);

/***
 * @fn float TotalMaintenance(float totalComida, float totalHospedaje, float totalTransporte)
 * @brief Calcula y devuelve la suma de los datos ingresados
 * @param totalComida => Flotante a sumar
 * @param totalHospedaje => Flotante a sumar
 * @param totalTransporte => Flotante a sumar
 * @return => Retorna la suma de los parametros ingresados
 */

float TotalMaintenance(float totalComida, float totalHospedaje, float totalTransporte);

/**
 * @fn float TaxesPrice(float imput)
 * @brief => Calcula el interes de un flotante.
 * @param imput => flotante al cual calcularle el interes.
 * @return => Retorna el flotante junto al interes generado.
 */
float TaxesPrice(float imput);

#endif /* FUNCIONES_H_ */
