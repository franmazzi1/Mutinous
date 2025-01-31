#include "Partida.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include "Enemigo.h"
#include "Disparo.h"
#include "Plata.h"
#include "Vida.h"
#include "Disparo_enemigo.h"
#include <SFML/System/Clock.hpp>
#include "Stack.h"
#include "Personaje.h"
#include "Juego.h"
#include "GameOver.h"
#include "Bonus.h"
#include <cstdlib>
#include <random>
#include "bomb.h"
using namespace std;
using namespace sf;

bool colisiona( const Sprite &spr1,  const Sprite &spr2){
	FloatRect r1= spr1.getGlobalBounds();
	FloatRect r2= spr2.getGlobalBounds();
	if(r2.width>=110.4){
		
		float newWidth = 75;
		float newHeight = 130;
		
		
		r2.left += (r2.width - newWidth) / 2;
		r2.top += (r2.height - newHeight) / 2;
		
		r2.width = newWidth;
		r2.height = newHeight;//r2.width=0;
	}
	
	r1.width=1;
	return r1.intersects(r2);
}
	
	void spawn(vector<Enemigo>& ee, Texture &ene_text,float speed) {
		int cant2 = 3;
		float eneposy = 105;
		
		for (int i = 0; i < cant2; ++i) {
			bool foundInactive = false;
			for (auto& enemigo : ee) {
				if (!enemigo.estaActivo()) {
					enemigo.activar(eneposy, ene_text);
					foundInactive = true;
					break;
				}
			}
			if (!foundInactive) {
				Enemigo ene(ene_text, eneposy,speed);
				ee.push_back(ene);
			}
			eneposy += 195;
		}
	}
	void spawn_bon(vector<Bonus>& bon, Texture &bonus_text) {
		
		
		static std::random_device rd;
		static std::mt19937 gen(rd()); 
		std::uniform_int_distribution<> distrib(0, 1); 
		

		float eneposy2 = distrib(gen) == 0 ? 270.0f : 470.0f;
		
		
		Bonus aux(bonus_text, eneposy2);
		bon.push_back(aux);
		//bon[0].revivir();
	}
	
	
	
	template <typename T,typename S>
		void borrar_memoria(vector<T>&spr,vector<S>&bol){
		int index = spr.size();
		Sprite aux;
		float x_pos_x;
		for (size_t i = 0; i < index;) {
			aux=spr[i].ver_sprite();
			x_pos_x=aux.getPosition().x;
			if (bol[i] or x_pos_x<=-30 or x_pos_x>= 1285) {
				spr.erase(spr.begin() + i);
				bol.erase(bol.begin() + i);
				--index; 
			} else {
				++i; 
			}
		}
	}
		
		
		Partida::Partida() {
			m_bonus.restart();
			buffer.loadFromFile("music/musicaamb.ogg");
			bonus_text.loadFromFile("img/titilda4.png");
			juego.setBuffer(buffer);
			juego.setLoop(true);
			juego.setVolume(10);
			juego.play();
			bongen=false;
			fondo_text.loadFromFile("img/fondito.png");
			fondo.setTexture(fondo_text);
			fondo.setPosition(0,-60);
			sco=0;
			f1.loadFromFile("text/Hibo.otf");
			score.setFont(f1);
			score.setCharacterSize(32);
			score.setString(to_string(sco));
			score.setPosition(854,663);
			cont=1;
			cant=0;
			cant2=2;
			cont3=0.1;
			entra=false;
			disp_text.loadFromFile("img/bala1.png");
			plata_text.loadFromFile("img/dinero.png");
			ene_text.loadFromFile("img/policamina.png");
			disp_text2.loadFromFile("img/bala2.png");
			vida_text.loadFromFile("img/corazon1.png");
			
			
			pos_y=680;
			pos_x=340;
			eneposy=120;
			speed = 100.0f;
			Enemigo ene(ene_text,eneposy,speed);
			Bonus Bon(bonus_text,eneposy2);
			Plata Pla(plata_text);
			Vida vi(vida_text);
			regen.restart();
			bomba_text.loadFromFile("img/bomb.png"); 
			bombgen=false;
			
			
			
			while(cant<=4){
				p.push_back(Pla);
				++cant;
			}
			cant=0;
			while(cant<=3){
				life.push_back(vi);
				++cant;
			}
			//Stack sta;
			
			
			spawn(ee,ene_text,speed);
			spawn_bon(bon,bonus_text);
			
			
			
			
			for(size_t i=0;i<p.size();++i){
				pos_y=pos_y-98;
				p[i].actualizar(pos_y);
			}
			for(size_t i=0;i<life.size();++i){
				pos_x=pos_x+60;
				life[i].actualizar(pos_x);
			}
			
			deltaTime = clock.restart().asSeconds();
			deltaTime2 = clock.restart().asSeconds();
			
		}
		
		void Partida::actualizar(Juego &ju) {
			float x=460;
			colisiono.resize(ee.size());
			colisionobon.resize(bon.size());
			colisionobon2.resize(bon.size());
			per.actualizar();
			deltaTime = clock.restart().asSeconds();
			deltaTime2 = clock2.restart().asSeconds();
			
			if (speed < 300.0f) {
				speed = speed + (sco/500.0f);
			}
			
			if(per.debe_disparar()){
				v.push_back(per.disparar(disp_text));
				coli_disparo.resize(v.size());
			}
			
			for (size_t i = 0; i < v.size(); ++i) {
				eliminar_balas.resize(v.size());
				v[i].actualizar();
				
				for (size_t j = 0; j < ee.size(); ++j) {
					if (ee[j].esta_vivo()) {
						if (colisiona(v[i].ver_sprite(), ee[j].ver_sprite())) {
							colisiono[j] = true;
							coli_disparo[i] = true;
							
							if (ee[j].esta_vivo()) {
								sco += 10;
								ee[j].matar();
							}
							
							score.setString(to_string(sco));
							eliminar_balas[i] = true;
						}
					}
				}
				
				for (size_t k = 0; k < bon.size(); ++k) {
					if (bon[k].esta_vivo()) {
						if (colisiona(v[i].ver_sprite(), bon[k].ver_sprite())) {
							colisionobon[k] = true;
							colisionobon2[k]=true;
							coli_disparo[i] = true;
							bon[k].matar();
							eliminar_balas[i] = true;
						}
					}
				}
			}
			
			for (int i = v.size() - 1; i >= 0; --i) {
				if (eliminar_balas[i]) {
					v.erase(v.begin() + i);  
					eliminar_balas.erase(eliminar_balas.begin() + i);  
				}
			}
			
			
			for(size_t i=0;i<p.size();++i){
				
				for(size_t j=0;j<ee.size();++j){
					if(colisiona(p[i].ver_sprite(),ee[j].ver_sprite())  ){
						p.erase(p.begin()+i);
						
					}
				}
			}
			if (p.empty()) {
				juego.stop();
				sco=sco*p.size();
				ju.cambiar_escena(new GameOver(sco));
			} 
			//bon[0].avanzar(deltaTime2,);
			///////////////////////////////////////////////////////////////////////////
			for(size_t i=0;i<ee.size();++i){
				
				ee[i].Avanzar(deltaTime,colisiono[i],disp_text2,de);
				if (ee[i].ver_sprite().getPosition().x < -30) {
					ee[i].desactivar();
				}
			}
			
			
			
			
			
			for (size_t i = 0; i < bon.size(); ++i) {
				bon[i].avanzar(deltaTime2, colisionobon[i],vida_text,bonus_life);
				
				if (bon[i].ver_sprite().getPosition().x < -30 ) {
					bon[i].desactivar();
				}
				
			}
			
			///--------------------------------------------------------------------
			
			
			if (sco % 50 == 0 && !bombgen && sco!=0) {
				float bomb_pos_y = (rand() % 2 + 1) * 220; 
				Bomb newBomb(bomba_text, bomb_pos_y,speed);
				bombas.push_back(newBomb);
				bombgen = true;
			} else if (sco % 50 != 0) {
				bombgen = false;
			}
			
			vector<size_t> bombas_a_eliminar;
			for (size_t i = 0; i < bombas.size(); ++i) {
				bombas[i].Avanzar(deltaTime, bombas[i].esta_explotada(), disp_text2);
				
				if (bombas[i].ver_sprite().getPosition().x < -30) {
					bombas_a_eliminar.push_back(i);
				}
			}
			
			for (size_t i = bombas_a_eliminar.size(); i-- > 0;) {
				bombas.erase(bombas.begin() + bombas_a_eliminar[i]);
			}
			
			for (size_t i = 0; i < bombas.size(); ++i) {
				if (colisiona(per.ver_sprite(), bombas[i].ver_sprite()) && !bombas[i].esta_explotada() && bombas[i].activa()) {
					bombas[i].explotar();
					per.recibe_impacto();
					if (!life.empty()) {
						life.pop_back();
						if(!life.empty()){
							life.pop_back();
						}
					}
					if (life.empty()) {
						juego.stop();
						sco=sco*p.size();
						ju.cambiar_escena(new GameOver(sco));
					}
				}
			}
			
			
			
			
			for(size_t i=0;i<de.size();++i){
				de[i].actualizar();
				coli_disparo2.resize(de.size());
			}
			
			bool colision_detectada = false;
			
			for(size_t i = 0; i < de.size(); ++i) {
				if(colisiona(de[i].ver_sprite(), per.ver_sprite()) && !coli_disparo2[i] && !colision_detectada) {
					coli_disparo2[i] = true;
					per.recibe_impacto();
					if(!life.empty()) {
						life.pop_back();
					}
					colision_detectada = true;
					if(life.empty()){
						juego.stop();
						sco=sco*p.size();
						ju.cambiar_escena(new GameOver(sco));
					}
				}
				colision_detectada = false; 
			}
			if(colisionobon2[0]){
				if(life.size()<4){
					Vida vi(vida_text);
					if(life.size()==3){
						float x1=580;
						life.push_back(vi);
						life[3].actualizar(x1);
						//break;
					}
					
					if(life.size()==2){
						float x2=520;
						life.push_back(vi);
						life[2].actualizar(x2);
						
					}
					
					if(life.size()==1){
						life.push_back(vi);
						life[1].actualizar(x);
						//break;
					}
					
				}
			}
			colisionobon2.erase(colisionobon2.begin(),colisionobon2.end());
			
			
		}
		
		void Partida::dibujar(RenderWindow &w) {
			w.clear();
			w.draw(fondo);
			
			for (size_t i = 0; i < ee.size(); ++i) {
				if (ee[i].estaActivo()) {
					ee[i].dibujar(w);
				}
			}
			for (size_t i = 0; i < bon.size(); ++i) {
				if (bon[i].esta_activo()) {
					bon[i].dibujar(w);
				}
			}
			
			sta.dibujar(w);
			
			for(size_t i=0;i<p.size();++i){
				p[i].dibujar(w);
			}
			for(size_t i=0;i<life.size();++i){
				life[i].dibujar(w);
			}
			//bon[0].dibujar(w);
			per.dibujar(w);
			
			for(size_t i=0;i<v.size();++i){
				//if(!coli_disparo[i]){
				v[i].dibujar(w);
				//}
				
			}
			
			for(size_t i=0;i<de.size();++i){
				if(!coli_disparo2[i]){
					de[i].dibujar(w);
				}
			}
			
			
			for (size_t i = 0; i < bonus_life.size(); ++i) {
				
				bonus_life[i].dibujar(w);
			
				if (bonus_life[i].debe_eliminarse()) {
					
					bonus_life.erase(bonus_life.begin() + i);
					
					--i;
				}
			}
			
			for (size_t i = 0; i < bombas.size(); ++i) {
				bombas[i].dibujar(w);
			}
			
			if (m_spawn.getElapsedTime().asSeconds() > (8-cont3)) {
				borrar_memoria(ee, colisiono);
				//bonus_life.erase(bonus_life.begin(),bonus_life.end());
				borrar_memoria(de, coli_disparo2);
				spawn(ee, ene_text,speed);
				cont3+=0.2;
				m_spawn.restart();
			}
			if (m_bonus.getElapsedTime().asSeconds() > 30 ) {
				
				//bon[0].revivir();
				borrar_memoria(bon, colisionobon);
				
				spawn_bon(bon, bonus_text);
				//bon[0].revivir();
				m_bonus.restart();
				
				
				
				
			}
			
			
			
			w.draw(score);
		}
		void Partida::manejarEventos(const sf::Event& event) {
			
		}
		
