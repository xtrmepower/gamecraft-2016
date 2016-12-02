#include "SetupScreen.hpp"

SetupScreen::SetupScreen(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {

}

const ViewMode SetupScreen::view_loop() {
	View::standardStateLoop();
	return ViewMode::IN_GAME;
}

void SetupScreen::draw() {}

void SetupScreen::update() {}

void SetupScreen::processKeypress(const sf::Keyboard::Key & key) {}
