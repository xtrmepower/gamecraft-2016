#ifndef UTIL_HPP
#define UTIL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <random>

// Element-wise multiplication
template <typename T>
sf::Vector2<T> operator*(const sf::Vector2<T> &l, const sf::Vector2<T> &r) {
	return sf::Vector2<T>(l.x * r.x, l.y * r.y);
}

inline sf::RectangleShape create_rect(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::Color& color) {
	sf::RectangleShape shape;
	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setSize(size - pos);
	return shape;
}

inline sf::RectangleShape create_rect(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::Texture *tex = nullptr) {
	sf::RectangleShape shape;
	shape.setFillColor(sf::Color::Transparent);
	shape.setTexture(tex);
	shape.setPosition(pos);
	shape.setSize(size - pos);
	return shape;
}

// 1.0 chance represents 100% chance
inline bool getChanceOutcome(float chance) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    return chance >= dist(mt);
}

inline float calcDistance(sf::Vector2f pos1, sf::Vector2f pos2)
{
	float dx = pos2.x - pos1.x;
	dx *= dx;

	float dy = pos2.y - pos1.y;
	dy *= dy;

	return sqrt(dx + dy);
}

#endif