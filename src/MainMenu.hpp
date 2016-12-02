#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "View.hpp"

class MainMenu : public View {
public:
	MainMenu(std::shared_ptr<sf::RenderWindow> window_);
	void draw() override;
	const ViewMode view_loop() override;

private:
	void update() override;
	void processKeypress(const sf::Keyboard::Key &key) override;
	void processJoystickButton(const int jsid, const int button) override;
	void processJoystickMove(const sf::Event::JoystickMoveEvent &e) override;

	// Must strictly be a subset of the available views, but can have different names
	enum Option {
		NEW_GAME = ViewMode::MISSION_SELECT,
		CONTINUE = ViewMode::LOAD_SAVE,
		OPTIONS = ViewMode::OPTION_MENU,
		EXIT = ViewMode::EXIT
	};
	const int n_options = 4;
	int current_option;

	sf::Text newgame_btn, continue_btn, options_btn, exit_btn;
};

#endif // MAINMENU_HPP