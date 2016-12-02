#ifndef MISSIONSELECT_HPP
#define MISSIONSELECT_HPP
#include "View.hpp"

class MissionSelect : public View {
public:
	MissionSelect(std::shared_ptr<sf::RenderWindow> window_);

	const ViewMode view_loop() override;

private:
	void draw() override;
	void update() override;
	void processKeypress(const sf::Keyboard::Key &key) override;
	void processJoystickButton(const int jsid, const int button) override;
	void processJoystickMove(const sf::Event::JoystickMoveEvent &e) override;

	std::vector<sf::RectangleShape> mission_btns;
	int curr_mission_choice;
	int avail_missions;
};

#endif // MISSIONSELECT_HPP