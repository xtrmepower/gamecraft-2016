#ifndef STAGE0_HPP
#define STAGE0_HPP

#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream> 

class Stage0 {
public:
	Stage0(std::shared_ptr<sf::RenderWindow> window_);

	void draw();
	void update();

	void reset();

	void onEnter();
	void onExit();

private:
	Player p;

	sf::View my_view;
	sf::Vector2f old_view_center;
	std::shared_ptr<sf::RenderWindow> window;

	std::vector<Enemy*> enemy_list;

	void enemyUpdate();
	void enterCombat();
	void endCombat();

	void initEnemyList();
	void deinitEnemyList();

	float calcDistance(sf::Vector2f pos1, sf::Vector2f pos2);
};

#endif