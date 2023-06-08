#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Escena.h"
#include "Game.h"
#include <SFML/Audio/Music.hpp>
using namespace sf;

class Menu : public Escena{
public:
	Menu();
	void dibujar(sf::RenderWindow &w) override;
	void update(Game &game, sf::RenderWindow &w) override;
private:
	sf::Music Fondo;
	sf::Sprite inicio;
	sf::Texture TTTT;
	sf::Text texto;
	sf::Font fuente;
	sf::Text texto2;
	sf::Font fuente2;
	sf::Text texto3;
	sf::Font fuente3;
	sf::Text texto4;
	sf::Font fuente4;
};

#endif

