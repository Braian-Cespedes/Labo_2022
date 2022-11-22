#include "ArrayJugadores.h"
#include "Generic_Functions.h"

void initJugador(eJugador listaJugadores[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
		listaJugadores[i].isEmpty = TRUE;
}

void harcodearJugador(eJugador listaJugadores[], int *idIncrementaJugador, int tam, int *pFlag)
{
	char Nombre[][TAMA] = {"Messi", "Ochoa", "Guerrero", "Emiliano", "Javier", "Christian"};
	char Posicion[][TAMA] = {"Delantero centro", "Mediapunta", "Delantero centro", "Extremo izquierdo", "Lateral izquierdo", "Mediocentro"};
	short numeroCamiseta[] = {10, 6, 9, 13, 5, 3};
	int idConfederacion[] = {1001, 1002, 1003, 1004, 1004, 1005};
	float salario[] = {3000.00,15000.34,32000.56,29000.28, 30500.23, 18000.56};
	short aniosContrato[] = {3,5,2,4,7,6};

	for(int i=0; i<tam; i++)
	{
	    if(listaJugadores[i].isEmpty == TRUE && idIncrementaJugador != NULL)
	    {
	    	listaJugadores[i].id = eGen_ObtenerID(*idIncrementaJugador);
		    strcpy(listaJugadores[i].nombre, Nombre[i]);
		    strcpy(listaJugadores[i].posicion, Posicion[i]);
		    listaJugadores[i].numeroCamiseta = numeroCamiseta[i];
		    listaJugadores[i].idConfederacion = idConfederacion[i];
		    listaJugadores[i].salario = salario[i];
		    listaJugadores[i].aniosContrato = aniosContrato[i];
		    listaJugadores[i].isEmpty = FALSE;
	    	*idIncrementaJugador = listaJugadores[i].id;
	    }
	}

	*pFlag = 1;
}

void harcodearConfederacion(eConfederacion listaConfederacion[], int tam)
{
	int id[] = {1000, 1001, 1002, 1003, 1004, 1005};
	char nombre[][50] = {"CONMEBOL", "UEFA", "AFC", "CAF", "CONCACAF", "OFC"};
	char region[][50] = {"SUDAMERICA", "EUROPA", "ASIA", "AFRICA", "NORTE Y CENTRO AMERICA", "OCEANIA"};
	int anio[] = {1916, 1954, 1954, 1957, 1961, 1966};

	for(int i=0; i<tam; i++)
	{
	    if(listaConfederacion[i].isEmpty == TRUE)
	    {
	    	listaConfederacion[i].id = id[i];
		    strcpy(listaConfederacion[i].nombre, nombre[i]);
		    strcpy(listaConfederacion[i].region, region[i]);
		    listaConfederacion[i].anioCreacion = anio[i];
		    listaConfederacion[i].isEmpty = FALSE;

	    }
	}

}

int buscarLibre(eJugador listaJugadores[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listaJugadores[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}
	return index;
}

int buscarJugadorPorId(eJugador listaJugadores[], int tam, int datoId)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listaJugadores[i].id == datoId)
		{
			index = i;
			break;
		}
	}
	return index;
}

int buscarConfederacionPorId(eConfederacion listaConfederacion[], int tam, int datoId)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listaConfederacion[i].id == datoId)
		{
			index = i;
			break;
		}
	}
	return index;
}

void addOneJugador(eJugador listaJugadores[], int tam, int IdIncrementalJugador, eConfederacion listaConfederacion[], int tamConfederacion, ePosicion posiciones[], int tamPosiciones)
{
	int i;
	i = buscarLibre(listaJugadores, tam);

	if(i != -1)
	{
		listaJugadores[i] = agregarJugador(IdIncrementalJugador, listaConfederacion, tamConfederacion, posiciones, tamPosiciones);
		if(listaJugadores[i].isEmpty == FALSE)
		{
			printf("\nDatos cargados con exito!!\n\n");
			system("pause");
			system("cls");
		}
	}
	else
	{
		 printf("\nNo hay espacio para la carga de datos\n\n");
		 system("pause");
		 system("cls");
	}
}

void InicializarConfederacion(eConfederacion listaConfederacion[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaConfederacion[i].isEmpty = TRUE;
	}
}

void mostrarConfederacion(eConfederacion listaConfederacion[], int tam)
{
	for(int i=0; i<tam; i++)
		{
			if(listaConfederacion[i].isEmpty == FALSE)
				{
					mostrarUnaConfederacion(listaConfederacion[i]);
				}
		}
}

void mostrarUnaConfederacion(eConfederacion listaConfederacion)
{
	if(listaConfederacion.isEmpty == FALSE)
	{
		printf("\n*%4d %13s %26s %16d\n", listaConfederacion.id,
						   listaConfederacion.nombre,
						   listaConfederacion.region,
						   listaConfederacion.anioCreacion);
	}
}

int buscarConfederacionJugador(eConfederacion listaConfederacion[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( listaConfederacion != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !listaConfederacion[i].isEmpty  && listaConfederacion[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


eJugador agregarJugador(int IdIncrementalJugador, eConfederacion listaConfederacion[], int tamConfederacion, ePosicion posiciones[], int tamPosiciones)
{
	eJugador AddedJugador;
	int auxConfederacion;
	int auxIndex;
	int auxPosicion;
	char posicionDescripcion[TAMA];

	get_StringConEspacios("\nIngrese el nombre del jugador: ", "Ingrese el nombre nuevamente(solo caracteres alfabeticos): ", AddedJugador.nombre, TAMA);
	mostrarPosiciones(posiciones, tamPosiciones);
	auxPosicion = getEnteroRango("\nIngrese el numero de la posicion del jugador: ", "Ingrese la posicion nuevamente(solo caracteres alfabeticos): ", 1, 10);
	buscarPosicionEnLista(posiciones, tamPosiciones, auxPosicion, posicionDescripcion);
	strcpy(AddedJugador.posicion, posicionDescripcion);

	AddedJugador.numeroCamiseta = getEnteroRango("\nIngrese el numero de la camiseta: ", "Ingrese el numero de la camiseta nuevamente (Solo numeros): ", 0, 30);
	printf("\n%s %19s %21s %24s ","ID", "Confederacion", "Region", "Anio Fundacion\n");
	mostrarConfederacion(listaConfederacion, tamConfederacion);

	AddedJugador.idConfederacion = getInt("\nIngrese el codigo de confederacion: ", "Ingrese devuelta el id (solo caracteres numericos positivos): ");
	AddedJugador.salario = getFlotante("\nIngrese el salario: ", "Ingrese devuelta el salario(Solo numeros): ");
	AddedJugador.aniosContrato = getInt("\nIngrese el anio del contrato: ", "Vuelve a ingresar el anio del contrato(Solo numeros)");


	while(!buscarConfederacionJugador (listaConfederacion, tamConfederacion, auxConfederacion, &auxIndex))
	{
		printf("/nERROR!!! No se encontro el ID ingresado.");
		auxConfederacion = getInt("\nIngrese la confederacion: ", "Ingrese la confederacion nuevamente (solo caracteres alfabeticos): ");

	}
	AddedJugador.id = IdIncrementalJugador;
	AddedJugador.isEmpty = FALSE;

	return AddedJugador;

}

void mostrarJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConf)
{
	for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tamConf; j++)
			{
				if(listaJugadores[i].isEmpty == FALSE && listaJugadores[i].idConfederacion == listaConfederacion[j].id)
					{
						mostrarUnJugadorConfederacion(listaJugadores[i], listaConfederacion[j]);

					}

			}

		}

}


void mostrarUnJugadorConfederacion(eJugador unJugador, eConfederacion unaConfederacion)
{

	if(unJugador.isEmpty == FALSE)
	{
		printf("\n*%2d %12s %25s %15d %19s %18.2f %12d\n\n", unJugador.id,
															 unJugador.nombre,
															 unJugador.posicion,
															 unJugador.numeroCamiseta,
															 unaConfederacion.nombre,
															 unJugador.salario,
															 unJugador.aniosContrato
															 );
	}
}

void mostrarUnJugador(eJugador unJugador, eConfederacion listaConfederacion[], int tamConf)
{
		for(int j=0; j<tamConf; j++)

			{
				if(unJugador.isEmpty == FALSE && unJugador.idConfederacion == listaConfederacion[j].id)
					{
						mostrarUnJugadorConfederacion(unJugador, listaConfederacion[j]);

						break;
					}

			}


}

int buscarJugador(eJugador listaJugadores[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( listaJugadores != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !listaJugadores[i].isEmpty  && listaJugadores[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


void modificarJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion, ePosicion posiciones[], int tamPosiciones)
{
	int indexJugador;
	int auxConfederacionId;
	int indexConfederacion;
	int idIngresada;
	char auxNombre[TAMA];
	char auxDescPosicion[TAMA];
	short auxCamiseta;
	float auxSalario;
	short auxContrato;
	int auxPosicion;
	int opcion;
	char seguir;

		system("cls");
		printf("\n\n### Jugadores encontrados ###\n");
		printf("\n%s %14s %21s %24s %17s %14s %16s","ID", "Nombre", "Posicion", "Numero Camiseta", "Confederacion", "Salario", "Contrato\n");
		mostrarJugador(listaJugadores, tam, listaConfederacion, tamConfederacion);
		idIngresada = getInt("\nIngrese el ID del jugador: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");
		while(!buscarJugador(listaJugadores, tam, idIngresada, &indexJugador))
			{
				printf("/nERROR!!! No se encontro el ID ingresado.");
				mostrarJugador(listaJugadores, tam, listaConfederacion, tamConfederacion);
				idIngresada = getInt("\nIngrese el ID de la confederacion: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");
			}

		if(indexJugador != -1)
		{
		  system("cls");
			printf("\n%s %14s %21s %24s %17s %14s %16s","ID", "Nombre", "Posicion", "Numero Camiseta", "Confederacion", "Salario", "Contrato\n");
		  mostrarUnJugador(listaJugadores[indexJugador], listaConfederacion, tamConfederacion);
		  opcion = getEnteroRango("\nSe ha encontrado la Id ingresada !!\n\nQue desea modificar? \n\n1-Nombre\n\n2-Posicion\n\n3-Numero Camiseta\n\n4-Confederacion\n\n5-Salario\n\n6-Contrato\n\n7-Salir\n\nIngrese una opcion: ", "Usted ha ingresado una opcion incorrecta, reingrese: ", 1, 7);

			switch(opcion)
			{
				case 1:

					get_StringConEspacios("Ingrese el nuevo nombre: ", "Error, reingrese el nuevo nombre: ", auxNombre, TAMA);
					seguir = getCaracter("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Error, reingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
						{
							strcpy(listaJugadores[indexJugador].nombre, auxNombre);
							printf("\nNombre modificado con exito!!\n");
							system("pause");
							system("cls");
						}
						else
							{
								printf("\nSe ha cancelado la modificacion del Nombre\n");
								system("pause");
								system("cls");
							}
					break;

				case 2:

						mostrarPosiciones(posiciones, tamPosiciones);
						auxPosicion = getEnteroRango("\nIngrese el numero de la posicion del jugador: ", "Ingrese la posicion nuevamente(solo caracteres numericos): ", 1, 10);
						buscarPosicionEnLista(posiciones, tamPosiciones, auxPosicion, auxDescPosicion);
						seguir = getCaracter("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Error, reingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
					{
						strcpy(listaJugadores[indexJugador].posicion, auxDescPosicion);
						printf("\nNueva posicion modificado con exito!!\n");
						system("pause");
						system("cls");
					}
					else
					{
						printf("\nSe ha cancelado la modificacion de la posicion\n");
						system("pause");
						system("cls");
					}

					break;

				case 3:

					auxCamiseta = getEnteroRango("\nIngrese el numero de la camiseta: ", "Ingrese el numero de la camiseta nuevamente (Solo numeros): ", 0, 30);
					seguir = getCaracter("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					   if(seguir == 's')
						{
							listaJugadores[indexJugador].numeroCamiseta = auxCamiseta;
							printf("\nSe ha modificado el numero de la camiseta con exito!!\n");
							system("pause");
							system("cls");
						}
						else
						{
							printf("\nSe ha cancelado la modificacion de la camiseta\n");
							system("pause");
							system("cls");
						}
					break;

				case 4:
						printf("\n%s %19s %21s %24s ","ID", "Confederacion", "Region", "Anio Fundacion\n");
						mostrarConfederacion(listaConfederacion, tamConfederacion);
						auxConfederacionId = getInt("\nIngrese el ID de la confederacion: ", "Ingrese el ID nuevamente (solo caracteres numericos enteros): ");
						while(!buscarConfederacionJugador(listaConfederacion, tamConfederacion, auxConfederacionId, &indexConfederacion))
						{
							printf("/nERROR!!! No se encontro el ID ingresado.");
							mostrarConfederacion(listaConfederacion, tamConfederacion);
							auxConfederacionId = getInt("\nIngrese el ID de la confederacion: ", "Ingrese el ID nuevamente (solo caracteres numericos enteros): ");

						}
						seguir = getCaracter("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

						 if(seguir == 's')
						{
							listaJugadores[indexJugador].idConfederacion = auxConfederacionId;
							printf("\nSe ha modificado el ID con exito!!\n");
							system("pause");
							system("cls");
						}
						else
						{
							printf("\nSe ha cancelado la modificacion del ID\n");
							system("pause");
							system("cls");
						}

					break;

				case 5:
					auxSalario = getFlotante("\nIngrese el salario: ", "Vuelve a ingresar el salario(Solo caracter numerico): ");
					seguir = getCaracter("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
					{
						listaJugadores[indexJugador].salario = auxSalario;
						printf("\nSe ha modificado el salario con exito!!\n");
						system("pause");
						system("cls");
					 }
					 else
					{
						 printf("\nSe ha cancelado la modificacion del salario\n");
						 system("pause");
						 system("cls");
					}

					break;

				case 6:

					auxContrato = getInt("\nIngrese el anio del contrato(Del 1 al 7): ", "Ingrese nuevamente el anio del contrato(Solo caracter numerico): ");
					seguir = getCaracter("Esta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
					{
						listaJugadores[indexJugador].aniosContrato = auxContrato;
						printf("\nSe ha modificado el anio del contrato con exito!!\n");
						system("pause");
						system("cls");
					 }
					 else
					{
						 printf("\nSe ha cancelado la modificacion del contrato\n");
						 system("pause");
						 system("cls");
					}

					break;

				case 7:
					 printf("\nSe ha cancelado la modificacion de los jugadores\n");
					system("pause");
					system("cls");
					break;
			}
		}
		else
		{
			printf("\nNo se ha encontrado la id ingresada\n");
			system("pause");
			system("cls");
		}
}

void eliminarJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion)
{
	int idEliminar;
	int indexJugador;
	char seguir;

	system("cls");
	printf("\n\n### Jugadores encontrados ###\n");
	printf("\n%5s %9s %13s %11s %17s %9s %16s","ID", "Nombre", "Posicion", "Numero Camiseta", "Confederacion", "Salario", "Contrato\n");
	mostrarJugador(listaJugadores, tam, listaConfederacion, tamConfederacion);
	idEliminar = getInt("\nIngrese el ID del Jugador: ", "Ingrese el ID nuevamente (solo caracteres numericos enteros): ");

	while(!buscarJugador(listaJugadores, tam, idEliminar, &indexJugador))
	{
		printf("/nERROR!!! No se encontro el ID ingresado.");
		mostrarJugador(listaJugadores, tam, listaConfederacion, tamConfederacion);
		idEliminar = getInt("\nIngrese el ID de la confederacion: ", "Ingrese nuevamente el ID de la confederacion (solo caracteres numericos enteros): ");
	}

	if(idEliminar != -1)
		{
			system("cls");

			printf("\n\nListado de Jugadores encontrados\n");
			printf("\n%s %14s %21s %24s %17s %14s %16s","ID", "Nombre", "Posicion", "Numero Camiseta", "Confederacion", "Salario", "Contrato\n");
			mostrarUnJugador(listaJugadores[indexJugador], listaConfederacion, tamConfederacion);
			seguir = getCaracter("\nSe ha encontrado la id ingresada, esta seguro de querer continuar con la baja? Ingrese s(si) o n(no): ", "\nReingrese s(si) o n(no): ");

			if(seguir == 's')
				{
					borrarJugador(listaJugadores, tam, indexJugador, "\nSe ha eliminado el jugador con exito!!!\n");
					system("pause");
				}
				else
				{
					printf("\nUsted ha cancelado la baja del jugador\n");
					system("pause");
					system("cls");
				}
			}
}

void borrarJugador(eJugador listaJugadores[], int tam, int indice, char mensaje[])
{
	for(int i=0; i<tam; i++)
	{
		if(i == indice)
		{
			printf("%s", mensaje);
			listaJugadores[i].isEmpty = TRUE;
			break;
		}
	}
}


int menuJugador(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion)
{
	int suma;
	float promedio;
	int ContadorJugadorMaxSalario;
	char confederacionMasAnios[TAMA] = "";

	int continuar;

	do
		{
			system("cls");
			printf("#### Menu Mostrar ###");
			printf("\n\n1-Listado de los jugadores ordenados alfabeticamente por posicion y confederacion.\n");
			printf("2-Listado de confederaciones con sus jugadores.\n");
			printf("3-Total y promedio de todos los salarios y cuantos jugadores cobran mas del salario promedio.\n");
			printf("4-La confederación con mayor cantidad de anios de contratos total.\n");
			printf("5-Informar porcentaje de jugadores por cada confederacion.\n");
			printf("6-Informar cual es la región con más jugadores y el listado de los mismos.\n");
			printf("7-Salir.\n");

			continuar = getEnteroRango("\nIngrese una opcion: ", "Usted ha ingresado una opcion invalida: \n", 1, 7);

				switch(continuar)
					{
						case 1:
							system("cls");
							printf("Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.\n");
							printf("\n%s %14s %21s %24s %17s %14s %16s","ID", "Nombre", "Posicion", "Numero Camiseta", "Confederacion", "Salario", "Contrato\n");
							ordenarJugadorByNombreConfederacion(listaJugadores, tam, listaConfederacion, tamConfederacion);

							system("pause");
							system("cls");

									break;

						case 2:
							system("cls");
							printf("Listado de confederaciones con sus jugadores\n");
							printf("\n%s %14s %21s %24s %17s %14s %16s","ID", "Nombre", "Posicion", "Numero Camiseta", "Confederacion", "Salario", "Contrato\n");
							mostrarJugadorConfederacion(listaJugadores, listaConfederacion, tam, tamConfederacion);

							system("pause");
							system("cls");
							break;

						case 3:
							system("cls");
							printf("### Total y promedio de todos los salarios y cuantos jugadores cobran mas del salario promedio ###\n");
							printf("\n%s %14s %21s %24s %17s %14s %16s","ID", "Nombre", "Posicion", "Numero Camiseta", "Confederacion", "Salario", "Contrato\n");
							mostrarJugador(listaJugadores, tam, listaConfederacion, tamConfederacion);
							suma = sumarPrecios(listaJugadores, tam);
							promedio = salarioPromedio(listaJugadores, tam);
							ContadorJugadorMaxSalario = mostrarJugadorMayorSalario(listaJugadores, tam);
							printf("\nEl total de salario entre los pasajeros es: %.2d$", suma);
							printf("\nEl promedio de todos los salarios es: %.2f$", promedio);
							printf("\nLa cantidad de jugadores que cobran mas salario es: %d\n\n", ContadorJugadorMaxSalario);
							system("pause");
							system("cls");

							break;

						case 4:
							system("cls");
							printf("\n### La confederación con mayor cantidad de años de contratos total. ###\n");
							printf("\n%s %14s %21s %24s %17s %14s %16s","ID", "Nombre", "Posicion", "Numero Camiseta", "Confederacion", "Salario", "Contrato\n");
							mostrarConfederacionMasAnios(listaJugadores, listaConfederacion, tam, tamConfederacion, confederacionMasAnios);
					        fflush(stdin);

							printf("\nLa confederacion con mas anio de contratos es: %s\n", confederacionMasAnios);
							system("pause");
							system("cls");

							break;

						case 5:
							system("cls");
							printf("\n### Porcentaje de jugadores por cada confederacion. ###\n");
							printf("\n%s %14s %21s %24s %17s %14s %16s","ID", "Nombre", "Posicion", "Numero Camiseta", "Confederacion", "Salario", "Contrato\n");
							contarJugadorConfederacion(listaJugadores, listaConfederacion, tam, tamConfederacion);
							system("pause");
							system("cls");
							break;

						case 6:
							system("cls");
							printf("\n### Region con mayor cantidad de jugadores ###\n");
							printf("\n%s %14s %21s %24s %17s %14s %16s","ID", "Nombre", "Posicion", "Numero Camiseta", "Confederacion", "Salario", "Contrato\n");
							mostrarRegionMasJugadores(listaJugadores, tam, listaConfederacion, tamConfederacion);
							system("pause");
							system("cls");
							break;

						case 7:
							system("cls");
							printf("Volviendo al menu\n");
							system("pause");
							system("cls");
							break;
					}

						}while(continuar !=7);

		if(continuar == 7 || continuar > 7)
		{
			continuar = -1;
		}
		return continuar;
}


float sumarPrecios(eJugador listaJugadores[], int tam)
{
    int i;
    float AcumularSalarios = 0;

    for(i=0; i<tam; i++)
    {
        if(listaJugadores[i].isEmpty == FALSE)
        {
        	AcumularSalarios += listaJugadores[i].salario;
        }
    }
    return AcumularSalarios;
}

float salarioPromedio(eJugador listaJugadores[], int tam)
{
    int i;
    float PromedioSalario = 0;

    for(i=0; i<tam; i++)
    {
        if(listaJugadores[i].isEmpty == FALSE)
        {
        	PromedioSalario = sumarPrecios(listaJugadores, tam) / contarJugadores(listaJugadores, tam);
        }
    }
    return PromedioSalario;
}


int contarJugadores(eJugador listaJugadores[], int tam)
{
    int i;
    int ContadorJugador = 0;

    for(i=0; i<tam; i++)
    {
        if(listaJugadores[i].isEmpty == FALSE)
        {
        	ContadorJugador++;
        }
    }
    return ContadorJugador;
}


int mostrarJugadorMayorSalario(eJugador listaJugadores[], int tam)
{
    int i;
    float Promedio;
    int jugadorMayorSalario = 0;
    Promedio = salarioPromedio(listaJugadores, tam);

    for(i=0; i<tam; i++)
    {
        if(listaJugadores[i].isEmpty == FALSE && listaJugadores[i].salario > Promedio)
        {
        	jugadorMayorSalario++;
        }
    }
    return jugadorMayorSalario;
}

void mostrarJugadorConfederacion(eJugador listaJugadores[], eConfederacion listaConfederaciones[], int tam, int tamCon)
{
	int i;
	int j;

	for(i = 0; i<tamCon; i++)
	{
		for(j = 0; j<tam; j++)
		{
			if(listaConfederaciones[i].isEmpty == FALSE && listaConfederaciones[i].id == listaJugadores[j].idConfederacion)
			{
				mostrarUnJugadorConfederacion(listaJugadores[j], listaConfederaciones[i]);
			}
		}

	}

}

void ordenarJugadorByNombreConfederacion(eJugador listaJugadores[], int tam, eConfederacion listaConfederacion[], int tamConfederacion)
{
	eJugador aux;
	int i;
	int j;
	char auxCon[TAMA];
	char con[TAMA];

	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
				buscarConfederacion(listaConfederacion, tamConfederacion, listaJugadores[i].idConfederacion, con);
				buscarConfederacion(listaConfederacion, tamConfederacion, listaJugadores[j].idConfederacion, auxCon);

				if(strcmp(con, auxCon)<0)
				{
					aux = listaJugadores[i];
					listaJugadores[i] = listaJugadores[j];
					listaJugadores[j] = aux;
				}
				else
				{
					if((strcmp(con, auxCon)==0) && (strcmp(listaJugadores[i].nombre, listaJugadores[j].nombre)>0))
					{
						{
							aux = listaJugadores[i];
							listaJugadores[i] = listaJugadores[j];
							listaJugadores[j] = aux;
						}
					}
				}

					}
		}
	mostrarJugador(listaJugadores, tam, listaConfederacion, tamConfederacion);
}

int buscarConfederacion(eConfederacion listaConfederaciones[], int tam, int index, char* nombreConfederacion)
{
	int respuesta = 0;

	for(int i = 0; i<tam; i++)
	{
		if(listaConfederaciones[i].isEmpty == FALSE && listaConfederaciones[i].id == index)
		{
			strcpy(nombreConfederacion, listaConfederaciones[i].nombre);
			respuesta = 1;
		}
	}
	return respuesta;

}

void mostrarConfederacionMasAnios(eJugador listaJugadores[], eConfederacion listaConfederacion[], int tam, int tamConf, char* nombreConf)
{


	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorOFC = 0;



	for(int i = 0; i<tam; i++)
	{
		for(int j = 0; j<tamConf; j++)
		{
			if(listaConfederacion[j].isEmpty == FALSE && listaJugadores[i].idConfederacion == listaConfederacion[j].id)
			{
				buscarConfederacion(listaConfederacion, tamConf, listaJugadores[i].idConfederacion, nombreConf);

				if(listaJugadores[i].idConfederacion == 1000)
				{
					 contadorCONMEBOL = contadorCONMEBOL + listaJugadores[i].aniosContrato;
				}
				else if(listaJugadores[i].idConfederacion == 1001)
				{
					 contadorUEFA = contadorUEFA + listaJugadores[i].aniosContrato;
				}
				else if(listaJugadores[i].idConfederacion == 1002)
				{
					 contadorAFC = contadorAFC + listaJugadores[i].aniosContrato;
				}
				else if(listaJugadores[i].idConfederacion == 1003)
				{
					 contadorCAF = contadorCAF + listaJugadores[i].aniosContrato;
				}
				else if(listaJugadores[i].idConfederacion == 1004)
				{
					 contadorCONCACAF = contadorCONCACAF + listaJugadores[i].aniosContrato;
				}
				else if(listaJugadores[i].idConfederacion == 1005)
				{
					 contadorOFC = contadorOFC + listaJugadores[i].aniosContrato;
				}

			}
		}

	}
	if(contadorCONMEBOL>contadorUEFA && contadorCONMEBOL>contadorAFC && contadorCONMEBOL>contadorCAF && contadorCONMEBOL>contadorCONCACAF && contadorCONMEBOL>contadorOFC)
			{
				strcat(nombreConf, "CONMEBOL");
				printf("CONMEBOL con %d anios\n", contadorCONMEBOL);
				system("pause");
			}
			else if(contadorUEFA>contadorCONMEBOL && contadorUEFA>contadorAFC && contadorUEFA>contadorCAF && contadorUEFA>contadorCONCACAF && contadorUEFA>contadorOFC)
			{
				strcat(nombreConf, "UEFA");
				printf("UEFA con %d anios\n", contadorUEFA);
				system("pause");
			}
			else if(contadorAFC>contadorCONMEBOL && contadorAFC>contadorUEFA && contadorAFC>contadorCAF && contadorAFC>contadorCONCACAF && contadorAFC>contadorOFC)
			{
				strcat(nombreConf, "AFC");
				printf("AFC con %d anios\n", contadorAFC);
				system("pause");
			}
			else if(contadorCAF>contadorCONMEBOL && contadorCAF>contadorUEFA && contadorCAF>contadorAFC && contadorCAF>contadorCONCACAF && contadorCAF>contadorOFC)
			{
				strcat(nombreConf, "CAF");
				printf("CAF con %d anios\n", contadorCAF);
				system("pause");
			}
			else if(contadorCONCACAF>contadorCONMEBOL && contadorCONCACAF>contadorUEFA && contadorCONCACAF>contadorCAF && contadorCONCACAF>contadorAFC && contadorCAF>contadorOFC)
			{
				strcat(nombreConf, "CONCACAF");
				printf("CONCACAF con %d anios\n", contadorCONCACAF);
				system("pause");
			}
			else if(contadorOFC>contadorCONMEBOL && contadorOFC>contadorUEFA && contadorOFC>contadorCAF && contadorOFC>contadorAFC && contadorOFC>contadorCAF)
			{
				strcat(nombreConf, "OFC");
				printf("OFC con %d anios\n", contadorOFC);
				system("pause");
			}
}

float calcularPromedioJugador(float totalJugadores, float totalConfederacion)
{
	return (totalConfederacion * 100) / totalJugadores;
}

void contarJugadorConfederacion(eJugador listaJugadores[], eConfederacion listaConfederaciones[], int tam, int tamCon)
{
	int i;
	int j;

	int contadorConf = 0;

	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorOFC = 0;

	for(i = 0; i<tamCon; i++)
	{
		for(j = 0; j<tam; j++)
		{
			if(listaConfederaciones[i].isEmpty == FALSE && listaConfederaciones[i].id == listaJugadores[j].idConfederacion)
			{
				switch(listaJugadores[i].idConfederacion)
				{
					case 1000:
						contadorCONMEBOL++;

						break;

					case 1001:
						contadorUEFA++;

						break;

					case 1002:
						contadorAFC++;
						break;

					case 1003:
						contadorCAF++;

						break;

					case 1004:
						contadorCONCACAF++;

						break;

					case 1005:
						contadorOFC++;

						break;
				}

				contadorConf++;
			}
		}

	}
	mostrarPorcentajes(contadorCONMEBOL, contadorUEFA, contadorAFC, contadorCAF, contadorCONCACAF, contadorOFC, contadorConf);
}

void mostrarPorcentajes(int contadorCONMEBOL, int contadorUEFA, int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorOFC, int totalConf)
{
	printf("\nPorcentaje AFC: %.2f", calcularPromedioJugador(totalConf, contadorAFC));
	printf("\nPorcentaje CAF: %.2f", calcularPromedioJugador(totalConf, contadorCAF));
	printf("\nPorcentaje CONCACAF: %.2f", calcularPromedioJugador(totalConf, contadorCONCACAF));
	printf("\nPorcentaje CONMEBOL: %.2f", calcularPromedioJugador(totalConf, contadorCONMEBOL));
	printf("\nPorcentaje OFC: %.2f", calcularPromedioJugador(totalConf, contadorOFC));
	printf("\nPorcentaje UEFA: %.2f\n\n", calcularPromedioJugador(totalConf, contadorUEFA));
}

void mostrarRegionMasJugadores(eJugador listaJugadores[], int tamJugador, eConfederacion listaConfederaciones[], int tamConf)
{
	int i;
		int j;

		int contadorSudamerica = 0;
		int contadorEuropa = 0;
		int contadorAsia = 0;
		int contadorAfrica = 0;
		int contadorNorteYCentro = 0;
		int contadorOceania = 0;

		for(i = 0; i<tamJugador; i++)
		{
			for(j = 0; j<tamConf; j++)
			{
				if(listaConfederaciones[i].isEmpty == FALSE && listaConfederaciones[i].id == listaJugadores[j].idConfederacion)
				{
					switch(listaJugadores[i].idConfederacion)
					{
						case 1000:
							contadorSudamerica++;

							break;

						case 1001:
							contadorEuropa++;

							break;

						case 1002:
							contadorAsia++;
							break;

						case 1003:
							contadorAfrica++;

							break;

						case 1004:
							contadorNorteYCentro++;

							break;

						case 1005:
							contadorOceania++;

							break;
					}

				}

			}

		}
		if(contadorSudamerica>contadorEuropa && contadorSudamerica>contadorAsia && contadorSudamerica>contadorAfrica && contadorSudamerica>contadorNorteYCentro && contadorSudamerica>contadorOceania)
				{
					mostrarJugadorPorConfederacion(listaJugadores, tamJugador, listaConfederaciones, tamConf, 1000);
					printf("La region con mas jugadores es: Sudamerica\n");
					system("pause");
				}
				else if(contadorEuropa>contadorSudamerica && contadorEuropa>contadorAsia && contadorEuropa>contadorAfrica && contadorEuropa>contadorNorteYCentro && contadorEuropa>contadorOceania)
				{
					mostrarJugadorPorConfederacion(listaJugadores, tamJugador, listaConfederaciones, tamConf, 1001);
					printf("La region con mas jugadores es: Europa\n");

					system("pause");
				}
				else if(contadorAsia>contadorSudamerica && contadorAsia>contadorEuropa && contadorAsia>contadorAfrica && contadorAsia>contadorNorteYCentro && contadorAsia>contadorOceania)
				{
					mostrarJugadorPorConfederacion(listaJugadores, tamJugador, listaConfederaciones, tamConf, 1002);
					printf("La region con mas jugadores es: Asia\n");

					system("pause");
				}
				else if(contadorAfrica>contadorSudamerica && contadorAfrica>contadorEuropa && contadorAfrica>contadorAsia && contadorAfrica>contadorNorteYCentro && contadorAfrica>contadorOceania)
				{
					mostrarJugadorPorConfederacion(listaJugadores, tamJugador, listaConfederaciones, tamConf, 1003);
					printf("La region con mas jugadores es: Africa\n");

					system("pause");
				}
				else if(contadorNorteYCentro>contadorSudamerica && contadorNorteYCentro>contadorAfrica && contadorNorteYCentro>contadorEuropa && contadorNorteYCentro>contadorAsia && contadorNorteYCentro>contadorOceania)
				{
					mostrarJugadorPorConfederacion(listaJugadores, tamJugador, listaConfederaciones, tamConf, 1004);
					printf("La region con mas jugadores es: Norte Y Centro America\n");

					system("pause");
				}
				else if(contadorOceania>contadorSudamerica && contadorOceania>contadorEuropa && contadorOceania>contadorAfrica && contadorOceania>contadorNorteYCentro && contadorOceania>contadorAsia)
				{
					mostrarJugadorPorConfederacion(listaJugadores, tamJugador, listaConfederaciones, tamConf, 1005);
					printf("La region con mas jugadores es: Oceania\n");
					system("pause");
				}
}

void mostrarPosiciones(ePosicion listaPosiciones[], int tam)
{
	if (tam > 0) {

		for (int i = 0; i < tam; i++) {

			printf("\n%d %20s\n", listaPosiciones[i].codigo,
								   listaPosiciones[i].descripcion
					);
		}
	}
}

int buscarPosicionEnLista(ePosicion listaPosiciones[], int tam, int index, char* posicion)
{
	int respuesta = 0;

	for(int i = 0; i<tam; i++)
	{
		if(listaPosiciones[i].codigo == index)
		{
			strcpy(posicion, listaPosiciones[i].descripcion);
			respuesta = 1;
		}
	}
	return respuesta;

}

void mostrarJugadorPorConfederacion(eJugador listaJugadores[], int tamJugador, eConfederacion listaConfederaciones[], int tamConf, int idConf)
{
	int i;
	int indexConf;

	for(i = 0; i<tamJugador; i++)
	{
		if(listaJugadores[i].isEmpty == FALSE && listaJugadores[i].idConfederacion == idConf)
		{
			indexConf = buscarConfederacionPorId(listaConfederaciones, tamConf, idConf);
			mostrarUnJugadorConfederacion(listaJugadores[i], listaConfederaciones[indexConf]);
		}
	}
}
