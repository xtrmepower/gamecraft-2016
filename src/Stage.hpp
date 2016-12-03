#ifndef STAGE_HPP
#define STAGE_HPP

#include "Player.hpp"
#include "Enemy.hpp"
#include "util.hpp"

class Stage {
public:
	Stage(std::shared_ptr<sf::RenderWindow> window, int stage_num);

	virtual void onEnter();
	virtual void onExit();

	virtual void draw();
	virtual void update();
	virtual void reset();

	void loadEnemyList(std::vector<Enemy> e_list);
	void addEnemy(int type, sf::Vector2f pos);
	void setPlayerStartPos(sf::Vector2f pos);

    int getSelectedWeapon();
    void setSelectedWeapon(int index);
    bool isBattlePhase();
    Enemy getEngagedEnemy();
    bool weaponSelected();
    void confirmSelectedWeapon();

	int stage_num;
    bool toEnterCombat;

protected:
	Player p;

	sf::View my_view;
	sf::Vector2f old_view_center;
	std::shared_ptr<sf::RenderWindow> window;

	std::vector<Enemy> enemy_list;

	virtual void enterCombat(Enemy e);
	virtual void endCombat();
	virtual void combatCheck();

	sf::Sprite ground_sprite;

	sf::Sprite bg_sprite_0;
	sf::Sprite bg_sprite_1;
	sf::Sprite bg_sprite_2;

    int selected_weapon;
    Enemy engaged_enemy;
    bool weapon_selected;
    bool has_engaged_enemy;

private:
	Stage() {}
};

#endif