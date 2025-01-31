#include "Bonus.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Vida.h"
#include <SFML/System/Vector2.hpp>

#include <vector>
using namespace std;
using namespace sf;

Bonus::Bonus( Texture &m_bonustext, float &bon_pos): m_speed(100.0f), m_currentFrame(0), m_elapsedTime(0.0f), m_frameTime(0.1f) {
	
	bonus_pos=bon_pos;
	male_text.loadFromFile("img/titi2.png");
	Bonus_spr.setPosition(1100, bon_pos);
	Bonus_text=m_bonustext;
	
	m_totalFrames = 10; 
	m_frameWidth = m_bonustext.getSize().x / 10; 
	m_frameHeight = m_bonustext.getSize().y;
	Bonus_spr.setTexture(m_bonustext);
	
	
	
	m_frameWidth = Bonus_spr.getGlobalBounds().width/10.5 ; 
	
	m_frameHeight = 59;
	
	Bonus_spr.setTextureRect(sf::IntRect(9 * m_frameWidth, 0, m_frameWidth, m_frameHeight));
	Bonus_spr.scale(2.7, 2.7);
	cod2=0;
	
}

Vida generar_vida(Texture &vida_text,Sprite &Bonus_spr){
	Vector2f pp=Bonus_spr.getPosition();
	float xx=pp.x+42.f;
	float yy=pp.y+40.f;
	Vector2f ppp;
	ppp.x=xx;
	ppp.y=yy;
	return Vida(vida_text,ppp);
	
}

void Bonus ::avanzar(float deltaTime,bool colisiona, Texture &vida_text, vector<Vida>&bonus_life){
	if(colisiona ){
		
		
		if(cod2<=12){
			Bonus_spr.setTexture(male_text);
			Bonus_spr.setTextureRect(sf::IntRect(0 + 44 *cod2, 0, 44, 60));
			++cod2;
			if(cod2==12){
				m_clock3.restart();
				Vida aux=generar_vida(vida_text,Bonus_spr);
				bonus_life.push_back(aux);
			}
			
		}
		
		if(cod2>=12 and m_clock3.getElapsedTime().asSeconds()>=2){
			Bonus_spr.setTexture(Bonus_text);
			Bonus_spr.move(-m_speed *0.16, 0);
			//desaparece=false;
			// Actualizar animación
			m_elapsedTime += deltaTime;
			if (m_elapsedTime >= m_frameTime) {
				m_elapsedTime = 0.0f;
				m_currentFrame = (m_currentFrame - 1) % m_totalFrames; // Usamos 8 frames para la animación
				Bonus_spr.setTextureRect(sf::IntRect((m_currentFrame + 9) * m_frameWidth, 0, m_frameWidth, m_frameHeight));
				//if(m_currentFrame==0){
				//	
				//}
				
			}
		}
		
	}else{
		Bonus_spr.move(-m_speed *0.16, 0);
		//desaparece=false;
		
		m_elapsedTime += deltaTime;
		if (m_elapsedTime >= m_frameTime) {
			m_elapsedTime = 0.0f;
			m_currentFrame = (m_currentFrame - 1) % m_totalFrames; // Usamos 8 frames para la animación
			Bonus_spr.setTextureRect(sf::IntRect((m_currentFrame + 9) * m_frameWidth, 0, m_frameWidth, m_frameHeight));
			//if(m_currentFrame==0){
			//	
			//}
			
		}
	}
	
}
void Bonus::dibujar(RenderWindow &w){
	w.draw(Bonus_spr);
}

Sprite Bonus::ver_sprite(){
	return Bonus_spr;
	
}
void Bonus::matar(){
	vivo=false;
}
bool Bonus::esta_vivo(){
	return vivo;
}
void Bonus::revivir(){
	vivo=true;
}
	
void Bonus:: desactivar() {
	activo = false;
	Bonus_spr.setPosition(-1000, -1000); 
}
bool Bonus:: esta_activo() const {
	return activo;
}
bool Bonus:: esta_vivo() const {
	return vivo;
}
void Bonus:: activar(float pos) {
	activo = true;
	Bonus_spr.setTexture(Bonus_text);
	Bonus_spr.setPosition(1100,pos);
	//Bonus_spr.setPosition(-1000, -1000); 
}

