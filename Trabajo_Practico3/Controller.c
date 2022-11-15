#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "Generic_Bibliotec.h"
#include "Controller.h"
#define L 30
#define T 100


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* pArchivo;
	int response = 0;

	pArchivo = (FILE*)malloc(sizeof(FILE));

	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path, "r");

		if(pArchivo != NULL)
		{
			response = parser_JugadorFromText(pArchivo, pArrayListJugador);
		}
	}

	return response;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int response = 0;

	FILE* pArchivo;

	pArchivo = (FILE*)malloc(sizeof(FILE));

	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path, "rb");

		if(pArchivo != NULL)
			response = parser_JugadorFromBinary(pArchivo, pArrayListJugador);
		else
			pArchivo = fopen(path, "wb");
	}

	return response;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	Jugador* newJugador;
	char idIngresado[L];
	char nombreIngresado[T];
	char posicion[L];
	char nacionalidad[L];
	char idSeleccion[L];
	char arrayEdad[L];
	int edad;

	int response = 0;
	int newId;
	int lengt;

	lengt = ll_len(pArrayListJugador);

	if(pArrayListJugador != NULL)
	{
		newJugador = jug_new();

		if(newJugador != NULL)
		{
			Get_OnlyAlphabetString("\nIngrese el nombre completo del jugador: ", "\nNombre invalido, reingrese: ", nombreIngresado, T);
			edad = GetEnteroRango("\nIngrese la edad del jugador: ", "\nEdad invalida, reingrese: ", 18, 50);
			Get_OnlyAlphabetString("\nIngrese la posicion del jugador: ", "\n Posicion invalida, reingrese: ", posicion, T);
			Get_OnlyAlphabetString("\nIngrese la nacionalidad del jugador: ", "\n Nacionalidad invalida, reingrese: ", nacionalidad, T);
			newId = lengt + 1;
			sprintf(idIngresado, "%d", newId);
			sprintf(idSeleccion, "%d", 0);
			sprintf(arrayEdad, "%d", edad);

			newJugador = jug_newParametros(idIngresado, nombreIngresado, arrayEdad, posicion, nacionalidad, idSeleccion);
			ll_add(pArrayListJugador, newJugador);

			printf("\nDatos del jugador cargados con exito!!!\n\n");
			response = 1;
		}
	}
	return response;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	Jugador *aJugador;
	char auxNombre[T];
	char auxPosicion[L];
	char auxNacionalidad[L];
	int auxEdad;
	int opcion;
	int auxId;
	int index;

	if (pArrayListJugador != NULL) {
		controller_listarJugadores(pArrayListJugador);
		auxId = Get_IntRange("\nIngrese el id del jugador a modficar: ",
				"\nReingrese el id a modificar: ", 0, ll_len(pArrayListJugador));

		index = jug_buscarIdJugador(pArrayListJugador, auxId);

		if (index != -1) {
			aJugador = (Jugador*) ll_get(pArrayListJugador, index);
			printf("\nQue desea modificar?\n");
			opcion = Get_IntRange(
					"1.Nombre\n2.Edad\n3.Posicion\n4.Nacionalidad\n",
					"Reingrese una opcion", 1, 4);

			switch (opcion) {
			case 1:
				Get_OnlyAlphabetString("\nIngrese el nuevo nombre: ",
						"\nReingrese el nombre: ", auxNombre, T);
				jug_setNombreCompleto(aJugador, auxNombre);
				printf("\nNombre modificado con exito!!!\n");
				break;

			case 2:
				auxEdad = Get_Int("\nIngrese la edad", "\nReingrese la edad: ");
				jug_setEdad(aJugador, auxEdad);
				printf("\nEdad modificada con exito!!!\n");
				break;

			case 3:
				Get_OnlyAlphabetString("\nIngrese la posicion del jugador: ",
						"\nReingrese la posicion: ", auxPosicion, T);
				jug_setNombreCompleto(aJugador, auxPosicion);
				printf("\nPosicion modificada con exito!!!\n");
				break;

			case 4:
				Get_OnlyAlphabetString("\nIngrese la nacionalidad del jugador: ",
						"\nReingrese la nacionalidad: ", auxNacionalidad, L);
				jug_setNacionalidad(aJugador, auxNacionalidad);
				printf("\nNacionalidad modificada con exito!!!\n");
				break;
			}
		}
	}
	return index;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	Seleccion *unaSeleccion;
	Jugador *unJugador;
	int auxId;
	int opcion;
	int index;
	int idSeleccion;
	int indiceSeleccion;

	if (pArrayListJugador != NULL) {
		controller_listarJugadores(pArrayListJugador);

		auxId = Get_IntRange("\nIngrese el id del jugador a eliminar: ",
				"\nReingrese el id a eliminar: ", 0, ll_len(pArrayListJugador));

		printf("\nEsta seguro de querer eliminar este jugador %d ?\n", auxId);

		opcion = Get_IntRange("1.Si\n2.No\n", "Reingrese una opcion", 1, 2);

		if (opcion == 1) {
			index = jug_buscarIdJugador(pArrayListJugador, auxId);
			if (index != -1) {
				unJugador = (Jugador*) ll_get(pArrayListJugador, index);
				jug_getIdSeleccion(unJugador, &idSeleccion);
				if(idSeleccion != 0)
				{
					indiceSeleccion = selec_buscarIdSeleccion(pArrayListSeleccion, idSeleccion);
					unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);
					selec_setSeleccionConvocados(unaSeleccion, -1);
					printf(
							"\nSe ha eliminado de la convocatoria al jugador...\n");

				}

				ll_pop(pArrayListJugador, index);
				printf("\nJugador eliminado correctamente...\n");
			}

		} else {
			printf("A cancelado la eliminacion\n");
		}
	}

	return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{

	Jugador* aJugador;

	int i;
	int lenght;
	int respuesta = 0;
	int auxId;
	char auxPosicion[T];
	int auxEdad;
	char auxNombre[T];
	char auxNacionalidad[T];
	int idSeleccion;
	char convocado[][T] = {"No convocado", "Convocado"};
	char estadoJugador[T];

	printf("\n%3s%25s%11s%23s%20s%20s", "ID", "Nombre", "Edad", "Posicion","Nacionalidad","Estado\n\n");
	printf("*******************************************************************************************************\n");
	if(pArrayListJugador != NULL)
	{
		lenght = ll_len(pArrayListJugador);

		for(i = 0; i<lenght; i++)
		{
			aJugador=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getId(aJugador, &auxId);
			jug_getNombreCompleto(aJugador, auxNombre);
			jug_getEdad(aJugador, &auxEdad);
			jug_getPosicion(aJugador, auxPosicion);
			jug_getNacionalidad(aJugador, auxNacionalidad);
			jug_getIdSeleccion(aJugador, &idSeleccion);
			if(idSeleccion != 0)
				strcpy(estadoJugador, convocado[1]);
			else
				strcpy(estadoJugador, convocado[0]);

			printf("%2d %25s %9d %25s %20s %15s\n",auxId, auxNombre, auxEdad, auxPosicion, auxNacionalidad, estadoJugador);
		}
		respuesta = 1;
	}
  return respuesta;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int opcion;

	if (pArrayListJugador != NULL) {
		printf("\nBajo que criterio le gustaria ordenar la lista?\n");
		opcion = Get_IntRange("\n"
				"1.Por Nacionalidad A->Z\n"
				"2.Por Nacionalidad Z->A\n"
				"3.Por Edad ascendente\n"
				"4.Por Edad descendente\n"
				"5.Por Nombre A->Z\n"
				"6.Por Nombre Z->A\n"
				"Ingrese una opcion: ", "Reingrese una opcion", 1, 6);

		switch (opcion) {
		case 1:
			ll_sort(pArrayListJugador, jug_compararNacionalidad, 1);
			controller_listarJugadores(pArrayListJugador);
			printf("\nJugadores ordenados por Nacionalidad ascendente con exito\n");
			break;
		case 2:
			ll_sort(pArrayListJugador, jug_compararNacionalidad, 0);
			controller_listarJugadores(pArrayListJugador);
			printf("\nJugadores ordenados por Nacionalidad descendente con exito\n");
			break;
		case 3:
			ll_sort(pArrayListJugador, jug_compararEdad, 1);
			controller_listarJugadores(pArrayListJugador);
			printf("\nJugadores ordenados por Edad ascendente con exito\n");
			break;
		case 4:
			ll_sort(pArrayListJugador, jug_compararEdad, 0);
			controller_listarJugadores(pArrayListJugador);
			printf("\nJugadores ordenados por Edad descendente con exito\n");
			break;
		case 5:
			ll_sort(pArrayListJugador, jug_compararNombre, 1);
			controller_listarJugadores(pArrayListJugador);
			printf("\nPasajeros ordenados Por Apellido A->Z  con exito\n");
			break;
		case 6:
			ll_sort(pArrayListJugador, jug_compararNombre, 0);
			controller_listarJugadores(pArrayListJugador);
			printf("\nPasajeros ordenados Por Apellido Z->A con exito\n");
			break;
		}
	}
	return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE *pFile;
	Jugador *unJugador;

	int length;
	int respuesta = 0;
	int i;
	char auxNombre[T];
	int auxEdad;
	char auxPosicion[L];
	char auxNacionalidad[L];
	int auxIdSeleccion;
	int auxId;

	if (path != NULL && pArrayListJugador != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			length = ll_len(pArrayListJugador);
			fprintf(pFile, "id,nombreCompleto,edad,posicion,nacionalidad,idSeleccionId\n");

			for (i = 0; i < length; i++) {
				unJugador = (Jugador*) ll_get(pArrayListJugador, i);
				jug_getId(unJugador, &auxId);
				jug_getNombreCompleto(unJugador, auxNombre);
				jug_getEdad(unJugador, &auxEdad);
				jug_getPosicion(unJugador, auxPosicion);
				jug_getNacionalidad(unJugador, auxNacionalidad);
				jug_getIdSeleccion(unJugador, &auxIdSeleccion);
				fprintf(pFile, "%d,%s,%d,%s,%s,%d\n", auxId, auxNombre,
						auxEdad, auxPosicion, auxNacionalidad, auxIdSeleccion);
			}
			fclose(pFile);
		}
		respuesta = 1;
	}
	return respuesta;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	FILE *pFile;
	Jugador *unJugador;

	int respuesta = 0;
	int i;
	int length;

	if (path != NULL && pArrayListJugador != NULL) {
		pFile = fopen(path, "wb");

		if (pFile != NULL) {
			length = ll_len(pArrayListJugador);

			for (i = 0; i < length; i++) {
				unJugador = (Jugador*) ll_get(pArrayListJugador, i);
				fwrite(unJugador, sizeof(Jugador), 1, pFile);
			}

			fclose(pFile);
		}
		respuesta = 1;
	}
	return respuesta;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE *pArchivo;
	int response = 0;

	pArchivo = (FILE*) malloc(sizeof(FILE));

	if (path != NULL && pArrayListSeleccion != NULL) {
		pArchivo = fopen(path, "r");

		if (pArchivo != NULL) {
			response = parser_SeleccionFromText(pArchivo, pArrayListSeleccion);
		}
	}

	return response;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
	Seleccion *aSeleccion;
	char auxPais[T];
	char auxConfederacion[L];
	int opcion;
	int auxId;
	int index;

	if (pArrayListSeleccion != NULL) {
		controller_listarSelecciones(pArrayListSeleccion);
		auxId = Get_Int("\nIngrese el id de la seleccion a modificar: ",
				"\nReingrese el id a modificar: ");

		index = selec_buscarIdSeleccion(pArrayListSeleccion, auxId);

		if (index != -1) {
			aSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, index);
			printf("\nQue desea modificar?\n");
			opcion = Get_IntRange(
					"1.Pais\n2.Confederaccion\n",
					"Reingrese una opcion", 1, 2);

			switch (opcion) {
			case 1:
				Get_OnlyAlphabetString("\nIngrese el nuevo pais: ",
						"\nReingrese el pais: ", auxPais, T);
				selec_setPais(aSeleccion, auxPais);
				printf("\nPais modificado con exito!!!\n");
				break;

			case 2:
				Get_OnlyAlphabetString("\nIngrese la nueva confederacion: ",
						"\nReingrese la confederacion: ", auxConfederacion, T);
				selec_setConfederacion(aSeleccion, auxConfederacion);
				printf("\nConfederacion modificada con exito!!!\n");
				break;
			}
		}
	}
	return index;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	Seleccion *aSeleccion;

	int i;
	int lenght;
	int respuesta = 0;
	int auxId;
	int auxConvocados;
	char auxPais[T];
	char auxConfederacion[T];

	printf("\n%3s%14s%18s%15s", "ID", "Pais", "Confederacion",
			"Convocados\n\n");
	printf("***************************************************\n");
	if (pArrayListSeleccion != NULL) {
		lenght = ll_len(pArrayListSeleccion);

		for (i = 0; i < lenght; i++) {
			aSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
			selec_getId(aSeleccion, &auxId);
			selec_getPais(aSeleccion, auxPais);
			selec_getConfederacion(aSeleccion, auxConfederacion);
			selec_getConvocados(aSeleccion, &auxConvocados);
			printf("%2d %17s %10s %15d \n", auxId, auxPais, auxConfederacion,
					auxConvocados);
		}
		respuesta = 1;
	}
	return respuesta;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int opcion;

	if (pArrayListSeleccion != NULL) {
		printf("\nBajo que criterio le gustaria ordenar la lista?\n");
		opcion = Get_IntRange("\n"
				"1.Por Confederacion A->Z\n"
				"2.Por Confederacion Z->A\n"
				"Ingrese una opcion: ", "Reingrese una opcion", 1, 2);

		switch (opcion) {
		case 1:
			ll_sort(pArrayListSeleccion, selec_compararConfederacion, 1);
			controller_listarSelecciones(pArrayListSeleccion);
			printf(
					"\nSelecciones ordenadas por confederacion (A->Z) con exito\n");
			break;
		case 2:
			ll_sort(pArrayListSeleccion, selec_compararConfederacion, 0);
			controller_listarSelecciones(pArrayListSeleccion);
			printf(
					"\nSelecciones ordenadas por confederacion (Z->A) con exito\n");
			break;
		}
	}
	return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE *pFile;
	Seleccion *unaSeleccion;

	int length;
	int respuesta = 0;
	int i;
	int auxConvocados;
	char auxPais[T];
	char auxConfederacion[T];
	int auxId;

	if (path != NULL && pArrayListSeleccion != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			length = ll_len(pArrayListSeleccion);
			fprintf(pFile,
					"id,pais,confederacion,convocados\n");

			for (i = 0; i < length; i++) {
				unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
				selec_getId(unaSeleccion, &auxId);
				selec_getPais(unaSeleccion, auxPais);
				selec_getConfederacion(unaSeleccion, auxConfederacion);
				selec_getConvocados(unaSeleccion, &auxConvocados);
				fprintf(pFile, "%d,%s,%s,%d\n", auxId, auxPais, auxConfederacion,
						auxConvocados);
			}
			fclose(pFile);
		}
		respuesta = 1;
	}
	return respuesta;
}


int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int auxId;
	int auxIdSeleccion;
	int opcion;
	int respuesta;
	Seleccion *unaSeleccion;
	Jugador *unJugador;

	if (pArrayListJugador != NULL) {
		controller_listarJugadores(pArrayListJugador);

		fflush(stdin);
		auxId = Get_IntRange("\nIngrese el id del jugador a convocar: ",
							 "\nReingrese el id del jugador a convocar: ", 0, ll_len(pArrayListJugador));

		printf("\nEsta seguro de querer convocar este jugador %d ?\n", auxId);

		fflush(stdin);
		opcion = Get_IntRange("1.Si\n2.No\n", "Reingrese una opcion", 1, 2);

		if (opcion == 1) {
			controller_listarSelecciones(pArrayListSeleccion);
			auxIdSeleccion = Get_IntRange("\nIngrese el id de la seleccion a asignar: ",
										 "\nReingrese el id de la seleccion: ", 0, ll_len(pArrayListSeleccion));

				unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, selec_buscarIdSeleccion(pArrayListSeleccion, auxIdSeleccion));
				unJugador = (Jugador*) ll_get(pArrayListJugador, jug_buscarIdJugador(pArrayListJugador, auxId));
				respuesta = selec_setSeleccionConvocados(unaSeleccion, 1);

				if(respuesta)
				{
					jug_setIdSeleccion(unJugador, auxIdSeleccion);
					printf("\nJugador convocado correctamente...\n");
				}
				else
					printf("\nNo se ha podido convocar al jugador porque la lista de convocados de la seleccion se encuentra llena...\n");

		} else {
			printf("A cancelado la convocatoria\n");
		}
	}

	return 1;
}

int controller_desconvocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int auxId;
	int idSeleccion;
	int opcion;
	int indiceJugador;
	int indiceSeleccion;
	int respuesta;
	int tieneSeleccion;
	Seleccion *unaSeleccion;
	Jugador *unJugador;

	if (pArrayListJugador != NULL) {
		controller_listarJugadores(pArrayListJugador);

		auxId = Get_IntRange(
				"\nIngrese el id del jugador a eliminar de la convocatoria: ",
				"\nReingrese el id del jugador a desconvocar: ", 0,
				ll_len(pArrayListJugador));

		indiceJugador = jug_buscarIdJugador(pArrayListJugador, auxId);
		unJugador = (Jugador*) ll_get(pArrayListJugador, indiceJugador);
		jug_getIdSeleccion(unJugador, &tieneSeleccion);

		if (tieneSeleccion) {
			printf("\nEsta seguro de querer desconvocar este jugador?\n");

			opcion = Get_IntRange("1.Si\n2.No\n", "Reingrese una opcion", 1, 2);

			if (opcion == 1) {
				jug_getIdSeleccion(unJugador, &idSeleccion);
				indiceSeleccion = selec_buscarIdSeleccion(pArrayListSeleccion, idSeleccion);
				unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);
				jug_setIdSeleccion(unJugador, 0);

				respuesta = selec_setSeleccionConvocados(unaSeleccion, -1);

				if (respuesta == -1)
					printf(
							"\nSe ha eliminado de la convocatoria al jugador...\n");
				else
					printf(
							"\nNo se ha podido eliminar la convocatoria del jugador...\n");
			} else
				printf("A cancelado la eliminacion de la convocatoria\n");
		}
		else
			printf("El jugador no ha sido convocado con anterioridad\n");
	}

	return 1;
}

int controller_listarJugadoresConvocados(LinkedList *pArrayListJugador) {

	Jugador *aJugador;

	int i;
	int lenght;
	int respuesta = 0;
	int auxId;
	char auxPosicion[T];
	int auxEdad;
	char auxNombre[T];
	char auxNacionalidad[T];
	int idSeleccion;
	char convocado[][T] = {"No convocado", "Convocado"};
	char estadoJugador[T];


	printf("\n%3s%25s%11s%23s%20s%20s", "ID", "Nombre", "Edad", "Posicion","Nacionalidad","Estado\n\n");
	printf(
			"*******************************************************************************************************\n");
	if (pArrayListJugador != NULL) {
		lenght = ll_len(pArrayListJugador);

		for (i = 0; i < lenght; i++) {

			aJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getIdSeleccion(aJugador, &idSeleccion);
			if (idSeleccion != 0) {
				jug_getId(aJugador, &auxId);
				jug_getNombreCompleto(aJugador, auxNombre);
				jug_getEdad(aJugador, &auxEdad);
				jug_getPosicion(aJugador, auxPosicion);
				jug_getNacionalidad(aJugador, auxNacionalidad);
				if(idSeleccion != 0)
					strcpy(estadoJugador, convocado[1]);
				else
					strcpy(estadoJugador, convocado[0]);

				printf("%2d %25s %9d %25s %20s %15s\n",auxId, auxNombre, auxEdad, auxPosicion, auxNacionalidad, estadoJugador);
			}
		}
		respuesta = 1;
	}
	return respuesta;
}
