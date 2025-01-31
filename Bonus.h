#ifndef BONUS_H
#define BONUS_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>
#include "Vida.h"
#include <SFML/System/Clock.hpp>
using namespace std;
using namespace sf;

class Bonus {
public: 
	Bonus( Texture &m_bonustext, float &bon_pos);
	void avanzar(float deltaTime,bool colisiona, Texture &vida_text,vector<Vida>&bonus_life);
	void dibujar(RenderWindow &w);
	Sprite ver_sprite();
	bool esta_vivo();
	void matar();
	void revivir();
	void desactivar();
	void activar(float pos);
	bool esta_activo() const;
	bool esta_vivo() const;
	
	
	
	
	
	
	
private:
	
	Clock m_clock3;
	Texture Bonus_text;
	Texture male_text;
	Sprite Bonus_spr;
	float bonus_pos;
	bool vivo=true;
	int m_frameWidth;
	int m_frameHeight;
	float m_speed;
	int m_currentFrame;
	float m_elapsedTime;
	float m_frameTime; // Tiempo por frame
	int m_totalFrames; // Número total de frames para la animación de caminata
	//int m_framesmuerte; // Numero total de frames para la animacion de muerte
	int cod2;
	int cod3;
	bool activo=true;
};

#endif

