#include "Game.hpp"

Game::Game(std::shared_ptr<sf::RenderWindow> window_)
	: View(window_)
{
	stage_list.push_back(Stage(window_, 0));
	stage_list[0].addEnemy(0, sf::Vector2f(1000.0f, 0.0f));
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