#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <ctime>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Disparo.h"
using namespace std;
using namespace sf;

class Personaje {
public:
	Personaje();
	void actualizar();
	void dibujar(RenderWindow &w);
	bool debe_disparar();
	Disparo disparar(Texture &t);
	void recibe_impacto();
	Sprite ver_sprite();
	
	//Vector2f ver_posicion();
private:
	bool dere;
	SoundBuffer buffer;
	SoundBuffer buffer3;
	Sound disparo;
	Texture mantex;
	Texture mantex2;
	Texture mantex3;
	Texture mantex4;
	Texture mantex5;
	Sprite man;
	Keyboard:: Key arriba,izq,der,abajo,disp;
	int cod=0;
	int cod2=5;
	Clock m_clock;
	Clock m_clock2;
	float time=1;
	bool dispara;
	
	
};

#endif

