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

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();


    //puts("funciona ok");

    do
    {
    	printf("//// Sistema de administracion de jugadores. ////\n");
    	printf("1) Cargar datos desde el archivo data.csv(Modo texto, binario).\n");
    	printf("2) Alta de jugador.\n");
    	printf("3) Modificar datos del jugador.\n");
    	printf("4) Baja de jugador.\n");
    	printf("5) Listados.\n");
    	printf("6) Convocar jugadores.\n");
    	printf("7) Ordenar y listar.\n");
    	printf("8) Generar archivo binario.\n");
    	printf("9) Cargar archivo binario.\n");
    	printf("10) Guardar archivo .CSV.\n");
    	printf("11) Salir.\n");
    	fflush(stdin);

    	option = Get_IntRange("\nIngrese una opcion: ", "\nUsted ha ingressado una pcion incorrecta. Vuelve a intentarlo: ", 1, 11);

        switch(option)
        {
            case 1:
            	flagJugadores = controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	flagSelecciones = controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);

            	if(flagJugadores == 1 && flagSelecciones == 1)
            		printf("\nArchivos cargados con exito!!!\n");
            	else if(flagJugadores == 1 && flagSelecciones == 0)
            		printf("\nArchivo de selecciones no encontrado\n");
            	else if(flagJugadores == 0 && flagSelecciones == 1)
            		printf("\nArchivo de jugadores no encontrado\n");
            	else
            		printf("\nArchivos no encontrados\n");

				system("pause");
				system("cls");

                break;

            case 2:
            	controller_agregarJugador(listaJugadores);
            	system("pause");
            	system("cls");
            	break;

			case 3:
				if(ll_len(listaJugadores))
					controller_editarJugador(listaJugadores);
				else
					printf("\nNo se encuentran jugadores en la lista\n");


				system("pause");
				system("cls");
				break;

			case 4:
			if (ll_len(listaJugadores))
				controller_removerJugador(listaJugadores, listaSelecciones);
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
			if (ll_len(listaJugadores))
			{
				orden =
						Get_IntRange(
								"\nCual es la tarea que desea realizar?\n1)Convocar Jugadores\n2)Desconvocar Jugadores",
								"\nUsted ha ingresado una opcion incorrecta. Vuelve a intentarlo: ",
								1, 2);
				if (orden == 1)
					controller_convocarJugador(listaJugadores,
							listaSelecciones);
				else
					controller_desconvocarJugador(listaJugadores,
							listaSelecciones);

			}
			else
				printf("\nNo se encuentran jugadores en la lista\n");

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
            	todoOk = controller_guardarJugadoresModoBinario("data.dat", listaJugadores);
            	 if(todoOk==1)
            		printf("\nGuardado con exito\n");
            	 else
            	      printf("\nNo se pudo guardar \n");

            	  system("pause");
            	  system("cls");

            	break;

            case 9:
            	todoOk = controller_cargarJugadoresDesdeBinario("data.dat", listaJugadores);
            	  if(todoOk==1)
            	     printf("\nArchivo cargado con exito\n");
            	  else
            	     printf("\nNo se pudo cargar el archivo \n");

            	  system("pause");
            	  system("cls");

            	break;

            case 10:
            	todoOk = controller_guardarJugadoresModoTexto("data.dat", listaJugadores);
            	todoOkSelecciones = controller_guardarSeleccionesModoTexto("dataSelecciones.dat", listaSelecciones);

            	if(todoOk == 1 && todoOkSelecciones == 1)
            		printf("\nArchivos guardados con exito!!!\n");
            	else if (todoOk == 1 && todoOkSelecciones == 0)
            		printf("\nHa ocurrido un error al guardar el archivo de selecciones\n");
            	else if (todoOk == 0 && todoOkSelecciones == 1)
            		printf("\nHa ocurrido un error al guardar el archivo de jugadores\n");
            	else
            		printf("\nNo se han podido guardar los archivos\n");

				system("pause");
				system("cls");

            	break;
        }
    }while(option != 11);

    return 0;
}

