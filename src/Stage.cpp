#include "Stage.hpp"

Stage::Stage(std::shared_ptr<sf::RenderWindow> window, int stage_num) {
	this->window = window;
	this->stage_num = stage_num;

	onEnter();
}

void Stage::onEnter() {
	old_view_center.x = window->getView().getCenter().x;
	old_view_center.y = window->getView().getCenter().y;

	float size_x = window->getSize().x;
	float size_y = window->getSize().y;
	my_view.setCenter(size_x*0.5f, size_y*0.5f);
	my_view.setSize(size_x, size_y);

	window->setView(my_view);
}

void Stage::onExit() {
	my_view.setCenter(old_view_center);
	window->setView(my_view);
	p.reset();
}

void Stage::draw() {
	my_view.setCenter(p.getPos());
	window->setView(my_view);
	p.draw(window);

	for (auto e : enemy_list) {
		e.draw(window);
	}
}

void Stage::update() {
	p.update();

	combatCheck();
}

void Stage::reset() {
	my_view.setCenter(old_view_center);
	window->setView(my_view);
	p.reset();
}

void Stage::loadEnemyList(std::vector<Enemy> e_list) {
	enemy_list = e_list;
}

void Stage::addEnemy(int type, sf::Vector2f pos) {
	/*Enemy* temp = new Enemy(type);
	temp->setPos(pos);
	enemy_list.push_back(temp);*/
}

void Stage::setPlayerStartPos(sf::Vector2f pos) {
	p.setPos(pos);
}

void Stage::enterCombat() {
	p.startTimeDilation();
}

void Stage::endCombat() {
	p.endTimeDilation();
}

void Stage::combatCheck() {
	const float combat_range = 100.0f;
	bool toEnterCombat = false;
	for (auto e : enemy_list) {
		sf::Vector2f e_pos = e.getPos();
		e_pos.x += e.getSize().x * 0.5f;
		e_pos.y += e.getSize().y * 0.5f;

		sf::Vector2f p_pos = p.getPos();
		p_pos.x += p.getSize().x * 0.5f;
		p_pos.y += p.getSize().y * 0.5f;

		if (e.isActive() && p_pos.x > e_pos.x) {
			e.setActive(false);
		} else if (e.isActive() && calcDistance(e_pos, p_pos) < combat_range + p.getSize().x * 0.5f) {
			toEnterCombat = true;
		}
	}

	toEnterCombat ? enterCombat() : endCombat();
}