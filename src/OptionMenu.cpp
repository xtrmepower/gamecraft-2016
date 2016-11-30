#include "OptionMenu.hpp"

const ViewMode OptionMenu::view_loop() {
	View::standardStateLoop();
	return ViewMode::MAIN_MENU;
}

void OptionMenu::draw() {
	window->clear(sf::Color(64, 64, 127));
	// Draw here
	window->display();
}

void OptionMenu::processKeypress(const sf::Keyboard::Key &key) {
	switch (key) {
	case sf::Keyboard::Left:
	case sf::Keyboard::A:
	{
		--difficulty;
		if (difficulty < 1) difficulty = 4;
		break;
	}
	case sf::Keyboard::Right:
	case sf::Keyboard::D:
	{
		++difficulty;
		if (difficulty > 4) difficulty = 1;
		break;
	}
	case sf::Keyboard::Space:
	case sf::Keyboard::Escape:
	{
		exit_state = true;
		break;
	}
	}
}