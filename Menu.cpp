#include "Menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Partida.h"
#include "Puntajes.h"
#include <cstdlib>
#include "Intermedio.h"
using namespace std;
using namespace sf;

Menu::Menu() {
	Fondo.openFromFile("Sonidos/Puntos.ogg");
	Fondo.setVolume(50);
	Fondo.setLoop(true);
	Fondo.play();
	
	TTTT.loadFromFile("Varios/Inicio2.png");
	inicio.setTexture(TTTT);
	fuente.loadFromFile("Varios/comet_deer/Comet Deer.ttf");
	
	texto.setFont(fuente);
	texto.setString("--Presione Barra para empezar--");
	texto.setPosition(200,145);
	texto.setCharacterSize(20);
	
	texto2.setFont(fuente);
	texto2.setString("--Presione P para ver los Puntajes--");
	texto2.setPosition(190,165);
	texto2.setCharacterSize(20);
	
	texto3.setFont(fuente);
	texto3.setString("--Presione ESC para Salir--");
	texto3.setPosition(205,185);
	texto3.setCharacterSize(20);
	
	texto4.setFont(fuente);
	texto4.setString("Pac-Man");
	texto4.setPosition(215,30);
	texto4.setCharacterSize(72);
}
//
void Menu::update (Game &game, sf::RenderWindow &w) {
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	texto.setFillColor({r,g,b});
	texto2.setFillColor({r,g,b});
	texto3.setFillColor({r,g,b});
	texto4.setFillColor({g,b,r});
	if(Keyboard::isKeyPressed(Keyboard::Space)){
		Fondo.stop();
		game.CambiarEscena(new Partida());
	}
	if(Keyboard::isKeyPressed(Keyboard::P)){
		Fondo.stop();
		game.CambiarEscena(new Puntajes(-1,'-','-','-','-'));
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		exit(0);
	}
}
//
void Menu::dibujar (sf::RenderWindow & w) {
	w.clear();
	w.draw(inicio);
	w.draw(texto);
	w.draw(texto2);
	w.draw(texto3);
	w.draw(texto4);
	w.display();
}
