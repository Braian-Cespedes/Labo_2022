#include "Jugador.h"
#include "LinkedList.h"
#include "Seleccion.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Jugador* jug_new()
{
	Jugador* pJugadoresList;

	return pJugadoresList = (Jugador*)malloc(sizeof(Jugador));
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* pJugador;

	pJugador = jug_new();

	if(pJugador != NULL)
	{
		jug_setId(pJugador, atoi(idStr));
		jug_setNombreCompleto(pJugador, nombreCompletoStr);
		jug_setPosicion(pJugador, posicionStr);
		jug_setEdad(pJugador, atoi(edadStr));
		jug_setNacionalidad(pJugador, nacionalidadStr);

		jug_setIdSeleccion(pJugador, atoi(idSelccionStr));
	}

	return pJugador;
}

int jug_setId(Jugador* thisJugador,int id)
{
	int responseSetId = 0;

	if(thisJugador != NULL && id > 0)
	{
		thisJugador->id = id;
		responseSetId = 1;
	}

	return responseSetId;
}

int jug_getId(Jugador* thisJugador,int* id)
{
	int responseGetId = 0;

	if(thisJugador != NULL && id != NULL)
	{
		*id = thisJugador->id;
		responseGetId = 1;
	}

	return responseGetId;
}

int jug_setEdad(Jugador* thisJugador,int edad)
{
	int responseSetEdad = 0;

	if(thisJugador != NULL && edad > 0)
	{
		thisJugador->edad = edad;
		responseSetEdad = 1;
	}

	return responseSetEdad;
}

int jug_getEdad(Jugador* thisJugador,int* edad)
{
	int responseGetEdad = 0;

	if(thisJugador != NULL && edad != NULL)
	{
		*edad = thisJugador->edad;
		responseGetEdad = 1;
	}

	return responseGetEdad;
}

int jug_setNombreCompleto(Jugador* thisJugador,char* nombreCompleto)
{
	int responseSetNombre = 0;

	if(thisJugador != NULL && nombreCompleto != NULL)
	{
		strcpy(thisJugador->nombreCompleto, nombreCompleto);
		responseSetNombre = 1;
	}

	return responseSetNombre;
}

int jug_getNombreCompleto(Jugador* thisJugador,char* nombreCompleto)
{
	int responseGetNombre = 0;

	if(thisJugador != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto, thisJugador->nombreCompleto);
		responseGetNombre = 1;
	}
	return responseGetNombre;
}

int jug_setPosicion(Jugador* thisJugador,char* posicion)
{
	int responseSetPosicion = 0;

	if(thisJugador != NULL && posicion != NULL)
	{
		strcpy(thisJugador->posicion, posicion);
		responseSetPosicion = 1;
	}

	return responseSetPosicion;
}

int jug_getPosicion(Jugador* thisJugador,char* nombrePosicion)
{
	int responseSetPosicion = 0;

	if(thisJugador != NULL && nombrePosicion != NULL)
	{
		strcpy(nombrePosicion, thisJugador->posicion);
		responseSetPosicion = 1;
	}
	return responseSetPosicion;
}

int jug_setNacionalidad(Jugador* thisJugador,char* nacionalidad)
{
	int responseSetNacionalidad = 0;

	if(thisJugador != NULL && nacionalidad != NULL)
	{
		strcpy(thisJugador->nacionalidad, nacionalidad);
		responseSetNacionalidad = 1;
	}

	return responseSetNacionalidad;
}

int jug_getNacionalidad(Jugador* thisJugador,char* nacionalidad)
{
	int responseGetNacionalidad = 0;

	if(thisJugador != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad, thisJugador->nacionalidad);
		responseGetNacionalidad = 1;
	}
	return responseGetNacionalidad;
}

int jug_setIdSeleccion(Jugador* thisJugador, int id)
{
	int responseSetId = 0;

	if(thisJugador != NULL)
	{
		thisJugador->idSeleccion = id;
		responseSetId = 1;
	}

	return responseSetId;
}

int jug_getIdSeleccion(Jugador* thisJugador,int* id)
{
	int responseGetId = 0;

	if(thisJugador != NULL && id != NULL)
	{
		*id = thisJugador->idSeleccion;
		responseGetId = 1;
	}

	return responseGetId;

}

int jug_buscarIdJugador(LinkedList* pArrayListJugador, int auxId)
{
    Jugador* auxJugador;

    int index=-1;
    int idJugador;
    int length;
    int i;

    length=ll_len(pArrayListJugador);

    for(i=0; i<length; i++)
    {
    	auxJugador = (Jugador*)ll_get(pArrayListJugador, i);
    	idJugador = auxJugador->id;
        jug_getId(auxJugador, &idJugador);

       if(auxId==idJugador)
       {
            index=i;
            break;
       }
    }
    return index;
}

int jug_compararNombre(void* jugador1, void* jugador2)
{
    Jugador* auxJugador;
    Jugador* auxJugador2;
    char auxNombre1[30];
    char auxNombre2[30];

    auxJugador = (Jugador*)jugador1;
    auxJugador2 = (Jugador*)jugador2;

    jug_getNombreCompleto(auxJugador, auxNombre1);
    jug_getNombreCompleto(auxJugador2, auxNombre2);

    return strcmp(auxNombre1, auxNombre2);
}

int jug_compararEdad(void* jugador1, void* jugador2)
{
	Jugador* jugador;
	Jugador* otroJugador;
    int auxedad1;
    int auxedad2;
    int compare = 0;

    jugador = (Jugador*)jugador1;
    otroJugador = (Jugador*)jugador2;

    jug_getEdad(jugador, &auxedad1);
    jug_getEdad(otroJugador, &auxedad2);

    if(auxedad1>auxedad2)
    {
        compare=1;
    }
    else
    {
    	if(auxedad1<auxedad2)
    	{
    	    compare=-1;
    	}
    }

    return compare;
}

int jug_compararNacionalidad(void* jugador1, void* jugador2)
{
    Jugador* auxJugador;
    Jugador* auxJugador2;
    char auxNacionalidad[30];
    char auxNacionalidad2[30];

    auxJugador = (Jugador*)jugador1;
    auxJugador2 = (Jugador*)jugador2;

    jug_getNacionalidad(auxJugador, auxNacionalidad);
    jug_getNacionalidad(auxJugador2, auxNacionalidad2);

    return strcmp(auxNacionalidad, auxNacionalidad2);
}


