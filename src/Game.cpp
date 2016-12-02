#include "Game.hpp"

Game::Game(std::shared_ptr<sf::RenderWindow> window_)
	: View(window_), stage0(window_)
{
}

const ViewMode Game::view_loop() {
	View::standardStateLoop();
	stage0.reset();
	return ViewMode::MAIN_MENU;
}

void Game::draw() {
	window->clear();
	// Draw here
	stage0.draw();
	window->display();
}

void Game::update() {
	stage0.update();
}

void Game::processKeypress(const sf::Keyboard::Key & key) {
	switch (key) {
	case sf::Keyboard::Escape: exit_state = true; break;
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