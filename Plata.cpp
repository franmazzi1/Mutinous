#include "Plata.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

Plata::Plata(Texture &platatext) {
	spr_plata.setTexture(platatext);
	spr_plata.setPosition(50,200);
	spr_plata.setScale(3,3);
	
}
Sprite Plata ::ver_sprite() {
	return spr_plata;
}
void Plata:: actualizar (float &pos_y) {
	spr_plata.setPosition(50,pos_y);
	
}
void Plata:: dibujar (RenderWindow &w) {
	w.draw(spr_plata);
	
}

