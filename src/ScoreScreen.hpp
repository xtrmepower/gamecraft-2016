#ifndef SCORESCREEN_HPP
#define SCORESCREEN_HPP

#include "View.hpp"

class Scores : public View {
public:
	Scores(std::shared_ptr<sf::RenderWindow> window_);

	const ViewMode view_loop() override;

private:
	void draw() override;

	void processKeypress(const sf::Keyboard::Key &key) override;
	void processJoystickButton(const int jsid, const int button) override;
};

#endif // SCORESCREEN_HPP