#ifndef OPTIONMENU_HPP
#define OPTIONMENU_HPP
#include "View.hpp"

class OptionMenu : public View {
public:
	OptionMenu(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {
		difficulty = 1;
		//loadSettings();
	}

	void draw() override;
	const ViewMode view_loop() override;

private:
	void processKeypress(const sf::Keyboard::Key &key) override;

	unsigned int difficulty;
};

#endif // OPTIONMENU_HPP