#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include "Escena.h"
#include <SFML/Window/VideoMode.hpp>

using namespace sf;

Juego::Juego(Escena *e):m_win(VideoMode(1280,720),"Mutinous") {
	m_win.setFramerateLimit(10);
	es=e;
}

void Juego::jugar(){
	while(m_win.isOpen()) {
		Event e;
		while(m_win.pollEvent(e)) {
			if(e.type == Event::Closed){
				m_win.close();
			}
			es->manejarEventos(e);
		}
		//es->manejarEventos(e);
		es->actualizar(*this);
		es->dibujar(m_win);
		m_win.display();
		if(m_prox){
			delete es;
			es=m_prox;
			m_prox=nullptr;
		}
	}
}
void Juego::cambiar_escena(Escena *m_nueva){
	m_prox=m_nueva;
}

Juego::~Juego(){
	delete es;
}
