#pragma once
#include "../../mario cplus school/mario cplus/AABB.hpp"
class testobject
{
private:
	
	sf::Texture t;
	sf::Vector2f size;
	sf::Vector2f position;
	Game::AABB collisionBox;
public:
	void move(float delta,testobject& t2);
	sf::Sprite sprite;
	bool IsColliding(testobject& other);
	testobject(sf::Vector2f size, sf::Vector2f position);
	
};

