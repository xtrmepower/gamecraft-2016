#include "Player.hpp"

const float NORMAL_TIME_SCALE = 1.0f;
const float DILATED_TIME_SCALE = 0.2f;

Player::Player()
{
	//pos = sf::Vector2f(100.0f, 100.0f);
	speed = 5.0f;
	time_scale = 1.0f;
	isTimeDilated = false;

	my_sprite.setRadius(50.0f);
	my_sprite.setFillColor(sf::Color(100, 250, 50));
}

Player::~Player()
{
}

void Player::update()
{
	isTimeDilated ? time_scale = DILATED_TIME_SCALE : time_scale = NORMAL_TIME_SCALE;

	pos.x += speed * time_scale;
}

void Player::draw(std::shared_ptr<sf::RenderWindow> window)
{
	my_sprite.setPosition(pos);
	window->draw(my_sprite);
}

void Player::reset()
{
	pos = original_pos;
}

void Player::startTimeDilation()
{
	isTimeDilated = true;
}

void Player::endTimeDilation()
{
	isTimeDilated = false;
}