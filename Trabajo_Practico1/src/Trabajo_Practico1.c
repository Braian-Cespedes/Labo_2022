/*
 ============================================================================
 Name        : Trabajo_Practico1.c
 Author      : Cespedes Braian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int main(void)
{
	setbuf(stdout,NULL);

	int validatedOption;
	int flagCostos, flagCalculo, flagTax, flagCargaForzada = 0;
	float avgAfc, avgCaf, avgConcaf, avgConmebol, avgUefa, avgOfc;
	float priceHospedaje = 0;
	float priceComida = 0;
	float priceTransporte = 0;
	int numArqueros = 0;
	int numDefensores = 0;
	int numDelanteros = 0;
	int numMedCampistas = 0;
	int numAfc = 0;
	int numCaf = 0;
	int numConcaf = 0;
	int numConmebol = 0;
	int numUefa = 0;
	int numOfc = 0;
	int numJugadores = 0;
	float totalMantenimiento;
	float impuestoUefa;
	float taxValue;

	do
	{
		system("cls");
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		ShowPlayers(&numArqueros, &numDefensores, &numDelanteros, &numMedCampistas);
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		ShowPrices(&priceHospedaje, &priceComida, &priceTransporte);
	    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	    printf("\t%c MENU DE INGRESOS %c\n",186,186);
	    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("\n1)Ingreso de costos de mantenimiento.");
		printf("\n2)Ingreso de jugadores.");
		printf("\n3)Calculo total de costos.");
		printf("\n4)Informe de resultados.");
		printf("\n5)Carga forzada de datos.");
		printf("\n6)Salida.");
		validatedOption =  GetIntRange("\n\nIngrese una opcion del menu ", "\nError Reingrese una opcion valida", 1, 6);

		switch(validatedOption)
		{
			case 1:
				SecondaryMenu("\n1)Ingresar precio de hospedaje.",
							  "\n2)Ingresar precio de comida.",
							  "\n3)Ingresar precio del transporte.",
							  "\n4)Salir.", &priceHospedaje, &priceComida, &priceTransporte);
				flagCostos = 1;
				break;

			case 2:
				if(!flagCargaForzada)
				{
					PlayersMenu("1)Arquero",
							   "\n2)Defensor",
							   "\n3)Delantero",
							   "\n4)Medio Campista",
							   "\n5)Salir",
							   &numArqueros, &numDefensores, &numDelanteros, &numMedCampistas,
							   &numAfc, &numCaf, &numConcaf, &numConmebol, &numUefa, &numOfc, &numJugadores);
				}
				else
				printf("\nSe ha detectado una carga forzada activa, no se podran ingresar mas jugadores al sistema ya que el plantel se encuentra completo\n");
				system("pause");
				break;

			case 3:

				if(flagCostos == 1 && numJugadores > 0)
				{
					avgAfc = AveragePlayers(numJugadores, numAfc);
					avgCaf = AveragePlayers(numJugadores, numCaf);
					avgConcaf = AveragePlayers(numJugadores, numConcaf);
					avgConmebol = AveragePlayers(numJugadores, numConmebol);
					avgUefa = AveragePlayers(numJugadores, numUefa);
					avgOfc = AveragePlayers(numJugadores, numOfc);
					totalMantenimiento = TotalMaintenance(priceComida, priceHospedaje, priceTransporte);

					if(numUefa > numAfc && numUefa > numConmebol && numUefa > numConcaf && numUefa > numOfc && numUefa > numCaf)
					{
						taxValue = totalMantenimiento * 0.35;
						impuestoUefa = TaxesPrice(totalMantenimiento);
						flagTax = 1;
					}

					flagCalculo = 1;
					printf("\nCostos calculados con exito\n\n");
					system("pause");
				}
				else
				{
					printf("\nIngrese todos los datos antes de continuar con esta opcion.\n\n");
					system("pause");
					system("cls");
				}
				break;

			case 4:
				if(flagCalculo == 1)
				{
					system("cls");
					printf("\na) Porcentaje de jugadores (UEFA): %.2f%%", avgUefa);
					printf("\nd) Porcentaje de jugadores (CONMEBOL): %.2f%%", avgConmebol);
					printf("\nc) Porcentaje de jugadores (CONCAF): %.2f%%", avgConcaf);
					printf("\nf) Porcentaje de jugadores (AFC): %.2f%%", avgAfc);
					printf("\ne) Porcentaje de jugadores (OFC): %.2f%%", avgOfc);
					printf("\nb) Porcentaje de jugadores (CAF): %.2f%%", avgCaf);
					printf("\n\nEl costo total del mantenimiento es: $%.2f", totalMantenimiento);

					if(flagTax == 1)
						printf("\n\nEl valor original de mantenimiento $%.2f sufrio un aumento del 35%% ($%.2f), por lo tanto, el nuevo valor es: $%.2f\n\n", totalMantenimiento, taxValue, impuestoUefa);
					else
						printf("\nEl impuesto del (+35%%) no puede ser aplicado, ya que el porcentaje de jugadores de la UEFA %.2f%% no compone a la mayoria del plantel.\n\n",
								avgConmebol);


					if(flagCargaForzada != 0)
					{
						priceHospedaje = 0;
						priceComida = 0;
						priceTransporte = 0;
						flagCostos = 0;

						numArqueros = 0;
						numDefensores = 0;
						numMedCampistas = 0;
						numDelanteros = 0;
						numJugadores = 0;

						numAfc = 0;
						numCaf = 0;
						numConcaf = 0;
						numConmebol = 0;
						numUefa = 0;
						numOfc = 0;

						flagCostos = 0;
						flagCargaForzada = 0;
					}
						flagCalculo = 0;
						system("pause");
						system("cls");
				}
				else
				{
					printf("\nDebe ingresar a la opcion 3 antes de poder mostrar los resultados\n\n");
					system("pause");
					system("cls");
				}
				break;

			case 5:
				 priceHospedaje = 20000;
				 priceComida = 40000;
				 priceTransporte = 50000;

				 numArqueros = 2;
				 numDefensores = 8;
				 numMedCampistas = 8;
				 numDelanteros = 4;
				 numJugadores = 22;

				 numAfc = 1;
				 numCaf = 2;
				 numConcaf = 1;
				 numConmebol = 3;
				 numUefa = 12;
				 numOfc = 3;

				 avgAfc = AveragePlayers(numJugadores, numAfc);
				 avgCaf = AveragePlayers(numJugadores, numCaf);
				 avgConcaf = AveragePlayers(numJugadores, numConcaf);
				 avgConmebol = AveragePlayers(numJugadores, numConmebol);
				 avgUefa = AveragePlayers(numJugadores, numUefa);
				 avgOfc = AveragePlayers(numJugadores, numOfc);
				 totalMantenimiento = TotalMaintenance(priceComida, priceHospedaje, priceTransporte);
				 impuestoUefa = TaxesPrice(totalMantenimiento);

				 flagCostos = 1;
				 flagCargaForzada = 1;

				 printf("\nCarga forzada realizada con exito\n\n");
				 system("pause");
				 break;

			case 6:
				printf("\nEsta saliendo del sistema de carga de jugadores\n\n");
				system("pause");
				break;
		}
	}while(validatedOption != 6);
}
