#include <memory>
#include "Enemy.hpp"
#include "AssetManager.hpp"

#include <cassert>

extern std::unique_ptr<AssetManager> ASSETMGR;

Enemy::Enemy(int id, bool is_boss) {
    id = id;
    if (is_boss) {
        switch (id) {
        case 0:
            name = "Very Evil Boss";
            texture = ASSETMGR->boss_texture_0;
            enemy_type = { 0, 1 };
            break;
        default:
            assert(false && "Reason: Unhandled enemy type");
        }
    } else {
        switch (id) {
        case 0:
            name = "Harambe";
            texture = ASSETMGR->enemy_texture_0;
            enemy_type = { 0 };
            break;
        case 1:
            name = "Doge";
            texture = ASSETMGR->enemy_texture_1;
            enemy_type = { 1 };
            break;
        case 2:
            name = "Nicolas Cage";
            texture = ASSETMGR->enemy_texture_2;
            enemy_type = { 2 };
            break;
        default:
            assert(false && "Reason: Unhandled enemy type");
        }
    }

	my_sprite.setSize(sf::Vector2f(5.0f, 100.0f));
	my_sprite.setFillColor(sf::Color(200, 50, 50));
}

std::string Enemy::getName() {
	return name;
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
	my_sprite.setPosition(pos);
	window->draw(my_sprite);
}

void Enemy::reset() {

}

bool Enemy::isBoss() {
    return is_boss;
}
