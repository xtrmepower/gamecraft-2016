#include <memory>
#include "Weapon.hpp"
#include "AssetManager.hpp"

#include <cmath>
#include <cassert>

extern std::unique_ptr<AssetManager> ASSETMGR;

Weapon::Weapon(int id) {
	id = id;

	float none = 0.0f;
	float low = 0.25f;
	float middle = 0.5f;
	float high = 0.75f;
	float definite = 1.0f;

	switch (id) {
	case 0:
		name = "Bow";
		texture = ASSETMGR->weapon_texture_0;
		range = 100.0f;
		damage = 100.0f;
		weapon_scale = 10.0f;
		stamina_scale = 10.0f;

		damage_modifiers[0] = middle;
		damage_modifiers[1] = high;
		damage_modifiers[2] = middle;

		break;
	case 1:
		name = "Musket";
		texture = ASSETMGR->weapon_texture_1;
		range = 50.0f;
		damage = 200.0f;
		weapon_scale = 100.0f;
		stamina_scale = 1.0f;

		damage_modifiers[0] = definite;
		damage_modifiers[1] = high;
		damage_modifiers[2] = middle;

		break;
	case 2:
		name = "Swrod";
		texture = ASSETMGR->weapon_texture_2;
		range = 0.0f;
		damage = 100.0f;
		weapon_scale = 1.0f;
		stamina_scale = 100.0f;

		damage_modifiers[0] = none;
		damage_modifiers[1] = high;
		damage_modifiers[2] = middle;

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

float Weapon::calculateBossDamage(std::vector<int> enemy_type, float distance) {
	if (distance > range) {
		return 0.0f;
	} else if (distance < 0) {
		distance = 0.0f;
	}
	float boss_damage_modifier = 0.0f;

	for (int i = 0; i < enemy_type.size(); i++) {
		if (damage_modifiers.count(i) == 0) {
			assert(false && "Reason: Unhandled enemy type");
		} else {
			boss_damage_modifier += damage_modifiers[i];
		}
	}
	boss_damage_modifier /= (float)enemy_type.size();
	boss_damage_modifier *= 2.0f;

	// scale^x, x in range(0, 1), y in range(0, scale)
	float distance_modifier = pow(weapon_scale, 1.0f - distance / range);

	return damage * boss_damage_modifier * distance_modifier;
}

float Weapon::calculateWinningChance(std::vector<int> enemy_type) {
	float winning_chance = 0.0f;

	for (int i = 0; i < enemy_type.size(); i++) {
		if (damage_modifiers.count(i) == 0) {
			assert(false && "Reason: Unhandled enemy type");
		} else {
			winning_chance += damage_modifiers[i];
		}
	}
	winning_chance /= (float)enemy_type.size();

	return winning_chance;
}