#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include "Enemy.hpp"
#include "Weapon.hpp"

class LevelData {
public:
	LevelData() {}

	void addEnemy(Enemy &e) { enemy_list.push_back(e); }
	void addWeapon(Weapon &w) { weapon_list.push_back(w); }

	const std::vector<Enemy> getEnemyList() { return enemy_list; }
	const std::vector<Weapon> getWeaponList() { return weapon_list; }

private:
	std::vector<Enemy> enemy_list;
	std::vector<Weapon> weapon_list;
};


class GameData {
public:
	GameData() {
		selected_level = 0;
		available_levels = 1;
		for (int i = 0; i < total_levels; i++) {
			scores[i] = 0;
			level_data.emplace_back();
		}

		addLevels();
	}

	// Sets the score for the currently selected level.
	void setScore(int score) {
		scores[selected_level] = score;
	}

	// Gets the currently accumulated score.
	const int getTotalScore() {
		int ret = 0;
		for (int i = 0; i < total_levels; i++)
			ret += scores[i];
	}

	// Returns the enemy list of the currently selected level.
	const std::vector<Enemy> getEnemyList() {
		return level_data[selected_level].getEnemyList();
	}

	// Returns the weapon list of the currently selected level.
	const std::vector<Weapon> getWeaponList() {
		return level_data[selected_level].getWeaponList();
	}

	void setHeldWeapons(const std::vector<Weapon> &wlist) {
		currently_held_weapons = wlist;
	}

	const std::vector<Weapon> getHeldWeapons() {
		return currently_held_weapons;
	}

	void clearHeldWeapons() {
		currently_held_weapons.clear();
	}

	int selected_level;
	int available_levels;

	constexpr static int total_levels = 4 * 5;

private:
	/*
	Add ALL level data here. How many enemies, what type,
	how many weapons, what type, et cetera.
	*/
	void addLevels() {
		// LEVEL 0
		for (int i = 0; i < 5; i++)
			level_data[0].addEnemy(Enemy(0));
		level_data[0].addEnemy(Enemy(0, true));

		level_data[0].addWeapon(Weapon(0));
		level_data[0].addWeapon(Weapon(1));
		level_data[0].addWeapon(Weapon(2));

		// LEVEL 1
		// ...

		// LEVEL 2
		// ...
	}

	int scores[total_levels];
	std::vector<LevelData> level_data;
	std::vector<Weapon> currently_held_weapons;
};

#endif // GAMEDATA_HPP