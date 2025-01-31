#include "Vida.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;

Vida::Vida(Texture &vidatext) {
	spr_vida.setTexture(vidatext);
	spr_vida.setPosition(50,657);
	spr_vida.setScale(0.9,0.9);
	
}
Vida::Vida(Texture &vidatext,Vector2f pos_vida) {
	spr_vida.setTexture(vidatext);
	spr_vida.setPosition(pos_vida.x,pos_vida.y);
	spr_vida.setScale(0.7,0.7);
	
}
Sprite Vida ::ver_sprite() {
	return spr_vida;
}
void Vida:: actualizar (float &pos_x) {
	spr_vida.setPosition(pos_x,657);
	
}
void Vida:: dibujar (RenderWindow &w) {
	w.draw(spr_vida);
	
}
bool Vida::debe_eliminarse() {
	// Supongamos que el objeto debe ser eliminado después de 2 segundos
	return m_tiempoVida.getElapsedTime().asSeconds() > 1.5f;
}
