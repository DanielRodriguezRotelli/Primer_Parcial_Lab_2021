/*
 * Informes.c
 *
 *  Created on: 19 oct. 2021
 *      Author: Aye
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Salon.h"
#include "Arcade.h"
#include "Informes.h"


#define LIBRE 1
#define OCUPADO 0


#define SALON_LEN 10
#define ARCADE_LEN 10
#define JUEGOS_LEN 10






/**
 * \brief Realiza el menu principal del programa
 * \param opcionesDeMenu correspondiente a la opcion elegida por el usuario pasado por punter
 * \param la funcion muestra el menu y pide al usuario que ingrese la opcion elegida.
 * \return no devuelve nada.
 */
void menuPrincipal(int* opcionDeMenu)
{
	int opcion;

	do
	{
		getInt(&opcion,1,11,3,"\n\n--MENU PRINCIPAL-- "
				"\n1) Alta de Salon. "
				"\n2) Eliminar Salon. "
				"\n3) Imprimir Salones. "
				"\n4) Incorporar Arcade. "
				"\n5) Modificar Arcade. "
				"\n6) Eliminar Arcade. "
				"\n7) Imprimir Arcades. "
				"\n8) Imprimir Juegos. "
				"\n9) Informes. "
				"\n10) Salir del Menu Principal"
				"\nIngrese la opcion deseada: ", "Error");
	}while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 && opcion!=6 && opcion!=7 && opcion!=8 && opcion!=9 && opcion!=10);
	*opcionDeMenu=opcion;
}



/**
 * \brief Inicializa el Array Juego.
 * \param Game* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param la funcion coloca en 1 o 0 las banderas de isEmpty.
 * \return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
void game_initList(Game* list, int len)
{
	int indice;
	int retorno=0;

	if(list!=NULL && len>0)
	{

		for(indice=0; indice<len; indice++)
		{
			list[indice].isEmpty=1;
			retorno=1;
		}
	}
}



/**
 * \brief Busca un campo en un Array
 * \param Game* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param juegos[] correspondiente a al array
 * \param la funcion recibe un array y busca si esta en la estructura
 * \return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int game_estaJuegoEnLista(Game* list, int len,char juegos[])
{
	int i;
	int retorno=0;
	if(list!=NULL && len>0 && juegos!=NULL)
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			//hay un cuit valido, lo comparo con "cuit"
			if(strncmp(list[i].Juegos,juegos,JUEGOS_LEN)==0)
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}


#define CANTIDAD_ARCADE 1000
int game_imprimirJuegos(Arcade* listArcade, int lenArcade)
{
	int retorno=-1;
	int i;
	int j;
	int flagExisteJuego=0;
	int indiceJuegoLibre=0;
	char listaJuegos[CANTIDAD_ARCADE][JUEGOS_LEN];

	if(listArcade!=NULL && lenArcade>0)
	{
		for(i=0; i<lenArcade;i++)
		{
			flagExisteJuego=0;
			if(listArcade[i].isEmpty==0)
			{
				for(j=0; j<indiceJuegoLibre;j++)
				{
					if(strncmp(listArcade[i].nombreDelJuego,listaJuegos[j],JUEGOS_LEN)==0)
					{
						flagExisteJuego=1;
						break;
					}
				}
				if(flagExisteJuego==0)
				{
					strncpy(listaJuegos[indiceJuegoLibre],listArcade[i].nombreDelJuego,JUEGOS_LEN);
					indiceJuegoLibre++;
				}
			}
		}
		printf("\nLISTA DE JUEGOS");
		for(j=0;j<indiceJuegoLibre;j++)
		{

			printf("\n- %s", listaJuegos[j]);
		}
	}
	return retorno;
}

/**
 * \brief Realiza el menu de informes del programa
 * \param opcionesDeMenuInformes correspondiente a la opcion elegida por el usuario pasado por punter
 * \param la funcion muestra el menu de informes y pide al usuario que ingrese la opcion elegida.
 * \return no devuelve nada.
 */
void salon_MenuInformes(int* opcionDeMenuInformes)
{
	int opcion;

	do
	{
		getInt(&opcion,1,11,3,"\n\n--MENU DE INFORMES-- "
				"\n  1-Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y "
				"tipo de salón. "
				"\n  2-Listar los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de "
				"jugadores, nombre del juego y nombre del salón al que pertenece. "
				"\n  3-Listar toda la información de un salón en específico ingresando su ID. Imprimir "
				"nombre, tipo y dirección y cantidad de arcades que posee. "
				"\n  4-Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre "
				"y tipo de salón, listar todos los arcades con sus datos junto con el nombre del juego que lo compone. "
				"\n  5-Imprimir el salón con más cantidad de arcades, indicando todos los datos del salón "
				"y la cantidad de arcades que posee. "
				"\n  6-Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo "
				"en pesos que puede recaudar el salón (sumar cantidad de fichas máximo de cada arcade del salón "
				"y multiplicarla por el valor en pesos ingresado) "
				"\n  7-Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen. "
				"\n  8- Salir del Menu Informes"
				"\nIngrese la opcion deseada: ", "Error");
	}while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 && opcion!=6 && opcion!=7 && opcion!=8);
	*opcionDeMenuInformes=opcion;
}

int inf_salonesCuatroArcade(Salon* listSalon, int lenSalon,Arcade* listArcade, int lenArcade)
{
	int retorno;
	int i;
	int j;
	int contArcade=0;
	if(listSalon!=NULL && lenSalon>0 && listArcade!=NULL && listArcade>0)
	{
		for(i=0;i<lenSalon;i++)
		{
			if(listSalon[i].isEmpty==OCUPADO)
			{
				for(j=0;j<lenArcade;j++)
				{
					if(listArcade[j].isEmpty==OCUPADO)
					{
						if(listSalon[i].idSalon == listArcade[j].idSalon)
						{
							contArcade++;
						}
					}
				}
				if(contArcade>4)
				{
					printf("\n	IdSalon		Nombre		Direccion		Tipo	");
					printf("\n	%d		%s		%s		%d	",listSalon->idSalon, listSalon->nombre, listSalon->direccion, listSalon->tipo);
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

int inf_ContDeArcade(Arcade* list, int len)
{
	int i;
	int contArcade=0;
	for(i=0;i<len;i++)
	{
		if(list->isEmpty==0)
		{
			contArcade++;
		}
	}
	return contArcade;
}


int inf_ArcadeDosJugadores(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon)
{
	int retorno=-1;
	int i;
	int j;
	int contArcade=0;
	int indiceDeSalon;
	int indiceJuegoLibre=0;
	char listaArcadeDosJugadores[ARCADE_LEN];

	if(listArcade!=NULL && lenArcade>0)
	{
		for(i=0; i<lenArcade;i++)
		{
			if(listArcade[i].isEmpty==0)
			{
				for(j=0;j<lenSalon;j++)
				{
					if(listSalon[i].idSalon == listArcade[j].idSalon)
					{
						if(listArcade[i].cantidadJugadores>2)
						{
							contArcade++;
							indiceDeSalon=j;
							strncpy(listaArcadeDosJugadores[])
							printf("\nArcades con mas de 2 jugadores");
							printf("\nId Arcade		Cant.deJugadores		NombreDelJuego		NombreDelSalon");
							printf("\n%d		%d		%s		%s",listArcade[i].idArcade, listArcade[i].cantidadJugadores, listArcade[i].nombreDelJuego,listSalon[j].nombre);
							retorno=0;
						}
					}
				}
			}
		}
	}
	return retorno;
}


