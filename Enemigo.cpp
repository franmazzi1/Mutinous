#include "Enemigo.h"
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <cmath>
#include "Disparo_enemigo.h"
#include <vector>
using namespace sf;
using namespace std;

Enemigo::Enemigo(Texture &m_texture,float &e_posy,float speed)
	: m_speed(speed), m_currentFrame(0), m_elapsedTime(0.0f), m_frameTime(0.1f)
{
	m_sprite.setPosition(1100, e_posy);
	muer.loadFromFile("img/milicocaducado.png");
	buffer2.loadFromFile("music/alienshoot3.wav");
	
	m_totalFrames = 12; 
	m_frameWidth = m_texture.getSize().x / 12; 
	
	m_sprite.setTexture(m_texture);
	
	
	
	m_frameWidth = m_sprite.getGlobalBounds().width/11.8 ; 
	
	m_frameHeight = 59;
	
	m_sprite.setTextureRect(sf::IntRect(11 * m_frameWidth, 0, m_frameWidth, m_frameHeight));
	m_sprite.scale(2.3, 2.3);
	cod2=6;
	
	
}
Disparo_enemigo disparar(Texture &t2,Sprite &m_sprite){
	
	Vector2f pp=m_sprite.getPosition();
	float ang=m_sprite.getRotation()*M_PI/180;
	Vector2f dd(cos(ang),sin(ang));
	float xx=pp.x+45.f;
	float yy=pp.y+35.f;
	Vector2f ppp;
	ppp.x=xx;
	ppp.y=yy;
	
	return Disparo_enemigo(t2,ppp,dd);
}
	void Enemigo::reset(float e_posy, Texture &m_texture) {
		m_sprite.setPosition(1100, e_posy);
		m_sprite.setTexture(m_texture);
		m_sprite.setTextureRect(sf::IntRect(11 * m_frameWidth, 0, m_frameWidth, m_frameHeight)); 
		cod2 = 6; 
		m_currentFrame = 0;
		m_elapsedTime = 0.0f;
	}
	
	void Enemigo:: desactivar() {
		activo = false;
		m_sprite.setPosition(-1000, -1000); 
	}
	void Enemigo::activar(float posY, Texture &m_texture) {
		activo = true;
		m_sprite.setTexture(m_texture);
		m_sprite.setPosition(1100, posY);
		cod2 = 6;
		m_currentFrame = 0;
		m_elapsedTime = 0.0f;
	}
	bool Enemigo:: estaActivo() const {
		return activo;
	}
	bool Enemigo::esta_vivo(){
		return vivo;
	}
	void Enemigo::matar(){
		vivo=false;
	}
	

void Enemigo::Avanzar(float deltaTime,bool colisiona,Texture &t2,vector<Disparo_enemigo>&de) {
	m_bullet2.setTexture(t2);
	
	if(colisiona ){
		
		
		if(cod2>=3){
			m_sprite.setTexture(muer);
			m_sprite.setTextureRect(sf::IntRect(0 + 62 *cod2, 0, 62, 80));
			--cod2;
			
			
		}
		
	}else{
		m_sprite.move((-m_speed) * deltaTime, 0);
		
		m_elapsedTime += deltaTime;
		if (m_elapsedTime >= m_frameTime) {
			m_elapsedTime = 0.0f;
			m_currentFrame = (m_currentFrame - 1) % m_totalFrames; 
			m_sprite.setTextureRect(sf::IntRect((m_currentFrame + 11) * m_frameWidth, 0, m_frameWidth, m_frameHeight));
			if(m_currentFrame==0){
				Disparo_enemigo aux=disparar(t2,m_sprite);
				de.push_back(aux);
				disparo2.setBuffer(buffer2);
				disparo2.play();
			}
			
		}
		
		
		
	}
	
}

void Enemigo::dibujar(sf::RenderWindow& window) {
	window.draw(m_sprite);
}

Sprite Enemigo::ver_sprite(){
	return m_sprite;
	
}







