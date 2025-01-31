#include "bomb.h"
#include <iostream>
using namespace sf;

Bomb::Bomb(const Texture &bomba, float b_posy, float speed)
	: m_speed(speed+100), m_currentFrame(0), m_currentFrame2(0), m_elapsedTime(0.0f), m_frameTime(0.1f), m_totalFrames(5), m_explota(false), soundplay(true) {
	
	m_sprite.setTexture(bomba);
	m_exptext.loadFromFile("img/explosion.png");
	m_sprite.setPosition(1300, b_posy);
	
	m_frameWidth = bomba.getSize().x / m_totalFrames;
	m_frameHeight = bomba.getSize().y;
	
	m_sprite.setTextureRect(IntRect(0, 0, m_frameWidth, m_frameHeight));
	m_sprite.scale(2, 2);
	
	m_mecha.loadFromFile("music/ruido_bomba.wav");
	m_sound.setBuffer(m_mecha);
	m_sound.setLoop(true); 
	m_sound.play();
	
	m_exp.loadFromFile("music/exp.wav");
	m_totalFrames2 = 7; 
}

void Bomb::Avanzar(float deltaTime, bool colisiona, Texture &t2) {
	if (colisiona) {
		if (soundplay) {
			m_sound.stop();
			m_sound.setBuffer(m_exp);
			m_sound.setLoop(false); 
			m_sound.play();
			soundplay = false;
		}
		
		m_sprite.setTexture(m_exptext);
		
		if (m_currentFrame2 < m_totalFrames2) {
			m_elapsedTime += deltaTime;
			if (m_elapsedTime >= m_frameTime) {
				m_elapsedTime = 0.0f;
				m_sprite.setTextureRect(IntRect(m_currentFrame2 * m_frameWidth, 0, m_frameWidth, m_frameHeight));
				m_currentFrame2++;
			}
		} else {
			activada = false; 
		}
	} else if (!colisiona && !m_explota) {
		m_sprite.move(-m_speed * deltaTime, 0);
		
		m_elapsedTime += deltaTime;
		if (m_elapsedTime >= m_frameTime) {
			m_elapsedTime = 0.0f;
			m_currentFrame = (m_currentFrame + 1) % m_totalFrames;
			m_sprite.setTextureRect(IntRect(m_currentFrame * m_frameWidth, 0, m_frameWidth, m_frameHeight));
		}
	}
}

void Bomb::dibujar(sf::RenderWindow& window) {
	
	if(activada){
		window.draw(m_sprite);
	}

}

Sprite Bomb::ver_sprite() {
	return m_sprite;
}

bool Bomb::esta_explotada() const {
	return m_explota;
}

void Bomb::explotar() {
	m_explota = true;
}
bool Bomb::activa(){
	return activada;
}
void Bomb::desactivar(){	
	activada=false;
}

