#include "SetupScreen.hpp"

extern std::unique_ptr<GameData> GAMEDATA;

SetupScreen::SetupScreen(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {
	current_hlgted_wpn = 0;

	sf::Vector2f curr(0.0f, 0.0f);
	// Top section. Size: screen width x 0.2 * screen height
	top_section = sf::RectangleShape(sf::Vector2f((float)res.x, res.y * 0.2f));
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
	bottom_section = sf::RectangleShape(sf::Vector2f((float)res.x, res.y * 0.2f));
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

	sf::Vector2f pos(10.0f, 10.0f);
	for (auto e : GAMEDATA->getEnemyList()) {
		// icon = e.get_icon();
		// icon.setPosition(pos);
		// window->draw(icon);
		// Then, advance the position by icon width + gap
		pos.x += 5.0f;
	}

	pos = sf::Vector2f(10.0f, res.y * 0.8f + 10.0f);
	for (auto w : selected_wpns) {
		// icon = w.get_icon();
		// icon.setPosition(pos);
		// window->draw(icon);
		// Then, advance the position by icon width + gap
		pos.x += 5.0f;
	}

	window->display();
}

void SetupScreen::update() {
	
}

void SetupScreen::processKeypress(const sf::Keyboard::Key & key) {
	switch (key) {
	case sf::Keyboard::Return:
	{
		// Move weapon #$(current_hlted_wpn) from choice box to selected_weapons
		break;
	}
	case sf::Keyboard::Escape: // Return to mission select
	{
		to_return = ViewMode::MISSION_SELECT;
		GAMEDATA->clearHeldWeapons();
		exit_state = true;
		break;
	}
	case sf::Keyboard::Space:// GAME START!
	{
		to_return = ViewMode::IN_GAME;
		GAMEDATA->setHeldWeapons(selected_wpns);
		exit_state = true;
		break;
	}
	case sf::Keyboard::Up:
	case sf::Keyboard::Left:
	case sf::Keyboard::A:
	case sf::Keyboard::W:
	{
		--current_hlgted_wpn;
		break;
	}
	case sf::Keyboard::Down:
	case sf::Keyboard::Right:
	case sf::Keyboard::D:
	case sf::Keyboard::S:
	{
		++current_hlgted_wpn;
		break;
	}
	default: break;
	}

	if (current_hlgted_wpn >= GAMEDATA->getWeaponList().size())
		current_hlgted_wpn = 0;
	if (current_hlgted_wpn < 0)
		current_hlgted_wpn = (int)GAMEDATA->getWeaponList().size() - 1;
}

