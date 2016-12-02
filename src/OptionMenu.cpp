#include "OptionMenu.hpp"

extern std::unique_ptr<AssetManager> ASSETMGR;

OptionMenu::OptionMenu(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {
	current_option = Option::SCRN_RES;
	difficulty = 1;

	// Optional: Load saved settings?

	// Make buttons
	auto apply_button = [] (const char* txt, const sf::Vector2f &pos) {
		auto btn = sf::Text(txt, ASSETMGR->main_menu_font, 30U);
		auto tr = btn.getLocalBounds();
		btn.setOrigin(tr.left + tr.width / 2.0f, tr.top + tr.height / 2.0f);
		btn.setPosition(pos);
		return btn;
	};

	const float optn_ht = 40.0f * scale_factor.y;
	// Option gap offset
	const float gap = (20.0f + optn_ht) * scale_factor.y;
	// Starting vertical position = center of screen
	sf::Vector2f curr(res.x / 2.0f, res.y / 2.0f);
	resolution_disp = apply_button(res2str(res).c_str(), curr);
	curr.y += gap;
	difficulty_disp = apply_button("0", curr);
}

const ViewMode OptionMenu::view_loop() {
	View::standardStateLoop();
	return ViewMode::MAIN_MENU;
}

void OptionMenu::draw() {
	window->clear(sf::Color(64, 64, 127));

	window->draw(resolution_disp);
	window->draw(difficulty_disp);

	window->display();
}

void OptionMenu::update() {
	auto highlight_option = [] (sf::Text &btn) -> void {
		btn.setOutlineColor(sf::Color::Yellow);
		btn.setOutlineThickness(1.0f);
	};

	auto unhighlight_option = [] (sf::Text &btn) -> void {
		btn.setOutlineColor(sf::Color::Black);
		btn.setOutlineThickness(0.0f);
	};

	unhighlight_option(resolution_disp);
	unhighlight_option(difficulty_disp);

	switch (difficulty) {
	default:
	case 0: difficulty_disp.setString("Easy"); break;
	case 1: difficulty_disp.setString("Normal"); break;
	case 2: difficulty_disp.setString("Hard"); break;
	case 3: difficulty_disp.setString("Nightmare"); break;
	}

	switch (current_option) {
	default:
	case Option::SCRN_RES: highlight_option(resolution_disp); break;
	case Option::DIFFICULTY: highlight_option(difficulty_disp); break;
	}
}

void OptionMenu::processKeypress(const sf::Keyboard::Key &key) {
	switch (key) {
	case sf::Keyboard::Space:
	case sf::Keyboard::Escape:
	{
		exit_state = true;
		break;
	}
	case sf::Keyboard::Up:
	case sf::Keyboard::W:
	{
		--current_option;
		if (current_option < 0)
			current_option = 1;
		break;
	}
	case sf::Keyboard::Down:
	case sf::Keyboard::S:
	{
		++current_option;
		if (current_option > 1)
			current_option = 0;
		break;
	}
	case sf::Keyboard::Left:
	case sf::Keyboard::A: processOptionChange(true); break;
	case sf::Keyboard::Right:
	case sf::Keyboard::D: processOptionChange(false); break;
	default: break;
	}
}

void OptionMenu::processJoystickButton(const int jsid, const int button) {
	switch (button) {
	case 7:
	case 1: exit_state = true; break;
	default: break;
	}
}

void OptionMenu::processJoystickMove(const sf::Event::JoystickMoveEvent &e) {
	switch (e.axis) {
	case sf::Joystick::Axis::PovY:
	case sf::Joystick::Axis::Y:
	{
		if (e.position > 99.0f)
			++current_option;
		else if (e.position < -99.0f)
			--current_option;
		if (current_option > 1)
			current_option = 0;
		if (current_option < 0)
			current_option = 1;
		break;
	}
	case sf::Joystick::Axis::PovX:
	case sf::Joystick::Axis::X:
	{
		if (e.position > 99.0f)
			processOptionChange(false);
		else if (e.position < -99.0f)
			processOptionChange(true);
		break;
	}
	default: break;
	}
}

void OptionMenu::processOptionChange(const bool left) {
	switch (current_option) {
	default:
	case Option::DIFFICULTY:
	{
		if (left) {
			--difficulty;
			if (difficulty < 0) difficulty = 3;
		} else {
			++difficulty;
			if (difficulty > 3) difficulty = 0;
		}
		break;
	}
	case Option::SCRN_RES:
	{
		if (left) {
			--resolution;
			if (resolution < 0) resolution = 2;
		} else {
			++resolution;
			if (resolution > 2) resolution = 0;
		}
		break;
	}
	}
}
