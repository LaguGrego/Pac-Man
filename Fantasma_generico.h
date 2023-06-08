#ifndef Fantasma_generico_H
#define Fantasma_generico_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Fantasma_generico.h"
using namespace std;


struct Posicion_animacion_fantasma {
	int xo;		//Posicion inicial X
	int tamx;	//Tamaño de recorte X
};

class Fantasma_generico {
protected:
	
	int tipo_de_fantasma;
	bool comido;
	
	int cont_vueltas=0;
	int nro_animacion=0;
	int cont_animacion=0;
	float vel_aum = 0.75;
	float mov_x_F=1.f+vel_aum;
	float mov_y_F=1.f+vel_aum;
	
	sf::Texture TF;
	
public:
	
	Fantasma_generico();
	
	bool presa=false;
	
	int redondeo(float x);
	
	sf::Sprite SF;
	
	
	vector<Posicion_animacion_fantasma> Animacion_movimiento;
	
	void llenar_animacion_fantasma(string imagen_fantasma);
	
	void llenar_animacion();
	
	int ver_nro_animacion();
	
	virtual void mover(sf::Vector2f posicion_pacman,char Mapa[30][41]);
	
	bool esta_comido(){return comido;}
	
	int ver_tipo_fantasma(){return tipo_de_fantasma;}
	
	
	
	
};
#endif
