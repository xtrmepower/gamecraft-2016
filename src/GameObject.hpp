#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <memory>

class GameObject {
public:
	virtual void update() = 0;
	virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;
	virtual void reset() = 0;

	sf::Vector2f getPos() const { return pos; }
    sf::Vector2f getSize() const { return size; }

	void setPos(sf::Vector2f newPos) { pos = newPos; original_pos = newPos; }
    void setSize(sf::Vector2f new_size) { size = new_size;  }

protected:
	sf::Vector2f pos;
	sf::Vector2f original_pos;
    sf::Vector2f size;
};

#endif