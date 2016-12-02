#include <memory>
#include "Weapon.hpp"
#include "AssetManager.hpp"

#include <cassert>

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

float Weapon::calculateWinningChance(std::vector<int> enemy_type) {
    float winning_chance = 0.0f;
    
    float none = 0.0f;
    float low = 0.25f;
    float middle = 0.5f;
    float high = 0.75f;
    float definite = 1.0f;

    switch (id) {
    case 0:  // Bow
        for (int i = 0; i < enemy_type.size(); i++) {
            switch (enemy_type[i]) {
            case 0:
                winning_chance += middle;
                break;
            case 1:
                winning_chance += high;
                break;
            case 2:
                winning_chance += middle;
                break;
            default:
                assert(false && "Reason: Unhandled enemy type");
            }
        }
        winning_chance /= (float) enemy_type.size();
        break;
    case 1:  // Musket
        for (int i = 0; i < enemy_type.size(); i++) {
            switch (enemy_type[i]) {
            case 0:
                winning_chance += definite;
                break;
            case 1:
                winning_chance += high;
                break;
            case 2:
                winning_chance += middle;
                break;
            default:
                assert(false && "Reason: Unhandled enemy type");
            }
        }
        winning_chance /= (float) enemy_type.size();
        break;
    case 2:  // Sword
        for (int i = 0; i < enemy_type.size(); i++) {
            switch (enemy_type[i]) {
            case 0:
                winning_chance += none;
                break;
            case 1:
                winning_chance += high;
                break;
            case 2:
                winning_chance += middle;
                break;
            default:
                assert(false && "Reason: Unhandled enemy type");
            }
        }
        winning_chance /= (float) enemy_type.size();
        break;
    default:
        assert(false && "Reason: Unhandled weapon type");
    }
    return winning_chance;
}
