#ifndef OPTIONMENU_HPP
#define OPTIONMENU_HPP
#include "View.hpp"

class OptionMenu : public View {
public:
	OptionMenu(std::shared_ptr<sf::RenderWindow> window_);

	void draw() override;
	const ViewMode view_loop() override;

private:
	void processKeypress(const sf::Keyboard::Key &key) override;

	enum Option {
		SCRN_RES = 0,
		DIFFICULTY = 1
	};
	enum Resolution_Option {
		HD720 = 0,
		HD1080 = 1,
		WQHD = 2
		//WXGA = 3,
		//WUXGA = 4,
		//WQXGA = 5
	};
	int current_option;
	unsigned int difficulty;
	sf::Text difficulty_disp, resolution_disp;
};

#endif // OPTIONMENU_HPP