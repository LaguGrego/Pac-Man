#include "Fantasma_3.h"

Fantasma_3::Fantasma_3(int X, int Y) {
	llenar_animacion_fantasma("AnimacionFantasma/Fantasma_Rosado.png");
	SF.setOrigin(8.f,8.f);
	SF.setPosition(X,Y);
}

void Fantasma_3::mover (sf::Vector2f posicion_pacman, char  Mapa[30][41]) {
	float M_y_2= (SF.getPosition().y-8)/(16);
	float M_x_2= (SF.getPosition().x-8)/(16);
	
	int M_x=M_x_2;
	int M_y=M_y_2;
	
	int M_x_3 = M_x_2*10 - M_x*10;
	int M_y_3 = M_y_2*10 - M_y*10;
	
	bool exacty= M_y_3 == 0;
	bool exactx= M_x_3 == 0;
	
	if(exactx and exacty and presa==true){
		srand(time(NULL));
		//camino sin salida
		if (Mapa[M_y][M_x+1]=='#' and Mapa[M_y][M_x-1]=='#' and Mapa[M_y+1][M_x]=='#'){nro_animacion=4;}
		//camino sin salida
		else if (Mapa[M_y][M_x+1]=='#' and Mapa[M_y][M_x-1]=='#' and Mapa[M_y-1][M_x]=='#'){nro_animacion=6;}
		//camino sin salida
		else if (Mapa[M_y][M_x-1]=='#' and Mapa[M_y-1][M_x]=='#' and Mapa[M_y+1][M_x]=='#'){nro_animacion=0;}
		//camino sin salida
		else if (Mapa[M_y][M_x+1]=='#' and Mapa[M_y-1][M_x]=='#' and Mapa[M_y+1][M_x]=='#'){nro_animacion=2;}
		//esquina
		else if (Mapa[M_y][M_x+1]=='#' and Mapa[M_y-1][M_x]=='#') {
			if(nro_animacion==0) {nro_animacion=6;}
			else {nro_animacion=2;}
		}
		//esquina
		else if (Mapa[M_y][M_x+1]=='#' and Mapa[M_y+1][M_x]=='#') {
			if(nro_animacion==0) {nro_animacion=4;}
			else {nro_animacion=2;}
		}
		//esquina
		else if (Mapa[M_y][M_x-1]=='#' and Mapa[M_y-1][M_x]=='#') {
			if(nro_animacion==2) {nro_animacion=6;}
			else {nro_animacion=0;}				
		}
		//esquina
		else if (Mapa[M_y][M_x-1]=='#' and Mapa[M_y+1][M_x]=='#') {
			if(nro_animacion==2) {nro_animacion=4;}
			else {nro_animacion=0;}
		}
		//		//crea un espacio 200x200 alrededor de pacman que el fantasma escapa
		else if	   (posicion_pacman.x<=SF.getPosition().x and posicion_pacman.y>=SF.getPosition().y and
					posicion_pacman.x+100>SF.getPosition().x and posicion_pacman.y-100<SF.getPosition().y){ 
			if (Mapa[M_y][M_x+1]!='#'){nro_animacion=0;}
			else if (Mapa[M_y-1][M_x]!='#'){nro_animacion=4;}
		}
		else if	   (posicion_pacman.x>=SF.getPosition().x and posicion_pacman.y>=SF.getPosition().y and
					posicion_pacman.x-100<SF.getPosition().x and posicion_pacman.y-100<SF.getPosition().y){
			if (Mapa[M_y][M_x-1]!='#'){nro_animacion=2;}
			else if (Mapa[M_y-1][M_x]!='#'){nro_animacion=4;}
		}
		else if	   (posicion_pacman.x>=SF.getPosition().x and posicion_pacman.y<=SF.getPosition().y and
					posicion_pacman.x-100<SF.getPosition().x and posicion_pacman.y+100>SF.getPosition().y){ 
			if (Mapa[M_y][M_x-1]!='#'){nro_animacion=2;}
			else if (Mapa[M_y+1][M_x]!='#'){nro_animacion=6;}
		}
		else if	   (posicion_pacman.x<=SF.getPosition().x and posicion_pacman.y<=SF.getPosition().y and 
					posicion_pacman.x+100>SF.getPosition().x and posicion_pacman.y+100>SF.getPosition().y){
			if (Mapa[M_y][M_x+1]!='#'){nro_animacion=0;}
			else if (Mapa[M_y+1][M_x]!='#'){nro_animacion=6;}
		}
		
		else if(Mapa[M_y][M_x]=='|' || Mapa[M_y][M_x]=='_'){
			int X=rand()%4;
			if(X==0) {nro_animacion=0;}
			if(X==1) {nro_animacion=2;}
			if(X==2) {nro_animacion=4;}
			if(X==3) {nro_animacion=6;}
			
			if(Mapa[M_y][M_x+1]=='#'){
				if(nro_animacion==0) {nro_animacion=4;}
			}
			if(Mapa[M_y][M_x-1]=='#'){
				if(nro_animacion==2) {nro_animacion=6;}
			}	
			if(Mapa[M_y+1][M_x]=='#'){
				if(nro_animacion==6) {nro_animacion=0;}
			}
			if(Mapa[M_y-1][M_x]=='#'){
				if(nro_animacion==4) {nro_animacion=2;}
			}
		}
	}
	
	else if (exactx and exacty and presa==false){
		srand(time(NULL));
		//camino sin salida
		if (Mapa[M_y][M_x+1]=='#' and Mapa[M_y][M_x-1]=='#' and Mapa[M_y+1][M_x]=='#'){nro_animacion=4;}
		//camino sin salida
		else if (Mapa[M_y][M_x+1]=='#' and Mapa[M_y][M_x-1]=='#' and Mapa[M_y-1][M_x]=='#'){nro_animacion=6;}
		//camino sin salida
		else if (Mapa[M_y][M_x-1]=='#' and Mapa[M_y-1][M_x]=='#' and Mapa[M_y+1][M_x]=='#'){nro_animacion=0;}
		//camino sin salida
		else if (Mapa[M_y][M_x+1]=='#' and Mapa[M_y-1][M_x]=='#' and Mapa[M_y+1][M_x]=='#'){nro_animacion=2;}
		//esquina
		else if (Mapa[M_y][M_x+1]=='#' and Mapa[M_y-1][M_x]=='#') {
			if(nro_animacion==0) {nro_animacion=6;}
			else {nro_animacion=2;}
		}
		//esquina
		else if (Mapa[M_y][M_x+1]=='#' and Mapa[M_y+1][M_x]=='#') {
			if(nro_animacion==0) {nro_animacion=4;}
			else {nro_animacion=2;}
		}
		//esquina
		else if (Mapa[M_y][M_x-1]=='#' and Mapa[M_y-1][M_x]=='#') {
			if(nro_animacion==2) {nro_animacion=6;}
			else {nro_animacion=0;}				
		}
		//esquina
		else if (Mapa[M_y][M_x-1]=='#' and Mapa[M_y+1][M_x]=='#') {
			if(nro_animacion==2) {nro_animacion=4;}
			else {nro_animacion=0;}
		}
		//
		else if (Mapa[M_y][M_x]=='|' || Mapa[M_y][M_x]=='_'){
			if	   (posicion_pacman.x<=SF.getPosition().x and posicion_pacman.y>=SF.getPosition().y){
				int X=rand()%2;
				if(X==0 and Mapa[M_y][M_x-1]!='#') {nro_animacion=2;} else {nro_animacion=6;}
				if(X==1 and Mapa[M_y+1][M_x]!='#') {nro_animacion=6;} else {nro_animacion=2;}
			}
			else if	   (posicion_pacman.x>=SF.getPosition().x and posicion_pacman.y>=SF.getPosition().y){
				int X=rand()%2;
				if(X==0 and Mapa[M_y][M_x+1]!='#') {nro_animacion=0;} else {nro_animacion=6;}
				if(X==1 and Mapa[M_y+1][M_x]!='#') {nro_animacion=6;} else {nro_animacion=0;}
			}
			else if	   (posicion_pacman.x>=SF.getPosition().x and posicion_pacman.y<=SF.getPosition().y){ 
				int X=rand()%2;
				if(X==0 and Mapa[M_y][M_x+1]!='#') {nro_animacion=0;} else {nro_animacion=4;}
				if(X==1 and Mapa[M_y-1][M_x]!='#') {nro_animacion=4;} else {nro_animacion=0;}
			}
			else if	   (posicion_pacman.x<=SF.getPosition().x and posicion_pacman.y<=SF.getPosition().y){
				int X=rand()%2;
				if(X==0 and Mapa[M_y][M_x-1]!='#') {nro_animacion=2;} else {nro_animacion=4;}
				if(X==1 and Mapa[M_y-1][M_x]!='#') {nro_animacion=4;} else {nro_animacion=2;}
			}
			else{
				int X=rand()%4;
				if(X==0) {nro_animacion=0;}
				if(X==1) {nro_animacion=2;}
				if(X==2) {nro_animacion=4;}
				if(X==3) {nro_animacion=6;}
				
				if(Mapa[M_y][M_x+1]=='#'){
					if(nro_animacion==0) {nro_animacion=4;}
				}
				if(Mapa[M_y][M_x-1]=='#'){
					if(nro_animacion==2) {nro_animacion=6;}
				}	
				if(Mapa[M_y+1][M_x]=='#'){
					if(nro_animacion==6) {nro_animacion=0;}
				}
				if(Mapa[M_y-1][M_x]=='#'){
					if(nro_animacion==4) {nro_animacion=2;}
				}
			}
		}
		if(Mapa[M_y][M_x+1]=='#'){
			if(nro_animacion==0) {nro_animacion=4;}
		}
		if(Mapa[M_y][M_x-1]=='#'){
			if(nro_animacion==2) {nro_animacion=6;}
		}	
		if(Mapa[M_y+1][M_x]=='#'){
			if(nro_animacion==6) {nro_animacion=0;}
		}
		if(Mapa[M_y-1][M_x]=='#'){
			if(nro_animacion==4) {nro_animacion=2;}
		}
	}
	
	switch(nro_animacion){
		case 0:{ SF.move(mov_x_F,0.f); break;}
		case 2:{ SF.move(-mov_x_F,0.f); break;}
		case 4:{ SF.move(0.f,-mov_x_F); break;}
		default: { SF.move(0.f,mov_x_F);}
	}
	//asigna la textura correspondiente al movimiento------------
	SF.setTextureRect(sf::IntRect(Animacion_movimiento[ver_nro_animacion()].xo, 0,Animacion_movimiento[ver_nro_animacion()].tamx, 16));
}

