#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>
#include "GameObject.hpp"

class Player : public GameObject {
public:
	Player();
	~Player();

	void update();
	void draw(std::shared_ptr<sf::RenderWindow> window);

	void reset();

	sf::Vector2f getPos() const;

private:
	float speed;
	float time_scale;
	sf::CircleShape my_sprite;
};

#endif