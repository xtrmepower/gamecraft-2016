#include "MissionSelect.hpp"

extern std::unique_ptr<GameData> GAMEDATA;

MissionSelect::MissionSelect(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {
	curr_mission_choice = 0;
	avail_missions = 1;
	
	auto apply_btn = [] (const sf::Vector2f &btn_size, const sf::Vector2f &pos) ->sf::RectangleShape {
		auto btn = sf::RectangleShape(btn_size);
		btn.setFillColor(sf::Color(0, 50, 70));
		btn.setPosition(pos);
		return btn;
	};

	// Size of the gap on one side
	float gap = 6.0f * scale_gradient;
	// Button size horz = res / 5 - gap on both sides
	// Button size vert = res / 4 - gap on both sides
	sf::Vector2f btn_size = sf::Vector2f(res.x / 5.0f - 2 * gap, res.y / 4.0f - 2 * gap) * scale_factor;
	sf::Vector2f curr = sf::Vector2f(0.0f, 0.0f);
	for (int i = 0; i < 4; i++) {
		curr.y += gap;
		for (int j = 0; j < 5; j++) {
			curr.x += gap;
			mission_btns.push_back(apply_btn(btn_size, curr));
			curr.x += btn_size.x;
			curr.x += gap;
		}
		curr.y += btn_size.y;
		curr.y += gap;
		curr.x = 0.0f;
	}
}

void MissionSelect::draw() {
	window->clear(sf::Color(64, 64, 127));

	for (auto btn : mission_btns) {
		window->draw(btn);
	}

	window->display();
}

const ViewMode MissionSelect::view_loop() {
	View::standardStateLoop();
	return to_return;
}

void MissionSelect::update() {
	for (int i = 0; i < avail_missions; i++) {
		mission_btns[i].setFillColor(sf::Color::Blue);
	}
}

void MissionSelect::processKeypress(const sf::Keyboard::Key &key) {
	// Unhighlight previous option.
	mission_btns[curr_mission_choice].setOutlineColor(sf::Color::White);
	mission_btns[curr_mission_choice].setOutlineThickness(0.0f);

	switch (key) {
	case sf::Keyboard::Space:
	case sf::Keyboard::Return:
	{
		to_return = ViewMode::SETUP;
		exit_state = true;
		break;
	}
	case sf::Keyboard::Escape:
	{
		to_return = ViewMode::MAIN_MENU;
		exit_state = true;
		break;
	}
	case sf::Keyboard::Up:
	case sf::Keyboard::W:
	{
		if (curr_mission_choice - 5 < 0)
			curr_mission_choice += 3 * 5;
		else curr_mission_choice -= 5;
		break;
	}
	case sf::Keyboard::Down:
	case sf::Keyboard::S:
	{
		if (curr_mission_choice + 5 >=  20)
			curr_mission_choice -= 3 * 5;
		else curr_mission_choice += 5;
		break;
	}
	case sf::Keyboard::Left:
	case sf::Keyboard::A:
	{
		if (curr_mission_choice - 1 < 0)
			curr_mission_choice = 20 - 1;
		else curr_mission_choice -= 1;
		break;
	}
	case sf::Keyboard::Right:
	case sf::Keyboard::D:
	{
		if (curr_mission_choice + 1 >= 20)
			curr_mission_choice = 0;
		else curr_mission_choice += 1;
		break;
	}
	default: break;// Do nothing
	}

	// Don't let the player choose beyond the current available missions.
	if (curr_mission_choice > avail_missions - 1)
		curr_mission_choice = avail_missions - 1;

	// Highlight new option.
	mission_btns[curr_mission_choice].setOutlineColor(sf::Color::Green);
	mission_btns[curr_mission_choice].setOutlineThickness(4.0f);
}

void MissionSelect::processJoystickButton(const int jsid, const int button) {
	switch (button) {
	case 7: // Start
	case 0: exit_state = true; break;
	default: break;
	}
}

void MissionSelect::processJoystickMove(const sf::Event::JoystickMoveEvent & e) {
	// Unhighlight previous option.
	mission_btns[curr_mission_choice].setOutlineColor(sf::Color::White);
	mission_btns[curr_mission_choice].setOutlineThickness(0.0f);
	
	switch (e.axis) {
	case sf::Joystick::Axis::PovY:
	{
		if (e.position > 99.0f) {
			if (curr_mission_choice - 5 < 0) {
				curr_mission_choice += 3 * 5;
			} else curr_mission_choice -= 5;
		} else if (e.position < -99.0f) {
			if (curr_mission_choice + 5 >= 20) {
				curr_mission_choice -= 3 * 5;
			} else curr_mission_choice += 5;
		}
		break;
	}
	case sf::Joystick::Axis::Y:
	{
		if (e.position < -99.0f) {
			if (curr_mission_choice - 5 < 0) {
				curr_mission_choice += 3 * 5;
			} else curr_mission_choice -= 5;
		} else if (e.position > 99.0f) {
			if (curr_mission_choice + 5 >= 20) {
				curr_mission_choice -= 3 * 5;
			} else curr_mission_choice += 5;
		}
		break;
	}
	case sf::Joystick::Axis::PovX:
	{
		if (e.position < -99.0f) {
			if (curr_mission_choice - 1 < 0) {
				curr_mission_choice = 20 - 1;
			} else curr_mission_choice -= 1;
		} else if (e.position > 99.0f) {
			if (curr_mission_choice + 1 >= 20) {
				curr_mission_choice = 0;
			} else curr_mission_choice += 1;
		}
		break;
	}
	case sf::Joystick::Axis::X:
	{
		if (e.position > 99.0f) {
			if (curr_mission_choice - 1 < 0) {
				curr_mission_choice = 20 - 1;
			} else curr_mission_choice -= 1;
		} else if (e.position < -99.0f) {
			if (curr_mission_choice + 1 >= 20) {
				curr_mission_choice = 0;
			} else curr_mission_choice += 1;
		}
		break;
	}
	default: break;
	}

	// Don't let the player choose beyond the current available missions.
	if (curr_mission_choice > avail_missions - 1)
		curr_mission_choice = avail_missions - 1;

	// Highlight new option.
	mission_btns[curr_mission_choice].setOutlineColor(sf::Color::Green);
	mission_btns[curr_mission_choice].setOutlineThickness(4.0f);

	GAMEDATA->selected_level = curr_mission_choice;
}