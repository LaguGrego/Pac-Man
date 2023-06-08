#include "Partida.h"
#include "Game.h"
#include "Menu.h"
#include "Puntajes.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Intermedio.h"
#include <SFML/Graphics/Texture.hpp>
#include <cstdlib>
using namespace std;

	
void Partida::dibujar (sf::RenderWindow &w) {
	if(Jugador.colission(Rojo,Rosado,Azul,Naranja)==1){
		w.clear(); 
		Mapa.dibujar_nivel(w,Jugador);
		w.draw(Jugador.Mostrar_puntaje());
		w.draw(Jugador.Mostrar_Vida());
		w.display();
	}
	else {
		w.clear(); 
		Mapa.dibujar_nivel(w,Jugador);
		w.draw(Jugador.PM);
		w.draw(Rojo->SF);
		w.draw(Rosado->SF);
		w.draw(Azul->SF);
		w.draw(Naranja->SF);
		w.draw(Jugador.Mostrar_puntaje());
		w.draw(Jugador.Mostrar_Vida());
		w.display();
	}
}

void Partida::update (Game &game, sf::RenderWindow &w) {

	if(Jugador.cazar==true) {
		cc++;
		
		Rojo->presa=true;
		Rojo->llenar_animacion_fantasma("AnimacionFantasma/Fantasma_Cagado.png");
		Rojo->presa=true;
		Rosado->presa=true;
		Rosado->llenar_animacion_fantasma("AnimacionFantasma/Fantasma_Cagado.png");
		Azul->presa=true;
		Naranja->presa=true;
		Naranja->llenar_animacion_fantasma("AnimacionFantasma/Fantasma_Cagado.png");
	}
	
	if(cc>=1001) {
		cc=0;
		Jugador.cazar=false;
		Rojo->presa=false;
		Rojo->llenar_animacion_fantasma("AnimacionFantasma/Fantasma_Rojo.png");
		Rosado->presa=false;
		Rosado->llenar_animacion_fantasma("AnimacionFantasma/Fantasma_Rosado.png");
		Azul->presa=false;
		Naranja->presa=false;
		Naranja->llenar_animacion_fantasma("AnimacionFantasma/Fantasma_Naranja.png");
	}
	
	if(Keyboard::isKeyPressed(Keyboard::F1)){
		FondoP.stop();
		game.CambiarEscena(new Menu());
	}
	
	if(Jugador.mostrar_vida()==-2){
		FondoP.stop();
		game.CambiarEscena(new Intermedio(Jugador.mostrar_puntos()));
	}
	
	if(Jugador.colission(Rojo,Rosado,Azul,Naranja)==1 and Jugador.cazar==false){
		Reset();
	}
	
	if(Jugador.colission(Rojo,Rosado,Azul,Naranja)==2 || Jugador.colission(Rojo,Rosado,Azul,Naranja)==3 || Jugador.colission(Rojo,Rosado,Azul,Naranja)==4 || Jugador.colission(Rojo,Rosado,Azul,Naranja)==5){
		if(Jugador.colission(Rojo,Rosado,Azul,Naranja)==2){
			Rojo->SF.setPosition(552,72);
		}
		else if(Jugador.colission(Rojo,Rosado,Azul,Naranja)==3){
			Rosado->SF.setPosition(24,264);
		}
		else if(Jugador.colission(Rojo,Rosado,Azul,Naranja)==4){
			Reset();
		}
		else if(Jugador.colission(Rojo,Rosado,Azul,Naranja)==5){
			Naranja->SF.setPosition(616,448);
		}
	}
	
	else {
		Jugador.mover(Mapa.Mapa,Mapa.Puntos1);
		Rojo->mover(Jugador.PM.getPosition(),Mapa.Mapa);
		Rosado->mover(Jugador.PM.getPosition(),Mapa.Mapa);
		Azul->mover(Jugador.PM.getPosition(),Mapa.Mapa);
		Naranja->mover(Jugador.PM.getPosition(),Mapa.Mapa);
	}
}

void Partida::Reset ( ) {
	Jugador.cazar=false;
	Jugador.PM.setPosition(24,24);
	Jugador.x=0;
	
	Rojo->presa=false;
	Rojo->SF.setPosition(552,72);
	Rojo->llenar_animacion_fantasma("AnimacionFantasma/Fantasma_Rojo.png");
	
	Rosado->presa=false;
	Rosado->SF.setPosition(24,264);
	Rosado->llenar_animacion_fantasma("AnimacionFantasma/Fantasma_Rosado.png");
	
	Azul->presa=false;
	Azul->SF.setPosition(24,456);
	
	Naranja->presa=false;
	Naranja->SF.setPosition(616,456);
	Naranja->llenar_animacion_fantasma("AnimacionFantasma/Fantasma_Naranja.png");
}

Partida::Partida ( ) {
	FondoP.openFromFile("Sonidos/Partida.ogg");
	FondoP.setVolume(20);
	FondoP.setLoop(true);
	FondoP.play();
}

