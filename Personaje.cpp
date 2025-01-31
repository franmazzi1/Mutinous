#include "Personaje.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <cmath>
#include <SFML/System/Sleep.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Disparo.h"
#include <SFML/Graphics/Texture.hpp>

using namespace sf;
using namespace std;
Personaje::Personaje() {
	arriba=Keyboard:: W;
	abajo=Keyboard:: S;
	der=Keyboard:: D;
	izq=Keyboard:: A;
	disp=Keyboard:: E;
	buffer.loadFromFile("music/title-_mp3cut.net_.ogg");
	buffer3.loadFromFile("music/pain1.wav");
	mantex.loadFromFile("img/manes.png");
	mantex2.loadFromFile("img/manes2.png");
	mantex3.loadFromFile("img/disparader.png");
	mantex4.loadFromFile("img/disparaizq.png");
	mantex5.loadFromFile("img/jasonmuerto.png");
	man.setTexture(mantex);
	man.setTextureRect(IntRect(0,0,73,80));
	man.setPosition(175, 350);
	man.setOrigin(50,20);
	man.scale(2,2);
	
}


void Personaje::recibe_impacto(){
	
	man.setTexture(mantex5);
	man.setTextureRect(IntRect(0,0,65,80));
	disparo.setBuffer(buffer3);

	static bool sonidoActivo = false;
	static sf::Clock cooldownTimer;
	
	if (!sonidoActivo || cooldownTimer.getElapsedTime() >= sf::seconds(0.80f)) {
		disparo.play();
		sonidoActivo = true;
		cooldownTimer.restart();
	}
	
	
	
}



void Personaje::actualizar(){
	
	
	float leftLimit = 180;
	float rightLimit = 700; 
	float topLimit = 100;
	float bottomLimit = 525;
	
	if (Keyboard::isKeyPressed(izq) && man.getPosition().x - 13.f > leftLimit){
		//Vector2f pos=man.getPosition();
		
		man.setTexture(mantex2);
		man.setTextureRect(IntRect(0+cod2*73,0,73,80));
		
		man.move(-13.f,0);
		--cod2;
		if(cod2==0){
			man.setTextureRect(IntRect(0+cod2*73,0,73,80));
			cod2=5;
		}
		dere=false;
		
	}
	else if (Keyboard::isKeyPressed(der) && man.getPosition().x + 13.f < rightLimit){
		//Vector2f pos=man.getPosition();
		
		man.move(13.f,0);
		man.setTexture(mantex);
		man.setTextureRect(IntRect(0+cod*73,0,73,80));
		++cod;
		if(cod==5){
			man.setTextureRect(IntRect(0+cod*73,0,73,80));
			cod=0;
		}
		dere=true;
	}
	else if (Keyboard::isKeyPressed(arriba) && man.getPosition().y - 13.f > topLimit){
		//Vector2f pos=man.getPosition();
		man.move(0,-13.f);
		if(dere){
			man.setTexture(mantex);
			man.setTextureRect(IntRect(0+cod*73,0,73,80));
			++cod;
			if(cod==5){
				man.setTextureRect(IntRect(0+cod*73,0,73,80));
				cod=0;
			}
			
		}else{
			man.setTexture(mantex2);
			man.setTextureRect(IntRect(0+cod2*73,0,73,80));
			--cod2;
			if(cod2==0){
				man.setTextureRect(IntRect(0+cod2*73,0,73,80));
				cod2=5;
			}
		}
		
	}
	else if (Keyboard::isKeyPressed(abajo) && man.getPosition().y + 13.f < bottomLimit){
		//Vector2f pos=man.getPosition();
		man.move(0,13.f);
		if(dere){
			man.setTexture(mantex);
			man.setTextureRect(IntRect(0+cod*73,0,73,80));
			++cod;
			if(cod==5){
				man.setTextureRect(IntRect(0+cod*73,0,73,80));
				cod=0;
			}
			
		}else{
			man.setTexture(mantex2);
			man.setTextureRect(IntRect(0+cod2*73,0,73,80));
			--cod2;
			if(cod2==0){
				man.setTextureRect(IntRect(0+cod2*73,0,73,80));
				cod2=5;
			}
		}
	}
	else if (Keyboard::isKeyPressed(disp)){
		
		if(dere){
			if (m_clock.getElapsedTime().asMilliseconds() >= 400) {
				
				m_clock.restart();
				
				man.setTexture(mantex3);
				man.setTextureRect(sf::IntRect(0, 0, 90, 80));
				disparo.setBuffer(buffer);
				disparo.play();
			} else {
				
				//disparo.setBuffer(buffer);
				//disparo.play();
				man.setTexture(mantex3);
				man.setTextureRect(sf::IntRect(90, 0, 90, 80));
			}
		}else{
			if (m_clock.getElapsedTime().asMilliseconds() >= 400) {
				
				m_clock.restart();
				
				man.setTexture(mantex4);
				man.setTextureRect(sf::IntRect(90, 0, 90, 80));
				disparo.setBuffer(buffer);
				disparo.play();
			} else {
				
				//disparo.setBuffer(buffer);
				//disparo.play();
				man.setTexture(mantex4);
				man.setTextureRect(sf::IntRect(0, 0, 90, 80));
			}
		}
		
	} 
	else{
		if(dere){
			man.setTexture(mantex);
			man.setTextureRect(IntRect(0,0,73,80));
		}else{
			man.setTexture(mantex2);
			man.setTextureRect(IntRect(365,0,73,80));
		}
		
	}}
void Personaje::dibujar(RenderWindow &w){
	w.draw(man);
}
bool Personaje::debe_disparar(){
	if(m_clock2.getElapsedTime().asMilliseconds()<500){
		return false;
	}
	if(not Keyboard::isKeyPressed(disp)){
		return false;
	}
	if(not Keyboard::isKeyPressed(arriba) and not Keyboard::isKeyPressed(abajo)and not Keyboard::isKeyPressed(der) and not Keyboard::isKeyPressed(izq) ){
		m_clock2.restart();
		return true;
	}
	//m_clock2.restart();
	//return true;
}
Disparo Personaje::disparar(Texture &t){
	Vector2f pp=man.getPosition();
	float ang=man.getRotation()*M_PI/180;
	Vector2f dd(cos(ang),sin(ang));
	
	return Disparo(t,pp,dd,dere);
}

Sprite Personaje::ver_sprite(){
	return man;
}

//Vector2f Personaje::ver_posicion(){
	//return man.getPosition();
//}
