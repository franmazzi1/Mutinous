#include "GameOver.h"
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include "Partida.h"
#include <SFML/Window/Mouse.hpp>

#include <iostream>
#include "ArchivoPuntajes.h"
#include <fstream>
using namespace std;
using namespace sf;




GameOver::GameOver(int &m_score):puntaje(m_score), registro_completado(false) {
	
	buffer_shot.loadFromFile("music/shotgun.ogg");
	sound_shot.setBuffer(buffer_shot);
	fondotext.loadFromFile("img/fondofondo.jpg");
	simbotext.loadFromFile("img/simbol.png");
	calab.loadFromFile("img/calabopcion.png");
	botontext.loadFromFile("img/botoningreso.png");
	spr_boton.setTexture(botontext);
	spr_calab.setTexture(calab);
	spr_simbo.setTexture(simbotext);
	spr_simbo2.setTexture(simbotext);
	spr_fondo.setTexture(fondotext);
	spr_calab.setPosition(385,180);
	spr_boton.setPosition(980,420);
	spr_boton.setScale(0.34,1.3);
	f3.loadFromFile("text/HORROR SPRAY DEMO Regular.otf");
	f4.loadFromFile("text/Melted Monster.ttf");
	finjuego.setFont(f3);
	JuegaDenuevo.setFont(f4);
	top3.setFont(f4);
	MenuPrincipal.setFont(f4);
	Puntos.setFont(f4);
	Registro.setFont(f4);
	score.setFont(f4);
	Ingresar.setFont(f4);
	IngUsuario.setFont(f4);
	TextoIngresado.setFont(f4);
	score.setCharacterSize(60);
	score.setString(to_string(puntaje));
	score.setPosition(850,510);
	TextoIngresado.setString(texto);
	TextoIngresado.setCharacterSize(25);
	TextoIngresado.setColor(Color::Black);
	TextoIngresado.setPosition(500,430);
	
	ifstream file("ranking.txt");
	
	while (getline(file, line) && count < 3) {
		nombres.push_back(line);
		count++;
	}
	
	file.close();
	
	
	

	for (int i = 0; i < nombres.size(); ++i) {
		Text mej(nombres[i], f4 , 30); 
		if(i==0){
			mej.setFillColor(Color(255, 215, 0));
		}else{
			if(i==1){
				mej.setFillColor(Color(192, 192, 192));
			}else{
				mej.setFillColor(Color(205, 127, 50));
			}
		}
		mej.setPosition(30, 50 *i + 250);   
		mejores.push_back(mej);
	}
	
	
	
	
	
	
	
	
	Ingresar.setString("Ingresar");
	Ingresar.setCharacterSize(30);
	Ingresar.setColor(Color(128, 0, 128));
	Ingresar.setPosition(985,425);
	IngUsuario.setString("Usuario:");
	IngUsuario.setCharacterSize(40);
	IngUsuario.setColor(sf::Color::Red);
	IngUsuario.setPosition(330,420);
	finjuego.setString("Juego Terminado");
	finjuego.setCharacterSize(80);
	finjuego.setColor(sf::Color::Red);
	finjuego.setPosition(450,50);
	top3.setString("TOP 3:");
	top3.setCharacterSize(70);
	top3.setColor(sf::Color::Red);
	top3.setPosition(40,150);
	JuegaDenuevo.setString("Jugar otra vez");
	JuegaDenuevo.setCharacterSize(40);
	JuegaDenuevo.setColor(sf::Color::Red);
	JuegaDenuevo.setPosition(500,200);
	MenuPrincipal.setString("Menu Principal");
	MenuPrincipal.setCharacterSize(40);
	MenuPrincipal.setColor(sf::Color::Red);
	MenuPrincipal.setPosition(500,310);
	Puntos.setString("Puntaje Obtenido:");
	Puntos.setCharacterSize(40);
	Puntos.setColor(sf::Color::Red);
	Puntos.setPosition(500,530);//(500,530)
	Registro.setString("Registrar");
	Registro.setCharacterSize(40);
	Registro.setColor(sf::Color::Red);
	Registro.setPosition(500,420);//(500,420)
	spr_simbo.setPosition(350,50);
	spr_simbo2.setPosition(875,50);
	textBounds= JuegaDenuevo.getGlobalBounds();
	CuadroDialogo.setSize(Vector2f(480,58));
	CuadroDialogo.setFillColor(sf::Color::White);
	CuadroDialogo.setOutlineColor(sf::Color::Red);
	CuadroDialogo.setOutlineThickness(5);
	CuadroDialogo.setPosition(Registro.getPosition().x-10 , Registro.getPosition().y );
	selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20)); 
	selectionRect.setFillColor(Color(255, 255, 0, 27));
	selectionRect.setOutlineColor(sf::Color::Yellow);
	selectionRect.setOutlineThickness(5);
	selectionRect.setPosition(JuegaDenuevo.getPosition().x-10 , JuegaDenuevo.getPosition().y );
	BotonIngreso.setSize(Vector2f(133, 59)); 
	BotonIngreso.setFillColor(Color(255, 255, 0, 27));
	BotonIngreso.setOutlineColor(sf::Color::Green);
	BotonIngreso.setOutlineThickness(5);
	BotonIngreso.setPosition(980,420);
	
	
	cursor.setSize(sf::Vector2f(2, 30)); 
	cursor.setFillColor(sf::Color::Black);
	cursorBlinkInterval = 0.5f; 
	
	
	
	pos_rect=selectionRect.getPosition();
	pres.restart();
}
void GameOver::actualizar(Juego &ju) {
	if (registrarse) {
		FloatRect textBounds = TextoIngresado.getLocalBounds();
		float textWidth = textBounds.width;
		cursor.setPosition(TextoIngresado.getPosition().x + textWidth, TextoIngresado.getPosition().y + 5); 
		if (cursorClock.getElapsedTime().asSeconds() > cursorBlinkInterval) {
			cursorClock.restart();
			cursor.setFillColor(cursor.getFillColor() == sf::Color::Black ? sf::Color::Transparent : sf::Color::Black);
		}
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Return) && pos_rect.y == 310) {
		sound_shot.play();
		ju.cambiar_escena(new Menu);
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Return) && pos_rect.y == 200) {
		sound_shot.play();
		ju.cambiar_escena(new Partida);
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Return) && pres.getElapsedTime().asMilliseconds() > 100 && registrarse && !registro_completado) {
		sound_shot.play();
		registrarse = false;
		ArchivoPuntajes aux(puntaje, texto);
		registro_completado = true; 
		texto.clear();
		TextoIngresado.setString(texto);
		pres.restart();
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Return) && pos_rect.y == 420 && pres.getElapsedTime().asMilliseconds() > 100 && !registrarse && !registro_completado) {
		sound_shot.play();
		registrarse = true;
		pres.restart();
	}
	
	if (pos_rect.y == 200 && Keyboard::isKeyPressed(Keyboard::S) && pres.getElapsedTime().asMilliseconds() > 100 && !registrarse) {
		textBounds = MenuPrincipal.getGlobalBounds();
		selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20));
		selectionRect.setPosition(MenuPrincipal.getPosition().x - 10, MenuPrincipal.getPosition().y);
		pos_rect = selectionRect.getPosition();
		spr_calab.setPosition(385, 290);
		pres.restart();
	}
	if (pos_rect.y == 310 && Keyboard::isKeyPressed(Keyboard::W) && pres.getElapsedTime().asMilliseconds() > 100 && !registrarse) {
		textBounds = JuegaDenuevo.getGlobalBounds();
		selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20));
		selectionRect.setPosition(JuegaDenuevo.getPosition().x - 10, JuegaDenuevo.getPosition().y);
		pos_rect = selectionRect.getPosition();
		spr_calab.setPosition(385, 180);
		pres.restart();
	} else if (pos_rect.y == 310 && Keyboard::isKeyPressed(Keyboard::S) && pres.getElapsedTime().asMilliseconds() > 100 && !registrarse) {
		textBounds = Registro.getGlobalBounds();
		selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20));
		selectionRect.setPosition(Registro.getPosition().x - 10, Registro.getPosition().y);
		pos_rect = selectionRect.getPosition();
		spr_calab.setPosition(385, 400);
		pres.restart();
	}
	if (pos_rect.y == 420 && Keyboard::isKeyPressed(Keyboard::W) && pres.getElapsedTime().asMilliseconds() > 100 && !registrarse) {
		textBounds = MenuPrincipal.getGlobalBounds();
		selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20));
		selectionRect.setPosition(MenuPrincipal.getPosition().x - 10, MenuPrincipal.getPosition().y);
		pos_rect = selectionRect.getPosition();
		spr_calab.setPosition(385, 290);
		pres.restart();
	}
}

void GameOver::manejarEventos(const sf::Event& event) {
	if (registrarse) {
		if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode == '\b') { 
				if (!texto.empty()) {
					texto.pop_back();
				}
			} else if (event.text.unicode < 128) { 
				
				Text tempText = TextoIngresado;
				tempText.setString(texto + static_cast<char>(event.text.unicode));
				if (tempText.getGlobalBounds().width < CuadroDialogo.getSize().x - 30 &&
					tempText.getGlobalBounds().height < CuadroDialogo.getSize().y - 10) {
					texto += static_cast<char>(event.text.unicode);
				}
			}
			TextoIngresado.setString(texto);
		}
	}
}

void GameOver::dibujar(RenderWindow &w) {
	w.draw(spr_fondo);
	w.draw(finjuego);
	w.draw(spr_simbo);
	w.draw(spr_simbo2);
	for(size_t i=0;i<mejores.size();++i){
		w.draw(mejores[i]);
	}
	w.draw(top3);
	w.draw(JuegaDenuevo);
	w.draw(MenuPrincipal);
	w.draw(selectionRect);
	if(!registrarse){
		w.draw(spr_calab);
	}
	w.draw(Puntos);
	w.draw(Registro);
	w.draw(score);
	if(registrarse){
		w.draw(CuadroDialogo);
		w.draw(IngUsuario);
		w.draw(spr_boton);
		w.draw(BotonIngreso);
		w.draw(Ingresar);
		w.draw(TextoIngresado);
		w.draw(cursor); 
		
	}
	
}
