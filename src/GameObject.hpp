#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <memory>

class GameObject {
public:
	virtual void update() = 0;
	virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;
	virtual void reset() = 0;

protected:
	sf::Vector2f pos;
};

#endif