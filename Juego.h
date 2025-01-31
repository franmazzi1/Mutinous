#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "Escena.h"
using namespace sf;
using namespace std;


class Escena;

class Juego {
	
public:
	Juego(Escena *e);
	void jugar();
	void cambiar_escena(Escena *m_nueva);
	~Juego();
private:
	Escena *es,*m_prox=nullptr;
	RenderWindow m_win;
};

#endif

