#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <memory>

class GameObject {
public:
	virtual void update() = 0;
	virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;
	virtual void reset() = 0;

	sf::Vector2f getPos() const { return pos; }
	void setPos(sf::Vector2f newPos) { pos = newPos; }

protected:
	sf::Vector2f pos;
};

#endif