#ifndef SETUPSCREEN_HPP
#define SETUPSCREEN_HPP
#include "Enemy.hpp"
#include "View.hpp"
#include "Weapon.hpp"

class SetupScreen : public View {
public:
	SetupScreen(std::shared_ptr<sf::RenderWindow> window_);
	~SetupScreen();

	const ViewMode view_loop() override;

private:
	void draw() override;
	void preProcessInput();
	void postProcessInput();

	void processKeypress(const sf::Keyboard::Key &key) override;


	sf::RectangleShape top_section, middle_section_left, 
		middle_section_right, bottom_section;
	ViewMode to_return;
	std::vector<sf::RectangleShape> enemy_icons;
	std::vector<sf::RectangleShape> weapn_icons;
	std::vector<Weapon> selected_wpns;
	int current_hlgted_obj;
};

#endif // SETUPSCREEN_HPP