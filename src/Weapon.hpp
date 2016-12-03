#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Weapon : public IGameObject<sf::RectangleShape> {
public:
	Weapon(int id);
	float getRange() { return range; }
	float getDamage() { return damage; }
	float calculateBossDamage(std::vector<int> enemy_type, float distance);
	float calculateWinningChance(std::vector<int> enemy_type);
	void useWeapon() { durability--; }
	bool isUsable() { return durability > 0; }

	void setTexture(const sf::Texture *t) { my_sprite.setTexture(t); }
	const sf::Texture* getTexture() { return my_sprite.getTexture(); }

private:
	int id;
	float range;
	float damage;
	float weapon_scale;
	float stamina_scale;
	std::map<int, float> damage_modifiers;
	int durability;
};

#endif // WEAPON_HPP