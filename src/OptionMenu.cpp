#include <sstream>
#include "OptionMenu.hpp"

extern std::unique_ptr<AssetManager> ASSETMGR;

OptionMenu::OptionMenu(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {
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
	const float gap = (15.0f + optn_ht) * scale_factor.y;
	// Starting vertical position
	const float baseY = (res.y / 2.0f);
	sf::Vector2f curr(res.x / 2.0f, baseY);
	difficulty_disp = apply_button("0", curr);
}

const ViewMode OptionMenu::view_loop() {
	View::standardStateLoop();
	return ViewMode::MAIN_MENU;
}

void OptionMenu::draw() {
	window->clear(sf::Color(64, 64, 127));
	
	switch (difficulty) {
	default:
	case 0: difficulty_disp.setString("Easy"); break;
	case 1: difficulty_disp.setString("Normal"); break;
	case 2: difficulty_disp.setString("Hard"); break;
	case 3: difficulty_disp.setString("Nightmare"); break;
	}

	window->draw(difficulty_disp);
	window->display();
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
	case sf::Keyboard::A:
	{
		--difficulty;
		if (difficulty < 0) difficulty = 3;
		break;
	}
	case sf::Keyboard::Right:
	case sf::Keyboard::D:
	{
		++difficulty;
		if (difficulty > 3) difficulty = 0;
		break;
	}
	default: break;
	}
}