#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>
#include "GameObject.hpp"

class Player : public IAnimatedGameObject<sf::CircleShape> {
public:
	Player();
	~Player();

	void update() override;
	void draw(std::shared_ptr<sf::RenderWindow> window) override;

	void startTimeDilation();
	void endTimeDilation();

	void reset();
    float getStamina();

private:
	float speed;
	float time_scale;

	bool isTimeDilated;
    float stamina;
};

#endif