#ifndef MAP_H
#define MAP_H
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Pac_Man.h"
using namespace std;


class Map {
public:
	Map();
	
	sf::Sprite Muro1;
	sf::Sprite Puntos1;
	sf::Sprite Fruta1;
	sf::Sprite Fruta2;
	
	char Mapa[30][41];
	int Puntitos=0;
	
	void dibujar_nivel(sf::RenderWindow &w, Pac_Man &Jugador);
	void cargar_nivel(int x);
	
private:
	sf::Texture T;
	sf::Texture TT;
	sf::Texture TTT;
	sf::Texture TTTT;
	
};

#endif

