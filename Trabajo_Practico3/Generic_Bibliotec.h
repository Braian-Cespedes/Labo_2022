/*
 * Generic_Bibliotec.h
 *
 *  Created on: 6 jun. 2021
 *      Author: bripo
 */

#ifndef GENERIC_BIBLIOTEC_H_
#define GENERIC_BIBLIOTEC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_BUFFER 1000

//VALIDACIONES
int Validate_OnlyNumberInt(char *buffer);
int Validate_OnlyNumberFloat(char *buffer);
int Validate_OnlyAlphabet(char *buffer);
int Validate_OnlyAlphabetWithSpaces(char *buffer);
int Validate_Exit_SN(char *MSJ, char *ERROR_MSJ);
int ValidarInt(char *numero);

//GET
int Get_Int(char *MSJ, char *ERROR_MSJ);
int Get_IntRange(char *MSJ, char *ERROR_MSJ, int MIN, int MAX);
float Get_Float(char *MSJ, char *ERROR_MSJ);
float Get_FloatRange(char *MSJ, char *ERROR_MSJ, float MIN, float MAX);

char Get_Char(char *MSJ, char *ERROR_MSJ);
void Get_String(char *MSJ, char *ERROR_MSJ, char *pString, int TAM);
int GetStringNumber(char *message, char *messageError, char *string, int TAM);
void Get_OnlyAlphabetString(char *MSJ, char *ERROR_MSJ, char *pString, int TAM);
void Get_OnlyAlphabetStringWithSpaces(char *MSJ, char *ERROR_MSJ, char *pString, int TAM);
int GetEnteroRango(char *mensaje, char *messageError, int min_range, int max_range);

#endif /* GENERIC_BIBLIOTEC_H_ */
