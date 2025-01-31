#include "Disparo.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "Personaje.h"

#include <cmath>
using namespace std;
using namespace sf;

Disparo::Disparo(Texture &t,Vector2f hpos,Vector2f dir,bool de) {
	
	bullet.setTexture(t);
	FloatRect bounds = bullet.getGlobalBounds();
	float centerX = (bounds.left + bounds.width )/ 2;
	float centerY = (bounds.top + bounds.height )/ 2;
	bullet.setPosition(hpos);
	bullet.setScale(2,2);
	bullet.setOrigin(centerX,centerY);
	if(de){
		m_vel=dir*65.f;
	}else{
		bullet.setRotation(180);
		bullet.move(-15.f,0);
		m_vel=-dir*65.f;
	}
	
	
}
void Disparo::actualizar(){
	bullet.move(m_vel);
}
void Disparo::dibujar(RenderWindow &w){
	w.draw(bullet);
}
Sprite Disparo::ver_sprite(){
	return bullet;
	
}
