#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "Escena.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Window/Event.hpp>

#include <vector>
using namespace std;
using namespace sf;

class GameOver :public Escena {
public:
	GameOver(int &m_score);
	void actualizar(Juego &ju)override;
	void dibujar(RenderWindow &w)override;
	void manejarEventos(const sf::Event& event)override;
private:
	Event event;
	Texture fondotext;
	Texture simbotext;
	Texture calab;
	Texture botontext;
	Text JuegaDenuevo;
	Text MenuPrincipal;
	Text Puntos;
	Text Registro;
	Text score;
	Text Ingresar;
	Text IngUsuario;
	Text TextoIngresado;
	Text top3;
	SoundBuffer buffer_shot;
	Sound sound_shot;
	Sprite spr_calab;
	Sprite spr_simbo;
	Sprite spr_fondo;
	Sprite spr_simbo2;
	Sprite spr_boton;
	Text finjuego;
	Font f3;
	Font f4;
	FloatRect textBounds;
	RectangleShape selectionRect;
	RectangleShape CuadroDialogo;
	RectangleShape BotonIngreso;
	Vector2f pos_rect;
	Clock pres;
	string texto;
	int puntaje;
	bool registrarse=false;
	bool clicked=false;
	vector<bool>keyStates;
	sf::RectangleShape cursor;
	sf::Clock cursorClock;
	float cursorBlinkInterval = 0.5f;
	vector<string> nombres;
	string line;
	int count = 0;
	vector<Text> mejores;
	bool registro_completado;
};

#endif

