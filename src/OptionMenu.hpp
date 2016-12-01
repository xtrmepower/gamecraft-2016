#ifndef OPTIONMENU_HPP
#define OPTIONMENU_HPP
#include "View.hpp"

class OptionMenu : public View {
public:
	OptionMenu(std::shared_ptr<sf::RenderWindow> window_);

	void draw() override;
	const ViewMode view_loop() override;

	static std::string res2str(const sf::Vector2u &res);

private:
	void processKeypress(const sf::Keyboard::Key &key) override;

	void processOptionChange(const bool left);

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
	int difficulty;
	int resolution;
	sf::Text difficulty_disp, resolution_disp;
};

inline std::string OptionMenu::res2str(const sf::Vector2u &res) {
	if (res.x == 1280U && res.y == 720U)
		return "HD720 (1280 x 720)";
	if (res.x == 1920U && res.y == 1080U)
		return "HD1080 (1920 x 1080)";
	if (res.x == 2560U && res.y == 1440U)
		return "WQHD (2560 x 1440)";
	return "Unsupported";
}

#endif // OPTIONMENU_HPP