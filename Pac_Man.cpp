#include "Pac_man.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Fantasma_1.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

using namespace std;
using namespace sf;


Pac_Man::Pac_Man () {
	asignar_textura("AnimacionPacMan/Movimiento-Pacman.png", "Varios/Vidas.png");
	PM.setPosition(24,24);
	PM.setOrigin(8.f,8.f);
	Vida.setPosition(435,24);
	Puntos2.setPosition(490,21);
	Puntos2.setScale(.6,.6);
	fuente.loadFromFile("Varios/comet_deer/Comet Deer.ttf");
	Puntos2.setFont(fuente);
	
	
	FRUTA1_M.openFromFile("Sonidos/ñam.ogg");
	FRUTA1_M.setVolume(10);
	
	FRUTA2_M.openFromFile("Sonidos/Cerveza.ogg");
	FRUTA2_M.setVolume(30);
	
	FANTASMA_M1.openFromFile("Sonidos/Doh.ogg");
	FANTASMA_M1.setVolume(10);
	
	FANTASMA_M12.openFromFile("Sonidos/Yajuu.ogg");
	FANTASMA_M12.setVolume(10);
}

void Pac_Man::llenar_animation ( ) {
	
	Animation_movimiento.size()+1;
	//Animacion Derecha
	Posicion_animacion T;
	T.xo=0;
	T.yo=0;
	T.tamx=16;
	T.tamy=16;
	Animation_movimiento.push_back(T);
	
	T.xo=16;
	T.yo=0;
	T.tamx=16;
	T.tamy=16;
	Animation_movimiento.push_back(T);


	//Animacion Izquierda
	Posicion_animacion T1;
	T1.xo=0;
	T1.yo=16;
	T1.tamx=16;
	T1.tamy=16;
	Animation_movimiento.push_back(T1);
	
	T1.xo=16;
	T1.yo=16;
	T1.tamx=16;
	T1.tamy=16;
	Animation_movimiento.push_back(T1);
	
	
	//Animacion Arriba
	Posicion_animacion T2;
	T2.xo=0;
	T2.yo=32;
	T2.tamx=16;
	T2.tamy=16;
	Animation_movimiento.push_back(T2);
	
	T2.xo=16;
	T2.yo=32;
	T2.tamx=16;
	T2.tamy=16;
	Animation_movimiento.push_back(T2);
	

	//Animacion Abajo
	Posicion_animacion T3;
	T3.xo=0;
	T3.yo=48;
	T3.tamx=16;
	T3.tamy=16;
	Animation_movimiento.push_back(T3);
	
	T3.xo=16;
	T3.yo=48;
	T3.tamx=16;
	T3.tamy=16;
	Animation_movimiento.push_back(T3);
	
}

void Pac_Man::asignar_textura (string S, string S2) {	
	T.loadFromFile(S);
	PM.setTexture(T);
	llenar_animation();
	T2.loadFromFile(S2);
	Vida.setTexture(T2);
}

void Pac_Man::mover (char  mapa[30][41],sf::Sprite s) {
	
	Vector2f posicion_pac_man= PM.getPosition();
	float M_x_2 = ((posicion_pac_man.x-8)/(16));
	float M_y_2 = ((posicion_pac_man.y-8)/(16));
	
	int M_x = M_x_2;
	int M_y = M_y_2;
	
	if(M_x == 0){ M_x = 1;}
	if(M_y == 0) { M_y = 1;}
	
	int M_x_3 = (M_x_2*10) - (M_x*10);
	int M_y_3 = (M_y_2*10) - (M_y*10);
	
	bool exactx = M_x_3 == 0;
	bool exacty = M_y_3 == 0;
	
	//Evalua si se esta presionando una tecla si es verdadera modifica la Posicion
	//Si la posicion de la matriz donde se dirije pacman hay un muro se deteiene
	//1-derecha 2-izquierda 3-arriba 4-abajo
	
	if (exacty) {
		if (Keyboard::isKeyPressed(Keyboard::Right))	{ x=1;}
		if (Keyboard::isKeyPressed(Keyboard::Left ))	{ x=2;}
	}
	
	if (exactx) {
		if (Keyboard::isKeyPressed(Keyboard::Up   ))	{ x=3;}
		if (Keyboard::isKeyPressed(Keyboard::Down ))	{ x=4;}
	}
	
	switch (x) {
		
		case 1: {
			if (mapa[M_y][M_x+1]=='#' && exactx)	{
				i=0;
			}
			else if (mapa[M_y][M_x]=='|' || mapa[M_y][M_x]=='-')	{
				PM.move(mov_x,0.f);  
				if(i>=1.9) {i=0;} 
				else {i=i+0.1;}
				if(mapa[M_y][M_x]=='|') {mapa[M_y][M_x]='_';}  
				else {mapa[M_y][M_x]='.';}
				puntos+=10;	
			}			
			else if (mapa[M_y][M_x]=='*')	{
				PM.move(mov_x,0.f);  
				if(i>=1.9) {i=0;} 
				else {i=i+0.1;} 
				mapa[M_y][M_x]='.';
				FRUTA1_M.play();
				puntos+=25;	
			}	
			else if (mapa[M_y][M_x]=='+')	{
				PM.move(mov_x,0.f);  
				if(i>=1.9) {i=0;} 
				else {i=i+0.1;} 
				mapa[M_y][M_x]='.';
				FRUTA2_M.play();
				cazar=true;
			}		
			else {PM.move(mov_x,0.f);  if(i>=1.9) {i=0;} else {i=i+0.1;}}
			break;}
		
		case 2: {
			if (mapa[M_y][M_x-1]=='#' && exactx)	{
				i=2;
			} 
			else if (mapa[M_y][M_x]=='|' || mapa[M_y][M_x]=='-')	{
				PM.move(-mov_x,0.f); 
				if((i>=3.9)||(i<2)) {i=2;} 
				else {i=i+0.1;}
				if(mapa[M_y][M_x]=='|') {mapa[M_y][M_x]='_';}  
				else {mapa[M_y][M_x]='.';}
				puntos+=10;
			} 
			else if (mapa[M_y][M_x]=='*')	{
				PM.move(-mov_x,0.f); 
				if((i>=3.9)||(i<2)) {i=2;} 
				else {i=i+0.1;}
				mapa[M_y][M_x]='.';
				FRUTA1_M.play();
				puntos+=25;
			}
			else if (mapa[M_y][M_x]=='+')	{
				PM.move(-mov_x,0.f); 
				if((i>=3.9)||(i<2)) {i=2;} 
				else {i=i+0.1;}
				mapa[M_y][M_x]='.';
				FRUTA2_M.play();
				cazar=true;
			} 
			else {PM.move(-mov_x,0.f); if((i>=3.9)||(i<2)) {i=2;} else {i=i+0.1;}}
			break;}
		
		case 3: {
			if (mapa[M_y-1][M_x]=='#' && exacty)	{
				i=4;
			} 
			else if (mapa[M_y][M_x]=='|' || mapa[M_y][M_x]=='-')	{
				PM.move(0.f,-mov_y);
				if((i>=5.9)||(i<4)) {i=4;}
				else {i=i+0.1;}
				if(mapa[M_y][M_x]=='|') {mapa[M_y][M_x]='_';}  
				else {mapa[M_y][M_x]='.';}
				puntos+=10;
			} 
			else if (mapa[M_y][M_x]=='*')	{
				PM.move(0.f,-mov_y);
				if((i>=5.9)||(i<4)) {i=4;}
				else {i=i+0.1;}
				mapa[M_y][M_x]='.';
				FRUTA1_M.play();
				puntos+=25;
			} 
			else if (mapa[M_y][M_x]=='+')	{
				PM.move(0.f,-mov_y);
				if((i>=5.9)||(i<4)) {i=4;}
				else {i=i+0.1;}
				mapa[M_y][M_x]='.';
				FRUTA2_M.play();
				cazar=true;
			} 
			else {PM.move(0.f,-mov_y); if((i>=5.9)||(i<4)) {i=4;} else {i=i+0.1;}}
			break;}
		
		case 4: {
			if (mapa[M_y+1][M_x]=='#' && exacty)	{
				i=6;
			}
			else if (mapa[M_y][M_x]=='|' || mapa[M_y][M_x]=='-')	{
				PM.move(0.f,mov_y);
				if((i>=7.9)||(i<6)) {i=6;}
				else {i=i+0.1;}
				if(mapa[M_y][M_x]=='|') {mapa[M_y][M_x]='_';}  
				else {mapa[M_y][M_x]='.';}
				puntos+=10;
			} 
			else if (mapa[M_y][M_x]=='*')	{
				PM.move(0.f,mov_y);
				if((i>=7.9)||(i<6)) {i=6;}
				else {i=i+0.1;}
				mapa[M_y][M_x]='.';
				FRUTA1_M.play();
				puntos+=25;
			} 
			else if (mapa[M_y][M_x]=='+')	{
				PM.move(0.f,mov_y);
				if((i>=7.9)||(i<6)) {i=6;}
				else {i=i+0.1;}
				mapa[M_y][M_x]='.';
				FRUTA2_M.play();
				cazar=true;
			} 
			else {PM.move(0.f,mov_y);  if((i>=7.9)||(i<6)) {i=6;} else {i=i+0.1;}}
			break;}
		
	}
	string N=std::to_string(puntos);
	Puntos2.setString(N);
	
	PM.setTextureRect(IntRect
	(Animation_movimiento[i].xo, Animation_movimiento[i].yo, 
	Animation_movimiento[i].tamx, Animation_movimiento[i].tamy));

}


int Pac_Man::colission (Fantasma_generico *F, Fantasma_generico *F2, Fantasma_generico *F3, Fantasma_generico *F4) {
	
	if(cazar==false){
		if(PM.getGlobalBounds().intersects(F->SF.getGlobalBounds())){
			vida--; V=V-8;
			Vida.setTextureRect(IntRect(0,0,V,16));
			FANTASMA_M1.play();
			return 1;
		}
		else if(PM.getGlobalBounds().intersects(F2->SF.getGlobalBounds())){
			vida--; V=V-8; 
			Vida.setTextureRect(IntRect(0,0,V,16)); 
			FANTASMA_M1.play();
			return 1;
		}
		else if(PM.getGlobalBounds().intersects(F3->SF.getGlobalBounds())){
			vida--; V=V-8; 
			Vida.setTextureRect(IntRect(0,0,V,16)); 
			FANTASMA_M1.play();
			return 1;
		}
		else if(PM.getGlobalBounds().intersects(F4->SF.getGlobalBounds())){
			vida--; V=V-8; 
			Vida.setTextureRect(IntRect(0,0,V,16)); 
			FANTASMA_M1.play();
			return 1;
		}
	}
	if(cazar==true){
		if(PM.getGlobalBounds().intersects(F->SF.getGlobalBounds())){
			puntos+=100;
			FANTASMA_M12.play();
			return 2;
		}
		else if(PM.getGlobalBounds().intersects(F2->SF.getGlobalBounds())){
			puntos+=100;
			FANTASMA_M12.play();
			return 3;
		}
		else if(PM.getGlobalBounds().intersects(F3->SF.getGlobalBounds())){
			puntos+=100;
			FANTASMA_M12.play();
			return 4;
		}
		else if(PM.getGlobalBounds().intersects(F4->SF.getGlobalBounds())){
			vida--; V=V-8; 
			Vida.setTextureRect(IntRect(0,0,V,16)); 
			FANTASMA_M1.play();
			return 5;
		}
	}
	return 0;
}

sf::Text Pac_Man::Mostrar_puntaje ( ) {
	return Puntos2;
}

sf::Sprite Pac_Man::Mostrar_Vida ( ) {
	return Vida;
}

int Pac_Man::mostrar_vida ( ) {
	return vida;
}

int Pac_Man::mostrar_puntos ( ) {
	return puntos;
}


