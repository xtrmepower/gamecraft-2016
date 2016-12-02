#include "MainMenu.hpp"
#include <iostream>

extern std::unique_ptr<AssetManager> ASSETMGR;

MainMenu::MainMenu(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {
	current_option = Option::NEW_GAME;

	// Make buttons
	auto apply_button = [] (const char* txt, const sf::Vector2f &pos) -> sf::Text {
		auto btn = sf::Text(txt, ASSETMGR->main_menu_font, 40U);
		auto tr = btn.getLocalBounds();
		btn.setOrigin(tr.left + tr.width / 2.0f, tr.top + tr.height / 2.0f);
		btn.setPosition(pos);
		return btn;
	};

	const float btn_ht = 50.0f * scale_factor.y;
	// Button gap offset = 20 px + height of box
	const float gap = (20.0f + btn_ht) * scale_factor.y;
	// Starting vertical position = bottom half of screen + one box height
	sf::Vector2f curr(res.x / 2.0f, (res.y / 2.0f) + btn_ht);
	newgame_btn = apply_button("New Game", curr);
	curr.y += gap;
	continue_btn = apply_button("Continue", curr);
	curr.y += gap;
	options_btn = apply_button("Options", curr);
	curr.y += gap;
	exit_btn = apply_button("Exit", curr);
}

const ViewMode MainMenu::view_loop() {
	View::standardStateLoop();
	return (ViewMode)current_option;
}

void MainMenu::draw() {
	window->clear(sf::Color(64, 64, 127));

	window->draw(newgame_btn);
	window->draw(continue_btn);
	window->draw(options_btn);
	window->draw(exit_btn);

	window->display();
}

void MainMenu::update() {
	auto highlight_option = [] (sf::Text &btn) -> void {
		btn.setOutlineColor(sf::Color::Yellow);
		btn.setOutlineThickness(2.0f);
	};

	auto unhighlight_option = [] (sf::Text &btn) -> void {
		btn.setOutlineColor(sf::Color::Black);
		btn.setOutlineThickness(0.0f);
	};

	unhighlight_option(newgame_btn);
	unhighlight_option(continue_btn);
	unhighlight_option(options_btn);
	unhighlight_option(exit_btn);

	switch (current_option) {
	case Option::NEW_GAME: highlight_option(newgame_btn); break;
	case Option::CONTINUE: highlight_option(continue_btn); break;
	case Option::OPTIONS: highlight_option(options_btn); break;
	case Option::EXIT: highlight_option(exit_btn); break;
	}
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
	default: break;
	}
}

void MainMenu::processJoystickButton(const int jsid, const int button) {
	switch (button) {
	case 7: // Start
	case 0: exit_state = true; break;
	default: break;
	}
}

void MainMenu::processJoystickMove(const sf::Event::JoystickMoveEvent &e) {
	switch (e.axis) {
	case sf::Joystick::Axis::PovY:
	case sf::Joystick::Axis::Y:
	{
		if (e.position > 99.0f)
			++current_option;
		else if (e.position < -99.0f)
			--current_option;
		if (current_option > 4)
			current_option = 1;
		if (current_option < 1)
			current_option = 4;
		break;
	}
	default: break;
	}
}
