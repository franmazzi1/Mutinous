#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/System/Clock.hpp>
#include "Disparo_enemigo.h"
using namespace std;
using namespace sf;

class Enemigo {
public:
	Enemigo(Texture &m_texture,float &e_posy, float speed);
	void Avanzar(float deltaTime,bool colisiona,Texture &t2,vector<Disparo_enemigo>&de);
	void dibujar(sf::RenderWindow& window);
	Sprite ver_sprite();
	void reset(float e_posy, Texture &m_texture); 
	void desactivar();
	bool estaActivo()const;
	void activar(float posY, Texture &m_texture);
	bool esta_vivo();
	void matar();
	
	

private:
	SoundBuffer policia;
	Sound pol;
	//Texture m_texture;
	Texture muer;
	Sprite m_sprite;
	Sprite m_bullet2;
	SoundBuffer buffer2;
	Sound disparo2;
	int m_frameWidth;
	int m_frameHeight;
	float m_speed;
	int m_currentFrame;
	float m_elapsedTime;
	float m_frameTime; 
	int m_totalFrames; 
	int m_framesmuerte; 
	int cod2;
	int cod3;
	bool dis;
	float e_posy;
	bool activo = true;
	bool vivo=true;

};

#endif 
