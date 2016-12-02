#include "Player.hpp"
#include <iostream>

Player::Player()
{
	pos = sf::Vector2f(0.0f, 0.0f);
	speed = 5.0f;
	time_scale = 1.0f;

	my_sprite.setRadius(50.0f);
	my_sprite.setFillColor(sf::Color(100, 250, 50));

    stamina = 100.0f;
}

Player::~Player()
{
}

void Player::update()
{
	pos.x += speed * time_scale;
}

void Player::draw(std::shared_ptr<sf::RenderWindow> window)
{
	my_sprite.setPosition(pos);
	window->draw(my_sprite);
}

void Player::reset()
{
	pos = sf::Vector2f(0.0f, 0.0f);
}

float Player::getStamina() {
    return stamina;
}