#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "Escena.h"
using namespace sf;

class Game {
private:
	Escena *escena;
	Escena *Next_escena = nullptr;

public:	
	
	void CambiarEscena (Escena *Next);
	
	void run();
	//Se modifica los datos del juego
	void update();
	//Se dibujan los objetos de juegos
	void dibujar();
	
	//Creacion de pantalla-------------------------------------------------
	sf::RenderWindow w;

};

#endif

