#include "SetupScreen.hpp"

extern std::unique_ptr<GameData> GAMEDATA;

SetupScreen::SetupScreen(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {
	current_hlgted_obj = 0;

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

	for (auto e : GAMEDATA->getEnemyList())
		enemy_icons.push_back(e.get_drawable());
	for (auto w : GAMEDATA->getWeaponList())
		weapn_icons.push_back(w.get_drawable());
}

SetupScreen::~SetupScreen() {
	enemy_icons.clear();
	weapn_icons.clear();
	selected_wpns.clear();
}

const ViewMode SetupScreen::view_loop() {
	View::standardStateLoop();
	if (to_return == ViewMode::MISSION_SELECT)
		GAMEDATA->clearHeldWeapons();
	else if (to_return == ViewMode::IN_GAME)
		GAMEDATA->setHeldWeapons(selected_wpns);

	return to_return;
}

void SetupScreen::draw() {
	window->clear();

	window->draw(top_section);
	window->draw(middle_section_left);
	window->draw(middle_section_right);
	window->draw(bottom_section);

	constexpr float icon_scale = 2.0f;
	
	// Draw enemy icons
	sf::Vector2f pos(10.0f, 10.0f);
	for (auto e : enemy_icons) {
		e.setPosition(pos);
		window->draw(e);
		pos.x += 10.0f + e.getSize().x;
	}

	// Draw weapon icons
	pos = sf::Vector2f(10.0f, res.y * 0.2f + 10.0f);
	for (auto w : weapn_icons) {
		w.setScale(sf::Vector2f(icon_scale, icon_scale));
		w.setPosition(pos);
		window->draw(w);
		pos.x += 5.0f + icon_scale * w.getSize().x;
	}

	// Draw selected weapon icons
	pos = sf::Vector2f(10.0f, res.y * 0.8f + 10.0f);
	for (auto w : selected_wpns) {
		auto sprite = w.get_drawable();
		sprite.setScale(sf::Vector2f(icon_scale, icon_scale));
		sprite.setPosition(pos);
		window->draw(sprite);
		pos.x += 5.0f + icon_scale * sprite.getSize().x;
	}

	window->display();
}

void SetupScreen::preProcessInput() {
	// Unhighlight icon.
	auto unhl_icon = [] (sf::Shape* s) -> void {
		s->setOutlineColor(sf::Color::White);
		s->setOutlineThickness(0.0f);
	};

	auto num_enem = enemy_icons.size();
	auto num_weap = weapn_icons.size();
	if (current_hlgted_obj < num_enem) {
		unhl_icon(&enemy_icons[current_hlgted_obj]);
	} else if (current_hlgted_obj < num_enem + num_weap) {
		unhl_icon(&weapn_icons[current_hlgted_obj - num_enem]);
	} else {
		unhl_icon(&selected_wpns[current_hlgted_obj - num_enem - num_weap].get_drawable());
	}
}

void SetupScreen::postProcessInput() {
	// Prevent selecting out of possible range.
	size_t total_num_obj = enemy_icons.size()
		+ weapn_icons.size()
		+ selected_wpns.size();

	if (current_hlgted_obj >= total_num_obj)
		current_hlgted_obj = 0;
	if (current_hlgted_obj < 0)
		current_hlgted_obj = (int)total_num_obj - 1;

	// Highlight icon.
	auto hl_icon = [] (sf::Shape* s) -> void {
		s->setOutlineColor(sf::Color::Red);
		s->setOutlineThickness(2.0f);
	};

	auto num_enem = enemy_icons.size();
	auto num_weap = weapn_icons.size();
	if (current_hlgted_obj < num_enem) {
		hl_icon(&enemy_icons[current_hlgted_obj]);
	} else if (current_hlgted_obj < num_enem + num_weap) {
		hl_icon(&weapn_icons[current_hlgted_obj - num_enem]);
	} else {
		hl_icon(&selected_wpns[current_hlgted_obj - num_enem - num_weap].get_drawable());
	}
}

void SetupScreen::processKeypress(const sf::Keyboard::Key & key) {
	preProcessInput();

	switch (key) {
	case sf::Keyboard::Return:
	{
		auto num_enem = GAMEDATA->getEnemyList().size();
		auto num_weap = GAMEDATA->getWeaponList().size();
		if (current_hlgted_obj > num_enem
			&& current_hlgted_obj < (num_enem + num_weap)) {
			selected_wpns.push_back(GAMEDATA->getWeaponList()[current_hlgted_obj - num_enem]);
		}
		break;
	}
	case sf::Keyboard::BackSpace:
	{
		auto num_enem = GAMEDATA->getEnemyList().size();
		auto num_weap = GAMEDATA->getWeaponList().size();
		if (current_hlgted_obj < (num_enem + num_weap)) {
			break;
		}

		int to_delete = current_hlgted_obj - num_enem - num_weap;
		selected_wpns.erase(selected_wpns.begin() + (to_delete));
		break;
	}
	case sf::Keyboard::Escape: // Return to mission select
	{
		to_return = ViewMode::MISSION_SELECT;
		exit_state = true;
		break;
	}
	case sf::Keyboard::Space:// GAME START!
	{
		to_return = ViewMode::IN_GAME;
		exit_state = true;
		break;
	}
	case sf::Keyboard::Up:
	case sf::Keyboard::Left:
	case sf::Keyboard::A:
	case sf::Keyboard::W:
	{
		--current_hlgted_obj;
		break;
	}
	case sf::Keyboard::Down:
	case sf::Keyboard::Right:
	case sf::Keyboard::D:
	case sf::Keyboard::S:
	{
		++current_hlgted_obj;
		break;
	}
	default: break;
	}

	postProcessInput();
}

