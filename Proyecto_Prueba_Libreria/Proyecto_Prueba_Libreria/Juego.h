#include "SFML\Graphics.hpp"


#pragma once
using namespace sf;

class Juego {


public:

	Juego(int ancho,int alto,std::string titulo);
void GameLoop();
void Dibujar();
void procesarEvento();
void moverbola();
private:

	RenderWindow * ventana;
	int fps;
	Texture *textura2;
	Texture *textura;
	Sprite *sprite;
	Sprite *sprite2;
	Event *evento;
	float radio;
};