#ifndef UTIL_HPP
#define UTIL_HPP

#include <SFML/System.hpp>

// Element-wise multiplication
template <typename T>
sf::Vector2<T> operator*(const sf::Vector2<T> &l, const sf::Vector2<T> &r) {
	return sf::Vector2<T>(l.x * r.x, l.y * r.y);
}

#endif