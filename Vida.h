#ifndef VIDA_H
#define VIDA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;

class Vida {
public:
	Vida( Texture &vidatext);
	Vida( Texture &vidatext,Vector2f pos_vida);
	Sprite ver_sprite();
	void actualizar(float &pos_x);
	void dibujar(RenderWindow &w);
	bool debe_eliminarse();
	sf::Clock m_tiempoVida;
private:
	Sprite spr_vida;
};

#endif

