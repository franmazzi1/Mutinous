#include "Stack.h"
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

Stack::Stack() {
	st_text.loadFromFile("img/vida_a (1).png");
	stack.setTexture(st_text);
	stack.setScale(0.8,0.8);
	stack.setPosition(85,480);
}

void Stack::dibujar(RenderWindow &w){
	w.draw(stack);
}
