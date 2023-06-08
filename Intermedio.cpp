#include "Intermedio.h"
#include <windows.h> 
#include <string>
#include <SFML/Window/Keyboard.hpp>
#include "Puntajes.h"
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;

Intermedio::Intermedio(int a) {
	puntos3=a;
	string N=std::to_string(a);
	f.loadFromFile("Varios/comet_deer/Comet Deer.ttf");
	
	t2.setFont(f);
	t2.setCharacterSize(40);
	t2.setPosition(180,130);
	t2.setString("Ingresa tu nombre: ");
	
	t.setFont(f);
	t.setCharacterSize(20);
	t.setPosition(270,200);

	t11.setFont(f);
	t11.setCharacterSize(20);
	t11.setPosition(290,200);
	
	t12.setFont(f);
	t12.setCharacterSize(20);
	t12.setPosition(310,200);
	
	t13.setFont(f);
	t13.setCharacterSize(20);
	t13.setPosition(330,200);
	
	t3.setFont(f);
	t3.setCharacterSize(30);
	t3.setPosition(230,240);
	t3.setString("Tu puntaje es: ");
	
	t4.setFont(f);
	t4.setCharacterSize(30);
	t4.setPosition(280,280);
	t4.setString(N);

	t5.setFont(f);
	t5.setCharacterSize(20);
	t5.setPosition(190,330);
	t5.setString("--Presione Espacio para continuar--");
}
void Intermedio::dibujar (sf::RenderWindow & w) {
	w.clear({0,0,0});
	w.draw(t);
	w.draw(t11);
	w.draw(t12);
	w.draw(t13);
	w.draw(t2);
	w.draw(t3);
	w.draw(t4);
	w.draw(t5);
	w.display();
}

void Intermedio::update (Game & game, sf::RenderWindow & w) {
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b1 = rand();
	t2.setFillColor({r,g,b1});
	t3.setFillColor({r,g,b1});
	t4.setFillColor({g,r,b1});
	t5.setFillColor({r,b1,g});
	
	Sleep(50);
	
	if(Keyboard::isKeyPressed(Keyboard::A)){
		Sleep(100);
		if(b=='-'){b='A';}
		else if(c=='-'){c='A';}
		else if(d=='-'){d='A';}
		else if(e=='-'){e='A';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::B)){
		Sleep(100);
		if(b=='-'){b='B';}
		else if(c=='-'){c='B';}
		else if(d=='-'){d='B';}
		else if(e=='-'){e='B';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::C)){
		Sleep(100);
		if(b=='-'){b='C';}
		else if(c=='-'){c='C';}
		else if(d=='-'){d='C';}
		else if(e=='-'){e='C';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::D)){
		Sleep(100);
		if(b=='-'){b='D';}
		else if(c=='-'){c='D';}
		else if(d=='-'){d='D';}
		else if(e=='-'){e='D';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::E)){
		Sleep(100);
		if(b=='-'){b='E';}
		else if(c=='-'){c='E';}
		else if(d=='-'){d='E';}
		else if(e=='-'){e='E';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::F)){
		Sleep(100);
		if(b=='-'){b='F';}
		else if(c=='-'){c='F';}
		else if(d=='-'){d='F';}
		else if(e=='-'){e='F';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::G)){
		Sleep(100);
		if(b=='-'){b='G';}
		else if(c=='-'){c='G';}
		else if(d=='-'){d='G';}
		else if(e=='-'){e='G';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::H)){
		Sleep(100);
		if(b=='-'){b='H';}
		else if(c=='-'){c='H';}
		else if(d=='-'){d='H';}
		else if(e=='-'){e='H';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::I)){
		Sleep(100);
		if(b=='-'){b='I';}
		else if(c=='-'){c='I';}
		else if(d=='-'){d='I';}
		else if(e=='-'){e='I';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::J)){
		Sleep(100);
		if(b=='-'){b='J';}
		else if(c=='-'){c='J';}
		else if(d=='-'){d='J';}
		else if(e=='-'){e='J';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::K)){
		Sleep(100);
		if(b=='-'){b='K';}
		else if(c=='-'){c='K';}
		else if(d=='-'){d='K';}
		else if(e=='-'){e='K';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::L)){
		Sleep(100);
		if(b=='-'){b='L';}
		else if(c=='-'){c='L';}
		else if(d=='-'){d='L';}
		else if(e=='-'){e='L';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::M)){
		Sleep(100);
		if(b=='-'){b='M';}
		else if(c=='-'){c='M';}
		else if(d=='-'){d='M';}
		else if(e=='-'){e='M';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::N)){
		Sleep(100);
		if(b=='-'){b='N';}
		else if(c=='-'){c='N';}
		else if(d=='-'){d='N';}
		else if(e=='-'){e='N';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::O)){
		Sleep(100);
		if(b=='-'){b='O';}
		else if(c=='-'){c='O';}
		else if(d=='-'){d='O';}
		else if(e=='-'){e='O';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::P)){
		Sleep(100);
		if(b=='-'){b='P';}
		else if(c=='-'){c='P';}
		else if(d=='-'){d='P';}
		else if(e=='-'){e='P';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Q)){
		Sleep(100);
		if(b=='-'){b='Q';}
		else if(c=='-'){c='Q';}
		else if(d=='-'){d='Q';}
		else if(e=='-'){e='Q';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::R)){
		Sleep(100);
		if(b=='-'){b='R';}
		else if(c=='-'){c='R';}
		else if(d=='-'){d='R';}
		else if(e=='-'){e='R';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::S)){
		Sleep(100);
		if(b=='-'){b='S';}
		else if(c=='-'){c='S';}
		else if(d=='-'){d='S';}
		else if(e=='-'){e='S';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::T)){
		Sleep(100);
		if(b=='-'){b='T';}
		else if(c=='-'){c='T';}
		else if(d=='-'){d='T';}
		else if(e=='-'){e='T';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::U)){
		Sleep(100);
		if(b=='-'){b='U';}
		else if(c=='-'){c='U';}
		else if(d=='-'){d='U';}
		else if(e=='-'){e='U';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::V)){
		Sleep(100);
		if(b=='-'){b='V';}
		else if(c=='-'){c='V';}
		else if(d=='-'){d='V';}
		else if(e=='-'){e='V';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::W)){
		Sleep(100);
		if(b=='-'){b='W';}
		else if(c=='-'){c='W';}
		else if(d=='-'){d='W';}
		else if(e=='-'){e='W';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::X)){
		Sleep(100);
		if(b=='-'){b='X';}
		else if(c=='-'){c='X';}
		else if(d=='-'){d='X';}
		else if(e=='-'){e='X';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Y)){
		Sleep(100);
		if(b=='-'){b='Y';}
		else if(c=='-'){c='Y';}
		else if(d=='-'){d='Y';}
		else if(e=='-'){e='Y';}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Z)){
		Sleep(100);
		if(b=='-'){b='Z';}
		else if(c=='-'){c='Z';}
		else if(d=='-'){d='Z';}
		else if(e=='-'){e='Z';}
	}
	t.setString(b);
	t11.setString(c);
	t12.setString(d);
	t13.setString(e);

	if(Keyboard::isKeyPressed(Keyboard::Space)){
		game.CambiarEscena(new Puntajes(puntos3,b,c,d,e));
	}
	
}

