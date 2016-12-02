#include "Player.hpp"

Player::Player()
{
	pos = sf::Vector2f(100.0f, 100.0f);
	speed = 50.0f;

	mySprite.setRadius(50.0f);
	mySprite.setFillColor(sf::Color(100, 250, 50));
}

Player::~Player()
{
}

void Player::update()
{
	pos.x += speed;
}

void Player::draw(std::shared_ptr<sf::RenderWindow> window)
{
	mySprite.setPosition(pos);
	window->draw(mySprite);
}

void Player::reset()
{
	pos = sf::Vector2f(100.0f, 100.0f);
}