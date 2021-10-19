/*
 * Informes.h
 *
 *  Created on: 19 oct. 2021
 *      Author: Aye
 */

#ifndef INFORMES_H_
#define INFORMES_H_

typedef struct
{
	char Juegos[63];
	int isEmpty;
}Game;

void game_initList(Game* list, int len);
int game_estaJuegoEnLista(Game* list, int len,char juegos[]);
int game_imprimirJuegos(Arcade* listArcade, int lenArcade);
void salon_MenuInformes(int* opcionDeMenuInformes);
int inf_salonesCuatroArcade(Salon* listSalon, int lenSalon,Arcade* listArcade, int lenArcade);
void menuPrincipal(int* opcionDeMenu);
int inf_ContDeArcade(Arcade* list, int len);
inf_ArcadeDosJugadores(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon);


#endif /* INFORMES_H_ */
