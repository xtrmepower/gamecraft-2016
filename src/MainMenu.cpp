#include "MainMenu.hpp"

const ViewMode MainMenu::view_loop() {
	View::standardStateLoop();
	return (ViewMode)current_option;
}

void MainMenu::draw() {
	window->clear(sf::Color(64, 64, 127));
	sf::Vector2f highlgHalfDims = sf::Vector2f(210.0f, 25.0f) * scale_factor;
	sf::Vector2f buttonHalfDims = sf::Vector2f(200.0f, 25.0f) * scale_factor;
	const float buttonGap = (20.0f + 2.0f * buttonHalfDims.y) * scale_factor.y;

	const float baseY = (res.y / 2.0f) + (2.0f * buttonHalfDims.y);
	for (int i = 0; i < n_options; ++i) {
		sf::Vector2f curr(res.x / 2.0f, baseY + i * buttonGap);

		if (current_option == i + 1) {
			draw_rectangle(curr - highlgHalfDims, curr + highlgHalfDims, sf::Color::Yellow);
		}

		draw_rectangle(curr - buttonHalfDims, curr + buttonHalfDims, sf::Color::Transparent);
	}

	window->display();
}

void MainMenu::processKeypress(const sf::Keyboard::Key &key) {
	switch (key) {
	case sf::Keyboard::Return:
	case sf::Keyboard::Space:
	{
		exit_state = true;
		break;
	}

	case sf::Keyboard::Up:
	case sf::Keyboard::W:
	{
		--current_option;
		if (current_option < 1)
			current_option = 4;
		break;
	}

	case sf::Keyboard::Down:
	case sf::Keyboard::S:
	{
		++current_option;
		if (current_option > 4)
			current_option = 1;
		break;
	}
	default:
	{
		break;
	}
	}
}