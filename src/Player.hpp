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

private:
	float speed;
	sf::CircleShape mySprite;
};

#endif