#include "Game.hpp"

const ViewMode Game::view_loop() {
	View::standardStateLoop();
	return ViewMode::MAIN_MENU;
}

void Game::draw() {
	window->clear();
	// Draw here
	window->display();
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