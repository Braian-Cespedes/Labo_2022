#ifndef ARRAYJUGADORES_H_
#define ARRAYJUGADORES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define P 3000
#define TRUE 1
#define FALSE 0
#define TAMA 51

typedef struct
{
	int codigo;
	char descripcion[50];
}ePosicion;

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;

}eConfederacion;

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;

}eJugador;

/**
 * void initJugador(eJugador listaJugadores[], int tam)
 *
 * @param listaJugadores = Inicializa la lista de jugadores.
 * @param tam = Tamanio de la lista de jugadores.
 * Inicializa una lista de pasajeros.
 */

void initJugador(eJugador listaJugadores[], int tam);

/**
 * void InicializarConfederacion(eConfederacion listaConfederacion[], int tam)
 *
 * @param listaConfederacion = Inicializa la lista de las confederaciones.
 * @param tam = Tamanio de la lista de confederaciones.
 * Inicializa una lista con la confederacion del jugador.
 */

void InicializarConfederacion(eConfederacion listaConfederacion[], int tam);

/**
 * HarcodearPassenger(ePassenger listaPasajeros[], int *idIncrementaPasajeros, int tam, int *pFlag)
 *
 * @param listaPasajeros = Harcodea una lista de pasajeros.
 * @param idIncrementaPasajeros = Incrementa la lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param pFlag = Bandera de primero de la lista.
 * Harcodea la lista de pasajeros con datos.
 */

void harcodearJugador(eJugador listaJugadores[], int *idIncrementaPasajeros, int tam, int *pFlag);

/**
 * void HarcodearJugador(eJugador listaJugadores[], int *idIncrementaJugador, int tam, int *pFlag)
 *
 * @param listaTipo = Harcodea la lista de tipos.
 * @param tam = Tamanio de la lista.
 * @param pFlag = Bandera de primero de la lista.
 * Harcodea la lista de jugadores con datos.
 */

void harcodearConfederacion(eConfederacion listaConfederacion[], int tam);

/**
 * void PrintConfederacion(eConfederacion listaConfederacion[], int tam)
 *
 * @param listaConfederacion = Muestra la lista de confederaciones.
 * @param tam = Tamanio de la lista.
 * Harcodea la lista de confederaciones.
 */

void mostrarConfederacion(eConfederacion listaConfederacion[], int tam);

/**
 * void PrintOneConfederacion(eConfederacion listaConfederacion)
 *
 * @param listaConfederacion = Muestra solo una lista de una confederacion
 * Muestra la lista de una confederacion de un jugador.
 */

void mostrarUnaConfederacion(eConfederacion listaConfederacion);

/**
 * void PrintJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConf)
 *
 * @param listaJugadores = Muestra la lista de los jugadores.
 * @param tam = Tamanio de la lista
 * @param listaConfederacion = Muestra la lista de las confederaciones.
 * @param tamConf = Tamanio de la lista de confederaciones.
 * Muestra la lista de jugadores con su confederaciones.
 */

void mostrarJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConf);

/**
 * void PrintOneJugador(eJugador unJugador, eConfederacion listaConfederacion[], int tamConf)
 *
 * @param unJugador = Jugador a mostrar.
 * Muestra un jugador de la lista.
 * Muestra solo un jugador en la lista.
 */

void mostrarUnJugador(eJugador unJugador, eConfederacion listaConfederacion[], int tamConf);

/**
 * void PrintOneJugadorConfederacion(eJugador unJugador, eConfederacion unaConfederacion)
 *
 * @param unJugador = Jugador de la lista a mostrar.
 * @param unTipo = Confederacion de la lista a mostrar.
 * Muestra un jugador con su confederacion en la lista.
 */

void mostrarUnJugadorConfederacion(eJugador unJugador, eConfederacion unaConfederacion);
/**
 * int buscarJugador(eJugador listaJugadores[], int tam, int id, int* pIndex)
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @param id = ID ingresada por el usuario.
 * @param pIndex = Indice donde se encuentra el jugador en la lista.
 * @return = Retorna el indice de la lista si lo encuentra de lo contrario retorna -1
 * Busca en la lista el jugador ingresado por el usuario.
 */
int buscarJugador(eJugador listaJugadores[], int tam, int id, int* pIndex);

/**
 * int buscarConfederacionJugador(eConfederacion listaConfederacion[], int tam, int id, int* pIndex)
 *
 * @param listaConfederacion = Lista de confederaciones.
 * @param tam = Tamanio de la lista.
 * @param id = ID ingresada por el usuario.
 * @param pIndex = Indice donde se encuentra la confederacion de la lista.
 * @return = Retorna el indice de la lista si lo encuentra de lo contrario retorna -1
 * Busca la confederacion del jugador en la lista ingresado por el usuario.
 */

int buscarConfederacionJugador(eConfederacion listaConfederacion[], int tam, int id, int* pIndex);

/**
 * int BuscarLibre(eJugador listaJugadores[], int tam)
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @return = Retorna el indice si encuentra un espacio libre para cargar.
 * Busca un lugar libre en la lista.
 */

int buscarLibre(eJugador listaJugadores[], int tam);

/**
 * int FindJugadorById(eJugador listaJugadores[], int tam, int datoId)
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @param datoId = Dato a buscar.
 * @return = Retorna el indice si el id coincide retorna a -1
 * Busca el jugador por el id ingresado.
 */

int buscarJugadorPorId(eJugador listaJugadores[], int tam, int datoId);

/**
 * void addOneJugador(eJugador listaJugadores[], int tam, int IdIncrementalJugador, eConfederacion listaConfederacion[], int tamConfederacion)
 *
 * @param listaJugador = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @param IdIncrementalJugador = ID a asignar.
 * @param listaConfederacion = Lista de confederaciones.
 * @param tamConfederacion = Tamanio de la lista de confederaciones.
 * Busca un indice libre y lo asigna a una lista de pasajeros vacia.
 */

void addOneJugador(eJugador listaJugadores[], int tam, int IdIncrementalJugador, eConfederacion listaConfederacion[], int tamConfederacion, ePosicion posiciones[], int tamPosiciones);

/**
 * void ModifyJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion)
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @param listaConfederacion = Lista de Confederaciones.
 * @param tamConfederacion = Tamanio de la lista de confederaciones.
 * Modifica un jugador ingresando la ID a modificar.
 */

void modificarJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion, ePosicion posiciones[], int tamPosiciones);
/**
 * eJugador AddJugador(int IdIncrementalJugador, eConfederacion listaConfederacion[], int tamConfederacion)
 *
 * @param IdIncrementalJugador = ID a asignar.
 * @param listaConfederaciones = Lista de confederaciones.
 * @param tamConfederacion = Tamanio de la lista de confederaciones.
 * @return = Retorna un jugador con todos los datos cargados.
 * Carga los datos de un jugador.
 */

eJugador agregarJugador(int IdIncrementalJugador, eConfederacion listaConfederacion[], int tamConfederacion, ePosicion posiciones[], int tamPosiciones);

/**
 * void DeleteJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion)
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista de jugadores.
 * @param listaConfederacion = Lista de confederaciones.
 * @param tamConfederacion = Tamanio de confederacion.
 * Solicita el id a ingresar por el usuario para eliminar un jugador de la lista.
 */

void eliminarJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * void RemoveJugador(eJugador listaJugadores[], int tam, int indice, char mensaje[])
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @param indice = Indice del array de jugadores.
 * @param mensaje = Mensaje a mostrar.
 * Elimina un jugador de la lista cambiandole el mensaje.
 */

void borrarJugador(eJugador listaJugadores[], int tam, int indice, char mensaje[]);
/**
 * int MenuJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion)
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @param listaConfederacion = Lista de confederaciones.
 * @param tamConfederacion = Tamanio de la lista de confederaciones.
 * @return = Retorna -1 si se decide salir del menu secundario.
 * Menu secundario de jugadores.
 */
int menuJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion);
/**
 * void sortJugadorByStatus(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamEstado)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param respuesta = Respuesta del usuario para ordenar el array.
 * @param listaTipo = Lista de tipos.
 * @param tamTipo = Tamanio de la lista de tipos.
 * Ordena la lista de pasajeros.
 */
void ordenarJugadores(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamEstado);
/**
 * float SumPrices(eJugador listaJugadores[], int tam)
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @return = Retorna a la suma total de salario.
 * Suma el salario de la lista.
 */
float sumarPrecios(eJugador listaJugadores[], int tam);
/**
 * float AverageSalario(eJugador listaJugadores[], int tam)
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @return = Retorna el promedio del salario de la lista.
 * Calcula el salario.
 */
float salarioPromedio(eJugador listaJugadores[], int tam);
/**
 * int CountJugador(eJugador listaJugadores[], int tam)
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @return = Retorna la cantidad de jugadores de la lista.
 * Cuenta y retorna la lista de jugadores.
 */
int contarJugadores(eJugador listaJugadores[], int tam);
/**
 * int ShowAverageJugador(eJugador listaJugadores[], int tam)
 *
 * @param listaJugadores = Lista de jugadores.
 * @param tam = Tamanio de la lista.
 * @return = Retorna el indice del jugador con salario superior al promedio.
 * Retorna el indice del jugador con el mayor salario promedio.
 */
int mostrarJugadorMayorSalario(eJugador listaJugadores[], int tam);
/**
 * void sortJugadorByNombreConfederacion(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion)
 *
 * @param listaJugadores = Listado de jugadores.
 * @param tam = Tamanio de la lista.
 * @param listaConfederacion = Lista de confederaciones.
 * @param tamConfederacion = Tamanio de la lista de confederaciones.
 * Ordena la lista de jugadores por nombre y confederacion.
 */
void ordenarJugadorByNombreConfederacion(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion);

/**
 * int BuscarConfederacion(eConfederacion listaConfederaciones[], int tam, int index, char* nombreConfederacion)
 *
 * @param listaConfederaciones = lista de confederaciones.
 * @param tam = tamanio de la lista
 * @param index =
 * @param nombreConfederacion = El nombre de la confederacion a agregar.
 * @return = retorna un 1 si hay respuesta para el ususario.
 * Busca la confederacion donde queda agregado el jugador.
 */
int buscarConfederacion(eConfederacion listaConfederaciones[], int tam, int index, char* nombreConfederacion);
/**
 * void ShowJugadorConfederacion(eJugador listaJugadores[], eConfederacion listaConfederaciones[], int tam, int tamCon)
 *
 * @param listaJugadores = lista de jugadores;
 * @param listaConfederaciones = lista de confederaciones.
 * @param tam = tamanio de la lista.
 * @param tamCon = tamanio de la lista de confederacion
 * Muestra al usuario el nombre y la confederacion que esta agregado el jugador.
 */

void mostrarJugadorConfederacion(eJugador listaJugadores[], eConfederacion listaConfederaciones[], int tam, int tamCon);

/**
 * void ShowConfederacionMasAnios(eJugador listaJugadores[], eConfederacion listaConfederacion[], int tam, int tamConf, char* nombreConf)
 *
 * @param listaJugadores = lista de jugadores.
 * @param listaConfederacion = lista de confederaciones.
 * @param tam = tamanio de confederaciones.
 * @param tamConf = tamanio de la lista de confederaciones.
 * @param nombreConf = nombre del jugador con su confederacion.
 * Muestra al usuario la confederacion y el nombre del jugador agregado.
 */

void mostrarConfederacionMasAnios(eJugador listaJugadores[], eConfederacion listaConfederacion[], int tam, int tamConf, char* nombreConf);

/**
 * float CalcularPromedioJugadores(float totalJugadores, float totalConfederacion)
 *
 * @param totalJugadores = El total de los jugadores sumado;
 * @param totalConfederacion = el total de las confederaciones
 * @return = devuelve el resultado calculado.
 * Calcula el promedio del salarios de los jugadores.
 */

float calcularPromedioJugador(float totalJugadores, float totalConfederacion);
/**
 * void CountJugadorConfederacion(eJugador listaJugadores[], eConfederacion listaConfederaciones[], int tam, int tamCon)
 *
 * @param listaJugadores = lista de jugadores.
 * @param listaConfederaciones = lista de confederaciones.
 * @param tam = tamanio de la lista.
 * @param tamCon = tamanio de la lista confederaciones.
 * Cuenta los jugadores en su propia confederacion.
 */

void contarJugadorConfederacion(eJugador listaJugadores[], eConfederacion listaConfederaciones[], int tam, int tamCon);

/**
 * void MostrarPorcentajes(int contadorCONMEBOL, int contadorUEFA, int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorOFC, int totalConf)
 *
 * @param contadorCONMEBOL = contador de la confederacion CONMEBOL.
 * @param contadorUEFA = contador de la confederacion UEFA.
 * @param contadorAFC = contador de la confederacion AFC.
 * @param contadorCAF = contador de la confederacion CAF.
 * @param contadorCONCACAF = contador de la confederacion CONCACAF.
 * @param contadorOFC = contador de la confederacion OFC.
 * @param totalConf = el total del porcentaje de las confederaciones.
 * Muestra el porcentaje de los jugadores en su confederacion.
 */

void mostrarPorcentajes(int contadorCONMEBOL, int contadorUEFA, int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorOFC, int totalConf);


/**
 * void  mostrarPosiciones(char* listaPosiciones, int tam)
 *
 * @param listaPosiciones = array de posiciones.
 * @param tam = tamanio del array.

 * Muestra las posiciones de los jugadores.
 */
void mostrarPosiciones(ePosicion posiciones[], int tam);


/**
 * int buscarPosicionEnLista(ePosicion listaPosiciones[], int tam, int index, char* posicion);

 * @param listaPosiciones = array de posiciones.
 * @param tam = tamanio del array.
 * @param index = indice de la lista a buscar.
 * @param posicion = variable que almacena la descripcion de la posicion.


 * Guarda en una variable la descripcion que corresponde a una id de posicion.
 */
int buscarPosicionEnLista(ePosicion listaPosiciones[], int tam, int index, char* posicion);

/**
 * int mostrarRegionMasJugadores(eJugador listaJugadores[], int tamJugador, eConfederacion listaConfederaciones[], int tamConf);

 * @param listaJugadores = array de jugadores.
 * @param tamJugador = tamanio del array.
 * @param listaConfederaciones = array de confederaciones.
 * @param tamConf = tamanio del array.


 * Permite mostrar la region con mas jugadores de la lista.
 */
void mostrarRegionMasJugadores(eJugador listaJugadores[], int tamJugador, eConfederacion listaConfederaciones[], int tamConf);

/**
 * void mostrarJugadorPorConfederacion(eJugador listaJugadores[], int tamJugador, eConfederacion listaConfederaciones[], int tamConf, int idConf);

 * @param listaJugadores = array de jugadores.
 * @param tamJugador = tamanio del array.
 * @param listaConfederaciones = array de confederaciones.
 * @param tamConf = tamanio del array.
 * @param idConf = id de confederacion a buscar.


 * Permite mostrar la los jugadores por confederacion
 */

void mostrarJugadorPorConfederacion(eJugador listaJugadores[], int tamJugador, eConfederacion listaConfederaciones[], int tamConf, int idConf);

/**
 * int buscarConfederacionPorId(eConfederacion listaConfederacion[], int tam, int datoId);

 * @param listaConfederaciones = array de confederaciones.
 * @param tam = tamanio del array.
 * @param datoId = id de confederacion a buscar.

 * Busca el indice el cual corresponde a una id determinada en la lista
 * return = indice correspondiente al id de la confederacion
 */

int buscarConfederacionPorId(eConfederacion listaConfederacion[], int tam, int datoId);

#endif /* ARRAYJUGADORES_H_ */
