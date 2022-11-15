#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Controller.h"
#define L 25
#define T 100

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* newJugador;
	char IdAux[L];
	char auxNombreCompleto[T];
	char auxEdad[T];
	char auxPosicion[L];
	char auxNacionalidad[T];
	char auxIdNacionalidad[L];
	int TextLeidos;
	int respuesta = 0;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", IdAux, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxIdNacionalidad);
		while(!feof(pFile))
		{
			TextLeidos = fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", IdAux, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxIdNacionalidad);
			if(TextLeidos == 6)
			{
				newJugador = jug_newParametros(IdAux, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxIdNacionalidad);
				ll_add(pArrayListJugador, newJugador);
				respuesta = 1;
			}
			if(feof(pFile))
			{
				break;
			}
		}
		fclose(pFile);
		controller_listarJugadores(pArrayListJugador);
		respuesta = 1;
	}
	return respuesta;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* newJugador;
	int respuesta = 0;
	int flag;

	if(pFile!= NULL && pArrayListJugador != NULL)
	{
		while(!feof(pFile))
		{
			newJugador = jug_new();
			flag = fread(newJugador, sizeof(Jugador), 1, pFile);

			if(flag == 1)
				ll_add(pArrayListJugador, newJugador);
		}
			respuesta = 1;
			fclose(pFile);
	}
	 return respuesta;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	Seleccion *newSeleccion;
	char IdAux[L];
	char auxPais[T];
	char auxConfederacion[T];
	char auxConvocados[L];
	int TextLeidos;
	int respuesta = 0;

	if (pFile != NULL && pArrayListSeleccion != NULL) {
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", IdAux, auxPais,
				auxConfederacion, auxConvocados);
		while (!feof(pFile)) {
			TextLeidos = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", IdAux,
					auxPais, auxConfederacion, auxConvocados);
			if (TextLeidos == 4) {
				newSeleccion = selec_newParametros(IdAux, auxPais,
						auxConfederacion, auxConvocados);
				ll_add(pArrayListSeleccion, newSeleccion);
				respuesta = 1;
			}
			if (feof(pFile)) {
				break;
			}
		}
		fclose(pFile);
		controller_listarSelecciones(pArrayListSeleccion);
		respuesta = 1;
	}
	return respuesta;
}

