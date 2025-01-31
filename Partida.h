#ifndef PARTIDA_H
#define PARTIDA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Personaje.h"
#include <SFML/Audio/Sound.hpp>


#include <vector>
#include "Disparo.h"
#include "Plata.h"
#include "Vida.h"
#include "Enemigo.h"
#include "Disparo_enemigo.h"
#include <SFML/System/Clock.hpp>
#include "Stack.h"
#include "Escena.h"
#include "Juego.h"
#include "Bonus.h"
#include "bomb.h"
using namespace std;
using namespace sf;

class Partida: public Escena {
public:
	Partida();
	void actualizar(Juego &ju )override;
	void dibujar(RenderWindow &w)override;
	void manejarEventos(const sf::Event& event)override;
private:
	SoundBuffer buffer;
	Sound juego;
	
	Personaje per;
	//Bonus Bon;
	vector<Disparo>v;
	vector<Plata>p;
	vector<Vida>life;
	vector<Enemigo>ee;
	vector<Bonus>bon;
	vector<Disparo_enemigo>de;
	vector<Vida>bonus_life;
	Clock m_spawn;
	Texture disp_text;
	Texture fondo_text;
	Texture plata_text;
	Texture ene_text;
	Texture bonus_text;
	Texture disp_text2;
	Texture vida_text;
	Sprite aux;
	float x_pos_x;
	bool bongen;
	//float eneposy2=160;
	Sprite fondo;
	Stack sta;
	int sco;
	Font f1;
	
	Text score;
	
	int cont;
	int cant;
	int cant2;
	bool entra;
	vector<bool>colisiono;
	vector<bool>colisionobon;
	vector<bool>colisionobon2;
	vector<bool>coli_disparo;
	vector<bool>eliminar_balas;
	float eneposy2=170;
	int conteo=0;
	vector<bool>coli_disparo2;
	vector<bool>vivos;
	Clock clock;
	Clock m_bonus;
	Clock clock2;
	Clock regen;
	Clock m_bonus2;
	Clock actionClock;
	float pos_y;
	float pos_x;
	float eneposy;
	float deltaTime;
	float deltaTime2;
	float speed;
	float cont3;
	bool des;
	bool bombgen;
	vector<Bomb> bombas;
	Clock bombSpawnClock;
	Texture bombTexture;
	Texture bomba_text;
};

#endif


