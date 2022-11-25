/*
 * Generic_Bibliotec.c
 *
 *  Created on: 6 jun. 2021
 *      Author: bripo
 */
#include "Generic_Bibliotec.h"

int getEnteroRango(char *mensaje, char *messageError, int min_range, int max_range)
{
	int valorInt;
	char buffer[30];

	do
	{
	  printf("%s: ", mensaje);
	  fflush(stdin);
	  gets(buffer);

	  while(validarInt(buffer)==0)
	  {
		 printf("%s: ", messageError);
	     fflush(stdin);
	     gets(buffer);
	  }

	        valorInt=atoi(buffer);

	        if(valorInt<min_range||valorInt>max_range)
	        {
	            printf("[ERROR] VALORES ENTRE [%d-%d]\n", min_range, max_range);
	        }

	    }
	    while(valorInt<min_range||valorInt>max_range);

	    return valorInt;
}


int Validate_OnlyNumberInt(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isdigit(pData[i]) == 0) {
				if (i == 0) {
					if (pData[0] != '-') {
						rtn = 0;
						break;
					}
				} else {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyNumberFloat(char *pData)
{
	int countSigno = 0;
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++)
		{

			if (pData[i] == '.' || pData[i] == ',')
			{
				countSigno++;
			}
			else
			{
				if (isdigit(pData[i]) == 0)
				{
					if (i == 0)
					{
						if (pData[0] != '-')
						{
							rtn = 0;
							break;
						}
					}
					else
					{
						rtn = 0;
						break;
					}
				}
			}
		}

		if (countSigno > 1)
		{
			rtn = 0;
		}
	}
	else
	{
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabet(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				rtn = 0;
				break;
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int validate_OnlyAlphabetWithSpaces(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				if (isspace(pData[i]) == 0) {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_Exit_SN(char *MSJ, char *ERROR_MSJ) {
	int rtn = 0;
	char c;

	c = Get_Char(MSJ, ERROR_MSJ);
	c = toupper(c);

	while (c != 'S' && c != 'N') {
		puts("ERROR. OPCION NO VALIDA");
		c = Get_Char(MSJ, ERROR_MSJ);
		c = toupper(c);
	}

	if (c == 'S') {
		rtn = 1;
	}

	return rtn;
}
//*** VALIDACIONES - FIN

//*** GET - INICIO
int Get_Int(char *MSJ, char *ERROR_MSJ) {
	char buffer[TAM_BUFFER];
	int rtn;

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (Validate_OnlyNumberInt(buffer) == 0) {
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atoi(buffer);

	return rtn;
}

int Get_IntRange(char *MSJ, char *ERROR_MSJ, int MIN, int MAX) {
	int rtn = Get_Int(MSJ, ERROR_MSJ);

	while (rtn < MIN || rtn > MAX) {
		printf("ERROR. Fuera de rango -> [MIN]=%d [MAX]=%d.\n", MIN, MAX);
		rtn = Get_Int(MSJ, ERROR_MSJ);
	}

	return rtn;
}

float Get_Float(char *MSJ, char *ERROR_MSJ) {
	char buffer[TAM_BUFFER];
	float rtn;

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (Validate_OnlyNumberFloat(buffer) == 0) {
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atof(buffer);

	return rtn;
}

float Get_FloatRange(char *MSJ, char *ERROR_MSJ, float MIN, float MAX) {
	float rtn = Get_Float(MSJ, ERROR_MSJ);

	while (rtn < MIN || rtn > MAX) {
		printf("ERROR. Fuera de rango -> [MIN]=%.2f [MAX]=%.2f.\n", MIN, MAX);
		rtn = Get_Float(MSJ, ERROR_MSJ);
	}

	return rtn;
}

double Get_Double(char *MSJ, char *ERROR_MSJ) {
	char buffer[TAM_BUFFER];
	double rtn;

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (Validate_OnlyNumberFloat(buffer) == 0) {
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atof(buffer);

	return rtn;
}

double Get_DoubleRange(char *MSJ, char *ERROR_MSJ, double MIN, double MAX) {
	double rtn = Get_Float(MSJ, ERROR_MSJ);

	while (rtn < MIN || rtn > MAX) {
		printf("ERROR. Fuera de rango -> [MIN]=%.2f [MAX]=%.2f.\n", MIN, MAX);
		rtn = Get_Float(MSJ, ERROR_MSJ);
	}

	return rtn;
}

char Get_Char(char *MSJ, char *ERROR_MSJ) {
	char buffer[TAM_BUFFER];
	char rtn;

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > 1 || Validate_OnlyAlphabet(buffer) == 0) {
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = buffer[0];

	return rtn;
}

void Get_String(char *MSJ, char *ERROR_MSJ, char *pString, int TAM) {
	char buffer[TAM_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > TAM || strlen(buffer) == 0) {
		printf("ERROR. Fuera de rango -> CARACTERES [MIN]=1 [MAX]=%d.\n", TAM);
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);
}

void Get_OnlyAlphabetString(char *MSJ, char *ERROR_MSJ, char *pString, int TAM) {
	char buffer[TAM_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > TAM || strlen(buffer) == 0
			|| Validate_OnlyAlphabet(buffer) == 0) {

		if (strlen(buffer) > TAM || strlen(buffer) == 0) {
			printf("ERROR. Fuera de rango -> CARACTERES [MIN]=1 [MAX]=%d.\n",
					TAM);
		} else {
			printf("ERROR. Solo caracteres alfabeticos validos.\n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);
}

void Get_OnlyAlphabetStringWithSpaces(char *MSJ, char *ERROR_MSJ, char *pString,
		int TAM) {
	char buffer[TAM_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > TAM || strlen(buffer) == 0
			|| validate_OnlyAlphabetWithSpaces(buffer) == 0) {

		if (strlen(buffer) > TAM || strlen(buffer) == 0) {
			printf("ERROR. Fuera de rango -> CARACTERES [MIN]=1 [MAX]=%d.\n",
					TAM);
		} else {
			printf("ERROR. Solo caracteres alfabeticos validos.\n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);
}

int validarInt(char *numero)
{
	int i;
	int result;
	int countsign = 0;

	result = 1;

	for (i=0; i<strlen(numero); i++)
	{
		if(numero[i] == '-')
		{
			countsign++;
		}
		else
		 {
			if(!isdigit(numero[i]))
			{
				result = 0;

			}
		 }
	}
	if(countsign > 1)
	  {
		result = 0;
	  }

	return result;
}

int GetStringNumber(char *message, char *messageError, char *string, int TAM)
{
	char buffer[TAM];
	int retorno = 1;

	printf ("%s", message);
	fflush(stdin);
	scanf("%s", string);

		while(validarInt(string) == 0)
		{
			printf ("%s", messageError);
			fflush(stdin);
			scanf("%[^\n]", string);
		}

	strcpy(string, buffer);

	return retorno;
}

