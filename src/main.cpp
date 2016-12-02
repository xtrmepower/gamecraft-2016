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
    std::cout << "Weapon: " << weapon.getName() << std::endl;

    float chance;
    int win_count;

    Enemy enemy_1(0);
    chance = weapon.calculateWinningChance(enemy_1.getEnemyType());
    std::cout << "Enemy: " << enemy_1.getName() << std::endl;
    std::cout << "Chance: " << chance << std::endl;
    win_count = 0;
    for (int i = 0; i < 20; i++) {
        if (getChanceOutcome(chance)) {
            std::cout << "W";
            win_count++;
        } else {
            std::cout << "L";
        }
    }
    std::cout << std::endl;
    std::cout << "Win: " << win_count << " / 20" << std::endl;

    Enemy enemy_2(1);
    chance = weapon.calculateWinningChance(enemy_2.getEnemyType());
    std::cout << "Enemy: " << enemy_2.getName() << std::endl;
    std::cout << "Chance: " << chance << std::endl;
    win_count = 0;
    for (int i = 0; i < 20; i++) {
        if (getChanceOutcome(chance)) {
            std::cout << "W";
            win_count++;
        } else {
            std::cout << "L";
        }
    }
    std::cout << std::endl;
    std::cout << "Win: " << win_count << " / 20" << std::endl;

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
	ASSETMGR = std::make_unique<AssetManager>();
	GAMEDATA = std::make_unique<GameData>();

    bool cmd_mode = true;
    if (cmd_mode) {
        test_ground();
    }

	int width = 1280, height = 720;
	auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "GAME");
	ViewMode current_mode = ViewMode::MAIN_MENU;
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