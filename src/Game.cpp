#include "Game.hpp"

extern std::unique_ptr<GameData> GAMEDATA;

Game::Game(std::shared_ptr<sf::RenderWindow> window_)
	: View(window_)
{
	stage_list.push_back(Stage(window_, 0));
	//stage_list[0].addEnemy(0, sf::Vector2f(1000.0f, 0.0f));
	stage_list[0].loadEnemyList(GAMEDATA->getEnemyList());
	stage_list[0].setPlayerStartPos(sf::Vector2f(0.0f, 0.0f));

	selected_stage = 0;
}

const ViewMode Game::view_loop() {
	stage_list[selected_stage].onEnter();
	View::standardStateLoop();
	stage_list[selected_stage].onExit();
	return ViewMode::MAIN_MENU;
}

void Game::draw() {
	window->clear();
	// Draw here
	stage_list[selected_stage].draw();
	window->display();
}

void Game::update() {
	stage_list[selected_stage].update();
}

void Game::processKeypress(const sf::Keyboard::Key & key) {
    int selected_weapon = 0;
    float chance = 0.0f;
    Enemy enemy;
    Weapon weapon;

	switch (key) {
	case sf::Keyboard::Escape: exit_state = true; break;
    case sf::Keyboard::Right:
        selected_weapon = stage_list[selected_stage].getSelectedWeapon() + 1;
        if (selected_weapon > 2) {
            selected_weapon = 0;
        }
        stage_list[selected_stage].setSelectedWeapon(selected_weapon);
        break;
    case sf::Keyboard::Left:
        selected_weapon = stage_list[selected_stage].getSelectedWeapon() - 1;
        if (selected_weapon < 0) {
            selected_weapon = 2;
        }
        stage_list[selected_stage].setSelectedWeapon(selected_weapon);
        break;
    case sf::Keyboard::Space:
        if (!stage_list[selected_stage].isBattlePhase() ||
            stage_list[selected_stage].weaponSelected()) break;
        stage_list[selected_stage].confirmSelectedWeapon();
        std::cout << "Stage " << selected_stage << std::endl;
        std::cout << "Weapon Confirmed? " << stage_list[selected_stage].weaponSelected() << std::endl;

        enemy = stage_list[selected_stage].getEngagedEnemy();
        weapon = Weapon(stage_list[selected_stage].getSelectedWeapon());
        chance = weapon.calculateWinningChance(enemy.getEnemyType());
        std::cout << "Enemy: " << enemy.getName() << std::endl;
        std::cout << "Chance: " << chance << std::endl;
        if (getChanceOutcome(chance)) {
            std::cout << "W" << std::endl;
        } else {
            std::cout << "L" << std::endl;
        }
        break;

	default: break; // Do nothing
	}
}

void Game::processJoystickButton(const int jsid, const int button) {
	switch (button) {
	case 1: exit_state = true; break;
	default: break;
	}
}

void Game::processJoystickMove(const sf::Event::JoystickMoveEvent & e) {
	
}