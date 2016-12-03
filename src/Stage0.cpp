#include "Stage0.hpp"

Stage0::Stage0(std::shared_ptr<sf::RenderWindow> window_) {
	window = window_;

	old_view_center.x = window_->getView().getCenter().x;
	old_view_center.y = window_->getView().getCenter().y;

	onEnter();

	std::cout << "e" << enemy_list.size() << std::endl;
}

void Stage0::draw() {
	my_view.setCenter(p.getPos());
	window->setView(my_view);
	p.draw(window);

	for (auto e : enemy_list) {
		e->draw(window);
	}
}

void Stage0::update() {
	p.update();

	enemyUpdate();
}

void Stage0::reset() {
	deinitEnemyList();
	my_view.setCenter(old_view_center);
	window->setView(my_view);
	p.reset();
}

void Stage0::initEnemyList() {
	Enemy* temp;
	temp = new Enemy(0);
	temp->setPos(sf::Vector2f(100.0f, 0.0f));
	enemy_list.push_back(temp);

	temp = new Enemy(1);
	temp->setPos(sf::Vector2f(150.0f, 0.0f));
	enemy_list.push_back(temp);

	temp = new Enemy(2);
	temp->setPos(sf::Vector2f(200.0f, 0.0f));
	enemy_list.push_back(temp);
}

void Stage0::deinitEnemyList() {
	auto e = std::begin(enemy_list);

	while (e != std::end(enemy_list))
		e = enemy_list.erase(e);
}

void Stage0::onEnter() {
	float size_x = window->getSize().x;
	float size_y = window->getSize().y;
	my_view.setCenter(size_x*0.5f, size_y*0.5f);
	my_view.setSize(size_x, size_y);

	window->setView(my_view);

	initEnemyList();
}

void Stage0::onExit() {
	reset();

	deinitEnemyList();
}

void Stage0::enemyUpdate() {
	// check if player is near the next enemy

	// if yes, enter combat

		// if player has moved past enemy

		// remove enemy

	const float combat_range = 100.0f;
	bool toEnterCombat = false;
	for (auto e : enemy_list) {
		std::cout << "dist=" << calcDistance(e->getPos(), p.getPos()) << std::endl;
		/*if (p.getPos().x > e->getPos().x) {
			// remove enemy
			break;
		} else */if (calcDistance(e->getPos(), p.getPos()) < combat_range) {
			toEnterCombat = true;
			std::cout << "hello\n";
		}
	}

	toEnterCombat ? enterCombat() : endCombat();
}

void Stage0::enterCombat() {
	p.startTimeDilation();
}

void Stage0::endCombat() {
	p.endTimeDilation();
}