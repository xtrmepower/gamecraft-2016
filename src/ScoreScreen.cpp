#include "ScoreScreen.hpp"

Scores::Scores(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {
}

const ViewMode Scores::view_loop() {
	View::standardStateLoop();
	// When you exit the scores screen always go to...
	return ViewMode::MAIN_MENU;
}

void Scores::draw() {

}

void Scores::processKeypress(const sf::Keyboard::Key & key) {
	switch (key) {
	case sf::Keyboard::Return:
	case sf::Keyboard::Space:
	{
		exit_state = true;
		break;
	}
	default: break;
	}
}

void Scores::processJoystickButton(const int jsid, const int button) {
	switch (button) {
	case 7: // Start
	case 0: exit_state = true; break;
	default: break;
	}
}
