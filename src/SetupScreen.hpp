#ifndef SETUPSCREEN_HPP
#define SETUPSCREEN_HPP
#include "View.hpp"

class SetupScreen : public View {
public:
	SetupScreen(std::shared_ptr<sf::RenderWindow> window_);

	const ViewMode view_loop() override;

private:
	void draw() override;
	void update() override;
	void processKeypress(const sf::Keyboard::Key &key) override;

	sf::RectangleShape top_section, middle_section_left, 
		middle_section_right, bottom_section;

	ViewMode to_return;
};

#endif // SETUPSCREEN_HPP