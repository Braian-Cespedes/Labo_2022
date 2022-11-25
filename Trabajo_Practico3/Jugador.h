#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int codigo;
	char descripcion[50];
}eEstructuraAux;

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete();

int jug_setId(Jugador* thisJugador,int id);
int jug_getId(Jugador* thisJugador,int* id);

int jug_setNombreCompleto(Jugador* thisJugador,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* thisJugador,char* nombreCompleto);

int jug_setPosicion(Jugador* thisJugador,char* posicion);
int jug_getPosicion(Jugador* thisJugador,char* posicion);

int jug_setNacionalidad(Jugador* thisJugador,char* nacionalidad);
int jug_getNacionalidad(Jugador* thisJugador,char* nacionalidad);

int jug_setEdad(Jugador* thisJugador,int edad);
int jug_getEdad(Jugador* thisJugador,int* edad);

int jug_setIdSeleccion(Jugador* thisJugador,int idSeleccion);
int jug_getIdSeleccion(Jugador* thisJugador,int* idSeleccion);

int jug_compararNombre(void* jugador1, void* jugador2);
int jug_compararEdad(void* jugador1, void* jugador2);
int jug_compararNacionalidad(void* jugador1, void* jugador2);

int esAux_mostrarEstructura(eEstructuraAux *listaEntidades, int tam);
int esAux_buscarDescEnLista(eEstructuraAux* listaEntidades, int tam, int index, char* posicion);

int jug_filtrarPorConfederacion (void* this, void* aux);

#endif // jug_H_INCLUDED
