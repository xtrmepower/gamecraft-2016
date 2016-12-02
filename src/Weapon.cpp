#include <memory>
#include "Weapon.hpp"
#include "AssetManager.hpp"

extern std::unique_ptr<AssetManager> ASSETMGR;

Weapon::Weapon(int id) {
    switch (id) {
    case 1:
        name = "Box";
        texture = ASSETMGR->weapon_texture_1;
        range = 100.0f;
        damage = 100.0f;
        break;
    case 2:
        name = "Musket";
        texture = ASSETMGR->weapon_texture_2;
        range = 50.0f;
        damage = 200.0f;
        break;
    case 3:
        name = "Swrod";
        texture = ASSETMGR->weapon_texture_3;
        range = 0.0f;
        damage = 100.0f;
        break;
    }
}

std::string Weapon::getName() {
    return name;
}

sf::Texture Weapon::getTexture() {
    return texture;
}

float Weapon::getRange() {
    return range;
}

float Weapon::getDamage() {
    return damage;
}

float Weapon::calculateBossDamage(float distance) {
    return 0.0f;
}

float Weapon::calculateWinningChance(int enemy_type) {
    return 0.0f;
}

