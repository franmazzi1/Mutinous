#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Juego.h"
#include "Escena.h"
#include "menu.h"
#include <iostream>
using namespace std;
using namespace sf;


	int main(int argc, char *argv[]){
		
		Juego game(new Menu);
		game.jugar();
		
		return 0;
	}

