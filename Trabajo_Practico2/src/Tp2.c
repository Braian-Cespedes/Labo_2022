#include <stdio.h>
#include <stdlib.h>

#include "ArrayJugadores.h"
#include "Generic_Functions.h"

int main(void)
{
	setbuf(stdout,NULL);

	int IdIncremental = 0;
	int seguir;
	int continuar;
	int ControlFlag = 0;
	ePosicion posicion[10] = {{1, "Portero"}, {2, "Defensa central"},
			{3,"Lateral izquierdo"}, {4, "Lateral derecho"}, {5, "Pivote"}, {6, "Mediocentro"},
			{7, "Extremo izquierdo"}, {8, "Extremo derecho"}, {9, "Mediapunta"}, {10, "Delantero centro"}};



	int* pFlag = &ControlFlag;

	eJugador listaJugadores[P];
	eConfederacion listaConfederacion[6];

	initJugador(listaJugadores, P);
	InicializarConfederacion(listaConfederacion, 6);

	harcodearJugador(listaJugadores, &IdIncremental, 6, pFlag);
	harcodearConfederacion(listaConfederacion, 6);

	do
		{
			system("cls");
			printf("#### Menu de jugadores de FIFA ###");
			printf("\n\n1-Ingresar un jugador.\n");
			printf("2-Modificar jugador.\n");
			printf("3-Eliminar jugador.\n");
			printf("4-Informar.\n");
			printf("5-Salir.\n");
			fflush(stdin);
			seguir = getEnteroRango("\nIngrese una opcion ", "\nUsted ha ingresado una opcion invalida, reingrese ", 1, 5);

			switch(seguir)
			{
				case 1:

					IdIncremental++;
					addOneJugador(listaJugadores, P,IdIncremental, listaConfederacion, 6, posicion, 10);
					ControlFlag = 1;

				    break;

				case 2:

					if(ControlFlag != 0)
					{
						modificarJugador(listaJugadores, P, listaConfederacion, 6, posicion, 10);
						system("cls");
					}
					else
					{
						printf("\nTiene que haber almenos un pasajero registrado para poder acceder a esta opcion.\n\n");
						system("pause");
						system("cls");
					}
				    	break;

				case 3:

					if(ControlFlag != 0)
					{
						system("cls");
						eliminarJugador(listaJugadores, P, listaConfederacion, 6);
						system("cls");
					}
					else
					{
						printf("\nTiene que haber almenos un pasajero cargado para poder acceder a esta opcion.\n\n");
						system("pause");
						system("cls");
					}
				    	break;

				case 4:

				if(ControlFlag != 0)
				{
					continuar = menuJugador(listaJugadores, P, listaConfederacion, 6);

					if(continuar == -1)
					{
						printf("\nSera redireccionado al menu principal\n\n");
						system("pause");
						system("cls");
					}
				}
				else
				{
					printf("\nTiene que haber almenos un jugador cargado para poder acceder a esta opcion.\n\n");
					system("pause");
					system("cls");
				}
			    	break;

				case 5:

					system("cls");

		            break;
			}
		}while(seguir != 5);
}
