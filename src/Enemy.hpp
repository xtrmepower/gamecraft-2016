#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

class Enemy : public GameObject {
public:
	Enemy(int id);
	std::string getName();
	sf::Texture getTexture();
	std::vector<int> getEnemyType();

	void update();
	void draw(std::shared_ptr<sf::RenderWindow> window);
	void reset();

private:
	int id;
	std::string name;
	sf::Texture texture;
	std::vector<int> enemy_type;

	// placeholder first
	sf::RectangleShape my_sprite;
};

#endif // ENEMY_HPP