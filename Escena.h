#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Window/Event.hpp>

using namespace sf;

class Juego;

class Escena {
public:
	Escena();
	virtual void actualizar(Juego &ju)=0;
	virtual void dibujar(RenderWindow &w)=0;
	virtual void manejarEventos(const sf::Event& event) = 0;
private:
};

#endif

