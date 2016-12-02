#ifndef STAGE0_HPP
#define STAGE0_HPP

#include "View.hpp"
#include "Player.hpp"

class Stage0 : public View {
public:
	Stage0(std::shared_ptr<sf::RenderWindow> window_);

	void draw() override;
	const ViewMode view_loop() override;

	void update() override;

	void reset();

	Player p;
};

#endif