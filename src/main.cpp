#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "MainMenu.hpp"
#include "OptionMenu.hpp"

int main(int argc, char* argv[]) {
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
		case ViewMode::LOAD_SAVE:
		{
			// current_mode = Load window -> view loop();
			// Save data object . set(load window -> get data)
		}
		default:
			// Default to exit the application.
			current_mode = ViewMode::EXIT;
		}
	}

	std::cout << "Exiting..." << std::endl;
	return EXIT_SUCCESS;
}