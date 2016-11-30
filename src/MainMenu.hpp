#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "View.hpp"

class MainMenu : public View {
public:
	MainMenu(std::shared_ptr<sf::RenderWindow> window_);
	void draw() override;
	const ViewMode view_loop() override;

private:
	void processKeypress(const sf::Keyboard::Key &key) override;

	// Must strictly be a subset of the available views, but can have different names
	enum Option {
		NEW_GAME = ViewMode::IN_GAME,
		CONTINUE = ViewMode::LOAD_SAVE,
		OPTIONS = ViewMode::OPTION_MENU,
		EXIT = ViewMode::EXIT
	};
	const int n_options = 4;
	int current_option = Option::NEW_GAME;
};

#endif // MAINMENU_HPP