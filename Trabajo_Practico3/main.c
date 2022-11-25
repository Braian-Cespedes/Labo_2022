#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Generic_bibliotec.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int orden = 0;
    int listar = 0;
	int flagJugadores = 0;
	int flagSelecciones = 0;
	int todoOk;
	int todoOkSelecciones;
	int confirmaSalida;
	int flagCambios = 0;
	int cargaArchivo;
	int guardarAchivo;
	int convocado;
	int flagCambiosSelecciones = 0;
	int cargaTextoJugadores = 0;
	int cargaTextoSelecciones = 0;
	int regenerarTexto;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do
    {
    	system("cls");
    	printf("//// Sistema de administracion de jugadores. ////\n");
    	printf("1) Cargar archivos de texto Jugador/Seleccion.\n");
    	printf("2) Alta de jugador.\n");
    	printf("3) Modificar datos del jugador.\n");
    	printf("4) Baja de jugador.\n");
    	printf("5) Listados.\n");
    	printf("6) Convocar jugadores.\n");
    	printf("7) Ordenar y listar.\n");
    	printf("8) Generar archivo binario.\n");
    	printf("9) Cargar archivo binario.\n");
    	printf("10) Guardar archivos .CSV.\n");
    	printf("11) Salir.\n");
    	fflush(stdin);

    	option = Get_IntRange("\nIngrese una opcion: ", "\nUsted ha ingresado una opcion incorrecta. Vuelve a intentarlo: ", 1, 11);

        switch(option)
        {
            case 1:

            	printf("\nQue tipo de archivo de texto desea cargar?\n\n1-Jugadores\n2-Selecciones\n3-Salir\n");
            	cargaArchivo = Get_IntRange("\nIngrese una opcion: ", "\nUsted ha ingressado una pcion incorrecta. Vuelve a intentarlo: ", 1, 3);

            	if(cargaArchivo == 1 && cargaTextoJugadores == 0)
            	{
                	flagJugadores = controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);

                	if(flagJugadores)
                	{
                		printf("\nArchivo de jugadores cargado con exito!!!\n");
                		cargaTextoJugadores = 1;
                	}
                	else
                		printf("\nArchivo de jugadores no encontrado\n");
            	}
            	else if(cargaArchivo == 2 && cargaTextoSelecciones == 0)
            	{
                	flagSelecciones = controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);

                	if (flagSelecciones)
                	{
                		printf("\nArchivo de selecciones cargado con exito!!!\n");
                		cargaTextoSelecciones = 1;
                	}
                	else
                		printf("\nArchivo de selecciones no encontrado\n");
            	}
            	else if(cargaArchivo == 3)
				{
            		printf("\nUsted ha cancelado la carga de archivos de texto\n");
				}
            	else
            		printf("\nYa se han cargado archivos de texto\n");

				system("pause");
				system("cls");

                break;

            case 2:
            	controller_agregarJugador(listaJugadores);
            	system("pause");
            	system("cls");
            	flagCambios = 1;

            	break;

			case 3:
				if(ll_len(listaJugadores))
					controller_editarJugador(listaJugadores);
				else
					printf("\nNo se encuentran jugadores en la lista\n");


				system("pause");
				system("cls");
            	flagCambios = 1;

				break;

			case 4:
			if (ll_len(listaJugadores))
			{
				if(controller_removerJugador(listaJugadores, listaSelecciones))
				{
					flagCambiosSelecciones = 1;
				}
				flagCambios = 1;
			}
			else
			{
				printf("\nNo se encuentran jugadores en la lista\n");
			}
				system("pause");
				system("cls");

			break;

			case 5:

				listar =Get_IntRange("\nQue entidad desea Ordenar?\n1)Todos los jugadores\n2)Todos las Selecciones\n3)Todos los jugadores convocados",
								"\nUsted ha ingresado la opcion incorrecta. Vuelve a intentarlo: ",1, 3);
				if (listar == 1) {
					if(ll_len(listaJugadores))
						controller_listarJugadores(listaJugadores);
					else
						printf("\nNo se encuentran jugadores en la lista\n");

				} else if (listar == 2) {
					if(ll_len(listaSelecciones))
						controller_listarSelecciones(listaSelecciones);
					else
						printf("\nNo se encuentran selecciones en la lista\n");
				} else {
					if(ll_len(listaSelecciones))
						controller_listarJugadoresConvocados(listaJugadores);
					else
						printf("\nNo se encuentran jugadores en la lista\n");
				}

				system("pause");
				system("cls");
				break;

			case 6:

				if (ll_len(listaSelecciones)) {

					if (ll_len(listaJugadores)) {
						orden =
							Get_IntRange(
									"\nCual es la tarea que desea realizar?\n1)Convocar Jugadores\n2)Desconvocar Jugadores",
									"\nUsted ha ingresado una opcion incorrecta. Vuelve a intentarlo: ",
									1, 2);

					if (orden == 1)
					{
						convocado = controller_convocarJugador(listaJugadores,
								listaSelecciones);
							if(convocado){
        							printf("\nJugador convocado correctamente...\n");
        							flagCambiosSelecciones = 1;
        							flagCambios = 1;
            				}
					}
					else
						if(controller_desconvocarJugador(listaJugadores,
								listaSelecciones)){
							printf("\nSe ha eliminado la convocatoria del jugador...\n");
							flagCambiosSelecciones = 1;
							flagCambios = 1;
						}
						else
							printf("\nNo se ha podido eliminar la convocatoria del jugador...\n");

					} else
						printf("\nNo se encuentran jugadores en la lista\n");
			} else {

				printf("\nNo se encuentran selecciones en el sistema, por favor cargue el archivo de selecciones primero\n\n");
			}

			system("pause");
			system("cls");

				break;

            case 7:

            	orden = Get_IntRange("\nQue entidad desea Ordenar?\n1)Jugadores\n2)Selecciones",
            			"\nUsted ha ingresado la opcion incorrecta. Vuelve a intentarlo: ", 1, 2);
            	if(orden == 1)
            	{
            		if(ll_len(listaJugadores))
            			controller_ordenarJugadores(listaJugadores);
            		else
        				printf("\nNo se encuentran jugadores en la lista\n");
            	}
            	else
            	{
            		if(ll_len(listaSelecciones))
            			controller_ordenarSelecciones(listaSelecciones);
            		else
            		    printf("\nNo se encuentran selecciones en la lista\n");
            	}
            	system("pause");
            	system("cls");
            	break;

            case 8:

            	if (!ll_isEmpty(listaJugadores)) {

				LinkedList *listFilter = ll_newLinkedList();

				listFilter = controller_listarJugadoresConfederacion(listaJugadores, listaSelecciones);

				if (ll_len(listFilter) > 0) {

					controller_guardarJugadoresModoBinario("data.dat", listFilter);
					controller_listarJugadores(listFilter);
					printf("\nArchivo Guardado con Exito\n\n");
					flagCambios = 0;

				} else
					printf("\nNo se puede guardar el archivo, ya que no existen jugadores asignados a la confederacion.\n\n");
			}
            else
				printf("\nNo se encuentran jugadores cargados en el sistema\n\n");


			system("pause");
			system("cls");

            	break;

            case 9:
            	todoOk = controller_cargarJugadoresDesdeBinario("data.dat", listaJugadores);
            	  if(todoOk==1)
            	  {
            		 controller_listarJugadores(listaJugadores);
            	     printf("\nArchivo cargado con exito\n");

            	  }
            	  else
            	     printf("\nNo se encontro el archivo binario \n");

            	  system("pause");
            	  system("cls");

            	break;

            case 10:

            	printf("\nQue tipo de archivo de texto desea guardar?\n\n1-Jugadores\n2-Selecciones\n3-Salir\n");
            	guardarAchivo = Get_IntRange("\nIngrese una opcion: ", "\nUsted ha ingresado una opcion incorrecta. Vuelve a intentarlo: ", 1, 3);

            	if(guardarAchivo == 1)
            	{
            		if (!ll_isEmpty(listaJugadores)){

            			todoOk = controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
            			if(todoOk)
            			{
            				printf("\nArchivos de jugadores guardado con exito!!!\n");
            				flagCambios = 0;

            				printf("\nUsted ha guardado un archivo de texto, desea volver a cargar los datos?\n\n1-Si\n2-No\n");
            				regenerarTexto = Get_IntRange("\nIngrese una opcion: ", "\nUsted ha ingresado una opcion incorrecta. Vuelve a intentarlo: ", 1, 2);

						if (regenerarTexto == 1) {

							ll_deleteLinkedList(listaJugadores);
							cargaTextoJugadores = 0;
							printf("\nUsted ha regenerado la lista, vuelva a cargar los archivos de jugadores\n");
							listaJugadores = ll_newLinkedList();

						} else
							printf("\nUsted ha cancelado la regeneracion de la lista\n");

            			}
            			else
            				printf("\nHa ocurrido un error al guardar el archivo de jugadores\n");
            			}
            		else
        				printf("\nNo se encuentran jugadores para guardar\n");
            	}
            	else if(guardarAchivo == 2)
            	{
            		if (!ll_isEmpty(listaSelecciones)){

            			todoOkSelecciones = controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones);
                	if(todoOkSelecciones)
                	{
                	    printf("\nArchivos de selecciones guardado con exito!!!\n");
                	    flagCambiosSelecciones = 0;

                	    printf("\nUsted ha guardado un archivo de texto, desea volver a cargar los datos?\n\n1-Si\n2-No\n");
                	    regenerarTexto = Get_IntRange("\nIngrese una opcion: ", "\nUsted ha ingresado una opcion incorrecta. Vuelve a intentarlo: ", 1, 2);

                	    if(regenerarTexto == 1)
                	    {
                	    	ll_deleteLinkedList(listaSelecciones);
                	    	cargaTextoSelecciones = 0;
                     	    printf("\nUsted ha regenerado la lista, vuelva a cargar los archivos de selecciones\n");
                     	    listaSelecciones = ll_newLinkedList();
                	    }
                	    else
                    	    printf("\nUsted ha cancelado la regeneracion de la lista de selecciones\n");
                	}
                	else
                	    printf("\nHa ocurrido un error al guardar el archivo de selecciones\n");
            		}
            		else
        				printf("\nNo se encuentran selecciones para guardar\n");

            	}
            	else
            		 printf("\nSe ha cancelado el guardado de archivos de texto\n");

				system("pause");
				system("cls");

            	break;

            case 11:

            	if(flagCambios != 0 && flagCambiosSelecciones != 0)
            	{
            		printf("\nSe han detectado cambios sin guardar en los archivos de jugadores y selecciones, Desea continuar con la salida del programa?\n\n");
            		confirmaSalida = Validate_Exit_SN("Ingrese S/s para continuar o N/n para cancelar: ", "Ha ingrsado un caracter invalido: ");

            			if (confirmaSalida) {

            				printf("\nSe ha confirmado la salida del programa\n");
            				option = 12;
            			} else{

            				printf("\nSe ha cancelado la salida del programa\n");
            				system("pause");
            			}
            	}
            	else if(flagCambiosSelecciones != 0)
            	{
            		printf("\nSe han detectado cambios sin guardar en el archivo de selecciones, Desea continuar con la salida del programa?\n\n");
            		confirmaSalida = Validate_Exit_SN("Ingrese S/s para continuar o N/n para cancelar: ", "Ha ingrsado un caracter invalido: ");

            			if (confirmaSalida) {

            				printf("\nSe ha confirmado la salida del programa\n");
            				option = 12;
            			} else{

            				printf("\nSe ha cancelado la salida del programa\n");
            				system("pause");
            			}
				}
            	else if(flagCambios != 0)
            	{
				printf("\nSe han detectado cambios sin guardar en el archivo de jugadores, Desea continuar con la salida del programa?\n\n");
				confirmaSalida = Validate_Exit_SN(
						"Ingrese S/s para continuar o N/n para cancelar: ",
						"Ha ingrsado un caracter invalido: ");

					if (confirmaSalida) {
						printf("\nSe ha confirmado la salida del programa\n");
						option = 12;
					} else {
						printf("\nSe ha cancelado la salida del programa\n");
						system("pause");
					}
            	}
            	else
            	{
            		printf("\nEsta a punto de salir del programa\n\n");

            		confirmaSalida = Validate_Exit_SN(
						"Ingrese S/s para continuar o N/n para cancelar: ",
						"Ha ingrsado un caracter invalido: ");

            		if (confirmaSalida) {
            			printf("\nSe ha confirmado la salida del programa\n");
            			option = 12;

            		} else {
            			printf("\nSe ha cancelado la salida del programa\n");
            			system("pause");
            		}
            	}
            	break;
        }
    }while(option != 12);

    return 0;
}

