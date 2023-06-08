#ifndef FANTASMA_3_H
#define FANTASMA_3_H
#include "Fantasma_generico.h"

class Fantasma_3 : public Fantasma_generico {
public:
	Fantasma_3(int X, int Y);
	void mover (sf::Vector2f posicion_pacman, char  Mapa[30][41]);
private:
};

#endif

