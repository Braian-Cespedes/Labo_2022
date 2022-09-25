#include "Funciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void SecondaryMenu(char* message1, char* message2, char* message3, char* message4, float* pHospedaje, float* pComida, float* pTransporte)
{
	int validatedOption;
	do
	{
		system("cls");
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

		ShowPrices(pHospedaje, pComida, pTransporte);
	    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("%s", message1);
		printf("%s", message2);
		printf("%s", message3);
		printf("%s", message4);

		validatedOption = GetIntRange("\nIngrese una opcion ", "Error!! Reingrese una opcion valida ", 1, 4);

		switch(validatedOption)
		{
			case 1:
				system("cls");

				*pHospedaje = GetInt("Ingrese el precio del hospedaje: ", "ERROR!!! Reingrese el precio del hospedaje: ");
				if(*pHospedaje == 0)
				{
					printf("\nIngreso de 0 detectado, vuelva a subir el dato.\n\n");
					system("pause");
				}
				else
				{
					printf("\nCarga de dato exitosa!\n");
					system("pause");
				}
				break;

			case 2:
				system("cls");

				*pComida = GetInt("Ingrese el precio de la comida: ", "ERROR!!! Reingrese el precio de la comida: ");
				if(*pComida == 0)
				{
					printf("\nIngreso de 0 detectado, vuelva a subir el dato.\n\n");
					system("pause");
				}
				else
				{
					printf("\nCarga de dato exitosa!\n");
					system("pause");
				}
				break;

			case 3:
				system("cls");

				*pTransporte = GetInt("Ingrese el precio del transporte: ", "ERROR!!! Reingrese el precio del transporte: ");
				if(*pTransporte == 0)
				{
					printf("\nIngreso de 0 detectado, vuelva a subir el dato.\n\n");
					system("pause");
				}
				else
				{
					printf("\nCarga de dato exitosa!\n");
					system("pause");
				}
				break;

			case 4:

				printf("\nSaliendo del menu de ingresos.\n\n");
				system("pause");
				break;
		}

	}while(validatedOption != 4);
}

void PlayersMenu(char* message1, char* message2, char* message3, char* message4, char* message5, int* pArquero, int* pDefensa, int* pDelantero, int* pMedioCampo,
				 int* pAfc, int* pCaf, int* pConcaf, int* pConmebol, int* pUefa, int* pOFC, int* pJugadores)
{
	int const maxArq = 2;
	int const maxDef = 8;
	int const maxCampo = 8;
	int const maxDel = 4;
	int option;
	int fLimiteJugadores = 0;
	int confValidada;

		system("cls");
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		ShowPlayers(pArquero, pDefensa, pDelantero, pMedioCampo);
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("%s", message1);
		printf("%s", message2);
		printf("%s", message3);
		printf("%s", message4);
		printf("%s", message5);

		option = GetIntRange("\n\nIngrese la posicion del jugador ", "\nError Reingrese la posicion del jugador ", 1, 5);

		switch(option)
		{
			case 1:
				if(*pArquero < maxArq)
					*pArquero = *pArquero + 1;
				else
				{
					printf("La posicion Arquero se encuentra con el maximo de jugadores disponibles (%d)\n", *pArquero);
					fLimiteJugadores = 1;
					system("pause");
					system("cls");
				}
				break;

			case 2:
				if(*pDefensa < maxDef)
					*pDefensa = *pDefensa + 1;
				else
				{
					printf("La posicion Defensor se encuentra con el maximo de jugadores disponibles (%d)\n", *pDefensa);
					fLimiteJugadores = 1;
					system("pause");
					system("cls");
				}
				break;

			case 3:
				if(*pDelantero < maxDel)
					*pDelantero = *pDelantero + 1;
				else
				{
					printf("La posicion Delantero se encuentra con el maximo de jugadores disponibles (%d)\n", *pDelantero);
					fLimiteJugadores = 1;
					system("pause");
					system("cls");
				}
				break;

			case 4:
				if(*pMedioCampo < maxCampo)
					*pMedioCampo = *pMedioCampo + 1;
				else
				{
					printf("La posicion Medio Campista se encuentra con el maximo de jugadores disponibles (%d)\n", *pMedioCampo);
					fLimiteJugadores = 1;
					system("pause");
					system("cls");
				}
				break;

			case 5:
				printf("\nSaliendo del menu de ingresos.\n\n");
				fLimiteJugadores = 1;
				break;
		}

	if(fLimiteJugadores != 1)
	{
		GetIntRange("\n\nIngrese la camiseta del jugador ", "\nError Reingrese la camiseta del jugador ", 1, 22);

		system("cls");
		ShowAssociations();

		confValidada = GetIntRange("\nIngrese la confederacion del jugador ", "\nError Reingrese la confederacion del jugador" , 1, 6);

		switch(confValidada)
		{
			case 1:
				*pAfc = *pAfc + 1;
				break;

			case 2:
				*pCaf = *pCaf + 1;
				break;

			case 3:
				*pConcaf = *pConcaf + 1;
				break;

			case 4:
				*pConmebol = *pConmebol + 1;
				break;

			case 5:
				*pUefa = *pUefa + 1;
				break;

			case 6:
				*pOFC = *pOFC + 1;
				break;
		}
		printf("Jugador cargado con exito!!!!\n\n");
		*pJugadores = *pJugadores + 1;
	}
	else
	{
		fLimiteJugadores = 0;
	}
}

void ShowPrices(float* priceHospedaje, float* priceComida,  float* priceTransporte)
{
	printf("\t Costos de hospedaje = $%.2f\n", *priceHospedaje);
	printf("\t Costos de comida = $%.2f\n", *priceComida);
	printf("\t Costos de transporte = $%.2f\n", *priceTransporte);
}

void ShowPlayers(int* pArquero, int* pDefensa,  int* pDelantero, int* pMedioCampo)
{
	printf("\t Arqueros = %d\n", *pArquero);
	printf("\t Defensores = %d\n", *pDefensa);
	printf("\t Delanteros = %d\n", *pDelantero);
	printf("\t Medio Campistas = %d\n", *pMedioCampo);
}

void ShowAssociations()
{
	printf("\n1)Confederacion Asiatica de Futbol (AFC)\n");
	printf("2)Confederacion Africana de Futbol (CAF)\n");
	printf("3)Confederacion de Norteamerica, Centroamerica y el Caribe de Futbol (CONCACAF)\n");
	printf("4)Confederacion Sudamericana de Futbol (CONMEBOL)\n");
	printf("5)Unión de Federaciones Europeas de Futbol (UEFA)\n");
	printf("6)Confederacion de Futbol de Oceania (OFC)\n\n");
}

int ImputValidate(char* stringImput, int rangeOptions)
{
	while(ValidateInt(stringImput) == 0 || ValidateIntRange(stringImput, rangeOptions) == 0)
		{
			printf("\nError, reingrese una opcion correcta: ");
			scanf("%s", stringImput);
		}
	return ParseInt(stringImput);
}

int GetInt(char mensaje[], char messageError[])
{
	char aux[20];
	int auxInt;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);

	while(ValidateInt(aux) == 0)
			{
				printf ("%s", messageError);
				fflush(stdin);
				scanf("%[^\n]", aux);
			}

	auxInt = TurnIntoInt(aux);

	return auxInt;
}

int GetIntRange(char *mensaje, char *messageError, int min_range, int max_range)
{
	int valorInt;
	char buffer[30];

	do
	{
	  printf("%s: ", mensaje);
	  fflush(stdin);
	  gets(buffer);

	  while(ValidateInt(buffer)==0)
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

int ValidateInt(char* stringImput)
{
	int isInt = 1;

	for(int i=0; i < strlen(stringImput); i++)
	{
		if(!isdigit(stringImput[i]))
			{
				isInt = 0;
				break;
			}
	}
	return isInt;
}

int ValidateIntRange(char* stringImput, int rangeOptions)
{
	int isOk = 0;

	if(ParseInt(stringImput) < rangeOptions && ValidateInt(stringImput) != 0)
	{
		isOk = 1;
	}
	return isOk;
}

int ParseInt(char* stringData)
{
	return atoi(stringData);
}

int ValidarInt(char cadenaValidar[])
{
	int esInt = 1;

	for(int i=0; i < strlen(cadenaValidar); i++)
	{
		if(!isdigit(cadenaValidar[i]))
			{
				esInt = 0;
				break;
			}
	}
	return esInt;
}

int ValidateFloat(char* stringImput)
{
	int i;
	int countsign = 0;
	int response;
	response = 1;

	for(i=0; i<strlen(stringImput); i++)
	{
		if(stringImput[i] == '.' || stringImput[i] == ',')
		{
			countsign++;
		}
		else
		{
			if(isdigit(stringImput[i]) == 0)
			{
				response = 0;
				break;
			}
		}
	}
	if(countsign > 1)
	{
		response = 0;
	}
	return response;
}


float ParseFloat(char* stringImput)
{
	return atof(stringImput);
}

int TurnIntoInt(char stringdata[])
{
	int IntNumber;

	IntNumber = atoi(stringdata);

	return IntNumber;
}


float AveragePlayers(int totalPlayers, float totalAsociations)
{
	return (totalAsociations * 100) / totalPlayers;
}


float TotalMaintenance(float totalComida, float totalHospedaje, float totalTransporte)
{
	return  totalComida + totalHospedaje + totalTransporte;
}


float TaxesPrice(float imput)
{
	return imput + imput * (0.35);
}
