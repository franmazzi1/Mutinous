#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


using namespace sf;

class Disparo {
public:
	Disparo(Texture &t,Vector2f pos,Vector2f dir,bool de);
	void actualizar();
	void dibujar(RenderWindow &w);
	Sprite ver_sprite();
private:
	Sprite bullet;
	Vector2f m_vel;
	
};

#endif

