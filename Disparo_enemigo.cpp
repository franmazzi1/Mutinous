#include "Disparo_enemigo.h"
#include <SFML/Graphics/Texture.hpp>

using namespace sf;

Disparo_enemigo::Disparo_enemigo(Texture &t2,Vector2f hpos2,Vector2f dir2) {
	
	bullet2.setTexture(t2);
	FloatRect bounds = bullet2.getGlobalBounds();
	float centerX2 = (bounds.left + bounds.width )/ 2;
	float centerY2 = (bounds.top + bounds.height )/ 2;
	bullet2.setPosition(hpos2);
	bullet2.setScale(1,1);
	bullet2.setOrigin(centerX2,centerY2);
	m_vel2=-dir2*40.f;
	
	
	
}
void Disparo_enemigo::actualizar(){
	bullet2.move(m_vel2);
}
void Disparo_enemigo::dibujar(RenderWindow &w){
	w.draw(bullet2);
}
Sprite Disparo_enemigo::ver_sprite(){
	return bullet2;
	
}

