#include <memory>
#include "Weapon.hpp"
#include "AssetManager.hpp"

extern std::unique_ptr<AssetManager> ASSETMGR;

Weapon::Weapon(int id) {
    id = id;
    switch (id) {
    case 0:
        name = "Bow";
        texture = ASSETMGR->weapon_texture_0;
        range = 100.0f;
        damage = 100.0f;
        break;
    case 1:
        name = "Musket";
        texture = ASSETMGR->weapon_texture_1;
        range = 50.0f;
        damage = 200.0f;
        break;
    case 2:
        name = "Swrod";
        texture = ASSETMGR->weapon_texture_2;
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
    float winning_chance = 0.0f;
    
    float none = 0.0f;
    float low = 0.25f;
    float middle = 0.5f;
    float high = 0.75f;
    float definite = 1.0f;

    switch (id) {
    case 0:  // Bow
        switch (enemy_type) {
        case 0: // Harambe
            winning_chance = middle;
            break;
        case 1: // Doge
            winning_chance = high;
            break;
        case 2: // Nicolas Cage
            winning_chance = middle;
            break;
        }
    case 1:  // Musket
        switch (enemy_type) {
        case 0: // Harambe
            winning_chance = definite;
            break;
        case 1: // Doge
            winning_chance = high;
            break;
        case 2: // Nicolas Cage
            winning_chance = middle;
            break;
        }
    case 2:  // Sword
        switch (enemy_type) {
        case 0: // Harambe
            winning_chance = none;
            break;
        case 1: // Doge
            winning_chance = high;
            break;
        case 2: // Nicolas Cage
            winning_chance = middle;
            break;
        }
    }
    return winning_chance;
}

