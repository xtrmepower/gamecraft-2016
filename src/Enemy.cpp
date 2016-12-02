#include <memory>
#include "Enemy.hpp"
#include "AssetManager.hpp"

extern std::unique_ptr<AssetManager> ASSETMGR;

Enemy::Enemy(int id) {
    id = id;
    switch (id) {
    case 0:
        name = "Harambe";
        texture = ASSETMGR->enemy_texture_0;
        enemy_type = 0;
        break;
    case 1:
        name = "Doge";
        texture = ASSETMGR->enemy_texture_1;
        enemy_type = 1;
        break;
    case 2:
        name = "Nicolas Cage";
        texture = ASSETMGR->enemy_texture_2;
        enemy_type = 2;
        break;
    }
}

std::string Enemy::getName() {
    return name;
}

sf::Texture Enemy::getTexture() {
    return texture;
}

int Enemy::getEnemyType() {
    return enemy_type;
}
