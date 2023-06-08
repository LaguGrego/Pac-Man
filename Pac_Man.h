#ifndef PACMAN_H
#define PACMAN_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <tuple>
#include <vector>
#include <string>
#include "Fantasma_generico.h"
#include "Fantasma_1.h"
#include <SFML/Audio/Music.hpp>
using namespace std;


struct Posicion_animacion {
	int xo;		//Posicion inicial X
	int yo;		//Posicion inicial Y
	int tamx;	//Tamaño de recorte X
	int tamy;	//Tamaño de recorte Y
};
//---------------------------------------------------
//
class Pac_Man {
	
private:
	int V=48;
	float i=0;
	int vida=3;
	int puntos=0;
	
	sf::Texture T;		
	sf::Texture T2;		
	sf::Texture T3;		
	sf::Sprite Vida;
	
	sf::Font fuente;
	sf::Text Puntos2;
	
	sf::Music FRUTA1_M;
	sf::Music FRUTA2_M;
	sf::Music FANTASMA_M1;
	sf::Music FANTASMA_M12;
	
	float vel_aum=0.65;
	float mov_x=1+vel_aum;
	float mov_y=1+vel_aum;
	
public:
	
	bool cazar=false;
	
	Pac_Man();
	
	vector<Posicion_animacion> Animation_movimiento;	//Vector de coordenadas que para el recorte de la imagen de movimiento
	
	void llenar_animation();	//llena el vector de coodernadas
	
	sf::Text Mostrar_puntaje();
	
	sf::Sprite Mostrar_Vida();
	
	int mostrar_vida();
	
	int mostrar_puntos();
	
	int colission(Fantasma_generico *F, Fantasma_generico *F2, Fantasma_generico *F3, Fantasma_generico *F4);
	
	void asignar_textura(string S, string S2);
	
	void mover(char mapp[30][41],sf::Sprite s);
	
	sf::Sprite PM;		//Lo que permite ver al Pac-man en pantalla
	
	int x=0;
	

};

#endif

