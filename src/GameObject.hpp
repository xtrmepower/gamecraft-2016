#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <memory>
#include <SFML/Graphics.hpp>

// T should be a type that inherits
// sf::Drawable && sf::Transformable
// (Any shape, Sprite, Text)
template <typename T>
class IGameObject {
public:
	virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;

	sf::Vector2f getPos() const { return pos; }
	sf::Vector2f getSize() const { return size; }
	void setSize(sf::Vector2f new_size) { size = new_size; }

	virtual T get_drawable() { return my_sprite; };

	void setName(const std::string &name_) { name = name_; }
	std::string getName() { return name; }

protected:
	std::string name;
	sf::Vector2f pos;
	sf::Vector2f size;
	T my_sprite;
};

template <typename T>
class IAnimatedGameObject : public IGameObject<T> {
public:
	virtual void reset() = 0;
	virtual void update() = 0;
	const sf::Vector2f getOriginalPos() { return original_pos; }
	void setPos(sf::Vector2f newPos) { pos = newPos; original_pos = newPos; }
protected:
	sf::Vector2f original_pos;
};

#endif