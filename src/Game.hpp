#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "View.hpp"

#include "Stage.hpp"

//#include "Stage0.hpp"

// The game view
class Game : public View {
public:
	Game(std::shared_ptr<sf::RenderWindow> window_);

	void draw() override;
	const ViewMode view_loop() override;
	
	//void new_game();
	//void continue_from();
private:
	void update() override;
	void processKeypress(const sf::Keyboard::Key &key) override;
	void processJoystickButton(const int jsid, const int button) override;
	void processJoystickMove(const sf::Event::JoystickMoveEvent &e) override;

	//Player p
	//PlayerPosition x, y

	std::vector<Stage> stage_list;
	int selected_stage;
};

#endif // GAME_HPP