#include <cassert>
#include <memory>
#include "AssetManager.hpp"
#include "Enemy.hpp"

extern std::unique_ptr<AssetManager> ASSETMGR;

Enemy::Enemy(int id_, bool is_boss_) : id(id_), is_boss(is_boss_) {
	if (is_boss_) {
		switch (id_) {
		case 0:
			name = "Very Evil Boss";
			// texture = ASSETMGR->boss_texture_0;
			enemy_type = { 0, 1 };
			break;
		default:
			assert(false && "Reason: Unhandled enemy type");
		}
	} else {
		switch (id_) {
		case 0:
			name = "Harambe";
			// texture = ASSETMGR->enemy_texture_0;
			enemy_type = { 0 };
			break;
		case 1:
			name = "Doge";
			// texture = ASSETMGR->enemy_texture_1;
			enemy_type = { 1 };
			break;
		case 2:
			name = "Nicolas Cage";
			// texture = ASSETMGR->enemy_texture_2;
			enemy_type = { 2 };
			break;
		default:
			assert(false && "Reason: Unhandled enemy type");
		}
	}

	my_sprite.setSize(sf::Vector2f(5.0f, 100.0f));
	my_sprite.setFillColor(sf::Color(200, 50, 50));

	is_active = true;
}

sf::Texture Enemy::getTexture() {
	return texture;
}

std::vector<int> Enemy::getEnemyType() {
	return enemy_type;
}

void Enemy::update() {

}

void Enemy::draw(std::shared_ptr<sf::RenderWindow> window) {
	if (is_active) {
		my_sprite.setPosition(pos);
		window->draw(my_sprite);
	}
}

void Enemy::reset() {
	is_active = true;
}

bool Enemy::isBoss() {
	return is_boss;
}

bool Enemy::isActive() {
	return is_active;
}

void Enemy::setActive(bool is_active) {
	this->is_active = is_active;
}