#include <SFML/Graphics.hpp>

#include "AssetManager.hpp"
#include "Game.hpp"
#include "GameData.hpp"
#include "MainMenu.hpp"
#include "MissionSelect.hpp"
#include "OptionMenu.hpp"
#include "ScoreScreen.hpp"
#include "SetupScreen.hpp"

#include "util.hpp"
#include <cassert>

std::unique_ptr<AssetManager> ASSETMGR;
std::unique_ptr<GameData> GAMEDATA;

void test_ground() {
    Weapon weapon(1);
    Enemy enemy(0);

    float chance = weapon.calculateWinningChance(enemy.getEnemyType());
    std::cout << "Weapon: " << weapon.getName() << std::endl;
    std::cout << "Enemy: " << enemy.getName() << std::endl;
    std::cout << "Chance: " << chance << std::endl;
    for (int i = 0; i < 10; i++) {
        if (getChanceOutcome(chance)) {
            std::cout << "Win" << std::endl;
        } else {
            std::cout << "Loss" << std::endl;
        }
    }

    Enemy boss(0, true);
    std::cout << "Boss: " << boss.getName() << std::endl;

    float distance;
    float damage;

    distance = 50.0f;
    damage = weapon.calculateBossDamage(boss.getEnemyType(), distance);
    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Boss Damage: " << damage << std::endl;

    distance = 25.0f;
    damage = weapon.calculateBossDamage(boss.getEnemyType(), distance);
    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Boss Damage: " << damage << std::endl;

    distance = 10.0f;
    damage = weapon.calculateBossDamage(boss.getEnemyType(), distance);
    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Boss Damage: " << damage << std::endl;

    distance = 0.0f;
    damage = weapon.calculateBossDamage(boss.getEnemyType(), distance);
    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Boss Damage: " << damage << std::endl;
}

int main(int argc, char* argv[]) {
    bool cmd_mode = true;
    if (cmd_mode) {
        test_ground();
    }

	int width = 1280, height = 720;
	auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "GAME");
	ViewMode current_mode = ViewMode::MAIN_MENU;

	ASSETMGR = std::make_unique<AssetManager>();
	GAMEDATA = std::make_unique<GameData>();
	MainMenu main_menu(window);
	OptionMenu option_menu(window);
	Game game(window);
	//game.new_game();
	// Save data object -> new game save state

	// Main game loop
	while (window->isOpen() && current_mode != ViewMode::EXIT) {
		switch (current_mode) {
		case ViewMode::MAIN_MENU:
		{
			current_mode = main_menu.view_loop();
			break;
		}
		case ViewMode::OPTION_MENU:
		{
			current_mode = option_menu.view_loop();
			break;
		}
		case ViewMode::IN_GAME:
		{
			current_mode = game.view_loop();
			break;
		}
		case ViewMode::MISSION_SELECT:
		{
			MissionSelect ms(window);
			current_mode = ms.view_loop();
			break;
		}
		case ViewMode::SETUP:
		{
			SetupScreen sus(window);
			current_mode = sus.view_loop();
			break;
		}
		case ViewMode::SCORE:
		{
			Scores s(window);
			current_mode = s.view_loop();
			break;
		}
		case ViewMode::LOAD_SAVE: // a.k.a. "Continue"
		{
			// current_mode = Load window -> view loop();
			// Save data object . set(load window -> get data)
		}
		default:
			// Default to exit the application.
			current_mode = ViewMode::EXIT;
		}
	}

	return EXIT_SUCCESS;
}