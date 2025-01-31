#ifndef DISPARO_ENEMIGO_H
#define DISPARO_ENEMIGO_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class Disparo_enemigo {
public:
	Disparo_enemigo(Texture &t2,Vector2f pos,Vector2f dir);
	void actualizar();
	void dibujar(RenderWindow &w);
	Sprite ver_sprite();
	
private:
	Sprite bullet2;
	Vector2f m_vel2;
};

#endif

