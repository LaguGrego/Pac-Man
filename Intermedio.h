#ifndef INTERMEDIO_H
#define INTERMEDIO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include "Escena.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
using namespace std;

class Intermedio : public Escena{
public:
	Intermedio(int a);
	void dibujar(sf::RenderWindow &w) override;
	void update(Game &game, sf::RenderWindow &w) override;
private:
	int puntos3=0;
	sf::Text t;
	sf::Text t11;
	sf::Text t12;
	sf::Text t13;
	sf::Text t2;
	sf::Text t3;
	sf::Text t4;
	sf::Text t5;
	sf::Font f;
	char b='-';
	char c='-';
	char d='-';
	char e='-';
};

#endif

