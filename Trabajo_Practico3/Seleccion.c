#include "Seleccion.h"
#include "LinkedList.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Seleccion* selec_new()
{
	Seleccion* pSeleccionList;

	return pSeleccionList = (Seleccion*)malloc(sizeof(Seleccion));
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* pSeleccion;

	pSeleccion = selec_new();

	if(pSeleccion != NULL)
	{
		selec_setId(pSeleccion, atoi(idStr));
		selec_setPais(pSeleccion, paisStr);
		selec_setConfederacion(pSeleccion, confederacionStr);
		selec_setConvocados(pSeleccion, atoi(convocadosStr));
	}

	return pSeleccion;
}

int selec_setId(Seleccion* thisSeleccion,int id)
{
	int responseSetId = 0;

	if(thisSeleccion != NULL && id > 0)
	{
		thisSeleccion->id = id;
		responseSetId = 1;
	}

	return responseSetId;
}

int selec_getId(Seleccion* thisSeleccion,int* id)
{
	int responseGetId = 0;

	if(thisSeleccion != NULL && id != NULL)
	{
		*id = thisSeleccion->id;
		responseGetId = 1;
	}

	return responseGetId;
}



int selec_setPais(Seleccion* thisSeleccion,char* pais)
{
	int responseSetPais = 0;

	if(thisSeleccion != NULL && pais != NULL)
	{
		strcpy(thisSeleccion->pais, pais);
		responseSetPais = 1;
	}

	return responseSetPais;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int responseGetPais = 0;

	if(this != NULL && this != NULL)
	{
		strcpy(pais, this->pais);
		responseGetPais = 1;
	}
	return responseGetPais;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int responseGetSeleccion = 0;

	if(this != NULL && confederacion != NULL)
	{
		strcpy(confederacion, this->confederacion);
		responseGetSeleccion = 1;
	}
	return responseGetSeleccion;
}

int selec_setConfederacion(Seleccion* thisSeleccion,char* confederacion)
{
	int responseSetConfederacion = 0;

	if(thisSeleccion != NULL && confederacion != NULL)
	{
		strcpy(thisSeleccion->confederacion, confederacion);
		responseSetConfederacion = 1;
	}

	return responseSetConfederacion;
}

int selec_setConvocados(Seleccion* thisSeleccion,int convocados)
{
	int responseSetConvocados = 0;

	if(thisSeleccion != NULL)
	{
		thisSeleccion->convocados = convocados;
		responseSetConvocados = 1;
	}

	return responseSetConvocados;
}

int selec_getConvocados(Seleccion* thisSeleccion,int* convocados)
{
	int responseGetConvocados = 0;

	if(thisSeleccion != NULL && convocados != NULL)
	{
		*convocados = thisSeleccion->convocados;
		responseGetConvocados = 1;
	}

	return responseGetConvocados;
}

int selec_compararConfederacion(void* seleccion1, void* seleccion2)
{
    Seleccion* auxSeleccion1;
    Seleccion* auxSeleccion2;
    char auxConfederacion1[30];
    char auxConfederacion2[30];

    auxSeleccion1 = (Seleccion*)seleccion1;
    auxSeleccion2 = (Seleccion*)seleccion2;

    selec_getConfederacion(auxSeleccion1, auxConfederacion1);
    selec_getConfederacion(auxSeleccion2, auxConfederacion2);

    return strcmp(auxConfederacion1, auxConfederacion2);
}

int selec_buscarIdSeleccion(LinkedList* pArrayListSeleccion, int auxId)
{
    Seleccion* auxSeleccion;

    int index=-1;
    int idSeleccion;
    int length;
    int i;

    length=ll_len(pArrayListSeleccion);

    for(i=0; i<length; i++)
    {
    	auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
    	idSeleccion = auxSeleccion->id;
        selec_getId(auxSeleccion, &idSeleccion);

       if(auxId==idSeleccion)
       {
            index=i;
            break;
       }
    }
    return index;
}

int selec_setSeleccionConvocados(Seleccion* thisSeleccion, int opcion)
{
	int responseSetConvocados = 0;

	if(opcion == 1)
	{
		if(thisSeleccion != NULL && thisSeleccion->convocados < 22)
		{
			thisSeleccion->convocados += 1;
			responseSetConvocados = 1;
		}
	}
	else
	{
		if(thisSeleccion != NULL && thisSeleccion->convocados > 0)
		{
			thisSeleccion->convocados -= 1;
			responseSetConvocados = -1;
		}
	}

	return responseSetConvocados;
}
