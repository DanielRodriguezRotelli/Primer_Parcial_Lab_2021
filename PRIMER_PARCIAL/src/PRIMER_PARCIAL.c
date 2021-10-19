/*
 ============================================================================
 Name        : PRIMER_PARCIAL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Salon.h"
#include "Arcade.h"
#include "Informes.h"

#define SALON_LEN 10
#define ARCADE_LEN 10
#define JUEGOS_LEN 10
#define SHOPPING 0
#define LOCAL 1


int main(void)
{
	setbuf(stdout, NULL);

	Salon salones[SALON_LEN];
	Arcade arcades[ARCADE_LEN];
	Game juegos[JUEGOS_LEN];


	int opcionDeMenu;
	int emptyPositionSalon;
	int fullPositionSalon;
	int posicionIdSalonABajar;
	int idSalonBuscado;
	int emptyPositionArcade;
	int fullPositionArcade;
	int posicionBajaArcade;
	int IdArcadeBuscado;
	int posicionIdArcadeAModificar;
	int opcionMenuInforme;





	salon_initList(salones,SALON_LEN);
	arcade_initList(arcades,ARCADE_LEN);

	salon_altaForzada(salones, SALON_LEN, 0, 1, "Salon A", "Avellaneda", SHOPPING);
	salon_altaForzada(salones, SALON_LEN, 1, 2, "Salon B", "WILDE", LOCAL);
	salon_altaForzada(salones, SALON_LEN, 2, 3, "Salon C", "FLORES", SHOPPING);

	arcade_altaForzada(arcades,ARCADE_LEN,0,1,"Juju","Argentino",1,300,2 ,1);
	arcade_altaForzada(arcades,ARCADE_LEN,1,2,"Juju","Paraguay",1,500,4 ,1);
	arcade_altaForzada(arcades,ARCADE_LEN,2,3,"PacMan","Nippon",0,300,1 ,1);
	arcade_altaForzada(arcades,ARCADE_LEN,3,4,"Futbol200","Korea",1,600,4,3);
	arcade_altaForzada(arcades,ARCADE_LEN,4,5,"Daytona","France",1,300,2 ,3);
	arcade_altaForzada(arcades,ARCADE_LEN,5,6,"Tetris","URRS",1,500,4 ,3);
	arcade_altaForzada(arcades,ARCADE_LEN,6,7,"Simpsons","USA",0,300,1 ,1);
	arcade_altaForzada(arcades,ARCADE_LEN,7,8,"KungFu Master","China",1,600,4,3);
	arcade_altaForzada(arcades,ARCADE_LEN,8,9,"Wonder Boy","USA",0,300,1 ,1);
	arcade_altaForzada(arcades,ARCADE_LEN,9,10,"Street Fighter","China",1,600,4,3);



	//printArrayList(displayList, DISPLAYS_LEN);

	//switch(opcion)
	do
	{
		menuPrincipal(&opcionDeMenu);

		switch(opcionDeMenu)
		{
			case 1:
			if(salon_buscarPosicionLibre(salones, SALON_LEN, &emptyPositionSalon)==0)
			{
				salon_altaForzada(salones, SALON_LEN, 0, 1, "Salon A", "Avellaneda", SHOPPING);
				salon_altaForzada(salones, SALON_LEN, 1, 2, "Salon B", "WILDE", LOCAL);
				salon_altaForzada(salones, SALON_LEN, 2, 3, "Salon C", "FLORES", SHOPPING);
				if(salon_loadArray(&salones[emptyPositionSalon])==0)
				{
					printf("\nSalon creado:\n");
					printf("	Id		Nombre		Direccion		Tipo	");
					salon_printCompleto(&salones[emptyPositionSalon]);
				}
				else
				{
					printf("No se pudo dar alta");
				}
			}
			else
			{
				printf("No hay espacio disponible para dar alta.\n");
			}
			break;

			case 2:
			if(salon_buscarPosicionOcupado(salones,SALON_LEN,&fullPositionSalon)==0)
			{
				salon_printArrayAEliminar(salones,SALON_LEN);
				//salon_printArraySalon(salones,SALON_LEN);
				if(salon_buscarPosicionId(salones,SALON_LEN,&posicionIdSalonABajar)==0)
				{
					if(salon_bajaArray(salones,SALON_LEN,posicionIdSalonABajar)==0)
					{
						printf("El id: %d se ha eliminado",salones[posicionIdSalonABajar].idSalon);
					}
				}
			}
			else
			{
				printf("No se puede dar de Baja. No hay altas cargadas.");
			}
			break;


			case 3:
			if(salon_buscarPosicionOcupado(salones, SALON_LEN,&fullPositionSalon)==0)
			{
				salon_printArrayCompleto(salones,SALON_LEN);
			}
			else
			{
				printf("No se puede imprimir. No hay altas ingresadas.");
			}
			break;

			case 4:
			if(salon_buscarPosicionOcupado(salones, SALON_LEN,&fullPositionSalon)==0)
			{
				if(arcade_buscarPosicionLibre(arcades,ARCADE_LEN,&emptyPositionArcade)==0)
				{
					salon_printArrayCompleto(salones,SALON_LEN);
					printf("\nA que salon quiere asociar el arcade?");
					if(salon_buscarId(salones,SALON_LEN,&idSalonBuscado)==0)
					{
						if(arcade_loadArray(arcades,idSalonBuscado)==0)
						{
							printf("\nArcade creado:\n");
							printf("\nId Arcade		Nombre		Nacionalidad		Cant.Jugadores		Tipo Sonido		Capacidad Fichas		Id Salon	");								arcade_printCompleto(&arcades[emptyPositionArcade]);
							//printf("Id de Arcade creado: %d",arcades[emptyPositionArcade].idArcade);
						}
						else
						{
							printf("No se pudo dar alta");
						}
					}
				}
				else
				{
					printf("No se puede cargar arcades. No hay posiciones libres para realizar el alta.");
				}
			}
			else
			{
				printf("No se puede cargar arcades. No hay salones dados de alta.");
			}

			break;

			case 5:
			if(arcade_buscarPosicionOcupado(arcades,ARCADE_LEN,&fullPositionArcade)==0)
			{
				arcade_printArrayCompleto(arcades,ARCADE_LEN);
				if(arcade_buscarId(arcades,ARCADE_LEN,&IdArcadeBuscado)==0)
				{
					if(arcade_buscarPosicionId(arcades,ARCADE_LEN,IdArcadeBuscado,&posicionIdArcadeAModificar)==0)
					{
						if(arcade_modificarArray(arcades,ARCADE_LEN,posicionIdArcadeAModificar)==0)
						{
							printf("Se ha modificado el id de arcade %d",arcades[posicionIdArcadeAModificar].idArcade);

						}
					}
				}

			}
			else
			{
				printf("No se puede modificar. No hay arcades dados de alta.");
			}

			break;

			case 6:
			if(arcade_buscarPosicionOcupado(arcades,ARCADE_LEN,&fullPositionArcade)==0)
			{
				arcade_printArrayCompleto(arcades,ARCADE_LEN);
				if(arcade_buscarId(arcades,ARCADE_LEN,&IdArcadeBuscado)==0)
				{
					if(arcade_buscarPosicionId(arcades,ARCADE_LEN,IdArcadeBuscado,&posicionBajaArcade)==0)
					{
						printf("\n	Id		Nombre		Nacionalidad		Cant.Jugadores		Tipo Sonido		Capacidad Fichas		Id Salon	");
						arcade_printCompleto(&arcades[posicionBajaArcade]);
						if(arcade_bajaArray(arcades,ARCADE_LEN,IdArcadeBuscado,posicionBajaArcade)==0)
						{
							printf("\nEl id: %d se ha eliminado",arcades[posicionBajaArcade].idArcade);
						}


						//getText(&respuestaEliminarArcade,1,"\nEstá seguro que quiere eliminar el arcade: s/n", "Error.", 3);
						//if(respuestaEliminarArcade=="s")
						//{
							//if(arcade_bajaArray(arcades,ARCADE_LEN,posicionBajaArcade)==0)
							//{
							//	printf("\nEl id: %d se ha eliminado",arcades[posicionBajaArcade].idArcade);
							//}
						//}
					}
				}

			}
			else
			{
				printf("No se puede eliminar. No hay arcades dados de alta.");
			}
			break;

			case 7:
			if(arcade_buscarPosicionOcupado(arcades,ARCADE_LEN,&fullPositionArcade)==0)
			{
				arcade_printArrayCompleto(arcades,ARCADE_LEN);
			}
			else
			{
				printf("No se puede imprimir. No hay arcades dados de alta.");
			}

			break;

			case 8:
			if(arcade_buscarPosicionOcupado(arcades,ARCADE_LEN,&fullPositionArcade)==0)
			{
				//arcade_printListaJuegos(arcades,ARCADE_LEN);
				//game_printListaJuegos(juegos,JUEGOS_LEN);
				game_imprimirJuegos(arcades,ARCADE_LEN);
				//game_imprimirJuegos(arcades,ARCADE_LEN,juegos);
			}

			else
			{
				printf("No se puede listar juegos. No hay arcades dados de alta.");
			}

			break;

			case 9:
			if(salon_buscarPosicionOcupado(salones, SALON_LEN,&fullPositionSalon)==0)
			{
				do
				{
					salon_MenuInformes(&opcionMenuInforme);
					switch(opcionMenuInforme)
					{
						case 1:
						if(inf_ContDeArcade(arcades,ARCADE_LEN)>0)
						{
							inf_salonesCuatroArcade(salones,SALON_LEN,arcades,ARCADE_LEN);
						}

						break;

						case 2:
						inf_ArcadeDosJugadores(arcades,ARCADE_LEN,salones,SALON_LEN);
						break;

						case 3:
						break;

						case 4:
						break;

						case 5:
						break;

						case 6:
						break;

						case 7:
						break;

					}
				}while(opcionMenuInforme!=8);
			}
			else
			{
				printf("No se pueden realizar informes. No hay salones y arcades dados de altas.");
			}
			break;


			case 10:
			printf("Usted salió del menu.");
			break;
		}

	}while(opcionDeMenu!=10);


	return EXIT_SUCCESS;
}
