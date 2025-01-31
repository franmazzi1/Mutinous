#ifndef PLATA_H
#define PLATA_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Plata {
public:
	Plata( Texture &platatext);
	Sprite ver_sprite();
	void actualizar(float &pos_y);
	void dibujar(RenderWindow &w);
	//void eliminar();
		
	
private:
	Sprite spr_plata;
};

#endif

