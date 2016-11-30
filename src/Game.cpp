#include "Game.hpp"

const ViewMode Game::view_loop() {
	View::standardStateLoop();
	return ViewMode::MAIN_MENU;
}

void Game::draw() {
	std::cout << "In game state now!" << std::endl;
}

void Game::processKeypress(const sf::Keyboard::Key & key) {
	switch (key) {
	case sf::Keyboard::Escape:
	{
		exit_state = true;
		break;
	}
	default: {}
		// Do nothing
	}
}