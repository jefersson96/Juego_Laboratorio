#include "Juego.h"


Juego::Juego(int ancho, int  alto, std::string titulo) {
	radio = 10.f;
	ventana = new RenderWindow(VideoMode(ancho, alto), titulo);
	ventana->setFramerateLimit(fps);

	textura = new Texture;
	textura2 = new Texture;
	sprite = new Sprite;
	sprite2 = new Sprite;
	textura->loadFromFile("1.png");
	textura2->loadFromFile("2.png");
	sprite->setTexture(*textura);
	sprite2->setTexture(*textura2);
	sprite2->setPosition(800/2, 600/2);
	sprite->setPosition(0,0);
	sprite->setScale(150.f / sprite->getTexture()->getSize().x, 25.f / sprite->getTexture()->getSize().y);
	sprite2->setScale(25.f / sprite2->getTexture()->getSize().x, 25.f / sprite2->getTexture()->getSize().y);
	evento = new Event;
	
	GameLoop();
	
}


void Juego::moverbola() {

	sprite2 ->setPosition(sprite2->getPosition().x + 0.2, sprite2->getPosition().y + 0.2);
	
	
	while (ventana->isOpen) {
	if(sprite2->getPosition().x >= 780 || sprite2->getPosition().y >= 580) {
	
		sprite2->setPosition(sprite2->getPosition().x/2, sprite2->getPosition().y/2);
	}
	
	}


}


void Juego::procesarEvento() {

	while (ventana->pollEvent(*evento)) {
	
		switch (evento->type)

		{

		case Event::Closed:
			ventana->close();
			exit(1);
		
			break;

		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				if (sprite2->getPosition().x < 800) {
					sprite->setPosition(sprite->getPosition().x + 20, sprite->getPosition().y);


				}

			}
			else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			
				if (sprite2->getPosition().x> 0) {
					sprite->setPosition(sprite->getPosition().x - 20, sprite->getPosition().y);
				}
			}
			
			break;
		}
	
	}



}


void Juego::GameLoop() {

	while (ventana->isOpen()) {
		procesarEvento();
		moverbola();
		Dibujar();
      
	}

}

void Juego::Dibujar() {

ventana->clear();

ventana->draw(*sprite);
ventana->draw(*sprite2);
		ventana->display();
	


}