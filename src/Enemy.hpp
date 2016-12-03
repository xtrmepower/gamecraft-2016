#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include "GameObject.hpp"

class Enemy : public IAnimatedGameObject<sf::RectangleShape> {
public:
	Enemy(int id, sf::Vector2f pos, bool is_boss = false);

	void update() override {}
	void draw(std::shared_ptr<sf::RenderWindow> window) override;
	void reset() override { is_active = true; }
	bool isBoss() { return is_boss; }
	bool isActive() { return is_active; }
	void setActive(bool is_active_) { is_active = is_active_; }
	std::vector<int> getEnemyType() { return enemy_type; }

	void setTexture(const sf::Texture *t) { my_sprite.setTexture(t); }
	const sf::Texture* getTexture() { return my_sprite.getTexture(); }

private:
	int id;

	// An enemy can be several types at the same time.
	std::vector<int> enemy_type;
	bool is_boss;
	bool is_active;
};

#endif // ENEMY_HPP