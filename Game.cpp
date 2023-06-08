#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
using namespace sf;

void Game::run ( ) {
	int ancho = 640;
	int alto = 480;
	w.create(VideoMode(ancho,alto),"Pac-Man");//640x480
	w.setFramerateLimit(60);
	escena = new Menu;
	
	while(w.isOpen()) {
		
		Event e;	
		while(w.pollEvent(e)) { 
			if(e.type == Event::Closed) 
				w.close();
		}
			
		update();
		dibujar();
			
		if (Next_escena) {
			delete escena;
			escena = Next_escena;
			Next_escena = nullptr;
		}
	}		
}
//
void Game::update ( ) {
	escena->update(*this, w);
}
//
void Game::dibujar ( ) {
	escena->dibujar(w);
}
//

void Game::CambiarEscena (Escena *Next) {
	escena=Next;
}

