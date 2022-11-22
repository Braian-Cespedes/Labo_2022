#include "Generic_Functions.h"

void getStrings(char message[], char aux[], int tam)
{
	char buffer[tam];

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", buffer);

	strcpy(aux, buffer);
}


int getInt(char mensaje[], char messageError[])
{
	char aux[L];
	int auxInt;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);

	while(validarInt(aux) == 0)
			{
				printf ("%s", messageError);
				fflush(stdin);
				scanf("%[^\n]", aux);
			}

	auxInt = turnIntoInt(aux);

	return auxInt;
}


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


float getFlotante(char mensaje[], char messageError[])
{
	float valorFlotante;
	    char buffer[30];

	    do
	    {
	        printf("%s: ", mensaje);
	        fflush(stdin);
	        gets(buffer);

	        while(validarNumeroExcluyeSignos(buffer)==1)
	        {
		        printf("%s: ", messageError);
	            fflush(stdin);
	            gets(buffer);
	            system("cls");
	        }

	        valorFlotante=atof(buffer);

	        if(valorFlotante<0)
	        {
	            puts("[ERROR] VALOR SOLO POSITIVO\n");
	            system("pause");
	            system("cls");
	        }

	    }
	    while(valorFlotante<0);

	    return valorFlotante;
}

int validarNumeroExcluyeSignos(char* numero)
{
    int i=0, retornoValidacion=0, j;

    j=strlen(numero);
    while (i<j && retornoValidacion==0)
    {
        if (isdigit(numero[i])!=0||numero[i]=='.'||numero[i]==','||numero[i]=='-')
        {
            i++;
        }
        else
        {
            retornoValidacion=1;
        }
    }
    return retornoValidacion;
}

int validarNumero(char* numero)
{
    int i=0, retornoValidacion=0, j;

    j=strlen(numero);
    while (i<j && retornoValidacion==0)
    {
        if (isdigit(numero[i])!=0)
        {
            i++;
        }
        else
        {
            retornoValidacion=1;
        }
    }
    return retornoValidacion;
}


char getCaracter(char mensaje[], char messageError[])
{
	char aux;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &aux);

	while((validarchar(aux) == 0) && (aux != 's' || aux != 'n'))
	{
		printf("%s", messageError);
		fflush(stdin);
		scanf("%c", &aux);
	}

	return aux;
}

void get_StringConEspacios(char MSJ[], char ERROR_MSJ[], char aux[], int TAM)
{
	char buffer[L];

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

	strcpy(aux, buffer);
}

int eGen_ObtenerID(int Gen_idIncremental)
{
	return Gen_idIncremental += 1;
}


//---------------------------------------------------------------------------------VALIDACIONES--------------------------------------------------------------------------------------------//

int validarInt(char numero[])
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

char validarchar(char caracter)
{
	char aux = 0;

	if(isalpha(caracter) != 0)

	{
		aux = caracter;
	}
	return aux;
}

int validarFloat(char validfloat[])
{
	int i;
	int countsign = 0;
	int response;
	response = 1;

	for(i=0; i<strlen(validfloat); i++)
	{
		if(validfloat[i] == '.' || validfloat[i] == ',')
		{
			countsign++;
		}
		else
		{
			if(isdigit(validfloat[i]) == 0)
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

int validate_OnlyAlphabetWithSpaces(char aux[])
{
	int rtn = 1;

	if (strlen(aux) > 0)
	{
		for (int i = 0; i < strlen(aux); i++)
		{
			if (isalpha(aux[i]) == 0) {
				if (isspace(aux[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}
	else
		{
			rtn = 0;
		}

	return rtn;
}

//---------------------------------------------------------------------------------CONVERSION DATOS--------------------------------------------------------------------------------------------//

float turnIntoFloat(char stringdata[])
{
	float FloatNumber;

		FloatNumber = atof(stringdata);

		return FloatNumber;
}


int turnIntoInt(char stringdata[])
{
	int IntNumber;

	IntNumber = atoi(stringdata);

	return IntNumber;
}
