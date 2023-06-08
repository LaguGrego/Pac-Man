#include "Map.h"
#include <SFML/Graphics/Texture.hpp>
#include <fstream>
#include <iostream>
#include "Pac_Man.h"
#include <cstdlib>
using namespace std;
using namespace sf;

Map::Map() {
	srand(time(NULL));
	//Se cargan las texturas de los elementos
	T.loadFromFile("Varios/Muro.png");
	Muro1.setTexture(T);
	Muro1.setOrigin(8.f,8.f);
	TT.loadFromFile("Varios/Puntos.png");
	Puntos1.setTexture(TT);
	Puntos1.setOrigin(4.f,4.f);
	TTT.loadFromFile("Varios/Pancho.png");
	Fruta1.setTexture(TTT);
	Fruta1.setOrigin(8.f,8.f);
	TTTT.loadFromFile("Varios/Birra.png");
	Fruta2.setTexture(TTTT);
	Fruta2.setOrigin(8.f,8.f);
	
	//Se carga el primer nivel
	int a=rand()%(3);
	cargar_nivel(a);
}


void Map::cargar_nivel (int x) {
	ifstream Nivel;
	char A;
	
	//Se abre el txt con el nivel indicado
	switch (x){
		case 0: { Nivel.open("Niveles/Nivel1.txt"); break; }
		case 1:	{ Nivel.open("Niveles/Nivel2.txt"); break; }
		case 2:	{ Nivel.open("Niveles/Nivel3.txt"); break; }
	}	
	
	//Se carga el nivel a la matriz
	for (int i=0;i<30;i++){
		for (int j=0;j<40;j++){
			Nivel>>A;
			Mapa[i][j]=A;
		}
	}
	Nivel.close();
}

void Map::dibujar_nivel (sf::RenderWindow & w,Pac_Man &Jugador) {
	srand(time(NULL));
	//Se dibujan los elementos del Mapa
	int t=0; int j=0; 
	for(t=0;t<41;t++){
		for(j=0;j<30;j++){
			//Muros
			if(Mapa[j][t]=='#') { 
				Muro1.setPosition(t*16+8,j*16+8);
				w.draw(Muro1);}
			//Puntos
			if(Mapa[j][t]=='-' || Mapa[j][t]=='|'){
				Puntos1.setPosition((t*16)+8,(j*16)+8);
				w.draw(Puntos1);
				Puntitos++;}
			//Pancho
			if(Mapa[j][t]=='*'){
				Fruta1.setPosition((t*16+8),(j*16+8));
				w.draw(Fruta1);}
			//Birra
			if(Mapa[j][t]=='+'){
				Fruta2.setPosition((t*16+8),(j*16+8));
				w.draw(Fruta2);}
		}
	}
	//Se evalua si todavia quedan puntos en el Mapa
	//Si no quedan, carga el siguiente nivel
	if(Puntitos==0) {
		int a=rand()%(3);
		cargar_nivel(a);
		Jugador.PM.setPosition(16.f,16.f);
	}
	Puntitos=0;
}

