#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Weapon {
public:
	Weapon(int id);
	std::string getName();
	sf::Texture getTexture();
	float getRange();
	float getDamage();
	float calculateBossDamage(std::vector<int> enemy_type, float distance);
	float calculateWinningChance(std::vector<int> enemy_type);
    void useWeapon();
    bool isUsable();

private:
	int id;
	std::string name;
	sf::Texture texture;
	float range;
	float damage;
	float weapon_scale;
	float stamina_scale;
	std::map<int, float> damage_modifiers;
    int durability;
};

#endif // WEAPON_HPP