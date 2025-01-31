#ifndef STACK_H
#define STACK_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class Stack {
public:
	Stack();
	void dibujar(RenderWindow &w);
private:
	Texture st_text;
	Sprite stack;
};

#endif

