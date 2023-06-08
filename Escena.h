#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
class Game;

class Escena {
public:
	Escena();
	virtual void update(Game &game, sf::RenderWindow &w) = 0;
	virtual void dibujar(sf::RenderWindow &w)=0;
private:
};

#endif

