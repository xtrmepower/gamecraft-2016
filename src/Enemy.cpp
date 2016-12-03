#include <cassert>
#include <memory>
#include "AssetManager.hpp"
#include "Enemy.hpp"

extern std::unique_ptr<AssetManager> ASSETMGR;

Enemy::Enemy(int id_, sf::Vector2f pos, bool is_boss_) : id(id_), is_boss(is_boss_) {
	if (is_boss_) {
		switch (id_) {
		case 0:
			name = "Very Evil Boss";
			setTexture(&ASSETMGR->boss_texture_0);
			enemy_type = { 0, 1 };
			break;
		default:
			assert(false && "Reason: Unhandled enemy type");
		}
	} else {
		switch (id_) {
		case 0:
			name = "Harambe";
            setTexture(&ASSETMGR->enemy_texture_0);
			enemy_type = { 0 };
			break;
		case 1:
			name = "Doge";
            setTexture(&ASSETMGR->enemy_texture_1);
			enemy_type = { 1 };
			break;
		case 2:
			name = "Nicolas Cage";
            setTexture(&ASSETMGR->enemy_texture_2);
			enemy_type = { 2 };
			break;
		default:
			assert(false && "Reason: Unhandled enemy type");
		}
	}

	my_sprite.setSize(sf::Vector2f(50.0f, 50.0f));
	my_sprite.setFillColor(sf::Color(200, 50, 50));

	is_active = true;

	this->setPos(pos);
}

void Enemy::draw(std::shared_ptr<sf::RenderWindow> window) {
	if (is_active) {
		my_sprite.setPosition(pos);
		window->draw(my_sprite);
	}
}