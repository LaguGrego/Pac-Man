#ifndef PARTIDA_H
#define PARTIDA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Pac_Man.h"
#include "Fantasma_generico.h"
#include "Map.h"
#include "Fantasma_2.h"
#include "Escena.h"
#include "Game.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Fantasma_3.h"
#include "Fantasma_1.h"
#include <SFML/Audio/Music.hpp>
using namespace sf;

class Partida : public Escena {
public:
	Partida();
	void dibujar(sf::RenderWindow &w) override;
	void update(Game &game, sf::RenderWindow &w) override;
	//Cuando un fantasma toca a pac-man
	void Reset();
	
private:
	int cc=1;
	Pac_Man Jugador;
	Map Mapa;
	Fantasma_generico *Rojo= new Fantasma_1(552,72);//552,72
	Fantasma_generico *Azul= new Fantasma_2(24,456);//24,456
	Fantasma_generico *Rosado= new Fantasma_3(24,264);//24,264
	Fantasma_generico *Naranja= new Fantasma_generico();
	sf::Music FondoP;
	
};

#endif

