#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Escena.h"
#include <SFML/Graphics/Texture.hpp>
#include "Juego.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

using namespace sf;

class Menu :public Escena{
public:
	Menu();
	Sprite ver_sprite();
	void dibujar(RenderWindow &w)override;
	void manejarEventos(const sf::Event& event)override;
	void actualizar(Juego &ju)override;
private:
	Sprite spr_menu;
	Texture texmenu;
	Texture calab;
	Texture texinst;
	Texture ene;
	Texture bomb;
	Texture x;
	Texture wasd;
	Texture bon;
	Sprite bonus;
	Sprite dis;
	Sprite mov;
	Sprite enemigo;
	Sprite bomba;
	Sprite spr_inst;
	Sprite spr_calab;
	SoundBuffer buffer_men;
	Sound sound_menu;
	SoundBuffer buffer_shot;
	Sound sound_shot;
	Text mutinous;
	Text play;
	Text instructions;
	Text exit;
	Text volver;
	Text inst1;
	Text inst2;
	Text inst3;
	Text inst4;
	Text inst5;
	Text inst6;
	Text inst7;
	Text inst8;
	Text inst9;
	Text suerte;
	Font f2;
	FloatRect textBounds;
	RectangleShape selectionRect;
	Vector2f pos_rect;
	Clock pres;
	bool cerrar=false;
	bool inst=false;
	//Menu m(texmenu);
};

#endif

