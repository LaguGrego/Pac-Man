#ifndef PUNTAJES_H
#define PUNTAJES_H
#include "Escena.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <SFML/Audio/Music.hpp>
using namespace std;
struct Puntaje {
	char a;
	char b;
	char c;
	char d;
	int puntos;
};

class Puntajes : public Escena {
public:
	Puntajes(int a, char b, char c, char d, char e);
	
	void dibujar(sf::RenderWindow &w) override;
	
	void update(Game &game, sf::RenderWindow &w) override;
	
private:
	sf::Music Fondo;
	sf::Sprite inicio;
	sf::Texture TTTT;
	sf::Font fuente1;
	sf::Text texto1;
	sf::Text texto2;
	sf::Text t1;
	vector<Puntaje> puntajes_1;
};

#endif

