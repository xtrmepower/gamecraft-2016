#include "SetupScreen.hpp"

SetupScreen::SetupScreen(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {

	sf::Vector2f curr(0.0f, 0.0f);
	// Top section. Size: screen width x 0.2 * screen height
	top_section = sf::RectangleShape(sf::Vector2f(res.x, res.y * 0.2f));
	top_section.setFillColor(sf::Color(201, 86, 20));

	curr.y += (res.y * 0.2f);
	// Middle section left
	middle_section_left = sf::RectangleShape(sf::Vector2f(res.x / 2.0f, res.y * 0.6f));
	middle_section_left.setFillColor(sf::Color::Cyan);
	middle_section_left.setPosition(curr);

	curr.x += (res.x / 2.0f);
	// Middle section right
	middle_section_right = sf::RectangleShape(sf::Vector2f(res.x / 2.0f, res.y * 0.6f));
	middle_section_right.setFillColor(sf::Color::Magenta);
	middle_section_right.setPosition(curr);

	curr = sf::Vector2f(0.0f, res.y * 0.8f);
	// Bottom section
	bottom_section = sf::RectangleShape(sf::Vector2f(res.x, res.y * 0.2f));
	bottom_section.setFillColor(sf::Color::Black);
	bottom_section.setPosition(curr);

}

const ViewMode SetupScreen::view_loop() {
	View::standardStateLoop();
	return to_return;
}

void SetupScreen::draw() {
	window->clear();

	window->draw(top_section);
	window->draw(middle_section_left);
	window->draw(middle_section_right);
	window->draw(bottom_section);

	window->display();
}

void SetupScreen::update() {}

void SetupScreen::processKeypress(const sf::Keyboard::Key & key) {
	switch (key) {
	case sf::Keyboard::Return:
	{
		to_return = ViewMode::MISSION_SELECT;
		exit_state = true;
		break;
	}
	case sf::Keyboard::Space:
	{
		to_return = ViewMode::IN_GAME;
		exit_state = true;
		break;
	}
	default: break;
	}
}
