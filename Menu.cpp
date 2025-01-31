#include "menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Juego.h"
#include <SFML/Window/Keyboard.hpp>
#include "Partida.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>

using namespace sf;

Menu::Menu (){
	
	spr_menu.setPosition(0,0);
	spr_menu.setScale(0.95,1.3);
	buffer_men.loadFromFile("music/ambmenu.ogg");
	buffer_shot.loadFromFile("music/shotgun.ogg");
	sound_shot.setBuffer(buffer_shot);
	sound_menu.setBuffer(buffer_men);
	sound_menu.setLoop(true);
	texmenu.loadFromFile("img/fondooscuro.jpg");
	texinst.loadFromFile("img/fondofondo.jpg");
	ene.loadFromFile("img/policamina.png");
	bomb.loadFromFile("img/bomb.png");
	bon.loadFromFile("img/titi2.png");
	
	bonus.setTexture(bon);
	bonus.setTextureRect(IntRect(535, 0, 580, 50));
	bonus.setScale(1.4,1.4);
	bonus.setPosition(487, 420);
	
	bomba.setTexture(bomb);
	bomba.setTextureRect(IntRect(0, 0, 36, 32));
	bomba.setScale(1.7,1.7);
	bomba.setPosition(470, 350);
	
	enemigo.setTexture(ene);
	enemigo.setTextureRect(IntRect(0, 0, 36, 59));
	enemigo.setScale(1.2,1.2);
	enemigo.setPosition(480, 280);
	
	x.loadFromFile("img/x.png");
	
	dis.setTexture(x);
	dis.setScale(0.7,0.7);
	dis.setPosition(500, 165);
	
	wasd.loadFromFile("img/wasd.png");
	
	mov.setTexture(wasd);
	mov.setScale(0.8,0.8);
	mov.setPosition(460, 220);
	
	
	
	spr_inst.setTexture(texinst);
	calab.loadFromFile("img/calabopcion.png");
	spr_calab.setTexture(calab);
	spr_menu.setTexture(texmenu);
	f2.loadFromFile("text/Melted Monster.ttf");
	
	mutinous.setFont(f2);
	play.setFont(f2);
	instructions.setFont(f2);
	exit.setFont(f2);
	volver.setFont(f2);
	inst1.setFont(f2);
	inst2.setFont(f2);
	inst3.setFont(f2);
	inst4.setFont(f2);
	inst5.setFont(f2);
	inst6.setFont(f2);
	inst7.setFont(f2);
	inst8.setFont(f2);
	inst9.setFont(f2);
	suerte.setFont(f2);
	inst1.setString("Instrucciones...");        
	inst1.setCharacterSize(70);     
	inst1.setFillColor(sf::Color::Red); 
	inst1.setPosition(420, 50);
	inst2.setString("Disparo");        
	inst2.setCharacterSize(25);     
	inst2.setFillColor(sf::Color::Red); 
	inst2.setPosition(550, 170);
	inst3.setString("Movimiento");        
	inst3.setCharacterSize(25);     
	inst3.setFillColor(sf::Color::Red); 
	inst3.setPosition(550, 230);
	inst4.setString("quita 1 vida");        
	inst4.setCharacterSize(25);     
	inst4.setFillColor(sf::Color::Red); 
	inst4.setPosition(550, 300);
	inst5.setString("quita 2 vidas");        
	inst5.setCharacterSize(25);     
	inst5.setFillColor(sf::Color::Red); 
	inst5.setPosition(550, 370);
	inst9.setString("da 1 vida");        
	inst9.setCharacterSize(25);     
	inst9.setFillColor(sf::Color::Red); 
	inst9.setPosition(550, 440);
	inst6.setString("Sobrevive el mayor tiempo posible con la mayor cantidad de bolsas que puedas");        
	inst6.setCharacterSize(22);     
	inst6.setFillColor(sf::Color::Red); 
	inst6.setPosition(250, 520);
	inst7.setString("Si pierdes el motín ");        
	inst7.setCharacterSize(22);     
	inst7.setFillColor(sf::Color::Red); 
	inst7.setPosition(470, 550);
	inst8.setString("MUERES");        
	inst8.setCharacterSize(26);     
	inst8.setFillColor(sf::Color::Red); 
	inst8.setPosition(680, 547);
	suerte.setString("SUERTE");        
	suerte.setCharacterSize(250);     
	suerte.setFillColor(Color(100,0,0,50)); 
	suerte.setPosition(275, 250);
	mutinous.setString("Mutinous");        
	mutinous.setCharacterSize(120);     
	mutinous.setFillColor(sf::Color::Red); 
	mutinous.setPosition(700, 50);
	play.setString("Jugar");        
	play.setCharacterSize(50);     
	play.setFillColor(sf::Color::Red); 
	play.setPosition(850, 250);
	spr_calab.setPosition(750,250);
	instructions.setString("Instrucciones");        
	instructions.setCharacterSize(50);     
	instructions.setFillColor(sf::Color::Red); 
	instructions.setPosition(850, 350);
	exit.setString("Salir");        
	exit.setCharacterSize(50);     
	exit.setFillColor(sf::Color::Red); 
	exit.setPosition(850, 450);
	volver.setString("Volver");
	volver.setCharacterSize(50);     
	volver.setFillColor(sf::Color::Red);
	volver.setPosition(550,600);
	textBounds= play.getGlobalBounds();
	selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20)); 
	selectionRect.setFillColor(Color(255, 255, 0, 27));
	selectionRect.setOutlineColor(sf::Color::Yellow);
	selectionRect.setOutlineThickness(5);
	selectionRect.setPosition(play.getPosition().x-10 , play.getPosition().y );
	pos_rect=selectionRect.getPosition();
	pres.restart();
	sound_menu.play();
	
}
Sprite Menu::ver_sprite(){
	return spr_menu;
}
void Menu::dibujar(RenderWindow &w) {
	
	
	if (!inst) {
		w.draw(spr_menu);
		w.draw(mutinous);
		w.draw(play);
		w.draw(instructions);
		w.draw(exit);
		w.draw(selectionRect);
		w.draw(spr_calab);
	} else if (inst) {
		w.draw(spr_inst);
		w.draw(volver);
		w.draw(selectionRect);
		w.draw(spr_calab);
		w.draw(inst1);
		w.draw(inst2);
		w.draw(inst3);
		w.draw(inst4);
		w.draw(inst5);
		w.draw(inst6);
		w.draw(inst7);
		w.draw(inst8);
		w.draw(inst9);
		w.draw(suerte);
		w.draw(bomba);
		w.draw(enemigo);
		w.draw(dis);
		w.draw(mov);
		w.draw(bonus);
	}
	
	if (cerrar) {
		w.close();
	}
}

void Menu:: actualizar (Juego &ju) {
	if (Keyboard::isKeyPressed(Keyboard::Return) && pos_rect.y==250){
		sound_shot.play();
		sound_menu.stop();
		ju.cambiar_escena(new Partida);
	}
	if (Keyboard::isKeyPressed(Keyboard::Return) && pos_rect.y==450){
		sound_shot.play();
		cerrar=true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Return) && pos_rect.y==350 && pres.getElapsedTime().asMilliseconds()>100){
		sound_shot.play();
		inst=true;
		textBounds= volver.getGlobalBounds();
		selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20));
		selectionRect.setPosition(volver.getPosition().x-10 , volver.getPosition().y );
		pos_rect=selectionRect.getPosition();
		spr_calab.setPosition(450,590);
		
		pres.restart();
		
	}
	if(Keyboard::isKeyPressed(Keyboard::Return) && pos_rect.y==600 && pres.getElapsedTime().asMilliseconds()>100){
		pres.restart();
		sound_shot.play();
		textBounds= instructions.getGlobalBounds();
		selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20));
		selectionRect.setPosition(instructions.getPosition().x-10 , instructions.getPosition().y );
		pos_rect=selectionRect.getPosition();
		spr_calab.setPosition(750,350);
		inst=false;
		pres.restart();
	}
	
	if(pos_rect.y==250 && Keyboard::isKeyPressed(Keyboard::S) && pres.getElapsedTime().asMilliseconds()>100){
		textBounds= instructions.getGlobalBounds();
		selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20));
		selectionRect.setPosition(instructions.getPosition().x-10 , instructions.getPosition().y );
		pos_rect=selectionRect.getPosition();
		spr_calab.setPosition(750,350);
		pres.restart();
		
	}	
	if(pos_rect.y==350 && Keyboard::isKeyPressed(Keyboard::S) && pres.getElapsedTime().asMilliseconds()>100){
		textBounds= exit.getGlobalBounds();
		selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20));
		selectionRect.setPosition(exit.getPosition().x-10 , exit.getPosition().y );
		pos_rect=selectionRect.getPosition();
		spr_calab.setPosition(750,450);
		pres.restart();
	}else if(pos_rect.y==350 && Keyboard::isKeyPressed(Keyboard::W) && pres.getElapsedTime().asMilliseconds()>100){
		textBounds= play.getGlobalBounds();
		selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20));
		selectionRect.setPosition(play.getPosition().x-10 , play.getPosition().y );
		pos_rect=selectionRect.getPosition();
		spr_calab.setPosition(750,250);
		pres.restart();
	}
	if(pos_rect.y==450 && Keyboard::isKeyPressed(Keyboard::W) && pres.getElapsedTime().asMilliseconds()>100){
		textBounds= instructions.getGlobalBounds();
		selectionRect.setSize(Vector2f(textBounds.width + 20, textBounds.height + 20));
		selectionRect.setPosition(instructions.getPosition().x-10 , instructions.getPosition().y );
		pos_rect=selectionRect.getPosition();
		spr_calab.setPosition(750,350);
		pres.restart();
	}
}
void Menu::manejarEventos(const sf::Event& event) {
	
}
