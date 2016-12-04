#include "testobject.hpp"
#include <iostream>



void testobject::move(float delta,testobject& t2)
{
	sf::Vector2f oldPos = sprite.getPosition(),newPos = oldPos;

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		newPos += sf::Vector2f(delta * 0.1f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		newPos += sf::Vector2f(0, delta * -0.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		newPos += sf::Vector2f(0 ,delta * 0.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		newPos += sf::Vector2f(delta * -0.1f, 0);
	}
	this->collisionBox.setPosition(newPos);
	if (IsColliding(t2)) {
		std::cout << "collision" << std::endl;
		if (this->collisionBox.getMinVector().x != 0) {
			std::cout << (this->collisionBox.getMinVector().x < 0 ? "left" : "right") << std::endl;
		}
		if (this->collisionBox.getMinVector().y != 0) {
			std::cout << (this->collisionBox.getMinVector().y < 0 ? "up" : "down") << std::endl;
		}
		
		
		sprite.setPosition(oldPos);
	}
	else {
		sprite.setPosition(newPos);
	}
	
	this->position = sprite.getPosition();
	this->collisionBox.setPosition(this->position);
	
}
std::ostream& operator<<(std::ostream& o, sf::Vector2f v) {
	o << "(" << v.x << "," << v.y << ")";
	return o;
}

bool testobject::IsColliding(testobject& other)
{							  
	if (this->collisionBox.IsColliding(other.collisionBox)) {
		std::cout << this->collisionBox.getMinVector();
	}
	return this->collisionBox.IsColliding(other.collisionBox);
}

testobject::testobject(sf::Vector2f size, sf::Vector2f position) : collisionBox(size,position)
{
	
	if (!t.loadFromFile("box.png")) {
		std::cout << "couldn't" << std::endl;
	};
	;
	sprite.setTexture(t);
	sprite.setPosition(position);
}

