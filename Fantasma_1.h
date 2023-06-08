#ifndef FANTASMA_1_H
#define FANTASMA_1_H
#include "Fantasma_generico.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <SFML/System/Clock.hpp>
class Fantasma_1:public Fantasma_generico{
private:
	int contador=0;
	
public:
	
	Fantasma_1(int X,int Y);
	
	void mover(sf::Vector2f posicion_pacman,char Mapa[30][41])override;
	
};

#endif

