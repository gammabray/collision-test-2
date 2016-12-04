
#include <SFML\Graphics.hpp>
#include "testobject.hpp"
#include <iostream>
int main() {
	sf::RenderWindow rw(sf::VideoMode(1280,720),"title");
	testobject t(sf::Vector2f(40,40),sf::Vector2f(300,200));
	testobject t2(sf::Vector2f(40,40), sf::Vector2f(600, 200));
	rw.setFramerateLimit(60);
	sf::Clock c;
	c.restart();
	float delta;
	while (rw.isOpen()) {
		sf::Event event;
		while (rw.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rw.close();

			}

		}
		
		delta = c.restart().asMilliseconds();
		
		rw.clear();
		t.move(delta,t2);
		rw.draw(t.sprite);
		rw.draw(t2.sprite);
		
		rw.display();
	}
	return 0;
}