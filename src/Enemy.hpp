#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include "GameObject.hpp"

class Enemy : public IAnimatedGameObject<sf::RectangleShape> {
public:
	Enemy(int id, sf::Vector2f pos, bool is_boss = false);
	sf::Texture getTexture();
	std::vector<int> getEnemyType();

	void update() override;
	void draw(std::shared_ptr<sf::RenderWindow> window) override;
	void reset() override;
	bool isBoss();
	bool isActive();
	void setActive(bool is_active);

private:
	int id;
	sf::Texture texture;

	// An enemy can be several types at the same time.
	std::vector<int> enemy_type;
	bool is_boss;
	bool is_active;
};

#endif // ENEMY_HPP