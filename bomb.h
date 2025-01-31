#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> 
using namespace sf;

class Bomb {
public:
	Bomb(const Texture &bomba, float b_posy, float speed);
	void Avanzar(float deltaTime, bool colisiona, Texture &t2);
	void dibujar(sf::RenderWindow& window);
	Sprite ver_sprite(); 
	bool esta_explotada() const; 
	void explotar();
	bool activa();
	void desactivar();

	
private:
	int m_frameWidth;
	int m_frameHeight;
	float m_speed;
	int m_currentFrame;
	int m_currentFrame2;
	float m_elapsedTime;
	float m_frameTime;
	int m_totalFrames;
	int m_totalFrames2;
	Sprite m_sprite;
	Texture m_exptext;
	SoundBuffer m_mecha;
	SoundBuffer m_exp;
	Sound m_sound;
	bool activada=true;
	bool soundplay=true;
	bool m_explota; 
};

#endif
