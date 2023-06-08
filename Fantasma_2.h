#ifndef FANTASMA_2_H
#define FANTASMA_2_H
#include "Fantasma_generico.h"

class Fantasma_2:public Fantasma_generico {
public:
	Fantasma_2(int x,int Y);
	void mover(sf::Vector2f posicion_pacman,char Mapa[30][41])override;
private:
};

#endif
