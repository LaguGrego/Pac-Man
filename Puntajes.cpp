#include "Puntajes.h"
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"
#include "Menu.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
bool Ordenar (Puntaje B, Puntaje A){
	if(B.puntos>A.puntos) {return true;}
	if(B.puntos<A.puntos) {return false;}
}
Puntajes::Puntajes(int a, char b, char c, char d, char e) {
	Fondo.openFromFile("Sonidos/Puntos.ogg");
	Fondo.setVolume(50);
	Fondo.setLoop(true);
	Fondo.play();
	
	fuente1.loadFromFile("Varios/comet_deer/Comet Deer.ttf");
	texto1.setFont(fuente1);
	texto1.setString("--Presione F2 para volver al inicio--");
	texto1.setPosition(195,170);
	texto1.setCharacterSize(20);

	texto2.setFont(fuente1);
	texto2.setString("--Puntajes--");
	texto2.setPosition(195,5);
	texto2.setCharacterSize(50);

	TTTT.loadFromFile("Varios/Inicio2.png");
	inicio.setTexture(TTTT);
	
	string x;
	Puntaje t;
	
	ifstream archi("Varios/Puntajes_Binario.bat", ios::binary);
	for (int i=0;i<10;i++) {
		archi.read(reinterpret_cast<char*>(&t),sizeof(Puntaje));
		puntajes_1.push_back(t);
	}
	archi.close();
	
	t.a=b;
	t.b=c;
	t.c=d;
	t.d=e;
	t.puntos=a;
	puntajes_1.push_back(t);
	
	sort(puntajes_1.begin(),puntajes_1.end(),Ordenar);
	
	Puntaje Z;
	
	ofstream archi2("Varios/Puntajes_Binario.bat", ios::binary);
	for (int i=0;i<10;i++) {
		Z.a=puntajes_1[i].a;
		Z.b=puntajes_1[i].b;
		Z.c=puntajes_1[i].c;
		Z.d=puntajes_1[i].d;
		Z.puntos=puntajes_1[i].puntos;
		archi2.write(reinterpret_cast<char*>(&Z),sizeof(Puntaje));
	}
	archi2.close();
	
}


void Puntajes::dibujar (sf::RenderWindow & w) {
	t1.setFont(fuente1);
	t1.setCharacterSize(20);
	int a=40;
	w.clear({0,0,0});
	w.draw(inicio);
	for(int i=0;i<5;i++){
		a=a+20;
		t1.setString(puntajes_1[i].a);
		t1.setPosition(195,a);
		w.draw(t1);
		
		t1.setString(puntajes_1[i].b);
		t1.setPosition(205,a);
		w.draw(t1);
		
		t1.setString(puntajes_1[i].c);
		t1.setPosition(215,a);
		w.draw(t1);
		
		t1.setString(puntajes_1[i].d);
		t1.setPosition(225,a);
		w.draw(t1);
		
		string N=std::to_string(puntajes_1[i].puntos);
		t1.setString(N);
		t1.setPosition(250,a);
		w.draw(t1);
	}
	a=40;
	for(int i=5;i<10;i++){
		a=a+20;
		t1.setString(puntajes_1[i].a);
		t1.setPosition(360,a);
		w.draw(t1);
		
		t1.setString(puntajes_1[i].b);
		t1.setPosition(370,a);
		w.draw(t1);
		
		t1.setString(puntajes_1[i].c);
		t1.setPosition(380,a);
		w.draw(t1);
		
		t1.setString(puntajes_1[i].d);
		t1.setPosition(390,a);
		w.draw(t1);
		
		string N=std::to_string(puntajes_1[i].puntos);
		t1.setString(N);
		t1.setPosition(420,a);
		w.draw(t1);
	}
	w.draw(texto1);
	w.draw(texto2);
	w.display();
}

void Puntajes::update (Game & game, sf::RenderWindow &w) {
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	texto1.setFillColor({r,g,b});
	texto2.setFillColor({r,g,b});
	if(Keyboard::isKeyPressed(Keyboard::F2)){
		Fondo.stop();
		game.CambiarEscena(new Menu());
	}
}

